#ifndef FT_MD5_H
# define FT_MD5_H

#define CHUNK_LEN_BITS		512
#define CHUNK_LEN_BYTES		CHUNK_LEN_BITS / 8

#define ONE_BIT				(unsigned char)(1 << 7)

#define INIT_DATA_A 		0x67452301
#define INIT_DATA_B 		0xefcdab89
#define INIT_DATA_C 		0x98badcfe
#define INIT_DATA_D 		0x10325476


void		ft_md5(char *message);

uint32_t	F(uint32_t b, uint32_t c, uint32_t d);
uint32_t	G(uint32_t b, uint32_t c, uint32_t d);
uint32_t	H(uint32_t b, uint32_t c, uint32_t d);
uint32_t	I(uint32_t b, uint32_t c, uint32_t d);

void		init_shifts_per_round(uint32_t *shift);
void		init_radians(uint32_t *radians);

// debug
void		print_shift(uint32_t *shift);
void		print_radians(uint32_t *radians);

#endif
