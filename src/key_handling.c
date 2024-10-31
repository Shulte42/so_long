/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/10/31 17:41:33 by shulte           ###   ########.fr       */
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

void	ft_end_game_checkers(t_struct *so_long, int y, int x)
{
	if (so_long->map[so_long->pl_y][so_long->pl_x] == 'C')
	{
		so_long->map[so_long->pl_y][so_long->pl_x] = '0';
		so_long->c_collected++;
	}
	if (so_long->map[so_long->pl_y][so_long->pl_x] == 'E')
	{
		if (so_long->collectables == so_long->c_collected)
		{
			write(1, "You have became the King of Pirates!\n", 37);
			ft_destroy(so_long);
		}
	}
	if (so_long->pl_x != x || so_long->pl_y != y)
	{
		so_long->steps++;
		ft_print_step(so_long->steps);
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
	if (keysym == XK_w && sl->map[y - 1][x] != '1')
		sl->pl_y--;
	else if (keysym == XK_s && sl->map[y + 1][x] != '1')
		sl->pl_y++;
	else if (keysym == XK_a && sl->map[y][x - 1] != '1')
		sl->pl_x--;
	else if (keysym == XK_d && sl->map[y][x + 1] != '1')
		sl->pl_x++;
	else if (keysym == XK_Escape)
	{
		ft_destroy(sl);
		exit(EXIT_SUCCESS);
	}
	ft_end_game_checkers(sl, y, x);
	if (sl->map[sl->pl_y][sl->pl_x] != 'E')
		PIW(sl->mlx_ptr, sl->mlx_win, sl->pl_ptr, sl->pl_x * 30, sl->pl_y * 30);
	return (0);
}
