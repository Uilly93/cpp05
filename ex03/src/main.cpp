#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/colors.hpp"

int main() {

	Intern Ryan;

	Bureaucrat Michael("Michael Scott", 1);

	AForm *form = Ryan.makeForm("RobotomyRequestForm", "Robot");
	AForm *form1 = Ryan.makeForm("PresidentialPardonForm", "Robot");
	AForm *form2 = Ryan.makeForm("ShrubberyCreationForm", "Robot");
	try {
		form->beSigned(Michael);
		form->execute(Michael);
		form1->beSigned(Michael);
		form1->execute(Michael);
		form2->beSigned(Michael);
		form2->execute(Michael);
		AForm *form3 = Ryan.makeForm("Invalid", "Robot");
		form3->beSigned(Michael);
		form3->execute(Michael);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	delete form;
	delete form1;
	delete form2;
	return 0;
}
