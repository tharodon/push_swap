#include "push_swap.h"

void	sort_three (t_stack **lst_a)
{
	int	a;
	int	b;
	int	c;

	while ((*lst_a)->back)
		*lst_a = (*lst_a)->back;
	a = (*lst_a)->count;
	b = (*lst_a)->next->count;
	c = (*lst_a)->next->next->count;
	if (a < b && b > c && c > a)
	{
		list_sasb(lst_a, 1);
		list_rarb(lst_a, 1);
	}
	if (a > b && a > c && b > c)
	{
		list_rarb(lst_a, 1);
		list_sasb(lst_a, 1);
	}
	if (a > b && a < c && b < c)
		list_sasb(lst_a, 1);
	if (a < b && a > c && c < b)
		list_rrab(lst_a, 1);
	if (a > b && a > c && b < c)
		list_rarb(lst_a, 1);
}

static void	sort_five_help (t_stack **lst_a, t_stack **lst_b, int a, int b)
{
	if (b == 0 || a == 0)
		list_pp(lst_a, lst_b, 1);
	else if (b == 4 || a == 4)
	{
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
	else if (b == 1 || a == 1)
	{
		list_rarb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
	else if (b == 2 || a == 2)
	{
		list_rarb(lst_a, 1);
		list_rarb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
	else if (b == 3 || a == 3)
	{
		list_rrab(lst_a, 1);
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
}

void	sort_five (t_stack **lst_a, t_stack **lst_b)
{
	int		a;
	int		b;
	t_stack	*tmp;

	linit(*lst_a);
	tmp = get_maxmin_count_el(*lst_a, ALL, MAX);
	a = get_current_index(tmp);
	b = get_current_index(tmp->back_order);
	sort_five_help(lst_a, lst_b, a, b);
	if (tmp->ab)
		b = get_current_index(tmp);
	else
		b = get_current_index(tmp->back_order);
	utils_five_sort(lst_a, lst_b, b);
	sort_three(lst_a);
	while ((*lst_b)->back)
		*lst_b = (*lst_b)->back;
	a = (*lst_b)->count;
	b = (*lst_b)->next->count;
	if (a > b)
		list_sasb(lst_b, 1);
	utils_five_sort_two(lst_a, lst_b);
}

void	sort_three_for_b (t_stack **lst_a, t_stack **lst_b)
{
	t_num	num;

	while ((*lst_a)->back)
		*lst_a = (*lst_a)->back;
	num.first = (*lst_a)->count;
	num.second = (*lst_a)->next->count;
	num.third = (*lst_a)->next->next->count;
	if (num.first > num.second && num.second < num.third && \
	num.third < num.first)
	{
		list_pp(lst_a, lst_b, 1);
		list_sasb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
	if (num.first < num.second && num.second > num.third && \
	num.third < num.first)
	{
		list_sasb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
	ut_s_three(lst_a, lst_b, num);
}

int	sort_three_for_a (t_stack **a, t_stack **b)
{
	t_num	num;

	while ((*a)->back)
		*a = (*a)->back;
	num.first = (*a)->count;
	num.second = (*a)->next->count;
	num.third = (*a)->next->next->count;
	if (num.first > num.second && num.second < num.third && \
	num.third > num.first)
	{
		list_sasb(a, 1);
		return (1);
	}
	if (num.first > num.second && num.second < num.third && \
	num.third < num.first)
	{
		list_sasb(a, 1);
		list_rarb(a, 1);
		list_sasb(a, 1);
		list_rrab(a, 1);
		return (1);
	}
	return (utils_sort_three_for_a(a, b, num));
}
