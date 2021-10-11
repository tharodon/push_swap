#include "../push_swap.h"

t_stack	*get_up_neighbour(t_stack *el, int div)
{
	t_stack	*start;
	t_stack	*tmp;

	start = el;
	tmp = get_maxmin_count_el(el, div, MAX);
	if (tmp == el)
		return (NULL);
	while (start->back)
		start = start->back;
	while (start)
	{
		if (start->divs == div || div == ALL)
			if (start->count < tmp->count && start->count > el->count)
				tmp = start;
		start = start->next;
	}
	return (tmp);
}

int	get_current_index(t_stack *el)
{
	int	i;

	i = 0;
	if (!el)
		return (-1);
	while (el->back)
	{
		el = el->back;
		i++;
	}
	return (i);
}

t_stack	*get_maxmin_count_el(t_stack *lst, int div, _Bool max_or_min)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = lst;
	min = lst;
	while (tmp->back)
		tmp = tmp->back;
	if (div != ALL)
		while (tmp->next && tmp->divs != div)
			tmp = tmp->next;
	while (tmp && (tmp->divs == div || div == ALL))
	{
		if (max_or_min == MAX && min->count < tmp->count)
			min = tmp;
		if (max_or_min == MIN && min->count > tmp->count)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	linit(t_stack *lst)
{
	t_stack	*min;
	t_stack	*max;

	min = get_maxmin_count_el(lst, ALL, MIN);
	max = get_maxmin_count_el(lst, ALL, MAX);
	while (min != max)
	{
		min->next_order = get_up_neighbour(min, ALL);
		if (min->next_order)
			min->next_order->back_order = min;
		min = min->next_order;
	}
}

int	llen(t_stack *lst, int div)
{
	int	i;

	i = 0;
	while (lst->back)
		lst = lst->back;
	while (lst)
	{
		if (lst->divs == div || div == ALL)
			i++;
		lst = lst->next;
	}
	return (i);
}
