#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.hpp"
#include <iostream>

class Bureaucrat {
public:
  // Constructor
  //   Bureaucrat();
  Bureaucrat(std::string name, unsigned int grade);
  //   Bureaucrat(const Bureaucrat &src);

  // Destructor
  ~Bureaucrat();

  // Operator Overload
  Bureaucrat &operator=(const Bureaucrat &src);

  // Methods

private:
  const std::string name;
  unsigned int grade;
};

#endif