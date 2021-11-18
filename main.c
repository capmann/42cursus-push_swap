/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 02:46:27 by cmarteau          #+#    #+#             */
/*   Updated: 2021/11/03 17:06:06 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parsing_arg(char **ag, int ac, t_arg_list *liste)
{
	int			n;
	t_arg		*new;

	while (--ac > 0)
	{
		n = ft_atoi(ag[ac], liste);
		new = malloc(sizeof(*new));
		if (new == NULL)
			return ;
		new->arg = n;
		new->next = liste->first;
		liste->first = new;
	}
}

t_arg_list	*list_init(void)
{
	t_arg_list	*liste;

	liste = malloc(sizeof(*liste));
	if (liste == NULL)
		exit(0);
	liste->first = NULL;
	return (liste);
}

void	ft_duplicates(t_arg_list *liste, int a, int b)
{
	t_arg	*new;
	int		j;

	j = 0;
	new = liste->first;
	while (new && j != b)
	{
		if (a == new->arg)
			ft_error(2, liste);
		new = new->next;
		j++;
	}
}

int	is_list_sorted(t_arg_list *liste, int ac)
{
	t_arg	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = liste->first;
	while (new)
	{
		ft_duplicates(liste, new->arg, j);
		if (new->next && new->arg < new->next->arg)
			i++;
		new = new->next;
		j++;
	}
	if (ac - 2 == i)
		return (1);
	return (0);
}

int	main(int ac, char **ag)
{
	t_arg_list	*stack_a;
	t_arg_list	*stack_b;
	t_arg_list	*stack_c;

	if (ac <= 2)
		return (0);
	stack_a = list_init();
	ft_parsing_arg(ag, ac, stack_a);
	while (is_list_sorted(stack_a, ac) == 0)
	{
		stack_b = list_init();
		if (ac == 4)
			stack_a = ft_small_list(stack_a);
		else if (ac <= 6)
			stack_a = ft_medium_list(stack_a, stack_b, ac);
		else
		{
			stack_c = ft_hidden_sort(stack_a, ac);
			stack_a = ft_big_list(stack_a, stack_b, stack_c, ac);
		}
		ft_free_list(stack_b);
	}
	ft_free_list(stack_a);
	return (0);
}
