/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:40:48 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 16:21:37 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_is_sorted(t_stack *s)
{
	t_dlist	*head;
	int		not_sorted;

	not_sorted = 0;
	head = s->top;
	while (head)
	{
		if (head->prev)
			if ((*(int *)head->prev->content) > (*(int *)head->content))
				return (0);
		head = head->next;
	}
	return (1);
}

int	ft_stack_get_max(t_stack *s)
{
	t_dlist	*head;
	int		max;
	int		first;

	if (!s || !s->top)
		return (0);
	head = s->top;
	max = *(int *)head->content;
	first = 1;
	while (head)
	{
		if (first || *(int *)head->content > max)
		{
			max = *(int *)head->content;
			first = 0;
		}
		head = head->next;
	}
	return (max);
}

int	ft_stack_get_min(t_stack *s)
{
	t_dlist	*head;
	int		min;
	int		first;

	if (!s || !s->top)
		return (0);
	head = s->top;
	min = *(int *)head->content;
	first = 1;
	while (head)
	{
		if (first || *(int *)head->content < min)
		{
			min = *(int *)head->content;
			first = 0;
		}
		head = head->next;
	}
	return (min);
}

int	ft_stack_get_val_pos(t_stack *s, int val)
{
	t_dlist	*head;
	int		pos;

	if (!s || !s->top)
		return (0);
	head = s->top;
	pos = 0;
	while (head)
	{
		if (*(int *)head->content == val)
			return (pos);
		pos++;
		head = head->next;
	}
	return (-1);
}
