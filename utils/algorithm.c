#include "../push_swap.h"
#include <limits.h>

void	ul_come_to_me(t_stack **lst, t_stack *el)
{
	int	len;

	len = llen(*lst, ALL) / 2;
	if (len > get_current_index(el))
		while (*lst != el)
			list_rarb(lst, 1);
	else
		while (*lst != el)
			list_rrab(lst, 1);
}

void	ul_sortig_stack_b (t_stack **b, t_stack **a)
{
	t_stack	*max_el;

	while (*b)
	{
		max_el = get_maxmin_count_el(*b, ALL, MAX);
		ul_come_to_me(b, max_el);
		(*b)->divs = -1;
		list_pp(b, a, 1);
	}
}

static int	fast_sort_b (t_stack **b, t_stack **a)
{
	if (llen(*b, ALL) == 2)
	{
		sort_two_for_b(b, a);
		return (1);
	}
	if (llen(*b, ALL) == 3)
	{
		sort_three_for_b(b, a);
		return (1);
	}
	if (llen(*b, ALL) == 5)
	{
		sort_five(b, a);
		return (1);
	}
	if (llen(*b, ALL) < 30)
	{
		ul_sortig_stack_b(b, a);
		return (1);
	}
	return (0);
}

void	algorithm(t_stack **a, t_stack **b)
{
	magic_algorithm(a, b);
	while (ul_getmax_div(*a)->divs > -1 || *b)
	{
		while (ul_getmin_div(*a)->divs == -1 && ul_get_last(*a)->divs != -1)
			list_rrab(a, 1);
		while (*b)
		{
			if (fast_sort_b(b, a))
				break ;
			magic_algorithm(b, a);
		}
		to_complete_short_sort_by_max_div(a);
		ul_come_to_me(a, ul_getmax_div(*a));
		if (ul_getmax_div(*a)->divs > -1)
			magic_algorithm(a, b);
	}
	ul_come_to_me(a, get_maxmin_count_el(*a, ALL, MIN));
}
