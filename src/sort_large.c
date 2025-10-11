/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:49:33 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 15:10:29 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunks_to_b(t_vars *env)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	gap;

	gap = ft_stack_get_max(env->a) - ft_stack_get_min(env->a);
	chunk_min = ft_stack_get_min(env->a);
	if (gap <= 100)
		chunk_size = gap / 3;
	else
		chunk_size = gap / 11;
	while (env->a->size > 0)
	{
		chunk_max = chunk_min + chunk_size;
		if (chunk_max > ft_stack_get_max(env->a))
			chunk_max = ft_stack_get_max(env->a);
		ft_process_chunk(env, chunk_min, chunk_max);
		chunk_min = chunk_max + 1;
	}
}

void	ft_push_back_to_a(t_vars *env)
{
	int	max_b;
	int	top;

	while (env->b->size > 0)
	{
		max_b = ft_stack_get_max(env->b);
		top = ft_stack_peek_top(&env->b);
		if (top == max_b)
		{
			ft_stack_pa(env->a, env->b);
		}
		else
		{
			if (ft_stack_get_val_pos(env->b,
					ft_stack_get_max(env->b)) <= (int)env->b->size / 2)
				ft_stack_rb(&env->b);
			else
				ft_stack_rrb(&env->b);
		}
	}
}
