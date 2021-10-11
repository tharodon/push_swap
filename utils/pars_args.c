#include "push_swap.h"

int	check_to_sort(t_stack **a)
{
	while ((*a)->back)
		*a = (*a)->back;
	linit(*a);
	while (*a)
	{
		if ((*a)->next != (*a)->next_order)
			return (0);
		*a = (*a)->next;
	}
	return (1);
}

int	check_duplicate (int *stack, int size)
{
	int	i;
	int	q;

	i = 1;
	q = 0;
	while (q < size)
	{
		while (i < size)
		{
			if (stack[i] == stack[q])
			{
				write (1, "Error\n", 6);
				return (0);
			}
			i++;
		}
		i = ++q + 1;
	}
	return (1);
}

static int	check_minus (char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9') && argv[i + 1] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	check_of_valid (char **argv)
{
	int	i;
	int	q;

	i = 0;
	q = 1;
	while (argv[q])
	{
		while (argv[q][i])
		{
			if (!((argv[q][i] >= '0' && argv[q][i] <= '9') || \
			argv[q][i] == '-' || argv[q][i] == ' ') || !check_minus(argv[q]))
			{
				write (1, "Error\n", 6);
				return (0);
			}
			i++;
		}
		q++;
		i = 0;
	}
	return (1);
}

int	*pars_argc (char **argv, int *argc, _Bool is_to_fresh)
{
	int	*r;
	int	i;

	if (argv[0] == '\0' || !check_maxmin_int(argv))
		return (NULL);
	if (is_to_fresh)
		*argc = count_tab_chars(argv);
	else
		argc[0]--;
	r = (int *)malloc(sizeof(int) * *argc);
	if (!r)
		return (NULL);
	i = -1;
	while (*argc > ++i)
		r[i] = ft_atoi(argv[i]);
	i = 0;
	if (is_to_fresh)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	return (r);
}
