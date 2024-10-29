/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_construct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:13:37 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/29 17:03:52 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_set_images_pointers(t_struct *so_long)
{
	int y;
	int x;

	y = 30;
	x = 30;
	so_long->floor_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./assets/ocean_floor.xpm", &y, &x);
	so_long->player_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./assets/player_ocean.xpm", &y, &x);
	so_long->walls_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./assets/walls.xpm", &y, &x);
	so_long->collectables_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./assets/collectable.xpm", &y, &x);
	so_long->exit_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./assets/exit.xpm", &y, &x);

}

void    ft_place_assets(t_struct *so_long)
{
	int y;
	int x;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->floor_ptr, x * 30, y * 30);
			else if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->player_ptr, x * 30, y * 30);
			else if (so_long->map[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->walls_ptr, x * 30, y * 30);
			else if (so_long->map[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->collectables_ptr, x * 30, y * 30);
			else if (so_long->map[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->exit_ptr, x * 30, y * 30);
			x++;
		}
		y++ ;
	}
}
