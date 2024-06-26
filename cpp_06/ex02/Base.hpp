#ifndef BASE_H
# define BASE_H

#include <iostream>

class Base {

	private:

	public:

		Base();
		virtual ~Base();
		Base(const Base &src);
		Base &operator=(const Base &src);
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
