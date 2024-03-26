/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:16:20 by andreasjehl       #+#    #+#             */
/*   Updated: 2024/03/26 11:40:26 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	forbidden_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '\n')
		return (0);
	else
		return (1);
}

int	ft_map_check_chars(char *map_in_string)
{
	int	i;

	i = 0;
	while (map_in_string[i])
	{
		if (forbidden_char(map_in_string[i]) || map_in_string[0] == '\n'
			|| ((map_in_string[i] == '\n') && (map_in_string[i + 1] == '\n')))
		{
			ft_printf("Error\nForbidden character:%c \n", map_in_string[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_unique_char(char *map_as_string, char character)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (map_as_string[i])
	{
		if (map_as_string[i] == character)
			check++;
		i++;
	}
	if (check != 1)
	{
		ft_printf("Error\nSomething wrong in map, amount of %c is wrong\n",
			character);
		return (1);
	}
	return (0);
}

int	ft_check_multiple_char(char *map_as_string, char character)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (map_as_string[i])
	{
		if (map_as_string[i] == character)
			check++;
		i++;
	}
	if (check <= 0)
	{
		ft_printf("Error\nSomething wrong in map, amount of %c is wrong\n",
			character);
		return (1);
	}
	return (0);
}

int	map_string_check(char *map_as_string)
{
	int	status;

	status = 0;
	status += ft_map_check_chars(map_as_string);
	status += ft_check_unique_char(map_as_string, 'P');
	status += ft_check_unique_char(map_as_string, 'E');
	status += ft_check_multiple_char(map_as_string, 'C');
	return (status);
}
