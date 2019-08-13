#include "ft_ssl.h"

void	ft_md5(char *message)
{
	ft_putstr("MD5 (\"");
	ft_putstr(message);
	ft_putstr("\") = ");
	ft_putendl("digest");
}
