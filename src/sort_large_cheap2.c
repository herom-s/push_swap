/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_cheap2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:48:21 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 17:54:40 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_target_pos_in_a(t_stack *a, int b_val)
{
	t_dlist	*current;
	int		target;
	int		pos;
	int		target_pos;
	int		min_pos;

	min_pos = ft_stack_get_val_pos(a, ft_stack_get_min(a));
	if (b_val < ft_stack_get_min(a) || b_val > ft_stack_get_max(a))
		return (min_pos);
	target = 2147483647;
	target_pos = min_pos;
	current = a->top;
	pos = 0;
	while (current)
	{
		if (*(int *)current->content > b_val
			&& *(int *)current->content < target)
		{
			target = *(int *)current->content;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (target_pos);
}

static int	ft_calculate_cost(t_vars *env, int b_pos)
{
	int	b_val;
	int	a_pos;
	int	cost_a;
	int	cost_b;

	b_val = ft_get_value_at_pos(env->b, b_pos);
	a_pos = ft_find_target_pos_in_a(env->a, b_val);
	if (b_pos <= (int)env->b->size / 2)
		cost_b = b_pos;
	else
		cost_b = env->b->size - b_pos;
	if (a_pos <= (int)env->a->size / 2)
		cost_a = a_pos;
	else
		cost_a = env->a->size - a_pos;
	return (cost_a + cost_b);
}

int	ft_find_cheapest_pos(t_vars *env)
{
	int	cheapest_pos;
	int	cheapest_cost;
	int	current_cost;
	int	pos;

	cheapest_pos = 0;
	cheapest_cost = ft_calculate_cost(env, 0);
	pos = 1;
	while (pos < (int)env->b->size)
	{
		current_cost = ft_calculate_cost(env, pos);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_pos = pos;
		}
		pos++;
	}
	return (cheapest_pos);
}
