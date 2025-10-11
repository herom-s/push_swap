/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:43:50 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/10 20:47:32 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_min_to_top(t_vars *env, t_stack_name name)
{
	t_stack	*stack;

	stack = NULL;
	if (name == STACK_A)
		stack = env->a;
	else if (name == STACK_B)
		stack = env->b;
	if (!stack || stack->size == 0)
		return ;
	ft_rotate_value_to_top(stack, name, ft_stack_get_min(stack));
}

int	ft_sort_two(t_vars *env, t_stack_name name)
{
	if (name == STACK_A)
	{
		if (ft_stack_peek_top(&env->a) > ft_stack_peek_top_next(&env->a))
			ft_stack_sa(env->a);
	}
	else if (name == STACK_B)
	{
		if (ft_stack_peek_top(&env->b) > ft_stack_peek_top_next(&env->b))
			ft_stack_sb(env->b);
	}
	return (1);
}

int	ft_sort_three(t_vars *env, t_stack_name name)
{
	int	max;

	if (name == STACK_A)
	{
		max = ft_stack_get_max(env->a);
		if (ft_stack_peek_top(&env->a) == max)
			ft_stack_ra(&env->a);
		else if (ft_stack_peek_top_next(&env->a) == max)
			ft_stack_rra(&env->a);
		if (ft_stack_peek_top(&env->a) > ft_stack_peek_top_next(&env->a))
			ft_stack_sa(env->a);
	}
	else if (name == STACK_B)
	{
		max = ft_stack_get_max(env->b);
		if (ft_stack_peek_top(&env->b) == max)
			ft_stack_rb(&env->b);
		else if (ft_stack_peek_top_next(&env->b) == max)
			ft_stack_rrb(&env->b);
		if (ft_stack_peek_top(&env->b) > ft_stack_peek_top_next(&env->b))
			ft_stack_sb(env->b);
	}
	return (1);
}

int	ft_sort_four(t_vars *env)
{
	ft_rotate_min_to_top(env, STACK_A);
	ft_stack_pb(env->a, env->b);
	ft_sort_three(env, STACK_A);
	ft_stack_pa(env->a, env->b);
	return (1);
}

int	ft_sort_five(t_vars *env)
{
	ft_rotate_min_to_top(env, STACK_A);
	ft_stack_pb(env->a, env->b);
	ft_rotate_min_to_top(env, STACK_A);
	ft_stack_pb(env->a, env->b);
	if (env->b->size >= 2
		&& ft_stack_peek_top(&env->b) < ft_stack_peek_top_next(&env->b))
		ft_stack_sb(env->b);
	ft_sort_three(env, STACK_A);
	ft_stack_pa(env->a, env->b);
	ft_stack_pa(env->a, env->b);
	return (1);
}
