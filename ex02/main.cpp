#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberryCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define CATCH catch (std::exception& e) { std::cout << e.what() << std::endl ; }

int	main()
{
	Bureaucrat max = Bureaucrat("ji", 1);
	Bureaucrat min = Bureaucrat("ju", 150);
	ShrubberyCreationForm contrat("sfr");
	ShrubberyCreationForm sign("free");
	RobotmyRequestForm contrat1("1sfr");
	RobotmyRequestForm sign1("1free");
	PresidentialPardonForm contrat2("aborting");
	PresidentialPardonForm sign2("vokda");

	try
	{
		max.signForm(contrat);
		max.executeFrom(contrat);
		min.signForm(sign);
		min.executeFrom(sign);
		max.signForm(contrat1);
		max.executeFrom(contrat1);
		min.signForm(sign1);
		min.executeFrom(sign1);
		max.signForm(contrat2);
		max.executeFrom(contrat2);
		min.signForm(sign2);
		min.executeFrom(sign2);

	}
	CATCH;
	
	std::cout << contrat << std::endl;
	std::cout << sign << std::endl;
	std::cout << max << std::endl;
    std::cout << min << std::endl;
	try {
		contrat.beSigned(min);
		std::cout << contrat << std::endl;
		min.signForm(contrat);
	}
	CATCH;
	try {
		sign.beSigned(max);
		std::cout << sign << std::endl;
		max.signForm(sign);
	}
	CATCH;
	try {
	contrat.beSigned(max);
	std::cout << contrat << std::endl;
	max.signForm(contrat);
	}
	CATCH;
	try
	{
		Bureaucrat c = Bureaucrat("tsu", 0);
		std::cout << "okey" << std::endl;
	}
	CATCH;
	try { max.increase(); }
	CATCH;
	try { min.decrement(); }
	CATCH;
	try
	{
		max.increase();
		std::cout << max.getGrade() << std::endl;
	}
	CATCH;
	return (0);
}