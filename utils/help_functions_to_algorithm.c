#include "../push_swap.h"

t_stack	*ul_getmid_elcnt(t_stack *lst, int div)
{
	int	len;

	len = llen(lst, div) / 2;
	lst = get_maxmin_count_el(lst, div, MIN);
	while (len--)
		lst = get_up_neighbour(lst, div);
	return (lst);
}

t_stack	*ul_getmax_div(t_stack *lst)
{
	t_stack	*el_with_max_div;

	el_with_max_div = lst;
	while (lst->back)
		lst = lst->back;
	while (lst)
	{
		if (lst->divs > el_with_max_div->divs)
			el_with_max_div = lst;
		lst = lst->next;
	}
	return (el_with_max_div);
}

t_stack	*ul_getmin_div(t_stack *lst)
{
	t_stack	*el_with_max_div;

	el_with_max_div = lst;
	while (lst->back)
		lst = lst->back;
	while (lst)
	{
		if (lst->divs < el_with_max_div->divs)
			el_with_max_div = lst;
		lst = lst->next;
	}
	return (el_with_max_div);
}

static t_stack	*return_mid_updown (t_stack *lst, t_stack *mid, \
t_stack *start, t_stack *end)
{
	int	len;

	len = (llen(lst, ALL) / 2) + 1;
	while (len--)
	{
		if (lst->ab && start->count <= mid->count && start->divs == lst->divs)
			return (start);
		if (lst->ab && end->count <= mid->count && end->divs == lst->divs)
			return (end);
		if (!lst->ab && start->count >= mid->count && start->divs == lst->divs)
			return (start);
		if (!lst->ab && end->count >= mid->count && end->divs == lst->divs)
			return (end);
		start = start->next;
		end = end->back;
	}
	return (NULL);
}

t_stack	*ul_finder_of_mid_updown(t_stack *lst, t_stack *mid)
{
	t_stack	*start;
	t_stack	*end;

	if (!lst)
		return (NULL);
	while (lst->back)
		lst = lst->back;
	start = lst;
	end = start;
	while (end->next)
		end = end->next;
	return (return_mid_updown(lst, mid, start, end));
}
