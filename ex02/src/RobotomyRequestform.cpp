#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/colors.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() {
	std::cout << GREEN << "RobotomyRequestForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 72;
	_required_to_execute = 45;
	_is_signed = false;
	_name = "RobotomyRequestForm";
	_target = "";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) {
	std::cout << GREEN << "RobotomyRequestForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 72;
	_required_to_execute = 45;
	_is_signed = false;
	_name = "RobotomyRequestForm";
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {
	std::cout << BLUE << "RobotomyRequestForm Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED << "RobotomyRequestForm Destructor called " << RESET << std::endl;
}

// Operator Overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	std::cout << PURPLE << "RobotomyRequestForm Copy Assignment Operator called" << RESET
			  << std::endl;
	if (this != &src) {
		this->_is_signed = src._is_signed;
		this->_required_to_execute = src._required_to_execute;
		this->_required_to_sign = src._required_to_sign;
		this->_target = src._target;
		this->_name = src._name;
	}
	return *this;
}
// Methods
