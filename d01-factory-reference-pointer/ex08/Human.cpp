

#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "smack that " << target  << " by hand" << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "toss some shit on "<< target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << target << " was abused" << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target){
	std::string actionNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	
	void (Human::*actions[])(std::string const & target) = {
		&Human::meleeAttack, 
		&Human::rangedAttack,
		&Human::intimidatingShout
	};

	int i = 3;
	while (--i >= 0)
		if (action_name.compare(actionNames[i]) == 0)
			(this->*actions[i])(target);

}