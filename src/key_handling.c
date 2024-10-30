/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/10/30 12:07:24 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_keypress(int keysym, t_struct *so_long)
{
	int y;
	int x;
	
	y = so_long->player_y;
	x = so_long->player_x;
	so_long->map[y][x] = '0';
	printf("x:%d\nY:%d\n", x, y);
   	mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->floor_ptr, x * 30, y * 30);
	ft_place_assets(so_long);
	if (keysym == XK_w && so_long->map[y - 1][x] != '1')
		{so_long->player_y--;
		printf("teste\n");}
	else if (keysym == XK_s && so_long->map[y + 1][x] != '1')
		so_long->player_y++;
	else if (keysym == XK_a && so_long->map[y][x - 1] != '1')
		so_long->player_x--;
	else if (keysym == XK_d && so_long->map[y][x + 1] != '1')
		so_long->player_x++;
	else if (keysym == XK_Escape)
	{
		ft_free_maps(so_long);
		mlx_destroy_window(so_long->mlx_ptr, so_long->mlx_display);
		mlx_destroy_display(so_long->mlx_ptr);
		free (so_long->mlx_ptr);
		exit (EXIT_SUCCESS);   
	}
	if (so_long->map[so_long->player_y][so_long->player_x] != 'E')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->player_ptr, so_long->player_x * 30, so_long->player_y * 30);
	
	return (0);
}