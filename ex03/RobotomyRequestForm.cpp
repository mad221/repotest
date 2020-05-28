#include "RobotomyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm()
{

}

RobotmyRequestForm::~RobotmyRequestForm()
{

}

RobotmyRequestForm::RobotmyRequestForm(const std::string &target) : Form(target, 72, 45)
{

}

RobotmyRequestForm::RobotmyRequestForm(RobotmyRequestForm &cpy)
{
    *this = cpy;
}

RobotmyRequestForm &RobotmyRequestForm::operator=(RobotmyRequestForm &cpy)
{
    this->_action = cpy._action;
    this->_target = cpy._target;
    return *this;
}

void RobotmyRequestForm::execute(Bureaucrat const &execute) const
{
    if (getSign() == true && execute.getGrade() <= getGradeExecut())
    {
        std::cout << "BREEEEEEEEE BREEEEEEEEEEEE";
        int i = rand() % 100;
        if (i%2 == 0 )
        {
            std::cout << execute.getName() << " BREEEEEE has been robotomized" << std::endl;
        }
        else
        {
                        std::cout << execute.getName() << " BROUTBROUTbruut clic clic has failed to be robotomized" << std::endl;

        }
    }
    else 
    {
        throw GradeTooLowException();
    }
}
