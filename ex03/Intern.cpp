#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
    if (_nb != 4)
        delete array[_nb];
}

int Intern::ft_search(const std::string &name)
{

    std::string _name[3]= {"robotomy request", "shrubberry creation", "presidential pardon"};
    int i = 0;
    while (i < 3)
    {
        if (_name[i] == name)
        {
            std::cout << name << " is create by the intern" << std::endl;
            return (i);
        }
        i++;
    }
    std::cout << name << " not found by the intern....." << std::endl;
    return (4);
}

Form *Intern::_good_class(int nb,const std::string &target)
{
        this->_nb = nb;
        array[4] = NULL;
        array[0] = new  RobotmyRequestForm(target);
        array[1] = new  ShrubberyCreationForm(target);
        array[2] = new  PresidentialPardonForm(target);
        int i = 0;
        while ( i < 3)
        {
            if (i != nb)
                delete array[i];
            i++;
        }
        return array[nb];
}

Form *Intern::makeForm(const std::string &name,const std::string &target)
{
    return (_good_class(ft_search(name), target));
}