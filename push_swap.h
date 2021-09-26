/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:15:31 by cmarteau          #+#    #+#             */
/*   Updated: 2021/09/22 02:56:50 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct	s_arg
{
	int				arg;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_arg_list
{
	t_arg	*first;
}				t_arg_list;

t_arg	*ft_parsing_arg(char **ag, int ac);

#endif
