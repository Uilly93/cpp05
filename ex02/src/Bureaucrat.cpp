#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/colors.hpp"
#include <exception>
#include <ostream>

// Constructors
Bureaucrat::Bureaucrat() {
	_name = "Bureaucrat";
	_grade = 150;
	std::cout << GREEN << "Bureaucrat Default Constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) {
	std::cout << GREEN << "Bureaucrat Default Constructor called" << RESET << std::endl;
	if (grade > 150)
		throw GradeIsTooLowException();
	else if (grade < 1)
		throw GradeIsTooHighException();
	_name = name;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
	std::cout << BLUE << "Bureaucrat Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
Bureaucrat::~Bureaucrat() {
	std::cout << RED << "Bureaucrat Destructor called " << RESET << std::endl;
}

// Operator Overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	std::cout << PURPLE << "Bureaucrat Copy Assignment Operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_grade = src._grade;
	}
	return *this;
}
// Methods

const std::string Bureaucrat::getName() const {
	return (_name);
}

unsigned int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::Upgrade() {
	if (_grade == 1)
		throw GradeIsTooHighException();
	_grade--;
	std::cout << NGREEN << _name << GREEN << " Upgraded to " << NGREEN << _grade << RESET
			  << std::endl;
}
void Bureaucrat::Downgrade() {
	if (_grade == 150)
		throw GradeIsTooLowException();
	_grade++;
	std::cout << NRED << _name << RED << " Downgraded to " << NRED << _grade << RESET << std::endl;
}

void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << NRED << _name << RED " couldn't sign " NRED << form.getName()
				  << RED " Because " << e.what();
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
	// try {
		form.execute(*this);
	// } catch (std::exception &e) {
	// 	std::cout << NRED << _name << RED " couldn't execute " NRED << form.getName()
	// 			  << RED " Because " << e.what();
	// }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src) {
	return out << NGREEN << src.getName() << GREEN << ", bureaucrat grade: " << NGREEN
			   << src.getGrade() << "." << RESET << std::endl;
}

// Exceptions

const char *Bureaucrat::GradeIsTooHighException::what() const throw() {
	return (RED "Bureaucrat: Grade is too HIGH\n" RESET);
}

const char *Bureaucrat::GradeIsTooLowException::what() const throw() {
	return (RED "Bureaucrat: Grade is too LOW\n" RESET);
}
