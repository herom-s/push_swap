/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:04:31 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 15:10:08 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_in_chunk(int value, int chunk_min, int chunk_max)
{
	return (value >= chunk_min && value <= chunk_max);
}

static int	ft_get_chunk_middle(int chunk_min, int chunk_max)
{
	return (chunk_min + (chunk_max - chunk_min) / 2);
}

static int	ft_has_chunk_value(t_stack *stack, int start, int end)
{
	t_dlist	*current;

	current = stack->top;
	while (current)
	{
		if (ft_is_in_chunk(*(int *)current->content, start, end))
			return (1);
		current = current->next;
	}
	return (0);
}

static void	ft_handle_pushed_value(t_vars *env, int c_mid, int c_min, int c_max)
{
	if (env->b->size > 1 && ft_stack_peek_top(&env->b) < c_mid)
	{
		if (env->a->size > 0 && !ft_is_in_chunk(ft_stack_peek_top(&env->a),
				c_min, c_max))
			ft_stack_rr(&env->b, &env->a);
		else
			ft_stack_rb(&env->b);
	}
	else if (env->a->size > 0 && !ft_is_in_chunk(ft_stack_peek_top(&env->a),
			c_min, c_max))
		ft_stack_ra(&env->a);
}

void	ft_process_chunk(t_vars *env, int chunk_min, int chunk_max)
{
	int	chunk_mid;

	chunk_mid = ft_get_chunk_middle(chunk_min, chunk_max);
	while (env->a->size > 0)
	{
		if (ft_is_in_chunk(ft_stack_peek_top(&env->a), chunk_min, chunk_max))
		{
			ft_stack_pb(env->a, env->b);
			ft_handle_pushed_value(env, chunk_mid, chunk_min, chunk_max);
		}
		else
			ft_stack_ra(&env->a);
		if (!ft_is_in_chunk(ft_stack_peek_top(&env->a), chunk_min, chunk_max)
			&& !ft_has_chunk_value(env->a, chunk_min, chunk_max))
			break ;
	}
}
