#ifndef _SHRUBERRY_
#define _SHRUBERRY_
#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
    private:
         ShrubberyCreationForm();
    public:
       virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm &cpy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &cpy);
        ShrubberyCreationForm(std::string target);
        virtual void execute(Bureaucrat const &execute) const;
};


#endif