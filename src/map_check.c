/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:16:20 by andreasjehl       #+#    #+#             */
/*   Updated: 2024/03/12 22:32:09 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int forbidden_char(char c)
{
	printf("CHAR IS %c\n",c);
	if(c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E' || c == '\n')
		return(0);
	else
		return(1);
}

int	ft_map_check_chars(char *map_in_string)
{
	int i;

	i = 0;
	while(map_in_string[i])
	{
		if(forbidden_char(map_in_string[i]))
			return(1);
		i++;
	}
	return(0);
}