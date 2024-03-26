/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:05:31 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/26 15:11:06 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_item(t_item *item)
{
	if (item)
	{
		if (item->pos)
			free(item->pos);
		free(item);
	}
}

static void	preset_item(t_item *item)
{
	item->pos->y = 0;
	item->pos->x = 0;
	item->texture = NULL;
	item->image = NULL;
	item->collected = 0;
}

static int	allocating_item(t_game *game, t_item **item)
{
	int	i;

	i = 0;
	if (game && item)
	{
		while (i < game->item_total)
		{
			item[i] = NULL;
			item[i] = malloc(1 * sizeof(t_item));
			if (!item[i])
			{
				while (i > 0)
				{
					i--;
					free_item(item[i]);
				}
				return (0);
			}
			item[i]->pos = NULL;
			i++;
		}
	}
	return (1);
}

static int	allocating_item_pos(t_game *game, t_item **item)
{
	int	i;

	i = 0;
	if (game && item)
	{
		while (i < game->item_total)
		{
			item[i]->pos = NULL;
			item[i]->pos = ft_calloc(1, sizeof(t_pos));
			if (!item[i]->pos)
			{
				while (i >= 0)
				{
					free_item(item[i]);
					i--;
				}
				free(item);
				return (0);
			}
			preset_item(item[i]);
			i++;
		}
	}
	return (1);
}

t_item	**ft_initialize_item(t_game *game)
{
	t_item	**item;

	item = NULL;
	item = malloc((game->item_total + 1) * sizeof(t_item *));
	if (!item)
		return (NULL);
	if (!allocating_item(game, item))
		return (NULL);
	if (!allocating_item_pos(game, item))
		return (NULL);
	return (item);
}
