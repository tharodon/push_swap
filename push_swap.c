#include "push_swap.h"

static int	check_spaces (char **s)
{
	int	i;

	i = 0;
	while (s[1][i])
	{
		if (s[1][i] != ' ')
			return (0);
		i++;
	}
	write (1, "Error\n", 6);
	return (1);
}

static int	recording_stack (int argc, char **argv, int **stack)
{
	if (argc == 2)
	{
		if (check_spaces(argv))
			return (0);
		*stack = pars_argc(ft_split(*++argv, ' '), &argc, 1);
		if (*stack == NULL)
			return (0);
	}
	else
		*stack = pars_argc((char **)++argv, &argc, 0);
	return (argc);
}

int	main(int argc, char const **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		*stack;
	int		args;

	if (!push_swap_validate(argc, (char **)argv))
		return (0);
	args = recording_stack(argc, (char **)argv, &stack);
	if (!args)
	{
		free(stack);
		return (0);
	}
	if (!push_swap_check(&list_a, &list_b, stack, args))
	{
		free(stack);
		return (0);
	}
	linit(list_a);
	algorithm(&list_a, &list_b);
	free(stack);
	return (0);
}
