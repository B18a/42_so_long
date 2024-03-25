/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_item.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:31 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/25 12:09:30 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void free_item(t_item *item)
{
	if (item)
	{
		if (item->pos)
			free (item->pos);
		free (item);
	}
}

void preset_item(t_item *item)
{
		item->pos->y = 0;
		item->pos->x = 0;
		item->texture = NULL;
		item->image = NULL;
		item->collected = 0;
}


t_item	**ft_initialize_item(t_game *game)
{
	t_item	**item;
	int		i;

	item = NULL;
	i = 0;
	item = malloc((game->item_total + 1) * sizeof(t_item *));
	if (!item)
		return (NULL);
	while (i < game->item_total)
	{
		item[i] = NULL;
		item[i] = malloc(1 * sizeof(t_item));
		if (!item[i])
		{
			while (i > 0)
			{
				i--;
				if (item[i])
				{
					if (item[i]->pos)
						free(item[i]->pos);
					free(item[i]);
				}
			}
			return (NULL);
		}
		item[i]->pos = NULL;
		item[i]->pos = ft_calloc(1, sizeof(t_pos));
		if (!item[i]->pos)
		{
			while (i >= 0)
			{
				free(item[i]->pos);
				free(item[i]);
				i--;
			}
			free(item);
			return (NULL);
		}
		preset_item(item[i]);
		i++;
	}
	return (item);
}
