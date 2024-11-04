#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	// Constructor
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	// Destructor
	~PresidentialPardonForm();

	// Operator Overload
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	// Methods
	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;

	private:
	PresidentialPardonForm();
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &src);

#endif