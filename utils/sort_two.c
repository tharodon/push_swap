#include "push_swap.h"

void	sort_two (t_stack **a)
{
	int	b;
	int	c;

	while ((*a)->back)
		*a = (*a)->back;
	b = (*a)->count;
	c = (*a)->next->count;
	if (c < b)
		list_sasb(a, 1);
}

void	sort_two_for_b (t_stack **a, t_stack **b)
{
	int	y;
	int	c;

	while ((*a)->back)
		*a = (*a)->back;
	y = (*a)->count;
	c = (*a)->next->count;
	if (c > y)
	{
		list_sasb(a, 1);
		list_pp(a, b, 1);
		list_pp(a, b, 1);
	}
	else
	{
		list_pp(a, b, 1);
		list_pp(a, b, 1);
	}
}

void	sort_two_for_a (t_stack **a)
{
	int	first;
	int	second;

	while ((*a)->back)
		*a = (*a)->back;
	first = (*a)->count;
	second = (*a)->next->count;
	if (second < first)
		list_sasb(a, 1);
}

int	check_maxmin_int (char **argv)
{
	int			i;
	long int	rem;

	i = 0;
	while (argv[i])
	{
		rem = ft_atoi_long(argv[i]);
		if (rem < -2147483648 || rem > 2147483647)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
