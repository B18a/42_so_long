

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

static int flood_fill(char **map, t_pos size, t_pos pos, char exit)
{
	int ret;

	ret = 0;
	if (pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y > size.y)
		return(0);
	if (map[pos.x][pos.y] == exit)
		return (1);
	// ret += flood_fill(map, size, (t_pos){pos.x + 1, pos.y}, exit);
	// ret += flood_fill(map, size, (t_pos){pos.x - 1, pos.y}, exit);
	// ret += flood_fill(map, size, (t_pos){pos.x, pos.y + 1}, exit);
	// ret += flood_fill(map, size, (t_pos){pos.x, pos.y - 1}, exit);
	return (ret);
}

static int	map_flood_fill(char **map_as_arr, t_pos size, t_pos player)
{
	int status;

	status = 0;
	status += flood_fill(map_as_arr, size, player, 'E');
	return(status);
}

static int	get_height(char **map_as_arr)
{
	int i;

	i = 0;
	while(map_as_arr[i])
		i++;
	return(i);
}

static t_pos get_pos_player(char **map_as_arr)
{
	int		i;
	int		j;
	t_pos	pos_player;

	i = 0;
	j = 0;
	pos_player.x = 0;
	pos_player.y = 0;
	while(map_as_arr[i])
	{
		while (map_as_arr[i][j])
		{
			if(map_as_arr[i][j] == 'P')
			{
				pos_player.x = j;
				pos_player.y = i;
				return(pos_player);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return(pos_player);
}

int	map_arr_check(char **map_as_arr)
{
	int		status;
	t_pos	size;
	t_pos	pos_player;
	
	status += map_check_rectangle(map_as_arr);
	status += map_check_wall(map_as_arr);
	status = 0;
	size.x = ft_strlen(map_as_arr[0]);
	printf("size.x is %i\n", size.x);
	size.y = get_height(map_as_arr);
	printf("size.y is %i\n", size.y);
	pos_player = get_pos_player(map_as_arr);
	printf("pos_player.x %i ,pos_player.y %i\n", pos_player.x,pos_player.y);
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
