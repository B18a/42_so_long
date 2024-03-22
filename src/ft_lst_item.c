/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajehle <ajehle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:20:19 by ajehle            #+#    #+#             */
/*   Updated: 2024/03/22 15:39:49 by ajehle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	ft_lstadd_asset_front(t_asset **lst, t_asset *new)
// {
// 	if (new == NULL)
// 		return ;
// 	else
// 	{
// 		new->next = lst[0];
// 		lst[0] = new;
// 	}
// }

// t_asset	*ft_lst_asset_last(t_asset *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	if (!(lst->next))
// 		return (lst);
// 	else
// 		return (ft_lst_asset_last(lst->next));
// }

// void	ft_lstadd_back2(t_asset **lst, t_asset *new)
// {
// 	if (!*lst)
// 		ft_lstadd_asset_front(lst, new);
// 	else
// 		ft_lst_asset_last(*lst)->next = new;
// }

// t_asset	*ft_lst_asset_new(void)
// {
// 	t_asset	*new;

// 	new = (t_asset *)malloc(sizeof(t_asset));
// 	if (!new)
// 		return (NULL);
// 	new->next = NULL;
// 	return (new);
// }


// t_asset	*ft_initialize_item(int amount)
// {
// 	int		i;
// 	t_asset	*begin;
// 	t_asset	*new;

// 	i = 0;
// 	new = ft_lst_asset_new();
// 	if(!new)
// 		return(NULL);
// 	begin = new;
// 	while (i < amount)
// 	{
// 		new->pos = NULL;
// 		new->next = ft_lst_asset_new();
// 		new = new->next;
// 		i++;
// 	}
// 	return (begin);
// }