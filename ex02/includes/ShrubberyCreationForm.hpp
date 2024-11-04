#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
	public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	// Constructor
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	// Destructor
	~ShrubberyCreationForm();

	// Operator Overload
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	// Methods
	void execute(Bureaucrat const &executor) const;
	std::string getTarget() const;

	private:
	ShrubberyCreationForm();
	std::string _target;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &src);

#endif