/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:49 by shulte            #+#    #+#             */
/*   Updated: 2024/10/30 15:59:12 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	ft_copy_map(t_struct *so_long, char *fd)
{
	int		i;
	char	*map_copy_ptr;

	i = 0;
	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->map = malloc(sizeof(char *) * (so_long->height + 1));
	so_long->map_copy = malloc(sizeof(char *) * (so_long->height + 1));
	if (!so_long->map || !so_long->map_copy)
	{
		ft_print_string("Fail Allocate Memory for the Map!\n");
		return (true);
	}
	while (i < so_long->height)
	{
		so_long->map[i] = ft_get_next_line(so_long->fd);
		map_copy_ptr = ft_strdup(so_long->map[i]);
		so_long->map_copy[i] = map_copy_ptr;
		i++;
	}
	so_long->map[i] = NULL;
	so_long->map_copy[i] = NULL;
	close(so_long->fd);
	return (false);
}

void	ft_check_retangle(t_struct *so_long, char *fd)
{
	char	*line;

	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->height = 0;
	line = ft_get_next_line(so_long->fd);
	if (!line)
		exit(EXIT_FAILURE);
	so_long->width = ft_strlen_gnl(line);
	while (line)
	{
		if (ft_strlen_gnl(line) != so_long->width)
		{
			free(line);
			close(so_long->fd);
			ft_print_string("Map not Allowed!\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		line = ft_get_next_line(so_long->fd);
		so_long->height++;
	}
	free(line);
	close(so_long->fd);
}

void	ft_arg_checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		ft_print_string("Invalid Arguments!\n");
		exit(0);
	}
	while (argv[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".ber"))
	{
		ft_print_string("Wrong Format File!\n");
		exit(0);
	}
}

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
