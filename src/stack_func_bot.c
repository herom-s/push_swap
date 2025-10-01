/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:12:02 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/29 17:21:40 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*ft_stack_add_bot(t_stack **s, int *value)
{
	t_dlist	*node;

	node = ft_dlstnew(value);
	if (!node)
		return (NULL);
	if ((*s)->bot == NULL && (*s)->top == NULL)
	{
		(*s)->top = node;
		(*s)->bot = node;
		(*s)->size = 1;
		return (*s);
	}
	node->next = NULL;
	node->prev = (*s)->bot;
	(*s)->bot->next = node;
	(*s)->bot = node;
	(*s)->size++;
	return (*s);
}

t_stack	*ft_stack_delete_bot(t_stack **s)
{
	t_dlist	*tmp;

	if (!s || !*s || !(*s)->bot)
		return (NULL);
	if ((*s)->size <= 0)
		return (NULL);
	tmp = (*s)->bot;
	if ((*s)->top == (*s)->bot)
	{
		(*s)->top = NULL;
		(*s)->bot = NULL;
	}
	else
	{
		(*s)->bot = (*s)->bot->prev;
		(*s)->bot->next = NULL;
	}
	(*s)->size--;
	ft_dlstdelone(tmp, free);
	return (*s);
}
