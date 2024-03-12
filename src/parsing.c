/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreasjehle <andreasjehle@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:20:06 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/12 19:16:46 by andreasjehl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**parse_input(char *path_map)
{
	int		fd;
	char	*map_in_line;
	char	*map_in_line_new;
	char	*map_in_line_temp;
	
	map_in_line = NULL;
	map_in_line_temp = NULL;
	map_in_line_new = ft_strdup("");

	// printf("%s\n",path_map);
	fd = open(path_map, O_RDONLY);
	if(fd < 0)
	{
		printf("Opening File failed\n");
		return (NULL);
	}
	while ((map_in_line_temp = get_next_line(fd)))
	{
		// printf("%s\n",map_in_line_temp);
		map_in_line = ft_calloc(sizeof(char), ft_strlen(map_in_line_new));
		ft_strlcpy(map_in_line, map_in_line_new, ft_strlen(map_in_line_new));
		if(map_in_line_new)
			free(map_in_line_new);
		map_in_line_new = NULL;
		map_in_line_new = ft_strjoin(map_in_line, map_in_line_temp);
		if(map_in_line_temp)
			free(map_in_line_temp);
		if(map_in_line)
			free(map_in_line);
	}
	close(fd);
	// printf("%s\n",map_in_line_new);
	if(map_in_line_new)
		free(map_in_line_new);
	return(ft_split(map_in_line_new, '\n'));
}
