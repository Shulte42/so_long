/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/11/01 15:12:21 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_destroy(t_struct *so_long)
{
	mlx_destroy_image(so_long->mlx_ptr, so_long->floor_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->walls_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->pl_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->collec_ptr);
	mlx_destroy_image(so_long->mlx_ptr, so_long->exit_ptr);
	ft_free_maps(so_long);
	mlx_destroy_window(so_long->mlx_ptr, so_long->mlx_win);
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

void	ft_end_game_checkers(t_struct *sl, int y, int x)
{
	if (sl->map[sl->pl_y][sl->pl_x] == 'C')
	{
		sl->map[sl->pl_y][sl->pl_x] = '0';
		sl->c_collected++;
	}
	if (sl->map[sl->pl_y][sl->pl_x] == 'E')
	{
		if (sl->collectables == sl->c_collected)
		{
			write(1, "You have became the King of Pirates!\n", 37);
			ft_destroy(sl);
		}
	}
	if (sl->pl_x != x || sl->pl_y != y)
	{
		sl->steps++;
		ft_print_step(sl->steps);
		write(1, "\n", 1);
	}
}

int	ft_keypress(int keysym, t_struct *sl)
{
	int	y;
	int	x;

	y = sl->pl_y;
	x = sl->pl_x;
	if (sl->map[y][x] != 'E')
		PIW(sl->mlx_ptr, sl->mlx_win, sl->floor_ptr, x * 30, y * 30);
	if (keysym == XK_w && ft_collision_check(sl, keysym))
		sl->pl_y--;
	else if (keysym == XK_s && ft_collision_check(sl, keysym))
		sl->pl_y++;
	else if (keysym == XK_a && ft_collision_check(sl, keysym))
		sl->pl_x--;
	else if (keysym == XK_d && ft_collision_check(sl, keysym))
		sl->pl_x++;
	else if (keysym == XK_Escape)
		ft_destroy(sl);
	ft_end_game_checkers(sl, y, x);
	if (sl->map[sl->pl_y][sl->pl_x] != 'E')
		PIW(sl->mlx_ptr, sl->mlx_win, sl->pl_ptr, sl->pl_x * 30, sl->pl_y * 30);
	return (0);
}
