#include "push_swap.h"

int	ft_find_min(t_arg *new)
{
	int	 min;

	min = new->arg;
	if (new->next)
		new = new->next;
	while (new)
	{
		if (new->arg < min)
			min = new->arg;
		new = new->next;
	}
	return (min);
}

int	ft_find_max(t_arg *new)
{
	int	 max;

	max = new->arg;
	if (new->next)
		new = new->next;
	while (new)
	{
		if (new->arg > max)
			max = new->arg;
		new = new->next;
	}
	return (max);
}

int	ft_find_median(t_arg_list *stack_c)
{
	t_arg	*new;
	int		median;
	int		i;

	new = stack_c->first;
	median = 0;
	i = 0;
	while (new)
	{
		new = new->next;
		i++;
	}
	i = (i / 2) - 1;
	new = stack_c->first;
	while (new && median++ < i)
		new = new->next;
	return (new->arg);
}

void	ft_free_list(t_arg_list *liste)
{
	t_arg	 *tmp;
	t_arg	 *tmp2;

	tmp = liste->first;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	if (liste)
		free(liste);
	liste = NULL;
}

t_arg_list	*ft_reverse(t_arg_list *liste)
{
	t_arg_list	*reverse;
	t_arg		*new;
	t_arg		*rev;

	reverse = list_init();
	new = liste->first;
	rev = reverse->first;
	while (new)
	{
		rev = malloc(sizeof(*rev));
		if (rev == NULL)
			exit(0);
		rev->arg = new->arg;
		rev->next = reverse->first;
		reverse->first = rev;
		new = new->next;
	}
	return (reverse);
}
