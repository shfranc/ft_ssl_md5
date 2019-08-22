#include "ft_ssl.h"


void		md5_output(char *digest)
{
	ft_putstr("MD5 (\"");
	ft_putstr(digest);
	ft_putstr("\") = ");
	ft_putendl("digest");
}

void		add_original_len(char *str, uint64_t len, uint64_t original_len)
{
	uint64_t		*original_len_bits;
	uint32_t		start;
	uint32_t		i;

	*original_len_bits = original_len * 8;
	start = len - sizeof(uint64_t);
	i = 0;
	while (i < sizeof(uint64_t))
	{
		str[start + i] = (unsigned char *)original_len_bits[i];
		i++;
	}
}

void		ft_md5(char *message)
{
	char			*padded_message;
	uint64_t		original_len;
	uint64_t		padded_len;
	uint32_t		shift[64];
	uint32_t		radians[64];
	uint32_t		a0;
	uint32_t		b0;
	uint32_t		c0;
	uint32_t		d0;

	// init constants
	init_shifts_per_round(shift);
	// print_shift(shift);
	init_radians(radians);
	// print_radians(radians);
	a0 = INIT_DATA_A;
	b0 = INIT_DATA_B;
	c0 = INIT_DATA_C;
	d0 = INIT_DATA_D;

	// pre-processing
	original_len = (uint64_t)ft_strlen(message);
	padded_len = original_len + 1 + ((original_len + 1) % CHUNK_LEN_BYTES);
	padded_message = ft_strnew(padded_len);
	ft_strcpy(padded_message, message);
	padded_message[original_len] = ONE_BIT;
	add_original_len(padded_message, padded_len, original_len);
	write(1, padded_message, padded_len);
	// md5_output(padded_message);
	free(padded_message);
}
