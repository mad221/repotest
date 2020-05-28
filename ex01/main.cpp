#include "Bureaucrat.hpp"
#include "Form.hpp"

#define CATCH catch (std::exception& e) { std::cout << e.what() << std::endl ; }

int	main()
{
	Bureaucrat max = Bureaucrat("ji", 1);
	Bureaucrat min = Bureaucrat("ju", 150);
	Form contrat("sfr", 120, 3);
	Form sign("free", 1, 1);
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
	try{
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