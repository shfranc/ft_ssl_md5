#include "ft_ssl.h"

void	print_shift(uint32_t *shift)
{
	uint32_t	i;
	
	i = 0;
	while (i < 64)
	{
		ft_putnbr(shift[i]);
		ft_putchar(' ');
		if (i && (i % 4) == 3)
			ft_putchar('\t');
		if (i && (i % 16) == 15)
			ft_putchar('\n');
		i++;
	}
}

void	print_radians(uint32_t *radians)
{
	uint32_t	i;
	
	i = 0;
	while (i < 64)
	{
		ft_putstr("0x");
		ft_puthexa_uint32(radians[i]);
		ft_putchar(' ');
		if (i && (i % 4) == 3)
			ft_putchar('\n');
		i++;
	}
}
