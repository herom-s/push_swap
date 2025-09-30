/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:56:24 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/30 16:56:48 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_vars	*ft_create_env(int *int_numbers, int int_numbers_size)
{
	t_vars	*env;
	int		*num;
	int		i;

	i = 0;
	env = ft_calloc(1, sizeof(t_vars));
	env->a = ft_stack_create();
	while (i < int_numbers_size)
	{
		num = ft_calloc(1, sizeof(int));
		if (!num)
		{
			free(int_numbers);
			return (NULL);
		}
		*num = int_numbers[i];
		ft_stack_add_bot(&env->a, num);
		i++;
	}
	env->b = ft_stack_create();
	free(int_numbers);
	return (env);
}

void	ft_destroy_env(t_vars *env)
{
	if (env->a)
		ft_stack_destroy(&env->a);
	if (env->b)
		ft_stack_destroy(&env->b);
	free(env);
}
