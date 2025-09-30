/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermarti <hermarti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:04:51 by hermarti          #+#    #+#             */
/*   Updated: 2025/09/30 13:08:15 by hermarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_str_numbers_size(char **str_numbers)
{
	int	i;

	i = 0;
	while (str_numbers[i])
		i++;
	return (i);
}

static char	*ft_buffer_realloc(char	*buffer, int *size)
{
	char	*res;

	res = ft_calloc(*size * 2, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, buffer, *size);
	free(buffer);
	*size *= 2;
	return (res);
}

char	**ft_no_args_handler(int *size_str_numbers)
{
	char	**str_numbers;
	char	*buffer;
	int		buffer_size;
	int		byte_read;

	buffer_size = 100;
	buffer = ft_calloc(buffer_size, sizeof(char));
	if (!buffer)
	{
		ft_print_error("Error\n");
		return (NULL);
	}
	byte_read = read(0, buffer, buffer_size);
	if (byte_read > 0)
	{
		while (byte_read > buffer_size)
		{
			buffer = ft_buffer_realloc(buffer, &buffer_size);
			if (!buffer)
				return (NULL);
		}
	}
	str_numbers = ft_split(buffer, ' ');
	*size_str_numbers = ft_str_numbers_size(str_numbers);
	return (str_numbers);
}

char	**ft_str_args_handler(int argc, char **argv, int *size_str_numbers)
{
	char	**str_numbers;

	str_numbers = ft_split(argv[argc - 1], ' ');
	if (str_numbers[0] == NULL)
	{
		free(str_numbers[0]);
		free(str_numbers);
		return (NULL);
	}
	*size_str_numbers = ft_str_numbers_size(str_numbers);
	return (str_numbers);
}

char	**ft_args_handler(int argc, char **argv, int *size_str_numbers)
{
	char	**str_numbers;
	int		argv_len;
	int		i;

	i = 1;
	argv_len = 0;
	str_numbers = ft_calloc(argc, sizeof(char *));
	while (i < argc)
	{
		argv_len = ft_strlen(argv[i]) + 1;
		str_numbers[i - 1] = ft_calloc(argv_len, sizeof(char));
		ft_strlcpy(str_numbers[i - 1], argv[i], argv_len);
		i++;
	}
	str_numbers[i - 1] = NULL;
	*size_str_numbers = ft_str_numbers_size(str_numbers);
	return (str_numbers);
}
