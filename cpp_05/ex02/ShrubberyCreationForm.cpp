#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <sstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Schrubbery Creation Form", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm("Schrubbery Creation Form", 145, 137), _target(src._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    (void)rhs;
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
	if (bureaucrat.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open()) {
		std::cerr << "Failed to open " << _target << " file." << std::endl;
		return ;
	}
	file << "                      ___" << std::endl;
	file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
	file << "             ,-'          __,,-- \\" << std::endl;
	file << "           ,'    __,--\"\"\"\"dF      )" << std::endl;
	file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
	file << "        ,'       _Hb ___dF\"-._,-'" << std::endl;
	file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
	file << "     (     ,-'                  `." << std::endl;
	file << "      `._,'     _   _             ;" << std::endl;
	file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
	file << "       \\    ,\"\"Hb.-'HH`-.dHF\"" << std::endl;
	file << "        `--'   \"Hb  HH  dF\"" << std::endl;
	file << "                \"Hb HH dF" << std::endl;
	file << "                 \"HbHHdF" << std::endl;
	file << "                  |HHHF" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  |HHH|" << std::endl;
	file << "                  dHHHb" << std::endl;
	file << "                .dFd|bHb.               o" << std::endl;
	file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
	file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__" << std::endl;
	file << "##########################################" << std::endl;
	file.close();
}