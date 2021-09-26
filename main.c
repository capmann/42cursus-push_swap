/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 02:46:27 by cmarteau          #+#    #+#             */
/*   Updated: 2021/09/22 03:37:06 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_arg	*ft_parsing_arg(char **ag, int ac)
{
	int			n;
	t_arg		*new;
	t_arg_list	*list;

	new = malloc(sizeof(t_arg) * ac);
	if (!new)
		exit(0);
	new->arg = 0;
	new->next = NULL;
	list->first = NULL;
	while (--ac > 0)
	{
		n = ft_atoi(ag[ac]);
		new->arg = n;
		new->next = list->first;
		list->first = new;
	}
	printf("first=%d\n", list->first->arg);
	printf("next=%d\n", new->next->arg);
	return (new);
}

int	main(int ac, char **ag)
{
	t_arg	*new;

	if (ac <= 1)
		exit(0);
	new = ft_parsing_arg(ag, ac);
/*	while(new->next)
	{
		printf("arg=%d\n", new->arg);
		new = new->next;
	}*/
}
