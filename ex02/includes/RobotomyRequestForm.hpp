#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "colors.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	public:
	// Constructor
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);

	// Destructor
	~RobotomyRequestForm();

	// Operator Overload
	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

	// Methods
	void execute(Bureaucrat const & executor) const;

	private:
	RobotomyRequestForm();
	std::string _target;
};

#endif