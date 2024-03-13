

#include "../include/so_long.h"


int	map_check_rectangle(char **map_as_arr)
{
	int i;

	i = 0;
	while(map_as_arr[i] && (ft_strlen(map_as_arr[0]) == ft_strlen(map_as_arr[i])))
		i++;
	if(map_as_arr[i] && (ft_strlen(map_as_arr[0]) != ft_strlen(map_as_arr[i])))
		return(1);
	return(0);
}

int	map_check_wall(char **map_as_arr)
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


int	map_arr_check(char **map_as_arr)
{
	int status;

	status = 0;
	status += map_check_rectangle(map_as_arr);
	status += map_check_wall(map_as_arr);


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
