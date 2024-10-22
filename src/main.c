/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:49 by shulte            #+#    #+#             */
/*   Updated: 2024/10/21 16:25:08 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define WEIGHT  400
#define HEIGHT  400

bool	ft_strcmp(char	*file, char	*format)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] != format[i])
			return (true);
		i++;
	}
	return (false);
}

void    ft_arg_checker(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Invalid Arguments!\n", 19);
		exit(0);
	}
	while (argv[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".ber"))
	{
		write(1, "Wrong Format File!\n", 19);
		exit(0);
	}
}

// void    on_keypress(int   keysym, t_struct so_long)
// {
	
// }

int  main(int argc, char **argv)
{
	t_struct    so_long;

	ft_arg_checker(argc, argv);
	so_long.mlx_ptr = mlx_init();
	if (!so_long.mlx_ptr)
		return (1);
	so_long.mlx_display = mlx_new_window(so_long.mlx_ptr, HEIGHT, WEIGHT, "so_long");
	if (!so_long.mlx_display)
	{
		mlx_destroy_display(so_long.mlx_ptr);
		free (so_long.mlx_ptr);
		return (1);
	}
	// mlx_hook(so_long.mlx_ptr, KeyRelease, KeyReleaseMask, on_keypress, &so_long);
	mlx_loop(so_long.mlx_ptr);
	mlx_destroy_window(so_long.mlx_ptr, so_long.mlx_display);
	mlx_destroy_display(so_long.mlx_ptr);
	free (so_long.mlx_ptr);
	return (0);
}