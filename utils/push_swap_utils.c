#include "../push_swap.h"

static int	ul_push_swap_check (t_stack **list_a, t_stack **list_b, int args)
{
	if (check_to_sort(list_a))
		return (1);
	if (args == 2)
	{
		sort_two(list_a);
		return (1);
	}
	if (args == 3)
	{
		sort_three(list_a);
		return (1);
	}
	if (args == 5)
	{
		sort_five(list_a, list_b);
		return (1);
	}
	return (0);
}

int	push_swap_check (t_stack **list_a, t_stack **list_b, int *stack, int args)
{
	int	argc;

	argc = args;
	if (!check_duplicate(stack, args))
		return (0);
	while (argc--)
		ladd_to_list(list_a, lnew_el(stack[argc]));
	if (ul_push_swap_check(list_a, list_b, args))
		return (0);
	return (1);
}

int	push_swap_validate (int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	if (!check_of_valid(argv))
		return (0);
	return (1);
}

int	count_tab_chars(char **tabs)
{
	int	i;

	i = 0;
	while (*tabs++)
		i++;
	return (i);
}
