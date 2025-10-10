/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:28:37 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/29 17:11:46 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*ft_stack_create(t_stack_name name)
{
	t_stack	*res;

	res = ft_calloc(1, sizeof(t_stack));
	if (!res)
		return (NULL);
	res->name = name;
	return (res);
}

t_stack	*ft_stack_destroy(t_stack **s)
{
	if (!s || !*s)
		return (NULL);
	ft_dlstclear(&((*s)->top), free);
	free(*s);
	*s = NULL;
	return (NULL);
}
