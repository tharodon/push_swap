#include "../push_swap.h"

static long int	schet_long (long int i, long int temp, const char *str)
{
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = (temp * 10) + (str[i] - 48);
		i++;
	}
	return (temp);
}

long int	ft_atoi_long (const char *str)
{
	long int		i;
	long int		temp;
	long int		minus;

	temp = 0;
	i = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		if (str[i + 1] == '-')
			return (temp);
		i++;
	}
	if (str[i] == '-')
	{
		minus++;
		i++;
	}
	temp = schet_long(i, temp, str);
	if (minus == 1)
		temp = temp * -1;
	return (temp);
}
