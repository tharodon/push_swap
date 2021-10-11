#include "push_swap.h"

static void	s_thr_b (t_stack **lst_a, t_stack **lst_b, t_num num)
{
	if (num.first < num.second && num.second > num.third && \
	num.third > num.first)
	{
		list_rarb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
	if (num.first > num.second && num.second > num.third && \
	num.third < num.first)
	{
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
}

int	utils_sort_three_for_a (t_stack **a, t_stack **b, t_num num)
{
	if (num.first < num.second && num.second > num.third && \
	num.third < num.first)
	{
		list_rarb(a, 1);
		list_sasb(a, 1);
		list_pp(a, b, 1);
		list_rrab(a, 1);
		list_pp(b, a, 1);
		return (1);
	}
	if (num.first < num.second && num.second > num.third && \
	num.third > num.first)
	{
		list_rarb(a, 1);
		list_sasb(a, 1);
		list_rrab(a, 1);
		return (1);
	}
	return (0);
}

void	ut_s_three (t_stack **lst_a, t_stack **lst_b, t_num num)
{
	if (num.first > num.second && num.first < num.third && \
	num.second < num.third)
	{
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
	if (num.first < num.second && num.second < num.third && \
	num.third > num.first)
	{
		list_sasb(lst_a, 1);
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
		list_pp(lst_a, lst_b, 1);
	}
	s_thr_b(lst_a, lst_b, num);
}

void	utils_five_sort (t_stack **lst_a, t_stack **lst_b, int b)
{
	if (b == 0)
		list_pp(lst_a, lst_b, 1);
	if (b == 1)
	{
		list_rarb(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
	if (b == 2)
	{
		list_rrab(lst_a, 1);
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
	if (b == 3)
	{
		list_rrab(lst_a, 1);
		list_pp(lst_a, lst_b, 1);
	}
}

void	utils_five_sort_two (t_stack **lst_a, t_stack **lst_b)
{
	int	a;

	a = 2;
	while (a--)
	{
		list_pp(lst_b, lst_a, 1);
		list_rarb(lst_a, 1);
	}
}
