//
// Created by comp on 7/5/2019.
//

#ifndef D08_MUTANTSTACK_HPP
#define D08_MUTANTSTACK_HPP



#include <iostream>
#include <stack>

	template <typename T>
	class MutantStack : public std::stack<T>
	{

		public:

			typedef typename std::stack<T>::container_type::iterator	iterator;

			MutantStack() {};
			MutantStack(const MutantStack & obj) {
				*this = obj;
			};

			MutantStack &	operator = (MutantStack const & ms) {

				return (static_cast<MutantStack &>(std::stack<T>::operator=(ms)));
			};

			iterator	begin() {
				return (std::stack<T>::c.begin());    //protected: _Sequence c in std::stack
			}
			iterator	end() {
				return (std::stack<T>::c.end());
			}

			~MutantStack() {};
	};


#endif //D08_MUTANTSTACK_HPP
