/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/10/30 14:00:22 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_destroy(t_struct *so_long)
{
	mlx_destroy_image(so_long->mlx_ptr, so_long->floor_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->walls_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->player_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->collectables_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->exit_ptr);
	ft_free_maps(so_long);
	mlx_destroy_window(so_long->mlx_ptr, so_long->mlx_display);
	mlx_destroy_display(so_long->mlx_ptr);
	free (so_long->mlx_ptr);
	exit(EXIT_SUCCESS);
}
void	ft_print_step(int step)
{
	char	c;

	if (step == -2147483648)
		write(1, "-2147483648", 11);
	else if (step < 0)
	{
		write(1, "-", 1);
		ft_print_step(-step);
	}
	else if (step > 9)
	{
		ft_print_step(step / 10);
		ft_print_step(step % 10);
	}
	else
	{
		c = step + 48;
		write(1, &c, 1);
	}
}

void	ft_end_game_checkers(t_struct *so_long, int y, int x)
{
	if (so_long->map[so_long->player_y][so_long->player_x] == 'C')
		{
			so_long->map[so_long->player_y][so_long->player_x] = '0';
			so_long->c_collected++;
		}
	if (so_long->map[so_long->player_y][so_long->player_x] == 'E')
	{
		if (so_long->collectables == so_long->c_collected)
			ft_destroy(so_long);
	}
	if (so_long->player_x != x || so_long->player_y != y)
	{
		so_long->steps++;
		ft_print_step(so_long->steps);
		write(1, "\n", 1);
	}
}

int ft_keypress(int keysym, t_struct *so_long)
{
	int y;
	int x;
	
	y = so_long->player_y;
	x = so_long->player_x;
	if (so_long->map[y][x] != 'E')
   		mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->floor_ptr, x * 30, y * 30);
	if (keysym == XK_w && so_long->map[y - 1][x] != '1')
		so_long->player_y--;
	else if (keysym == XK_s && so_long->map[y + 1][x] != '1')
		so_long->player_y++;
	else if (keysym == XK_a && so_long->map[y][x - 1] != '1')
		so_long->player_x--;
	else if (keysym == XK_d && so_long->map[y][x + 1] != '1')
		so_long->player_x++;
	else if (keysym == XK_Escape)
	{
		ft_destroy(so_long);
		exit (EXIT_SUCCESS);   
	}
	ft_end_game_checkers(so_long, y, x);
	if (so_long->map[so_long->player_y][so_long->player_x] != 'E')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->mlx_display, so_long->player_ptr, so_long->player_x * 30, so_long->player_y * 30);
	
	return (0);
}
