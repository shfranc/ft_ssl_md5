#include "ft_ssl.h"

static void md5_output(char *digest)
{
	ft_putstr("MD5 (\"");
	ft_putstr(digest);
	ft_putstr("\") = ");
	ft_putendl("digest");
}

void	ft_md5(char *message)
{
	uint32_t		shift[64];
	// uint32_t		K[64];
	// uint32_t		a;
	// uint32_t		b;
	// uint32_t		c;
	// uint32_t		d;

	init_shifts_per_round(shift);

	int i = 0;
	while (i < 64)
	{
		ft_putnbr(shift[i]);
		ft_putchar(' ');
		if (i && (i % 16) == 15)
			ft_putchar('\n');
		i++;
	}

	md5_output(message);
}
