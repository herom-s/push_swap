/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:07:01 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/01 02:27:41 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_stack_print(t_vars *env)
{
	t_dlist	*head;

	head = env->a->top;
	ft_printf("A = ");
	while (head)
	{
		ft_printf(" %d ", *(int *)head->content);
		head = head->next;
	}
	head = env->b->top;
	ft_printf("\nB = ");
	while (head)
	{
		ft_printf(" %d ", *(int *)head->content);
		head = head->next;
	}
	ft_printf("\n");
}

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

int	ft_sort_two(t_vars *env, t_stack_name name)
{
	if (name == STACK_A)
	{
		if (ft_stack_peek_top(&env->a) > ft_stack_peek_top_next(&env->a))
			ft_stack_sa(env->a);
	}
	else if (name == STACK_B)
	{
		if (ft_stack_peek_top(&env->b) > ft_stack_peek_top_next(&env->b))
			ft_stack_sb(env->b);
	}
	return (1);
}

int	ft_sort_three(t_vars *env, t_stack_name name)
{
	int	max;

	if (name == STACK_A)
	{
		max = ft_stack_get_max(env->a);
		if (ft_stack_peek_top(&env->a) == max)
			ft_stack_ra(&env->a);
		else if (ft_stack_peek_top_next(&env->a) == max)
			ft_stack_rra(&env->a);
		if (ft_stack_peek_top(&env->a) > ft_stack_peek_top_next(&env->a))
			ft_stack_sa(env->a);
	}
	else if (name == STACK_B)
	{
		max = ft_stack_get_max(env->b);
		if (ft_stack_peek_top(&env->b) == max)
			ft_stack_rb(&env->b);
		else if (ft_stack_peek_top_next(&env->b) == max)
			ft_stack_rrb(&env->b);
		if (ft_stack_peek_top(&env->b) > ft_stack_peek_top_next(&env->b))
			ft_stack_sb(env->b);
	}
	return (1);
}

void	ft_rotate_min_to_top(t_stack *s)
{
	int				min;
	unsigned int	position;
	int				i;
	t_dlist			*head;

	min = ft_stack_get_min(s);
	position = 0;
	i = 0;
	head = s->top;
	while (head)
	{
		if (*(int *)head->content == min)
		{
			position = i;
			break ;
		}
		head = head->next;
		i++;
	}
	if (position <= s->size / 2)
		while (ft_stack_peek_top(&s) != min)
			ft_stack_ra(&s);
	else
		while (ft_stack_peek_top(&s) != min)
			ft_stack_rra(&s);
}

int	ft_sort_five(t_vars *env)
{
	ft_rotate_min_to_top(env->a);
	ft_stack_pb(env->a, env->b);
	ft_rotate_min_to_top(env->a);
	ft_stack_pb(env->a, env->b);
	ft_sort_three(env, STACK_A);
	ft_stack_pa(env->a, env->b);
	ft_stack_pa(env->a, env->b);
	return (1);
}

static int	ft_get_max_bits(t_stack *s)
{
	int	max;
	int	bits;

	max = s->size - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

static void	ft_swap_ints(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_get_index_for_value(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (0);
}

static int	*ft_create_sorted_array(t_vars *env, int size)
{
	int		*sorted;
	t_dlist	*head;
	int		i;
	int		j;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	head = env->a->top;
	i = 0;
	while (i < size && head)
	{
		sorted[i] = *(int *)head->content;
		head = head->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[i] > sorted[j])
				ft_swap_ints(&sorted[i], &sorted[j]);
			j++;
		}
		i++;
	}
	return (sorted);
}

int	ft_sort_n_radix(t_vars *env)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;
	int		*sorted;
	int		current_val;
	int		index;

	size = env->a->size;
	sorted = ft_create_sorted_array(env, size);
	if (!sorted)
		return (0);
	max_bits = ft_get_max_bits(env->a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current_val = ft_stack_peek_top(&env->a);
			index = ft_get_index_for_value(sorted, size, current_val);
			if (((index >> i) & 1) == 0)
				ft_stack_pb(env->a, env->b);
			else
				ft_stack_ra(&env->a);
			j++;
		}
		while (env->b->size > 0)
			ft_stack_pa(env->a, env->b);
		i++;
	}
	free(sorted);
	return (1);
}

int	ft_sort_numbers(t_vars *env)
{
	if (ft_stack_is_sorted(env->a))
		return (1);
	if (env->a->size == 2)
		return (ft_sort_two(env, STACK_A));
	else if (env->a->size == 3)
		return (ft_sort_three(env, STACK_A));
	else if (env->a->size == 5)
		return (ft_sort_five(env));
	else
	{
		ft_sort_n_radix(env);
		return (1);
	}
	return (1);
}
