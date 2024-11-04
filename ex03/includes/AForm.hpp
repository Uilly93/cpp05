#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm {
	public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	// Constructor
	AForm(const std::string &name, unsigned int to_sign, unsigned int to_exec);
	AForm(const AForm &src);

	// Destructor
	virtual ~AForm();

	// Operator Overload
	AForm &operator=(const AForm &src);

	// Methods
	unsigned int reqSign() const;
	unsigned int reqExec() const;
	bool isSigned() const;
	std::string getName() const;
	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	protected:
	AForm();
	std::string _name;
	bool _is_signed;
	unsigned int _required_to_sign;
	unsigned int _required_to_execute;
};

std::ostream &operator<<(std::ostream &out, AForm const &src);

#endif