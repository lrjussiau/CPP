#include "Bureaucrat.hpp"

int main() {
	try
	{
		std::cout << "Bureaucrate 1 :" << std::endl;
		Bureaucrat b1("Tom", 150);
		std::cout << b1 << std::endl;
		b1.incrementGrade();

		std::cout << "Bureaucrate 2 :" << std::endl;
		Bureaucrat b2 = b1;
		std::cout << b2 << std::endl;
	}
	catch (GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
	catch (GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }

}