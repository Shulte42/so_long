/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:13:37 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/30 15:53:24 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	ft_set_images_pointers(t_struct *so_long)
{
	int	y;
	int	x;

	y = 30;
	x = 30;
	so_long->floor_ptr = XFTI(so_long->mlx_ptr, FLOOR, &y, &x);
	so_long->pl_ptr = XFTI(so_long->mlx_ptr, PLAYER, &y, &x);
	so_long->walls_ptr = XFTI(so_long->mlx_ptr, WALLS, &y, &x);
	so_long->collec_ptr = XFTI(so_long->mlx_ptr, COLLEC, &y, &x);
	so_long->exit_ptr = XFTI(so_long->mlx_ptr, EXIT, &y, &x);
}

void	ft_place_assets(t_struct *sl)
{
	int	y;
	int	x;

	y = 0;
	while (sl->map[y])
	{
		x = 0;
		while (sl->map[y][x])
		{
			if (sl->map[y][x] == '0')
				PIW(sl->mlx_ptr, sl->mlx_win, sl->floor_ptr, x * 30, y * 30);
			else if (sl->map[y][x] == 'P')
				PIW(sl->mlx_ptr, sl->mlx_win, sl->pl_ptr, x * 30, y * 30);
			else if (sl->map[y][x] == '1')
				PIW(sl->mlx_ptr, sl->mlx_win, sl->walls_ptr, x * 30, y * 30);
			else if (sl->map[y][x] == 'C')
				PIW(sl->mlx_ptr, sl->mlx_win, sl->collec_ptr, x * 30, y * 30);
			else if (sl->map[y][x] == 'E')
				PIW(sl->mlx_ptr, sl->mlx_win, sl->exit_ptr, x * 30, y * 30);
			x++;
		}
		y++ ;
	}
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
	ft_flood_fill(so_long, so_long->pl_y, so_long->pl_x);
	if (so_long->collectables != so_long->flood_collectables
		|| so_long->exit != so_long->flood_exit)
	{
		ft_print_string("There`s no Path!\n");
		return (true);
	}
	return (false);
}
