/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:35:49 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/24 19:56:03 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack **s, int *value)
{
	ft_stack_add_top(s, value);
}

int	ft_stack_pop(t_stack **s)
{
	int	tmp_val;

	tmp_val = 0;
	if ((*s)->size > 0 && (*s)->top)
	{
		tmp_val = *(int *)(*s)->top->content;
		ft_stack_delete_top(s);
	}
	return (tmp_val);
}

int	ft_stack_is_empty(t_stack *s)
{
	if (s->size == 0)
		return (1);
	return (0);
}
