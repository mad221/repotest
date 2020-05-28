#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy)
{
    *this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &cpy)
{
    this->_action = cpy._action;
    this->_target = cpy._target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(target, 25, 5)
{
}

void PresidentialPardonForm::execute(Bureaucrat const &execute) const
{
        if (getSign() == true && execute.getGrade() <= getGradeExecut())
    {
        std::cout << execute.getName() << " is forgive" << std::endl;
    }   
    else
        throw GradeTooLowException();
}
