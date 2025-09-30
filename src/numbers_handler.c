/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:09:58 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/30 13:23:38 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_check_duplicated_int_nums(int *int_numbers, int size_str_numbers)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_str_numbers)
	{
		j = i + 1;
		while (j < size_str_numbers)
		{
			if (int_numbers[i] == int_numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_str_numbers(char **str_numbers, int size_str_numbers)
{
	int	i;

	i = 0;
	if (str_numbers == NULL)
		return (0);
	while (i < size_str_numbers)
	{
		if (!ft_isnumber(str_numbers[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_str_numbers_to_int(char **str_numbers, int size_str_numbers)
{
	int		i;
	int		*int_numbers;
	long	tmp_val;

	i = 0;
	int_numbers = ft_calloc(size_str_numbers + 1, sizeof(int));
	if (!int_numbers)
		return (NULL);
	while (i < size_str_numbers)
	{
		tmp_val = ft_atol(str_numbers[i]);
		if (tmp_val < INT_MIN || tmp_val > INT_MAX)
		{
			free(int_numbers);
			return (NULL);
		}
		int_numbers[i] = tmp_val;
		i++;
	}
	if (!ft_check_duplicated_int_nums(int_numbers, size_str_numbers))
	{
		free(int_numbers);
		return (NULL);
	}
	return (int_numbers);
}
