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

const char *PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return (NRED "Error: PresidentialPardonForm\nBureaucrat Grade too Low\n" RESET);
}

// Methods

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _required_to_execute){
		throw GradeTooLowException();
	}
	std::cout << NBLUE << _target << " has been pardoned by Zaphod Beeblebrox." << RESET
			  << std::endl;
}

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &src) {
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	if (src.isSigned())
		return out << PURPLE << "PresidentialPardonForm infos:\n"
				   << "Target: " << src.getTarget() << "\nSign requierment: " << src.reqSign()
				   << "\nExecute requierment: " << src.reqExec() << "\nForm is signed\n"
				   << NPURPLE << "--------------------------------------------------------------"
				   << RESET << std::endl;
	return out << PURPLE << "PresidentialPardonForm infos:\n"
			   << "Target: " << src.getTarget() << "\nSign requierment: " << src.reqSign()
			   << "\nExecute requierment: " << src.reqExec() << "\nForm is not signed\n"
			   << NPURPLE << "--------------------------------------------------------------"
			   << RESET << std::endl;
}