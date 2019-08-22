#include "ft_ssl.h"

static void    init_hash_algo(t_cipher_table *algo_table)
{
	if (algo_table[0].name)
		return ; 
	algo_table[0].name = "md5";
	algo_table[0].hash_func = &ft_md5;
}

t_ex_ret		run_hash_algo(char *algo_name, char *str)
{
	static t_cipher_table algo_table[NB_HASH_ALGO];
	uint32_t		i;

	init_hash_algo(algo_table);
	i = 0;
	while (i < NB_HASH_ALGO)
	{
		if (ft_strcmp(algo_name, algo_table[i].name) == 0)
		{
			algo_table[i].hash_func(str);
			return (SUCCESS);
		}
		i++;
	}
	return (ret_error("No mathing algorithm found."));
}
