#include "ft_ssl.h"

void	usage(char *prog)
{
	ft_putstr("usage: ");
	ft_putstr(prog);
	ft_putendl(" algo");
}

int		main(int ac, char **av)
{
	if (ac <= 1)
		usage(av[0]);
	else
		ft_putendl(av[1]);
	return (0);
}
