#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	// Constructor
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);

	// Destructor
	~RobotomyRequestForm();

	// Operator Overload
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	// Methods
	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;

	private:
	RobotomyRequestForm();
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &src);

#endif