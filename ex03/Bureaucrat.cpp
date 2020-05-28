#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknow"), _grade(150)
{ }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHightException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy.getName()), _grade(cpy.getGrade())
{
	*this = cpy;
}
Bureaucrat::~Bureaucrat(void) { }
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &cpy)
{
	_grade = cpy.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName(void)	const 
{ 
    return (_name); 
}
int			Bureaucrat::getGrade(void)	const 
{
     return (_grade);
}

void Bureaucrat::increase()
{
        if (_grade <= 1)
            throw  GradeTooHightException();
        _grade--;
}

void Bureaucrat::decrement()
{

        if (_grade >= 150)
            throw GradeTooLowException();
        _grade++;
}

std::ostream &operator<<(std::ostream &cout, Bureaucrat &classe)
{
    cout << classe.getName() << " ,bureaucrate grade " << classe.getGrade();
    return (cout);
}

Bureaucrat::GradeTooHightException::GradeTooHightException()
{

}
Bureaucrat::GradeTooHightException::~GradeTooHightException()
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{

}

const char* Bureaucrat::GradeTooHightException::what() const throw()
{
    return ("Error: Grade too hight");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: Grade too low");
}

void Bureaucrat::signForm(Form &classe)
{   
    try
    {
        if (classe.beSigned(*this) != true)
            {
                throw Form::GradeTooLowException();
            }
        std::cout << getName() << " signs " << classe.getName() << std::endl;
    }
    catch(std::exception &text)
    {
        std::cout << getName() << " can't sign " << classe.getName() << " because " << text.what() << std::endl; 
    }
}

void Bureaucrat::executeFrom(Form const &form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() <<" has executed " << form.getName() << std::endl;

    }
    catch(std::exception &error)
    {
        std::cout << getName() << " failed because " << error.what() << " of grade" << std::endl;
    }
}