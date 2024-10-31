#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/colors.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() {
	std::cout << GREEN << "PresidentialPardonForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 25;
	_required_to_execute = 5;
	_is_signed = false;
	_name = "PresidentialPardonForm";
	_target = "";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) {
	std::cout << GREEN << "PresidentialPardonForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 25;
	_required_to_execute = 5;
	_is_signed = false;
	_name = "PresidentialPardonForm";
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {
	std::cout << BLUE << "PresidentialPardonForm Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED << "PresidentialPardonForm Destructor called " << RESET << std::endl;
}

// Operator Overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	std::cout << PURPLE << "PresidentialPardonForm Copy Assignment Operator called" << RESET
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

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	
}

