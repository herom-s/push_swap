/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:04:31 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 17:32:11 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_in_chunk(int value, int chunk_min, int chunk_max)
{
	return (value >= chunk_min && value <= chunk_max);
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

static int	ft_should_rotate_or_reverse(t_stack *stack, int chunk_min,
		int chunk_max)
{
	t_dlist	*current;
	int		pos;
	int		first_pos;
	int		last_pos;

	current = stack->top;
	pos = 0;
	first_pos = -1;
	last_pos = -1;
	while (current)
	{
		if (ft_is_in_chunk(*(int *)current->content, chunk_min, chunk_max))
		{
			if (first_pos == -1)
				first_pos = pos;
			last_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (first_pos == -1)
		return (0);
	if (first_pos <= (int)stack->size - last_pos - 1)
		return (1);
	return (2);
}

static void	ft_push_and_rotate(t_vars *env, int chunk_min, int chunk_max,
		int chunk_mid)
{
	ft_stack_pb(env->a, env->b);
	if (env->b->size > 1 && ft_stack_peek_top(&env->b) < chunk_mid)
	{
		if (env->a->size >= 2 && ft_has_chunk_value(env->a, chunk_min,
				chunk_max) && ft_should_rotate_or_reverse(env->a,
				chunk_min, chunk_max) == 1)
			ft_stack_rr(&env->b, &env->a);
		else
			ft_stack_rb(&env->b);
	}
}

void	ft_process_chunk(t_vars *env, int chunk_min, int chunk_max)
{
	int	chunk_mid;
	int	direction;

	chunk_mid = chunk_min + (chunk_max - chunk_min) / 2;
	while (ft_has_chunk_value(env->a, chunk_min, chunk_max))
	{
		if (ft_is_in_chunk(ft_stack_peek_top(&env->a), chunk_min, chunk_max))
		{
			ft_push_and_rotate(env, chunk_min, chunk_max, chunk_mid);
		}
		else
		{
			direction = ft_should_rotate_or_reverse(env->a, chunk_min,
					chunk_max);
			if (direction == 1)
				ft_stack_ra(&env->a);
			else
				ft_stack_rra(&env->a);
		}
	}
}
