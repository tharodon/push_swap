#include "../push_swap.h"

void	list_rrr(t_stack **list_a, t_stack **list_b, _Bool flag)
{
	list_rrab(list_a, 0);
	list_rrab(list_b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}

void	list_rr(t_stack **list_a, t_stack **list_b, _Bool flag)
{
	list_rarb(list_a, 0);
	list_rarb(list_b, 0);
	if (flag)
		write(1, "rr\n", 3);
}

void	list_rrab(t_stack **lst, _Bool flag)
{
	t_stack	*tmp;

	if (!(*lst) || (!(*lst)->back && !(*lst)->next))
		return ;
	if ((*lst)->ab && flag)
		write(1, "rra\n", 4);
	if (!(*lst)->ab && flag)
		write(1, "rrb\n", 4);
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	tmp = *lst;
	(*lst) = (*lst)->back;
	(*lst)->next = NULL;
	tmp->back = NULL;
	while (*lst && (*lst)->back)
		*lst = (*lst)->back;
	tmp->next = *lst;
	(*lst) = ((*lst)->back = tmp);
}
