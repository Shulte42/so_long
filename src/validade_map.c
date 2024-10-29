/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:40:28 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/29 11:16:07 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	ft_check_components(t_struct *so_long)
{
	int x;
	int y;

	y = 0;
	while (y != so_long->map_height)
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] != '1' &&
				so_long->map[y][x] != 'E' &&
				so_long->map[y][x] != 'C' &&
				so_long->map[y][x] != '0' &&
				so_long->map[y][x] != 'P' &&
				so_long->map[y][x] != '\n')
				{
					ft_print_string("A Component inside the Map is INVALID!\n");
					return (true);
				}
			x++;
		}
		y++;
	}
	return (false);
}

bool	ft_check_player(t_struct *so_long)
{
	int y;
	int x;

	y = 0;
	while (y != so_long->map_height)
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->player_y = y;
				so_long->player_x = x;
				so_long->player++;
			}
			x++;
		}
		y++;
	}
	if (so_long->player != 1)
		ft_print_string("The Number of Players is INVALID!\n");
	if (so_long->player != 1)
		return (true);
	return(false);
	
}

bool	ft_check_collectables(t_struct	*so_long)
{
	int y;
	int x;

	y = 0;
	while (y != so_long->map_height)
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'C')
			{
				so_long->collectables++;
			}
			x++;
		}
		y++;
	}
	if (so_long->collectables < 1)
	{
		ft_print_string("The Number of Collectables is INVALID!\n");
		return (true);
	}
	return (false);
}



bool	ft_check_exit(t_struct *so_long)
{
	int y;
	int x;

	y = 0;
	while (y != so_long->map_height)
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == 'E')
			{
				so_long->exit++;
			}
			x++;
		}
		y++;
	}
	if (so_long->exit != 1)
	{
		ft_print_string("The Number of Exits is INVALID!\n");
		return (true);
	}
	return (false);
}

bool	ft_check_walls(t_struct *so_long)
{
	int	y;
	int x;

	y = 0;
	while (y < so_long->map_height)
	{
		x = 0;
		if (y == 0 || y == so_long->map_height -1)
		{
			while (x < so_long->map_weidth)
			{
				if (so_long->map[y][x] != '1')
					return (true);
				x++;
			}
		}
		else
			if (so_long->map[y][0] != '1' 
				|| so_long->map[y][so_long->map_weidth - 1] != '1')
				return (true);
		y++;
	}
	return (false);
}

int	ft_flood_fill(t_struct *so_long, int y, int x)
{
	if (so_long->map_copy[y][x] == '1')
		return (0);
	if (so_long->map_copy[y][x] == 'E')
		so_long->flood_exit++;
	if (so_long->map_copy[y][x] == 'C')
		so_long->flood_collectables++;
	so_long->map_copy[y][x] = '1';
	ft_flood_fill(so_long, y - 1, x);
	ft_flood_fill(so_long, y + 1, x);
	ft_flood_fill(so_long, y, x - 1);
	ft_flood_fill(so_long, y, x + 1);
	return (1);
}

bool	ft_full_check(t_struct *so_long)
{
	if (ft_check_components(so_long))
		return (true);
	if (ft_check_walls(so_long))
		return (true);
	if (ft_check_player(so_long))
		return (true);
	if (ft_check_exit(so_long))
		return (true);
	if (ft_check_collectables(so_long))
		return (true);
	ft_flood_fill(so_long, so_long->player_y, so_long->player_x);
	if (so_long->collectables != so_long->flood_collectables
		|| so_long->exit != so_long->flood_exit)
		{
			ft_print_string("There`s no Path!\n");
			return (true);
		}
	return (false);
}
