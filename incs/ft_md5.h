#ifndef FT_MD5_H
# define FT_MD5_H

#define INIT_DATA_A (uint32_t)0x67452301
#define INIT_DATA_B (uint32_t)0xefcdab89
#define INIT_DATA_C (uint32_t)0x98badcfe
#define INIT_DATA_D (uint32_t)0x10325476

void		ft_md5(char *message);

uint32_t	F(uint32_t b, uint32_t c, uint32_t d);
uint32_t	G(uint32_t b, uint32_t c, uint32_t d);
uint32_t	H(uint32_t b, uint32_t c, uint32_t d);
uint32_t	I(uint32_t b, uint32_t c, uint32_t d);

#endif
