#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include <exception>
#include <iostream>

class Form {
	public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};
	// Constructor
	Form(const std::string &name, unsigned int to_sign, unsigned int to_exec);
	Form(const Form &src);

	// Destructor
	~Form();

	// Operator Overload
	Form &operator=(const Form &src);

	// Methods
	unsigned int reqSign() const;
	unsigned int reqExec() const;
	bool isSigned() const;
	std::string getName() const;
	void beSigned(Bureaucrat const &bureaucrat);

	private:
	Form();
	std::string _name;
	bool _is_signed;
	unsigned int _required_to_sign;
	unsigned int _required_to_execute;
};

std::ostream &operator<<(std::ostream &out, Form const &src);

#endif