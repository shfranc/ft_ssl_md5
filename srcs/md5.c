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
	uint32_t		radians[64];
	// uint32_t		a;
	// uint32_t		b;
	// uint32_t		c;
	// uint32_t		d;

	init_shifts_per_round(shift);
	print_shift(shift);

	init_radians(radians);
	print_radians(radians);

	md5_output(message);
}
