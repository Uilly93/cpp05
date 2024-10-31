#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.hpp"

// Constructors
Form::Form() {
	std::cout << GREEN << "Form Default Constructor called" << RESET << std::endl;
	_name = "";
	_is_signed = false;
	_required_to_execute = 150;
	_required_to_sign = 150;
}

Form::Form(const std::string &name, unsigned int to_sign, unsigned int to_exec) {
	std::cout << GREEN << "Form Default Constructor called" << RESET << std::endl;
	if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
	else if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	_name = name;
	_required_to_sign = to_sign;
	_required_to_execute = to_exec;
	_is_signed = false;
}

Form::Form(const Form &src) {
	std::cout << BLUE << "Form Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
Form::~Form() {
	std::cout << RED << "Form Destructor called " << RESET << std::endl;
}

// Operator Overload
Form &Form::operator=(const Form &src) {
	std::cout << PURPLE << "Form Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_required_to_sign = src._required_to_sign;
		this->_required_to_execute = src._required_to_execute;
		this->_is_signed = src._is_signed;
	}
	return *this;
}
// Methods

unsigned int Form::reqSign() const {
	return _required_to_sign;
}

unsigned int Form::reqExec() const {
	return _required_to_execute;
}

bool Form::isSigned() const {
	return _is_signed;
}

std::string Form::getName() const {
	return _name;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > _required_to_sign) {
		throw GradeTooLowException();
	}
	std::cout << NGREEN << bureaucrat.getName() << GREEN << " signed " << NGREEN << _name << RESET
			  << std::endl;
	_is_signed = true;
}

// Redefine what();
const char *Form::GradeTooHighException::what() const throw() {
	return (RED "Form: Grade is too high !\n" RESET);
}

const char *Form::GradeTooLowException::what() const throw() {
	return (RED "Form :Grade is to Low\n" RESET);
}

std::ostream &operator<<(std::ostream &out, Form const &src) {
	if (src.isSigned())
		return out << BLUE "name: " << src.getName() << ", sign requierment: " << src.reqSign()
				   << ", execute requierment: " << src.reqExec() << "and for is signed"
				   << std::endl;
	return out << BLUE "name: " << src.getName() << ", sign requierment: " << src.reqSign()
			   << ", execute requierment: " << src.reqExec() << "and for is not signed"
			   << std::endl;
}