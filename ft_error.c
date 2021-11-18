#include "push_swap.h"

void	ft_error(int a, t_arg_list *liste)
{
	if (a == 1 )
		write(1, "Error\n", 6);
	if (a == 2)
		write(1, "Error\n", 6);
	if (a == 3)
		write(1, "Error\n", 6);
	ft_free_list(liste);
	exit(0);
}

int	ft_count_list(t_arg_list *liste)
{
	t_arg	*new;
	int		i;
	int		b;
	int		c;

	i = 0;
	new = liste->first;
	while (new)
	{
		i++;
		new = new->next;
	}
	b = ft_root(i) / 2;
	c = i / b;
	return (c);
}

int	ft_root(int a)
{
	int	an;
	int	an1;
	int	i;

	an = a;
	i = 0;
	while (i++ < 8)
	{
		an1 = (an + (a / an)) / 2;
		an = an1;
	}
	return (an1);
}
