/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_func2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:45:27 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/25 17:45:30 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_stack_ra(t_stack **a)
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
	ft_printf("ra\n");
}

void	ft_stack_rb(t_stack **b)
{
	t_dlist	*first;

	if (!b || !*b || (*b)->size < 2)
		return ;
	first = (*b)->top;
	(*b)->top = first->next;
	(*b)->top->prev = NULL;
	first->next = NULL;
	first->prev = (*b)->bot;
	(*b)->bot->next = first;
	(*b)->bot = first;
	ft_printf("rb\n");
}

void	ft_stack_rra(t_stack **a)
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
	ft_printf("rra\n");
}

void	ft_stack_rrb(t_stack **b)
{
	t_dlist	*last;

	if (!b || !*b || (*b)->size < 2)
		return ;
	last = (*b)->bot;
	(*b)->bot = last->prev;
	(*b)->bot->next = NULL;
	last->prev = NULL;
	last->next = (*b)->top;
	(*b)->top->prev = last;
	(*b)->top = last;
	ft_printf("rrb\n");
}
