#ifndef _PRESIDENTIALPARDON_
#define _PRESIDENTIALPARDON_
#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
    private:
        std::string  _action;
        std::string _target;
        PresidentialPardonForm();
    public:
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(PresidentialPardonForm &cpy);
        virtual void execute(Bureaucrat const &execute) const;

};

#endif