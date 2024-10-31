#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.hpp"
#include <exception>
#include <iostream>
#include <ostream>

class Form;

class Bureaucrat {
	public:
	// Constructor
	class GradeIsTooHighException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	class GradeIsTooLowException : public std::exception {
		public:
		virtual const char *what() const throw();
	};
	Bureaucrat(const std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &src);

	// Destructor
	~Bureaucrat();

	// Operator Overload
	Bureaucrat &operator=(const Bureaucrat &src);

	// Methods
	const std::string getName() const;
	unsigned int getGrade() const;
	void signForm(Form &form) const;

	void Upgrade();
	void Downgrade();

	private:
	Bureaucrat();
	std::string _name;
	unsigned int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &src);

#endif