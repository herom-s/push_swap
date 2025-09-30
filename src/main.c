/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:18:19 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/30 13:22:45 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void *ft_free_str_numbers(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[--i]);
	}
	free(s);
	s = NULL;
	return (NULL);
}

static	int *ft_fill_numbers(int argc, char **argv)
{
	char	**str_numbers;
	int		*int_numbers;
	int		size_str_numbers;

	str_numbers = NULL;
	size_str_numbers = 0;
	if (argc == 1)
		str_numbers = ft_no_args_handler(&size_str_numbers);
	else if (argc == 2)
		str_numbers = ft_str_args_handler(argc, argv, &size_str_numbers);
	else if (argc >= 3)
		str_numbers = ft_args_handler(argc, argv, &size_str_numbers);
	if (!str_numbers)
		return (NULL);
	if (!ft_check_str_numbers(str_numbers, size_str_numbers))
		return (ft_free_str_numbers(str_numbers, size_str_numbers));
	int_numbers = ft_str_numbers_to_int(str_numbers, size_str_numbers);
	if (!int_numbers)
		return (ft_free_str_numbers(str_numbers, size_str_numbers));
	ft_free_str_numbers(str_numbers, size_str_numbers);
	return (int_numbers);
}

int	main(int argc, char **argv)
{
	int		*int_numbers;
	t_vars	env;

	(void)env;
	int_numbers = ft_fill_numbers(argc, argv);
	if (!int_numbers)
		return (ft_print_error("Error\n"));
	free(int_numbers);
	return (0);
}
