#include "../push_swap.h"

static int	help_magic_algorithm (t_stack **a, t_stack **b, t_stack *mid)
{
	if (llen(mid, mid->divs) == 2)
	{
		sort_two_for_a(a);
		return (1);
	}
	if ((*a)->ab && llen(mid, mid->divs) == 3)
		if (sort_three_for_a(a, b))
			return (1);
	return (0);
}

void	magic_algorithm(t_stack **a, t_stack **b)
{
	t_stack		*mid;
	t_stack		*el;
	int			olddivs;
	static int	divs;

	mid = ul_getmid_elcnt(*a, ul_getmax_div(*a)->divs);
	if (help_magic_algorithm(a, b, mid))
		return ;
	olddivs = mid->divs;
	el = ul_finder_of_mid_updown(*a, mid);
	divs++;
	while (el && el->divs == olddivs)
	{
		ul_come_to_me(a, el);
		(*a)->divs = divs;
		list_pp(a, b, 1);
		el = ul_finder_of_mid_updown(*a, mid);
	}
}

t_stack	*ul_get_last(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	complete_short_sort (t_stack **a, t_stack *el_max_div, int cnt_divs)
{
	if (cnt_divs == 1)
		el_max_div->divs = -1;
	else if (cnt_divs == 2)
	{
		el_max_div->divs = -1;
		el_max_div->next->divs = -1;
		if (el_max_div->next != el_max_div->next_order)
			list_sasb(a, 1);
	}
	else if (cnt_divs == 3)
		sort_three(a);
}

void	to_complete_short_sort_by_max_div(t_stack **a)
{
	t_stack	*el_max_div;
	t_stack	*beginer;
	int		cnt_divs;

	cnt_divs = 0;
	beginer = *a;
	while (beginer->back)
		beginer = beginer->back;
	el_max_div = ul_getmax_div(*a);
	if (el_max_div)
	{
		while (beginer)
		{
			if (beginer->divs == el_max_div->divs)
				cnt_divs++;
			beginer = beginer->next;
		}
	}
	ul_come_to_me(a, el_max_div);
	complete_short_sort(a, el_max_div, cnt_divs);
}
