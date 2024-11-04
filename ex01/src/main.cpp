#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/colors.hpp"
#include <exception>
#include <iostream>

int main() {

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NGREEN << "trying correct input" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;

	std::cout << NPURPLE << "creating Michael" << RESET << std::endl;
	try {
		Bureaucrat Michael("Michael Scott", 1); // Correct input
		Form bills("bills", 1, 1);
		std::cout << Michael;
		Michael.signForm(bills);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;
	std::cout << NRED << "trying incorrect input" << RESET << std::endl;
	std::cout << NPURPLE << "--------------------------------------------------------------"
			  << RESET << std::endl;

	std::cout << NPURPLE << "creating Jim" << RESET << std::endl;
	try {
		Bureaucrat Jim("Jim Halper", 2); // Incorrect input
		std::cout << Jim;
		std::cout << NPURPLE << "creating Form" << RESET << std::endl;
		Form bills("bills", 1, 1);
		Jim.signForm(bills);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << NPURPLE << "creating Dwight" << RESET << std::endl;
	try {
		Bureaucrat Dwight("Dwight Schrute", 150); // Incorrect input
		std::cout << Dwight;
		std::cout << NPURPLE << "creating Form" << RESET << std::endl;
		Form bills("bills", 150, 1);
		Dwight.signForm(bills);
	} catch (std::exception &e) {
		std::cout << e.what();
	}

	std::cout << NPURPLE << "creating Pam Beesly" << RESET << std::endl;
	try {
		Bureaucrat Pam("Pam Beesly", 15); // Incorrect input
		std::cout << NPURPLE << "creating Form" << RESET << std::endl;
		Form bills("bills", 151, 1);
		std::cout << Pam;
		Pam.Downgrade();
		Pam.Downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}
