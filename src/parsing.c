/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:20:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/12 22:02:14 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**parse_input(char *path_map)
{
	int		fd;
	char	*map_in_line;
	char	*map_in_line_temp;
	char	*map_in_line_joined;
	char	**map_in_arr;

	map_in_line = NULL;
	map_in_line_temp = NULL;
	map_in_line_joined = ft_strdup("");

	// printf("%s\n",path_map);
	fd = open(path_map, O_RDONLY);
	if(fd < 0)
	{
		printf("Opening File failed\n");
		return (NULL);
	}
	while ((map_in_line = get_next_line(fd)))
	{
		map_in_line_temp = ft_strjoin(map_in_line_joined, map_in_line);
		free(map_in_line_joined);
		free(map_in_line);
		map_in_line_joined = map_in_line_temp;
	}
	close(fd);
	printf("%s\n",map_in_line_joined);
	map_in_arr = ft_split(map_in_line_joined, '\n');		

	
	if(map_in_line_joined)
		free(map_in_line_joined);

	return(map_in_arr);
}
