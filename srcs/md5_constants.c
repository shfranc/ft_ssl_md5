#include "ft_ssl.h"

static void	fill_shifts(uint32_t *shift, uint32_t i, const uint32_t sample[4])
{
	shift[i] = sample[0];
	shift[i + 1] = sample[1];
	shift[i + 2] = sample[2];
	shift[i + 3] = sample[3];
}

void	init_shifts_per_round(uint32_t *shift)
{
	uint32_t	i;
	const uint32_t	sample1[4] = {7, 12, 17, 22};
	const uint32_t	sample2[4] = {5, 9, 14, 20};
	const uint32_t	sample3[4] = {4, 11, 16, 23};
	const uint32_t	sample4[4] = {6, 10, 15, 21};
	

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			fill_shifts(shift, i, sample1);
		else if (i < 32)
			fill_shifts(shift, i, sample2);
		else if (i < 48)
			fill_shifts(shift, i, sample3);
		else if (i < 64)
			fill_shifts(shift, i, sample4);
		i += 4;
	}
	
}

void	init_radians(uint32_t *radians)
{

	uint32_t	i;
	uint64_t	p;

	p = 0x100000000;
	i = 0;
	while (i < 64)
	{
		radians[i] = floor(p * fabs(sin(i + 1)));
		i++;
	}
}
