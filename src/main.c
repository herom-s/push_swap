/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:18:19 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/24 19:09:09 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	main(void)
{
	int		i;
	int		*val;
	t_stack	*a;
	t_stack	*b;

	a = ft_stack_create();
	b = ft_stack_create();
	if (!a || !b)
		return (1);
	i = 0;
	while (i < 5)
	{
		val = malloc(sizeof(int));
		if (!val)
			return (1);
		*val = i + 1;
		ft_stack_push(&a, val);
		i++;
	}
	ft_stack_pb(a, b);
	ft_stack_pb(a, b);
	ft_stack_pb(a, b);
	ft_stack_pa(a, b);
	i = 0;
	while (i < 5)
	{
		ft_printf("a = %d b = %d\n", ft_stack_pop(&a), ft_stack_pop(&b));
		i++;
	}
	ft_stack_destroy(&a);
	ft_stack_destroy(&b);
	return (0);
}
