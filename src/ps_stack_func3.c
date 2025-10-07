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

void	ft_stack_ss(t_stack *a, t_stack *b)
{
	void	*tmp;

	if (!a || a->size < 2 || !a->top || !a->top->next)
		return ;
	tmp = a->top->content;
	a->top->content = a->top->next->content;
	a->top->next->content = tmp;
	if (!b || b->size < 2 || !b->top || !b->top->next)
		return ;
	tmp = b->top->content;
	b->top->content = b->top->next->content;
	b->top->next->content = tmp;
	ft_printf("ss\n");
}

void	ft_stack_rr(t_stack **a, t_stack **b)
{
	t_dlist	*first;

	if (!a || !*a || (*a)->size < 2)
		return ;
	first = (*a)->top;
	(*a)->top = first->next;
	(*a)->top->prev = NULL;
	first->next = NULL;
	first->prev = (*a)->bot;
	(*a)->bot->next = first;
	(*a)->bot = first;
	if (!b || !*b || (*b)->size < 2)
		return ;
	first = (*b)->top;
	(*b)->top = first->next;
	(*b)->top->prev = NULL;
	first->next = NULL;
	first->prev = (*b)->bot;
	(*b)->bot->next = first;
	(*b)->bot = first;
	ft_printf("rr\n");
}

void	ft_stack_rrr(t_stack **a, t_stack **b)
{
	t_dlist	*last;

	if (!a || !*a || (*a)->size < 2)
		return ;
	last = (*a)->bot;
	(*a)->bot = last->prev;
	(*a)->bot->next = NULL;
	last->prev = NULL;
	last->next = (*a)->top;
	(*a)->top->prev = last;
	(*a)->top = last;
	if (!b || !*b || (*b)->size < 2)
		return ;
	last = (*b)->bot;
	(*b)->bot = last->prev;
	(*b)->bot->next = NULL;
	last->prev = NULL;
	last->next = (*b)->top;
	(*b)->top->prev = last;
	(*b)->top = last;
	ft_printf("rrr\n");
}
