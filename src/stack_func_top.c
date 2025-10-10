/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:11:21 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/29 17:16:56 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*ft_stack_add_top(t_stack **s, int *value)
{
	t_dlist	*node;

	node = ft_dlstnew(value);
	if (!node)
		return (NULL);
	if ((*s)->top == NULL && (*s)->bot == NULL)
	{
		(*s)->top = node;
		(*s)->bot = node;
		(*s)->size = 1;
		return (*s);
	}
	node->prev = NULL;
	node->next = (*s)->top;
	(*s)->top->prev = node;
	(*s)->top = node;
	(*s)->size++;
	return (*s);
}

t_stack	*ft_stack_delete_top(t_stack **s)
{
	t_dlist	*tmp;

	if (!s || !*s || !(*s)->top)
		return (NULL);
	if ((*s)->size <= 0)
		return (NULL);
	tmp = (*s)->top;
	if ((*s)->top == (*s)->bot)
	{
		(*s)->top = NULL;
		(*s)->bot = NULL;
	}
	else
	{
		(*s)->top = (*s)->top->next;
		(*s)->top->prev = NULL;
	}
	(*s)->size--;
	ft_dlstdelone(tmp, free);
	return (*s);
}

int	ft_stack_peek_top(t_stack **s)
{
	if (!s || !*s || !(*s)->top || (*s)->size == 0)
		return (0);
	return (*(int *)(*s)->top->content);
}

int	ft_stack_peek_top_next(t_stack **s)
{
	if (!s || !*s || !(*s)->top || (*s)->size <= 1)
		return (0);
	if (!(*s)->top->next)
		return (0);
	return (*(int *)(*s)->top->next->content);
}
