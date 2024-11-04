#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"

class Intern {
	public:
	// Constructor
	Intern();
	// Intern(parametric constructor);
	Intern(const Intern &src);

	// Destructor
	~Intern();

	// Operator Overload
	Intern &operator=(const Intern &src);

	// Methods
	AForm *makeForm(std::string name, std::string target) const;
	int choseCase(std::string name) const;

	private:
};

#endif