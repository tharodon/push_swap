#include "../push_swap.h"

static void	back_to_begin (t_stack **lst)
{
	while ((*lst)->back)
		*lst = (*lst)->back;
}

void	list_sasb(t_stack **lst, _Bool flag)
{
	t_stack	*two;
	t_stack	*one;

	if (!*lst)
		return ;
	while ((*lst)->back != NULL)
		(*lst) = (*lst)->back;
	if (!*lst || !(*lst)->next)
		return ;
	two = (*lst)->next;
	one = (*lst);
	*lst = (*lst)->next->next;
	two->next = one;
	two->back = NULL;
	one->back = two;
	one->next = (*lst);
	if (*lst)
		(*lst)->back = one;
	(*lst) = two;
	if ((*lst)->ab && flag)
		write(1, "sa\n", 3);
	if (!(*lst)->ab && flag)
		write(1, "sb\n", 3);
}

void	list_rarb(t_stack **ab, _Bool flag)
{
	t_stack	*tmp;
	t_stack	*end;

	if (!*ab || !(*ab)->next)
		return ;
	while ((*ab)->next)
		*ab = (*ab)->next;
	end = *ab;
	while ((*ab)->back)
		*ab = (*ab)->back;
	tmp = *ab;
	if ((*ab)->next)
		(*ab) = (*ab)->next;
	(*ab)->back = NULL;
	if (end == tmp)
		return ;
	end->next = tmp;
	tmp->back = end;
	tmp->next = NULL;
	if ((*ab)->ab && flag)
		write(1, "ra\n", 3);
	if (!(*ab)->ab && flag)
		write(1, "rb\n", 3);
}

void	list_pp(t_stack **a, t_stack **b, _Bool flag)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	if ((*a)->ab && flag)
		write(1, "pb\n", 3);
	if (!(*a)->ab && flag)
		write(1, "pa\n", 3);
	back_to_begin(a);
	while (*b && (*b)->back)
		*b = (*b)->back;
	tmp = *a;
	if (tmp->ab == A)
		tmp->ab = B;
	else
		tmp->ab = A;
	*a = (*a)->next;
	if (*a)
		(*a)->back = NULL;
	tmp->next = *b;
	if (*b)
		tmp->back = NULL;
	if (*b)
		(*b)->back = tmp;
	*b = tmp;
}

void	list_ss(t_stack **list_a, t_stack **list_b, _Bool flag)
{
	list_sasb(list_a, 0);
	list_sasb(list_b, 0);
	if (flag)
		write(1, "ss\n", 3);
}
