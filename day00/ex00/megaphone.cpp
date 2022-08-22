#include <iostream>
int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if (argc == 1)
    {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		std::cout << std::endl;
		return (0);
    }
    while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << char(toupper(argv[i][j]));
			j++;
		}
		if (argv[i + 1] != '\0')
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}