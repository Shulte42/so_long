/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:49 by shulte            #+#    #+#             */
/*   Updated: 2024/10/31 16:40:50 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_struct	sl;

	ft_arg_checker(argc, argv);
	ft_memset(&sl, 0, (sizeof(sl)));
	ft_check_retangle(&sl, argv[1]);
	if (ft_copy_map(&sl, argv[1]) || ft_full_check(&sl))
	{
		ft_free_maps(&sl);
		return (1);
	}
	sl.mlx_ptr = mlx_init();
	if (!sl.mlx_ptr)
		return (1);
	sl.mlx_win = MNW(sl.mlx_ptr, (sl.width) * 30, (sl.height) * 30, "so_long");
	if (!sl.mlx_win)
	{
		mlx_destroy_display(sl.mlx_ptr);
		free (sl.mlx_ptr);
		return (1);
	}
	ft_set_images_pointers(&sl);
	ft_place_assets(&sl);
	mlx_hook(sl.mlx_win, KeyRelease, KeyReleaseMask, ft_keypress, &sl);
	mlx_loop(sl.mlx_ptr);
	return (0);
}
