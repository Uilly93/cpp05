#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	public:
	// Constructor
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &src);

	// Destructor
	~PresidentialPardonForm();

	// Operator Overload
	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	// Methods
	void execute(Bureaucrat const & executor) const;
	private:
	PresidentialPardonForm();
	std::string _target;
};

#endif