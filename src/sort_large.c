/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:49:33 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 17:52:28 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_chunks_to_b(t_vars *env)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	num_chunks;

	chunk_min = ft_stack_get_min(env->a);
	if (env->a->size <= 16)
		num_chunks = 1;
	else if (env->a->size <= 100)
		num_chunks = 3;
	else if (env->a->size <= 200)
		num_chunks = 5;
	else
		num_chunks = 9;
	chunk_size = (ft_stack_get_max(env->a) - chunk_min) / num_chunks;
	if (chunk_size < 1)
		chunk_size = 1;
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
	int	cheapest_pos;
	int	max_b;

	if (env->b->size > 0)
	{
		max_b = ft_stack_get_max(env->b);
		if (ft_stack_get_val_pos(env->b, max_b) <= (int)env->b->size / 2)
		{
			while (ft_stack_peek_top(&env->b) != max_b)
				ft_stack_rb(&env->b);
		}
		else
		{
			while (ft_stack_peek_top(&env->b) != max_b)
				ft_stack_rrb(&env->b);
		}
		ft_stack_pa(env->a, env->b);
	}
	while (env->b->size > 0)
	{
		cheapest_pos = ft_find_cheapest_pos(env);
		ft_execute_cheapest_move(env, cheapest_pos);
	}
	ft_rotate_value_to_top(env->a, STACK_A, ft_stack_get_min(env->a));
}
