#ifndef _ROBOTMYREQUEST_
#define _ROBOTMYREQUEST_
#include <iostream>
#include <string>
#include "Form.hpp"
#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"


class RobotmyRequestForm : public Form
{
    private:
        std::string _action;
        std::string _target;
        RobotmyRequestForm();
    public:
       virtual ~RobotmyRequestForm();
        RobotmyRequestForm(RobotmyRequestForm &cpy);
        RobotmyRequestForm &operator=(RobotmyRequestForm &cpy);
        RobotmyRequestForm(const std::string &target);
        virtual void execute(Bureaucrat const &execute) const;


};

#endif