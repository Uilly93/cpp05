#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/colors.hpp"
#include <fstream>

static const std::string tree = "          &&& &&  & &&\n"
								"      && &\\/&\\|& ()|/ @, &&\n"
								"      &\\/(/&/&||/& /_/)_&/_&\n"
								"   &() &\\/&|()|/&\\/ '%\" & ()\n"
								"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
								"&&   && & &| &| /& & % ()& /&&\n"
								" ()&_---()&\\&\\|&&-&&--%---()~\n"
								"     &&     \\|||\n"
								"             |||\n"
								"             |||\n"
								"             |||\n"
								"       , -=-~  .-^- _\n"
								"              `\n";

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() {
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 145;
	_required_to_execute = 137;
	_is_signed = false;
	_name = "ShrubberyCreationForm";
	_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) {
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor called" << RESET << std::endl;
	_required_to_sign = 145;
	_required_to_execute = 137;
	_is_signed = false;
	_name = "ShrubberyCreationForm";
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) {
	std::cout << BLUE << "ShrubberyCreationForm Copy Constructor called" << RESET << std::endl;
	*this = src;
}
// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << RED << "ShrubberyCreationForm Destructor called " << RESET << std::endl;
}

// Operator Overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	std::cout << PURPLE << "ShrubberyCreationForm Copy Assignment Operator called" << RESET
			  << std::endl;
	if (this != &src) {
		this->_is_signed = src._is_signed;
		this->_required_to_execute = src._required_to_execute;
		this->_required_to_sign = src._required_to_sign;
		this->_target = src._target;
		this->_name = src._name;
	}
	return *this;
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return (RED "Error: ShrubberyCreationForm\n" RESET);
}

// Methods

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _required_to_execute)
		throw GradeTooLowException();
	std::ofstream file(_target + "_shrubbery");
	if (file.is_open()) {
		file << tree;
		file.close();
	} else
		throw std::runtime_error("fail open");
}
