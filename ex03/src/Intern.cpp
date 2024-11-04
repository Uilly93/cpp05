#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/colors.hpp"
// #include <exception>
// #include <stdexcept>

// Constructors
Intern::Intern() {
	std::cout << GREEN << "Intern Default Constructor called" << RESET << std::endl;
}

// Intern::Intern(parametric constructor){
//      std::cout << GREEN << "Intern Default Constructor called" << RESET << std::endl;
// }

Intern::Intern(const Intern &src) {
	std::cout << BLUE << "Intern Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
Intern::~Intern() {
	std::cout << RED << "Intern Destructor called " << RESET << std::endl;
}

// Operator Overload
Intern &Intern::operator=(const Intern &src) {
	std::cout << PURPLE << "Intern Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
	}
	return *this;
}
// Methods
int Intern::choseCase(std::string name) const {
	std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for(int i = 0; i < 3; i++){
		if(name == tab[i])
			return i;
	}
	return -1;
}

AForm *Intern::makeForm(std::string name, std::string target) const {
	int form = this->choseCase(name);
	switch (form) {
		case -1:
			throw std::invalid_argument(RED "invalid Form name\n" RESET);
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);
		default:
			throw std::invalid_argument("invalid Form name");
	}
}



