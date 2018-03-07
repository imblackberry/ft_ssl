#include <stdio.h>
#include <stdlib.h>

int ft_is_prime(int n)
{
	int i;

	i = 2;
	while(i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void ft_fprime(int n)
{
	int i;

	i = 2;
	while (n > 1)
	{
		if (n % i == 0)
		{
			(n / i > 1) ? printf("%d * ", i) : printf("%d", i);
			n = n / i;
		}
		else 
		{
			i++;
			while (ft_is_prime(i) != 1)
				i++;
		}
	}
	printf("\n");
	return ;
}

int main(int ac, char **av)
{
	ft_fprime(atoi(av[1]));
	return (ac);
}
