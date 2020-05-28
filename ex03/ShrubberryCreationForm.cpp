#include "ShrubberryCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy)
{
	*this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &cpy)
{
	(void)cpy;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &execute) const
{
    	if (getSign() == true && getGradeExecut() > execute.getGrade())
    	{
        	std::string name;
        	name = getName();
        	name += "_shruberry";
        	std::ofstream flux(name);
        		flux << "                     .o00o" << std::endl
				<< "             ooooooo000000oo" << std::endl
				<< "           00000oo00000000000o" << std::endl
				<< "         000000  00000000000000" << std::endl
				<< "        oooooo  oooooo  00000000  o88o" << std::endl
				<< "      0 oooooooOOOOOOOoo  ```''  888888" << std::endl
				<< "     ooo OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl
				<< "    oooooooOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl
				<< "       \\ OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl
				<< "        \\OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl
				<< "         =OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl
				<< "             OO:F_P:O `QQQ/  /Q'" << std::endl
				<< "         0    \\\\. \\ |  // |" << std::endl
				<< "        000      d\\ \\\\\\|_////" << std::endl
				<< "       00000     qP| \\\\ _' `|Ob" << std::endl
				<< "      0000000     \\ \\ / \\  \\Op" << std::endl
				<< "        |||         || | O| |" << std::endl
				<< "        ||| _       /\\. \\_/ /\\" << std::endl
				<< "            `---__/|_\\\\   //|  __" << std::endl
				<< "                  `-'  `-'`-'-'" << std::endl;

    	}
		else
		{
			throw GradeTooLowException();
		}	
}