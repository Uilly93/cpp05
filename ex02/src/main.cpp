// #include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/colors.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

int main() {
	std::srand(time(0));
	// Creating Bureaucrats
	PresidentialPardonForm pres("Michael");
	RobotomyRequestForm robot("Robotomy");
	ShrubberyCreationForm shrub("Shrubbery");

	// Creating Forms
	Bureaucrat Michael("Michael Scott", 1);
	Bureaucrat Jim("Jim Halpert", 40);
	Bureaucrat Dwight("Dwight Schrute", 100);
	std::cout << Michael;
	std::cout << Jim;
	std::cout << Dwight;

	// Printing Forms infos
	// AForm badForm(""); //Uncomment to see if the class is abstact
	std::cout << shrub;
	std::cout << robot;
	std::cout << pres;

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "Trying to execute all Forms with Michael" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	try {

		Michael.executeForm(shrub);
		for (int i = 0; i < 10; i++)
			Michael.executeForm(robot);
		Michael.executeForm(pres);

	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "Trying to execute all Forms with Jim" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	try {
		Jim.executeForm(shrub);
		for (int i = 0; i < 10; i++)
			Jim.executeForm(robot);
		Jim.executeForm(pres);

	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "Trying to execute all Forms with Dwight" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	try {
		Dwight.executeForm(shrub);
		for (int i = 0; i < 10; i++)
			Dwight.executeForm(robot);
		Dwight.executeForm(pres);

	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}
