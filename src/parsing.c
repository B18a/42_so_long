/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:20:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/10 11:09:27 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**parse_input(char *path_map)
{
	int		fd;
	char	*map_in_line;
	char	*map_in_line_temp;
	char	**map_in_arr;
	
	map_in_line = ft_strdup("");
	map_in_line_temp = ft_strdup("");
	map_in_arr = NULL;

	printf("%s\n",path_map);
	fd = open(path_map, O_RDONLY);
	if(fd < 0)
	{
		printf("Opening File failed\n");
		return (NULL);
	}
	while ((map_in_line_temp = get_next_line(fd)))
	{
			// map_in_line_temp = get_next_line(fd);
			// printf("%s\n",map_in_line_temp);
			map_in_line = ft_strjoin(map_in_line, map_in_line_temp);
			// printf("%s\n",map_in_line);
			free(map_in_line_temp);
			map_in_line_temp = NULL;
	}
	// printf("%s\n",map_in_line);
	free(map_in_line_temp);
	// free(map_in_line);
	close(fd);
	return(map_in_arr);
}