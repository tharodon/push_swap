#include "../push_swap.h"

static int	check_list_init (t_stack **list_a, int *stack, int args)
{
	int	argc;

	argc = args;
	if (!check_duplicate(stack, args))
		return (0);
	while (argc--)
		ladd_to_list(list_a, lnew_el(stack[argc]));
	return (1);
}

static int	recording_stack (int argc, char **argv, int **stack)
{
	if (argc == 2)
	{
		*stack = pars_argc(ft_split(*++argv, ' '), &argc, 1);
		if (*stack == NULL)
			return (0);
	}
	else
		*stack = pars_argc((char **)++argv, &argc, 0);
	return (argc);
}

static void	comands_and_checksort(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		run_commands(line, a, b);
		free(line);
	}
	run_commands(line, a, b);
	free(line);
	if (!check_to_sort(a))
		write (1, "KO\n", 3);
	else
		write (1, "OK\n", 3);
}

int	main (int argc, const char **argv)
{
	t_stack	*a;
	t_stack	*b;
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
	if (!check_list_init(&a, stack, args))
	{
		free(stack);
		return (0);
	}
	comands_and_checksort(&a, &b);
	return (0);
}
