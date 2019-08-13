#include "ft_ssl.h"

void	usage(char *prog)
{
	ft_putstr("usage: ");
	ft_putstr(prog);
	ft_putendl(" algo");
}

int		main(int ac, char **av)
{
	t_ex_ret	ret;
	int			i;
	
	ret = SUCCESS;
	if (ac <= 1)
		usage(av[0]);
	else
	{
		i = 2;
		while (av[i])
		{
			ft_putendl(av[1]);
			ret = (run_hash_algo(av[1], av[i]) == FAILURE) ? FAILURE : 0;
			i++;
		}
		return (ret);
	}
	return (ret);
}
