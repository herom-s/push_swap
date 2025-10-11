/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:07:01 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 14:54:35 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_n_chunk(t_vars *env)
{
	ft_push_chunks_to_b(env);
	ft_push_back_to_a(env);
	return (1);
}

int	ft_sort_numbers(t_vars *env)
{
	if (ft_stack_is_sorted(env->a))
		return (1);
	if (env->a->size == 2)
		return (ft_sort_two(env, STACK_A));
	else if (env->a->size == 3)
		return (ft_sort_three(env, STACK_A));
	else if (env->a->size == 4)
		return (ft_sort_four(env));
	else if (env->a->size == 5)
		return (ft_sort_five(env));
	else
		return (ft_sort_n_chunk(env));
}
