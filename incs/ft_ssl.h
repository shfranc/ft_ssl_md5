#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"
# include <math.h>

# define	NB_HASH_ALGO		1

typedef void (func_algo)(char *);

typedef struct  s_cipher_table
{
	char		*name;
	func_algo	*hash_func;
}				t_cipher_table;

/*
** ALGO
*/
t_ex_ret	run_hash_algo(char *algo_name, char *str);

/*
** UTILS
*/
t_ex_ret	ret_error(char *message);

#endif
