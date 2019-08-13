#include "ft_ssl.h"

uint32_t	F(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & c) | (~b & d));
}

uint32_t	G(uint32_t b, uint32_t c, uint32_t d)
{
	return ((b & d) | (c & ~d));
}

uint32_t	H(uint32_t b, uint32_t c, uint32_t d)
{
	return (b ^ c ^ d);
}

uint32_t	I(uint32_t b, uint32_t c, uint32_t d)
{
	return (c ^ (b | ~d));
}
