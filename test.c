#include <unistd.h>

int ft_atoi(const char *str)
{
	int i = 0;
	int flag = 1;
	int n = 0;

	while(str[i] == '\t' || str[i] == '\n' ||str[i] == '\v' ||str[i] == '\f' ||str[i] == '\r' ||str[i] == ' ')
			i++;
	if(str[i] == '-')
		flag = -1;
	if(str[i] == '-' || str[i] == '+')
			i++;
	while('0' <= str[i] && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0') ;
		i++;
	}
	return(n * flag);
}
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("%d", ft_atoi(argv[1]));
}