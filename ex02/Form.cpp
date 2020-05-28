#include "Form.hpp"

Form::Form(void) : _name("default"), _sign(false), _grade_to_sign(1), _grade_to_execut(1)
{
}

Form::Form(const Form &cpy) : _name(cpy.getName()), _sign(cpy.getSign()), _grade_to_sign(cpy.getGradeSign()), _grade_to_execut(getGradeExecut())
{
	*this = cpy;
}

Form &Form::operator=(const Form &cpy)
{
    (void)cpy;
    return *this;
}


Form::Form(std::string const name, int grade_to_sign, int grade_to_execut) : _name(name), _sign(false), _grade_to_sign(grade_to_sign), _grade_to_execut(grade_to_execut)
{
        if (grade_to_execut < 1 || grade_to_execut > 150)
        {
            if (grade_to_execut < 1)
            {
                std::cout << "Grade to execut ";
                throw Form::GradeTooHightException();
            }
            if (grade_to_execut > 150)
            {
                std::cout << "Grade to execut ";
                throw Form::GradeTooLowException();
            }
        }
        if (grade_to_sign < 1 || grade_to_sign > 150)
        {
            if (grade_to_sign < 1)
            {
                std::cout << "Grade to sign ";
                throw Form::GradeTooHightException();
            }
            if (grade_to_sign > 150)
            {
                std::cout << "Grade to sign ";
                throw Form::GradeTooLowException();
            }
         }
}

int Form::getGradeExecut() const
{
    return (_grade_to_execut);
}

int Form::getGradeSign() const
{
    return(_grade_to_sign);
}

bool Form::getSign() const
{
    return (_sign);
}

std::string Form::getName() const
{
    return(_name);
}

Form::~Form()
{

}

bool Form::beSigned(Bureaucrat &man)
{
        if (man.getGrade() > _grade_to_sign)
        {
            throw Form::GradeTooLowException();
        }
        _sign = true;
        return (_sign);

}

std::ostream &operator<<(std::ostream &cout, Form &classe)
{
    cout << classe.getName() << " , grade to execute = " << classe.getGradeExecut() << ", grade to sign = " << classe.getGradeSign() << " signed ? " << classe.getSign();
    return (cout);
}

Form::GradeTooLowException::GradeTooLowException()
{}


Form::GradeTooLowException::~GradeTooLowException()
{}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Error: for sign form Too low !");
}


Form::GradeTooHightException::GradeTooHightException()
{}

Form::GradeTooHightException::~GradeTooHightException()
{}

const char* Form::GradeTooHightException::what() const throw()
{
    return ("Error: for sign form Too hight");
}