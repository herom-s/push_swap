/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:18:32 by hermarti          #+#    #+#             */
/*   Updated: 2025/10/11 17:54:23 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef enum e_stack_name
{
	STACK_A,
	STACK_B
}					t_stack_name;

typedef struct s_stack
{
	t_stack_name	name;
	unsigned int	size;
	struct s_dlist	*top;
	struct s_dlist	*bot;
}					t_stack;

typedef struct s_vars
{
	t_stack			*a;
	t_stack			*b;
}					t_vars;

t_stack				*ft_stack_create(t_stack_name name);
t_stack				*ft_stack_add_top(t_stack **s, int *value);
t_stack				*ft_stack_delete_top(t_stack **node);
t_stack				*ft_stack_add_bot(t_stack **s, int *value);
t_stack				*ft_stack_delete_bot(t_stack **s);
t_stack				*ft_stack_destroy(t_stack **s);

void				ft_stack_push(t_stack **s, int *value);
int					ft_stack_pop(t_stack **s);
int					ft_stack_peek_top(t_stack **s);
int					ft_stack_peek_top_next(t_stack **s);
int					ft_stack_peek_bot(t_stack **s);
int					ft_stack_peek_bot_prev(t_stack **s);

int					ft_stack_is_sorted(t_stack *s);
int					ft_stack_get_max(t_stack *s);
int					ft_stack_get_min(t_stack *s);
int					ft_stack_get_val_pos(t_stack *s, int val);
int					ft_stack_is_empty(t_stack *s);

void				ft_stack_sa(t_stack *a);
void				ft_stack_sb(t_stack *b);
void				ft_stack_ss(t_stack *a, t_stack *b);
void				ft_stack_pa(t_stack *a, t_stack *b);
void				ft_stack_pb(t_stack *a, t_stack *b);
void				ft_stack_ra(t_stack **a);
void				ft_stack_rb(t_stack **b);
void				ft_stack_rr(t_stack **a, t_stack **b);
void				ft_stack_rra(t_stack **a);
void				ft_stack_rrb(t_stack **b);
void				ft_stack_rrr(t_stack **a, t_stack **b);

int					ft_sort_two(t_vars *env, t_stack_name name);
int					ft_sort_three(t_vars *env, t_stack_name name);
int					ft_sort_four(t_vars *env);
int					ft_sort_five(t_vars *env);
int					ft_sort_numbers(t_vars *env);

void				ft_rotate_value_to_top(t_stack *stack, t_stack_name name,
						int target);
int					ft_get_value_at_pos(t_stack *stack, int pos);
int					ft_find_target_pos_in_a(t_stack *a, int b_val);
void				ft_execute_cheapest_move(t_vars *env, int b_pos);
int					ft_find_cheapest_pos(t_vars *env);
void				ft_push_chunks_to_b(t_vars *env);
void				ft_push_back_to_a(t_vars *env);
void				ft_process_chunk(t_vars *env, int chunk_min, int chunk_max);

int					ft_check_str_numbers(char **str_numbers,
						int size_str_numbers);
int					*ft_str_numbers_to_int(char **str_numbers,
						int size_str_numbers);
void				*ft_free_str_numbers(char **s, size_t i);

char				**ft_no_args_handler(int *size_str_numbers);
char				**ft_str_args_handler(int argc, char **argv,
						int *size_str_numbers);
char				**ft_args_handler(int argc, char **argv,
						int *size_str_numbers);

t_vars				*ft_create_env(int *int_numbers, int int_numbers_size);
void				ft_destroy_env(t_vars *env);

int					ft_print_error(char *msg);
#endif
