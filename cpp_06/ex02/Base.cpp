#include "Base.hpp"

Base::Base() {}

Base::~Base() {}

Base::Base(const Base &src) {
	(void) src;
}

Base &Base::operator=(const Base &src) {
	(void) src;
	return *this;
}

Base	*generate(void) {
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	std::cout << "Type " << c << " created!" << std::endl;
	switch (c)
	{
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Error : identification" << std::endl;
}

void	identify(Base& p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void) a;
	} catch (std::bad_cast &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void) b;
		} catch (std::bad_cast &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void) c;
			} catch (std::bad_cast &e) {
				std::cout << "Error : identification" << std::endl;
			}
		}
	}
}