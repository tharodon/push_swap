#include "../push_swap.h"

t_stack	*lnew_el(int count)
{
	t_stack	*el;

	el = (t_stack *)malloc(sizeof(t_stack));
	if (!el)
		return (NULL);
	el->count = count;
	el->back = NULL;
	el->next_order = NULL;
	el->back_order = NULL;
	el->ab = A;
	el->next = NULL;
	el->index = -1;
	el->divs = 0;
	return (el);
}

void	ladd_to_list(t_stack **lst, t_stack *el)
{
	if (!el)
		return ;
	if (!*lst)
	{
		*lst = el;
		return ;
	}
	el->next = *lst;
	(*lst)->back = el;
	*lst = el;
}
