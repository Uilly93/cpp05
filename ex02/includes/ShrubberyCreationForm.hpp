#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
	public:
	// Constructor
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);

	// Destructor
	~ShrubberyCreationForm();

	// Operator Overload
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	// Methods
	void execute(Bureaucrat const & executor) const;
	private:
	ShrubberyCreationForm();
	std::string _target;
};

#endif