

#include "../include/so_long.h"


static int	map_check_rectangle(char **map_as_arr)
{
	int i;

	i = 0;
	while(map_as_arr[i] && (ft_strlen(map_as_arr[0]) == ft_strlen(map_as_arr[i])))
		i++;
	if(map_as_arr[i] && (ft_strlen(map_as_arr[0]) != ft_strlen(map_as_arr[i])))
		return(1);
	return(0);
}

static int	map_check_wall(char **map_as_arr)
{
	int i;
	int height;
	int len;

	i = 0;
	height = 0;
	len = ft_strlen(map_as_arr[0]);
	while(map_as_arr[height + 1])
		height++;
	while(map_as_arr[0][i] && i < len && map_as_arr[0][i] == '1')
		i++;
	if(map_as_arr[0][i] && i < len && map_as_arr[0][i] != '1')
		return(1);
	i = 1;
	while (i <= height)
	{
		if(map_as_arr[i][0] != '1' || map_as_arr[i][len - 1] != '1')
			return(1);
		i++;
	}
	i = 0;
	while(map_as_arr[height][i] && i < len && map_as_arr[height][i] == '1')
		i++;
	if(map_as_arr[height][i] && i < len && map_as_arr[height][i] != '1')
		return(1);
	return(0);
}

static int map_flood_fill(char **map, t_pos size, t_pos pos)
{
	// printf("size.x is %i\n", size.x);
	// printf("size.y is %i\n", size.y);
	// printf("map pos[%i][%i], char %c  \n", pos.x, pos.y, map[pos.x][pos.y]);
	// print_2d_arr(map);
	if (pos.x < 0 || pos.x >= size.x || pos.y < 0 || pos.y >= size.y)
	{
		// printf("				Out of Map at [%i][%i]\n",pos.x, pos.y);
		return(1);
	}
	if (map[pos.x][pos.y] == '1')
	{
		// printf("				Wall at [%i][%i]\n",pos.x, pos.y);
		return (1);
	}
	if (map[pos.x][pos.y] == 'V')
	{
		// printf("				Visited at [%i][%i]\n",pos.x, pos.y);
		return (1);
	}
	if (map[pos.x][pos.y] == 'E')
	{
		// printf("				Exit at [%i][%i]\n",pos.x, pos.y);
		return (0);
	}
		// printf("				Loop at [%i][%i]\n",pos.x, pos.y);
	map[pos.x][pos.y] = 'V';
	if(map_flood_fill(map, size, (t_pos){pos.x + 1, pos.y}) == 0
	|| map_flood_fill(map, size, (t_pos){pos.x - 1, pos.y}) == 0
	|| map_flood_fill(map, size, (t_pos){pos.x, pos.y + 1}) == 0
	|| map_flood_fill(map, size, (t_pos){pos.x, pos.y - 1}) == 0)
		return(0);
	return (1);
}

int	get_height(char **map_as_arr)
{
	int i;

	i = 0;
	while(map_as_arr[i])
		i++;
	return(i);
}

int	map_arr_check(char **map_as_arr)
{
	int		status;
	t_pos	size;
	t_pos	pos_player;

	status = 0;
	status += map_check_rectangle(map_as_arr);
	status += map_check_wall(map_as_arr);
	// status = 0;
	size.y = ft_strlen(map_as_arr[0]);
	// printf("size.y is %i\n", size.y);
	size.x = get_height(map_as_arr);
	// printf("size.x is %i\n", size.x);
	pos_player = get_pos_uniqe(map_as_arr, 'P');
	// printf("pos_player.x %i ,pos_player.y %i\n", pos_player.x,pos_player.y);
	status += map_flood_fill(map_as_arr, size, pos_player);
	return(status);
}

/*	???????
	5x3

	11111
	1PCE1
	11111

--------------
	3x5

	111
	1P1
	1C1
	1E1
	111
*/
