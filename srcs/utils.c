#include "ft_ssl.h"

t_ex_ret	ret_error(char *message)
{
	ft_putstr_fd("./ft_ssl_md5: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (FAILURE);
}
