/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:34 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/25 17:44:55 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_stack_sa(t_stack *a)
{
	void	*tmp;

	if (!a || a->size < 2 || !a->top || !a->top->next)
		return ;
	tmp = a->top->content;
	a->top->content = a->top->next->content;
	a->top->next->content = tmp;
	ft_printf("sa\n");
}

void	ft_stack_sb(t_stack *b)
{
	void	*tmp;

	if (!b || b->size < 2 || !b->top || !b->top->next)
		return ;
	tmp = b->top->content;
	b->top->content = b->top->next->content;
	b->top->next->content = tmp;
	ft_printf("sb\n");
}

void	ft_stack_ss(t_stack *a, t_stack *b)
{
	ft_stack_sa(a);
	ft_stack_sb(b);
	ft_printf("ss\n");
}

void	ft_stack_pa(t_stack *a, t_stack *b)
{
	void	*first;

	first = NULL;
	if (b->size <= 0)
		return ;
	first = b->top->content;
	ft_stack_pop(&b);
	ft_stack_push(&a, first);
	ft_printf("pa\n");
}

void	ft_stack_pb(t_stack *a, t_stack *b)
{
	void	*first;

	first = NULL;
	if (a->size <= 0)
		return ;
	first = a->top->content;
	ft_stack_pop(&a);
	ft_stack_push(&b, first);
	ft_printf("pb\n");
}
