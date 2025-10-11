/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:48:37 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 14:48:52 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_direction(t_stack **stack, t_stack_name name, int rev)
{
	if (rev)
	{
		if (name == STACK_A)
			ft_stack_rra(stack);
		else
			ft_stack_rrb(stack);
	}
	else
	{
		if (name == STACK_A)
			ft_stack_ra(stack);
		else
			ft_stack_rb(stack);
	}
}

void	ft_rotate_value_to_top(t_stack *stack, t_stack_name name, int target)
{
	unsigned int	pos;
	int				reverse;

	if (!stack || stack->size == 0)
		return ;
	pos = ft_stack_get_val_pos(stack, target);
	reverse = (pos > stack->size / 2);
	while (*(int *)stack->top->content != target)
		ft_rotate_direction(&stack, name, reverse);
}
