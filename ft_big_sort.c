#include "push_swap.h"

t_arg_list	*ft_hidden_sort(t_arg_list *stack_a, int ac)
{
	t_arg_list	*stack_c;
	t_arg_list	*stack_d;
	t_arg		*new_a;
	t_arg		*new_c;
	int			i;

	i = ac;
	new_a = stack_a->first;
	stack_c = list_init();
	stack_d = list_init();
	new_c = stack_c->first;
	while (--i > 0)
	{
		new_c = malloc(sizeof(*new_c));
		if (new_c == NULL)
			exit(0);
		new_c->arg = new_a->arg;
		new_c->next = stack_c->first;
		stack_c->first = new_c;
		new_a = new_a->next;
	}
	stack_c = ft_insertion_sort(stack_c, stack_d, ac, 0);
	ft_free_list(stack_d);
	return (stack_c);
}

t_arg_list	*ft_prep_sort(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int a)
{
	t_arg_list	*reverse_a;
	int			i;
	int			j;
	int			median;

	i = ft_parse_list(sa, c, a);
	reverse_a = ft_reverse(sa);
	j = ft_parse_list(reverse_a, c, a);
	median = ft_find_median(c);
	if (i > j)
	{
		while (j-- > -1)
			ft_reverse_rotate(sa, 'a');
	}
	else
	{
		while (i-- > 0)
			ft_rotate(sa, 1, 'a');
	}
	ft_push_b(sa, b, 1);
	if (b->first->next && b->first->arg <= median)
		ft_rotate(b, 1, 'b');
	ft_free_list(reverse_a);
	return (sa);
}

int	ft_parse_list(t_arg_list *stack_a, t_arg_list *stack_c, int a)
{
	t_arg		*new_a;
	t_arg		*new_c;
	int			i;
	int			min;
	int			b;

	b = ft_count_list(stack_c) - 1;
	new_c = stack_c->first;
	i = -1;
	while (new_c && new_c->next && ++i < a)
		new_c = new_c->next;
	min = new_c->arg;
	while (new_c && new_c->next && i++ < a + b)
		new_c = new_c->next;
	new_a = stack_a->first;
	i = ft_find_pos(new_a, new_c, min);
	return (i);
}

int	ft_find_pos(t_arg *new_a, t_arg *new_c, int min)
{
	int	i;

	i = 0;
	while (new_a && new_a->next)
	{
		if (new_a->arg >= min && new_a->arg <= new_c->arg)
			break ;
		new_a = new_a->next;
		i++;
	}
	return (i);
}

t_arg_list	*ft_final_sort(t_arg_list *stack_a, t_arg_list *stack_b)
{
	t_arg_list	*reverse;
	t_arg		*new;
	t_arg		*ne;
	int			j;
	int			i;

	new = stack_b->first;
	j = 0;
	i = 0;
	while (new && new->next && new->arg != ft_find_max(new))
	{
		new = new->next;
		i++;
	}
	reverse = ft_reverse(stack_b);
	ne = reverse->first;
	while (ne && ne->next && ne->arg != ft_find_max(ne))
	{
		ne = ne->next;
		j++;
	}
	stack_b = ft_nb_moves(i, j, stack_b);
	ft_push_a(stack_a, stack_b, 1);
	ft_free_list(reverse);
	return (stack_a);
}
