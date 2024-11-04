#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.hpp"

// Constructors
AForm::AForm() {
	std::cout << GREEN << "AForm Default Constructor called" << RESET << std::endl;
	_name = "";
	_is_signed = false;
	_required_to_execute = 150;
	_required_to_sign = 150;
}

AForm::AForm(const std::string &name, unsigned int to_sign, unsigned int to_exec) {
	if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
	else if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	std::cout << GREEN << "AForm Default Constructor called" << RESET << std::endl;
	_name = name;
	_required_to_sign = to_sign;
	_required_to_execute = to_exec;
	_is_signed = false;
}

AForm::AForm(const AForm &src) {
	std::cout << BLUE << "AForm Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
AForm::~AForm() {
	std::cout << RED << "AForm Destructor called " << RESET << std::endl;
}

// Operator Overload
AForm &AForm::operator=(const AForm &src) {
	std::cout << PURPLE << "AForm Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_required_to_sign = src._required_to_sign;
		this->_required_to_execute = src._required_to_execute;
		this->_is_signed = src._is_signed;
	}
	return *this;
}
// Methods

unsigned int AForm::reqSign() const {
	return _required_to_sign;
}

unsigned int AForm::reqExec() const {
	return _required_to_execute;
}

bool AForm::isSigned() const {
	return _is_signed;
}

std::string AForm::getName() const {
	return _name;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _required_to_sign) {
		throw GradeTooLowException();
	}
	std::cout << NGREEN << bureaucrat.getName() << GREEN << " signed " << NGREEN << _name << RESET
			  << std::endl;
	_is_signed = true;
}

// Redefine what();
const char *AForm::GradeTooHighException::what() const throw() {
	return (RED "Grade is too high !\n" RESET);
}

const char *AForm::GradeTooLowException::what() const throw() {
	return (RED "Grade is to Low\n" RESET);
}

std::ostream &operator<<(std::ostream &out, AForm const &src) {
	if (src.isSigned())
		return out << BLUE "name: " << src.getName() << ", sign requierment: " << src.reqSign()
				   << ", execute requierment: " << src.reqExec() << "and for is signed"
				   << std::endl;
	return out << BLUE "name: " << src.getName() << ", sign requierment: " << src.reqSign()
			   << ", execute requierment: " << src.reqExec() << "and for is not signed"
			   << std::endl;
}