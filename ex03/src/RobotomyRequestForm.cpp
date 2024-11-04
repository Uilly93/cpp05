#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/colors.hpp"
#include <cstdlib>

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

const char *RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return (NRED "Error: RobotomyRequestForm\nBureaucrat Grade too Low\n" RESET);
}

// Methods
std::string RobotomyRequestForm::getTarget() const {
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _required_to_execute) {
		throw GradeTooLowException();
	} else {
		std::cout << NBLUE << executor.getName() << BLUE << " Executed " << NBLUE << _target << RESET
				  << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << NBLUE << _target << " has been robotomized succesfully" << RESET
					  << std::endl;
		else
			std::cout << NBLUE << _target << " robotomy failed" << RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &src) {
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	if (src.isSigned())
		return out << PURPLE << "RobotomyRequestForm infos:\n"
				   << "Target: " << src.getTarget() << "\nSign requierment: " << src.reqSign()
				   << "\nExecute requierment: " << src.reqExec() << "\nForm is signed\n"
				   << NPURPLE << "--------------------------------------------------------------"
				   << RESET << std::endl;
	return out << PURPLE << "RobotomyRequestForm infos:\n"
			   << "Target: " << src.getTarget() << "\nSign requierment: " << src.reqSign()
			   << "\nExecute requierment: " << src.reqExec() << "\nForm is not signed\n"
			   << NPURPLE << "--------------------------------------------------------------"
			   << RESET << std::endl;
}
