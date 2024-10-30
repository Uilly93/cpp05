#ifndef FORM_HPP
#define FORM_HPP

#include "colors.hpp"
#include <iostream>

class Form {
	public:
	// Constructor
	Form();
	// Form(parametric constructor);
	Form(const Form &src);

	// Destructor
	~Form();

	// Operator Overload
	Form &operator=(const Form &src);

	// Methods


	private:
	const std::string _name;
	bool is_signed;
	const unsigned int required_to_sign;
	const unsigned int required_to_execute;
};

#endif