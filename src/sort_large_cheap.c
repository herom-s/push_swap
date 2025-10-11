/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_cheap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:42:18 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 17:50:47 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_both(t_vars *env, int *b_dist, int *a_dist)
{
	while (*b_dist > 0 && *a_dist > 0)
	{
		ft_stack_rr(&env->a, &env->b);
		(*b_dist)--;
		(*a_dist)--;
	}
}

static void	ft_reverse_both(t_vars *env, int *b_dist, int *a_dist)
{
	while (*b_dist > 0 && *a_dist > 0)
	{
		ft_stack_rrr(&env->a, &env->b);
		(*b_dist)--;
		(*a_dist)--;
	}
}

static void	ft_rotate_b_remaining(t_vars *env, int b_dist, int b_pos)
{
	while (b_dist-- > 0)
	{
		if (b_pos <= (int)env->b->size / 2)
			ft_stack_rb(&env->b);
		else
			ft_stack_rrb(&env->b);
	}
}

static void	ft_rotate_a_remaining(t_vars *env, int a_dist, int a_pos)
{
	while (a_dist-- > 0)
	{
		if (a_pos <= (int)env->a->size / 2)
			ft_stack_ra(&env->a);
		else
			ft_stack_rra(&env->a);
	}
}

void	ft_execute_cheapest_move(t_vars *env, int b_pos)
{
	int	b_val;
	int	a_pos;
	int	b_dist;
	int	a_dist;

	b_val = ft_get_value_at_pos(env->b, b_pos);
	a_pos = ft_find_target_pos_in_a(env->a, b_val);
	if (b_pos <= (int)env->b->size / 2)
		b_dist = b_pos;
	else
		b_dist = (int)env->b->size - b_pos;
	if (a_pos <= (int)env->a->size / 2)
		a_dist = a_pos;
	else
		a_dist = (int)env->a->size - a_pos;
	if (b_pos <= (int)env->b->size / 2 && a_pos <= (int)env->a->size / 2)
		ft_rotate_both(env, &b_dist, &a_dist);
	else if (b_pos > (int)env->b->size / 2 && a_pos > (int)env->a->size / 2)
		ft_reverse_both(env, &b_dist, &a_dist);
	ft_rotate_b_remaining(env, b_dist, b_pos);
	ft_rotate_a_remaining(env, a_dist, a_pos);
	ft_stack_pa(env->a, env->b);
}
