#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain {
	private : 
		std::string _ideas[100];
	public:
		Brain();
		virtual ~Brain();
		Brain(const Brain &);
		Brain &operator=(const Brain &rhs);
};

#endif