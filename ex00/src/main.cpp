#include "../includes/Bureaucrat.hpp"
#include "../includes/colors.hpp"
#include <exception>
#include <iostream>

int main() {
	std::cout << NPURPLE << "creating Michael" << RESET << std::endl;
	Bureaucrat Michael("Michael Scott", 1); // Correct input
	std::cout << Michael;
	std::cout << NPURPLE << "creating Jim" << RESET << std::endl;
	Bureaucrat Jim("Jim Halper", 2); // Incorrect input
	std::cout << Jim;
	std::cout << NPURPLE << "creating Dwight" << RESET << std::endl;
	Bureaucrat Dwight("Dwight Schrute", 149); // Incorrect input
	std::cout << Dwight;
	try {
		Michael.Downgrade();
		Michael.Upgrade();
		// Michael.Upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		Jim.Upgrade();
		Jim.Upgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		Dwight.Downgrade();
		Dwight.Downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	try {
		std::cout << NPURPLE << "creating Pam Beesly" << RESET << std::endl;
		Bureaucrat Pam("Pam Beesly", 151); // Incorrect input
		std::cout << Pam;
		Pam.Downgrade();
		Pam.Downgrade();
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 0;
}
