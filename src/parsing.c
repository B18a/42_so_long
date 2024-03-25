/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:20:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 08:56:53 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*map_to_string(char *path_map)
{
	int		fd;
	char	*map_in_line;
	char	*map_in_line_temp;
	char	*map_in_line_joined;

	map_in_line = NULL;
	map_in_line_temp = NULL;
	map_in_line_joined = ft_strdup("");
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
	{
		if (map_in_line_joined)
			free(map_in_line_joined);
		return (ft_printf("Opening File failed\n"), NULL);
	}
	map_in_line = get_next_line(fd);
	while (map_in_line)
	{
		map_in_line_temp = ft_strjoin(map_in_line_joined, map_in_line);
		free(map_in_line_joined);
		free(map_in_line);
		map_in_line_joined = map_in_line_temp;
		map_in_line = get_next_line(fd);
	}
	return (close(fd), map_in_line_joined);
}

char	*read_map(char *map)
{
	char	*line;
	char	*line_joined;
	int		fd;

	fd = open(map, O_RDONLY);
	line_joined = ft_calloc(1, 1);
	if (!line_joined)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			line_joined = ft_strjoin(line_joined, line);
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (line_joined);
}

int	check_file_type(char *str)
{
	while (str && *str != '.')
		str++;
	if (ft_strncmp(str, ".ber", 4))
		return (1);
	return (0);
}
