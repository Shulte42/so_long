/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:49 by shulte            #+#    #+#             */
/*   Updated: 2024/10/23 15:07:12 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

#define WEIGHT  400
#define HEIGHT  400

int	ft_copy_map(t_struct *so_long, char *fd)
{
	int	i;

	i = 0;
	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->map = malloc(sizeof(char *) * (so_long->map_height + 1));
	so_long->map_copy = malloc(sizeof(char *) * (so_long->map_height + 1));
	if (!so_long->map || !so_long->map_copy)
	{
		write(1, "Fail Allocate Memory for the Map!\n", 35);
		return (0);
	}
	while (i < so_long->map_height)
	{
		so_long->map[i] = ft_get_next_line(so_long->fd);
		so_long->map_copy[i] = so_long->map[i];
		i++; 
	}
	so_long->map[i] = NULL;
	so_long->map_copy[i] = NULL;
	close(so_long->fd);
	return (1);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_retangle(t_struct *so_long, char *fd)
{
	char	*line;

	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->map_height = 0;
	line = ft_get_next_line(so_long->fd);
	if (!line)
		return (0);
	so_long->map_weidth = ft_strlen_gnl(line);
	while (line)
	{
		if (ft_strlen_gnl(line) != so_long->map_weidth)
		{
			free(line);
			close(so_long->fd);
			write(1, "Map not Allowed!\n", 17);
			return (0);
		}
		free(line);
		line = ft_get_next_line(so_long->fd);
		so_long->map_height++;
	}
	free(line);
	close(so_long->fd);
	return (1);
}

void	*ft_memset(void *ptr, int ch, size_t n)
{
	size_t		i;
	char	*str;

	str = (char	*)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}

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
	ft_memset(&so_long, 0, (sizeof(so_long)));
	if (!ft_check_retangle(&so_long, argv[1]) ||
		!ft_copy_map(&so_long, argv[1]) ||
		!ft_check_components(&so_long))
		return (0);
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