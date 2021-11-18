/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarteau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 00:15:31 by cmarteau          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:29 by cmarteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_arg
{
	int				arg;
	struct s_arg	*next;
}				t_arg;

typedef struct s_arg_list
{
	t_arg	*first;
}				t_arg_list;

void		ft_parsing_arg(char **ag, int ac, t_arg_list *liste);
void		ft_error(int a, t_arg_list *liste);
void		ft_duplicates(t_arg_list *liste, int a, int b);
void		ft_free_list(t_arg_list *liste);
void		ft_push_a(t_arg_list *stack_a, t_arg_list *stack_b, int f);
void		ft_push_b(t_arg_list *stack_a, t_arg_list *stack_b, int f);
void		ft_printr(int flag, int f, char c);

int			is_list_sorted(t_arg_list *liste, int ac);
int			ft_find_min(t_arg *new);
int			ft_find_max(t_arg *new);
int			ft_find_median(t_arg_list *stack_c);
int			ft_parse_list(t_arg_list *stack_a, t_arg_list *stack_c, int a);
int			ft_count_list(t_arg_list *stack_a);
int			ft_atoi(const char *str, t_arg_list *liste);
int			ft_find_pos(t_arg *new_a, t_arg *new_c, int min);
int			ft_root(int a);

t_arg_list	*list_init(void);
t_arg_list	*ft_swap(t_arg_list *liste);
t_arg_list	*ft_rotate(t_arg_list *liste, int f, char c);
t_arg_list	*ft_reverse_rotate(t_arg_list *liste, char c);
t_arg_list	*ft_insertion_sort(t_arg_list *sa, t_arg_list *b, int ac, int f);
t_arg_list	*ft_small_list(t_arg_list *stack_a);
t_arg_list	*ft_medium_list(t_arg_list *stack_a, t_arg_list *stack_b, int ac);
t_arg_list	*ft_swap_until_sorted(t_arg_list *stack_a, int ac);
t_arg_list	*ft_hidden_sort(t_arg_list *stack_a, int ac);
t_arg_list	*ft_prep_sort(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int a);
t_arg_list	*ft_reverse(t_arg_list *liste);
t_arg_list	*ft_final_sort(t_arg_list *stack_a, t_arg_list *stack_b);
t_arg_list	*ft_prep_med_list(t_arg_list *stack_a);
t_arg_list	*ft_repeat_100(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int a);
t_arg_list	*ft_repeat_500(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int a);
t_arg_list	*ft_big_list(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int ac);
t_arg_list	*ft_nb_moves(int i, int j, t_arg_list *stack_b);

#endif
