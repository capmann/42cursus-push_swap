#include "push_swap.h"

t_arg_list	*ft_big_list(t_arg_list *sa, t_arg_list *b, t_arg_list *c, int ac)
{
	int	i;
	int	chunks;
	int	inc;
	int	k;
	int	limits;

	i = 0;
	ac -= 1;
	chunks = ft_root(ac) / 2;
	inc = ac / chunks;
	limits = 0;
	while (i++ < chunks)
	{
		k = 0;
		while (k++ < inc)
			sa = ft_prep_sort(sa, b, c, limits);
		limits += inc;
	}
	while (limits++ < ac)
		ft_push_b(sa, b, 1);
	ft_free_list(c);
	while (ac-- > 0)
		sa = ft_final_sort(sa, b);
	return (sa);
}

t_arg_list	*ft_nb_moves(int i, int j, t_arg_list *stack_b)
{
	if (i > j)
	{
		while (j-- > -1)
			ft_reverse_rotate(stack_b, 'b');
	}
	else
	{
		while (i-- > 0)
			ft_rotate(stack_b, 1, 'b');
	}
	return (stack_b);
}

void	ft_printr(int flag, int f, char c)
{
	if (flag > 0 && f == 1 && c == 'a')
		write(1, "ra\n", 3);
	if (flag > 0 && f == 1 && c == 'b')
		write(1, "rb\n", 3);
}
