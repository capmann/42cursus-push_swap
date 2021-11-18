#include "push_swap.h"

t_arg_list	*ft_insertion_sort(t_arg_list *sa, t_arg_list *b, int ac, int f)
{
	int	i;

	i = ac;
	while (--i > 0)
	{
		while (sa->first->arg != ft_find_min(sa->first))
			ft_rotate(sa, f, 'a');
		ft_push_b(sa, b, f);
	}
	while (--ac > 0)
		ft_push_a(sa, b, f);
	return (sa);
}

t_arg_list	*ft_small_list(t_arg_list *stack_a)
{
	t_arg	 *new;

	new = stack_a->first;
	if (new->arg == ft_find_min(new))
	{
		stack_a = ft_swap(stack_a);
		stack_a = ft_rotate(stack_a, 1, 'a');
	}
	else if (new->arg == ft_find_max(new))
	{
		if (new->next && new->next->arg == ft_find_min(new))
			stack_a = ft_rotate(stack_a, 1, 'a');
		else
		{
			stack_a = ft_swap(stack_a);
			stack_a = ft_reverse_rotate(stack_a, 'a');
		}
	}
	else if (new->next && new->next->arg == ft_find_max(new))
		stack_a = ft_reverse_rotate(stack_a, 'a');
	else
		stack_a = ft_swap(stack_a);
	return (stack_a);
}

t_arg_list	*ft_medium_list(t_arg_list *stack_a, t_arg_list *stack_b, int ac)
{
	t_arg	*new;
	int		i;

	i = ac;
	stack_a = ft_prep_med_list(stack_a);
	if (is_list_sorted(stack_a, ac) == 1)
		return (stack_a);
	while (--i > 3)
		ft_push_b(stack_a, stack_b, 1);
	if (is_list_sorted(stack_a, 4) == 0)
		stack_a = ft_small_list(stack_a);
	while (--ac > 3)
	{
		ft_push_a(stack_a, stack_b, 1);
		new = stack_a->first;
		if (new->arg == ft_find_max(new))
			stack_a = ft_rotate(stack_a, 1, 'a');
		else if (new->arg != ft_find_min(new))
			stack_a = ft_swap_until_sorted(stack_a, ac);
	}
	return (stack_a);
}

t_arg_list	*ft_swap_until_sorted(t_arg_list *stack_a, int ac)
{
	stack_a = ft_swap(stack_a);
	if (is_list_sorted(stack_a, 5) == 0)
	{
		stack_a = ft_rotate(stack_a, 1, 'a');
		stack_a = ft_swap(stack_a);
		stack_a = ft_reverse_rotate(stack_a, 'a');
	}
	if (ac == 6 && is_list_sorted(stack_a, ac) == 0)
	{
		stack_a = ft_rotate(stack_a, 1, 'a');
		stack_a = ft_rotate(stack_a, 1, 'a');
		stack_a = ft_swap(stack_a);
		stack_a = ft_reverse_rotate(stack_a, 'a');
		stack_a = ft_reverse_rotate(stack_a, 'a');
	}
	return (stack_a);
}

t_arg_list	*ft_prep_med_list(t_arg_list *stack_a)
{
	t_arg	*new;
	int		k;
	int		min;

	new = stack_a->first;
	min = ft_find_min(new);
	k = 0;
	while (new && new->arg != min)
	{
		new = new->next;
		k++;
	}
	while (stack_a->first->arg != min)
	{
		if (k <= 2)
			stack_a = ft_rotate(stack_a, 1, 'a');
		else
			stack_a = ft_reverse_rotate(stack_a, 'a');
	}
	return (stack_a);
}
