/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:18:32 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/30 13:21:07 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	unsigned int	size;
	struct s_dlist	*top;
	struct s_dlist	*bot;
}				t_stack;

typedef struct s_vars
{
	t_stack			a;
	t_stack			b;
}				t_vars;

t_stack				*ft_stack_create(void);
t_stack				*ft_stack_add_top(t_stack **s, int *value);
t_stack				*ft_stack_delete_top(t_stack **node);
t_stack				*ft_stack_add_bot(t_stack **s, int *value);
t_stack				*ft_stack_delete_bot(t_stack **s);
t_stack				*ft_stack_destroy(t_stack **s);

void				ft_stack_push(t_stack **s, int *value);
int					ft_stack_pop(t_stack **s);
int					ft_stack_peek_top(t_stack **s);
int					ft_stack_peek_bot(t_stack **s);

void				ft_stack_sa(t_stack *a);
void				ft_stack_sb(t_stack *b);
void				ft_stack_ss(t_stack *a, t_stack *b);
void				ft_stack_pa(t_stack *a, t_stack *b);
void				ft_stack_pb(t_stack *a, t_stack *b);
void				ft_stack_ra(t_stack **a);
void				ft_stack_rb(t_stack **b);
void				ft_stack_rr(t_stack *a, t_stack *b);
void				ft_stack_rra(t_stack **a);
void				ft_stack_rrb(t_stack **b);
void				ft_stack_rrr(t_stack *a, t_stack *b);

int					ft_check_str_numbers(char **str_numbers,
						int size_str_numbers);
int					*ft_str_numbers_to_int(char **str_numbers,
						int size_str_numbers);
void				*ft_free_str_numbers(char **s, size_t i);

char				**ft_no_args_handler(int *size_str_numbers);
char				**ft_str_args_handler(int argc,
						char **argv, int *size_str_numbers);
char				**ft_args_handler(int argc, char **argv,
						int *size_str_numbers);

int					ft_print_error(char *msg);
#endif
