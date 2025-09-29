/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_func3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:45:43 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/25 17:45:54 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rrr(t_stack *a, t_stack *b)
{
	ft_stack_rra(&a);
	ft_stack_rrb(&b);
	ft_printf("rrr\n");
}
