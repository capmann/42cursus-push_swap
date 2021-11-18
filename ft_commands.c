#include "push_swap.h"

t_arg_list	*ft_swap(t_arg_list *liste)
{
	t_arg	*new;
	int		tmp;

	new = liste->first;
	tmp = new->arg;
	new->arg = new->next->arg;
	new->next->arg = tmp;
	write(1, "sa\n", 3);
	return (liste);
}

t_arg_list	*ft_rotate(t_arg_list *liste, int f, char c)
{
	t_arg	*new;
	int		tmp;
	int		tmp1;
	int		flag;

	new = liste->first;
	flag = 0;
	if (new->next)
	{
		flag++;
		tmp = new->arg;
		new->arg = new->next->arg;
		new->next->arg = tmp;
		liste->first = new;
		new = new->next;
	}
	while (new->next)
	{
		tmp1 = new->arg;
		new->arg = new->next->arg;
		new->next->arg = tmp1;
		new = new->next;
	}
	ft_printr(flag, f, c);
	return (liste);
}

void	ft_push_b(t_arg_list *stack_a, t_arg_list *stack_b, int f)
{
	t_arg	 *new_a;
	t_arg	 *new_b;
	t_arg	 *tmp;

	new_a = stack_a->first;
	tmp = new_a->next;
	new_b = new_a;
	new_b->next = stack_b->first;
	stack_b->first = new_b;
	new_a = tmp;
	stack_a->first = new_a;
	if (f == 1)
		write(1, "pb\n", 3);
}

void	ft_push_a(t_arg_list *stack_a, t_arg_list *stack_b, int f)
{
	t_arg	 *new_a;
	t_arg	 *new_b;
	t_arg	 *tmp;

	new_b = stack_b->first;
	tmp = new_b->next;
	new_a = new_b;
	new_a->next = stack_a->first;
	stack_a->first = new_a;
	new_b = tmp;
	stack_b->first = new_b;
	if (f == 1)
		write(1, "pa\n", 3);
}

t_arg_list	*ft_reverse_rotate(t_arg_list *liste, char c)
{
	t_arg	 *new;
	t_arg	 *tmp;

	new = liste->first;
	tmp = new;
	while (new->next)
		new = new->next;
	liste->first = new;
	new->next = tmp;
	new = new->next;
	while (new->next != liste->first)
		new = new->next;
	new->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return (liste);
}
