#ifndef _INTERN_
#define _INTERN_
#include <iostream>
#include <string>
#include "Form.hpp"
#include <locale>
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(Intern &cpy) {(void)cpy;}
        Intern &operator=(Intern &cpy) {(void)cpy; return *this;}
        Form *makeForm(const std::string &name, const std::string  &target);
        int ft_search(const std::string &name);
        Form *_good_class(int nb, const std::string &target);
    private:
        Form *array[5];
        int _nb;
};


#endif