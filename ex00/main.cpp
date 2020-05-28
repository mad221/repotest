#include "Bureaucrat.hpp"

#define CATCH catch (std::exception& e) { std::cout << e.what() << std::endl ; }

int	main()
{
	Bureaucrat max("ji", 1);
	Bureaucrat min("ju", 150);
	std::cout << max << std::endl;
    std::cout << min << std::endl;
	try
	{
		Bureaucrat c("tsu", 0);
		std::cout << "okey" << std::endl;
	}
	CATCH;
	try { max.increase(); }
	CATCH;
	try {
		std::cout << min << std::endl; 
		min.decrement(); }
	CATCH;
	try {
		min.increase();
		std::cout << min << std::endl; 
		}
	CATCH;
	try
	{
		max.decrement();
		std::cout << max.getGrade() << std::endl;
	}
	CATCH;
	return (0);
}