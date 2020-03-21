
#include "Enemy.hpp"

Enemy::Enemy(){
	_hp = 1;
	_type = "Random Scav";
}

Enemy::Enemy(int hp, std::string const & type){
	_hp = hp;
	_type = type;
}

Enemy::Enemy(Enemy const & o){
	*this = o;
}

Enemy &	Enemy::operator = (Enemy const & o){
	_hp = o.getHP();
	_type = o.getType();
	return (*this);
}

Enemy::~Enemy(){
}
// // // // // // // // // // // // // // // // // 
int						Enemy::getHP() const{
	return (_hp);
}
std::string const &		Enemy::getType() const{
	return (_type);
}
// // // // // // // // // // // // // // // // // 
void				Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	_hp -= damage;
	if (_hp <= 0)
		Enemy::~Enemy();
}