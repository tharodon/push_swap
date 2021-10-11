#include "../push_swap.h"

void	run_commands(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("sa", line, 2) == 0)
		list_sasb(a, 0);
	else if (ft_strncmp("sb", line, 2) == 0)
		list_sasb(b, 0);
	else if (ft_strncmp("ra", line, 2) == 0)
		list_rarb(a, 0);
	else if (ft_strncmp("rb", line, 2) == 0)
		list_rarb(b, 0);
	else if (ft_strncmp("pa", line, 2) == 0)
		list_pp(b, a, 0);
	else if (ft_strncmp("pb", line, 2) == 0)
		list_pp(a, b, 0);
	else if (ft_strncmp("ss", line, 2) == 0)
		list_ss(a, b, 0);
	else if (ft_strncmp("rra", line, 3) == 0)
		list_rrab(a, 0);
	else if (ft_strncmp("rrb", line, 3) == 0)
		list_rrab(b, 0);
	else if (ft_strncmp("rr", line, 2) == 0)
		list_rr(a, b, 0);
	else if (ft_strncmp("rrr", line, 3) == 0)
		list_rrr(a, b, 0);
}
