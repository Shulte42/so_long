/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:45:49 by shulte            #+#    #+#             */
/*   Updated: 2024/10/30 10:07:18 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	ft_copy_map(t_struct *so_long, char *fd)
{
	int	i;
	char *map_copy_ptr;

	i = 0;
	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->map = malloc(sizeof(char *) * (so_long->map_height + 1));
	so_long->map_copy = malloc(sizeof(char *) * ( so_long->map_height + 1));
	if (!so_long->map || !so_long->map_copy)
	{
		ft_print_string("Fail Allocate Memory for the Map!\n");
		return (true);
	}
	while (i < so_long->map_height)
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

bool	ft_check_retangle(t_struct *so_long, char *fd)
{
	char	*line;

	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->map_height = 0;
	line = ft_get_next_line(so_long->fd);
	if (!line)
		return (true);
	so_long->map_weidth = ft_strlen_gnl(line);
	while (line)
	{
		if (ft_strlen_gnl(line) != so_long->map_weidth)
		{
			free(line);
			close(so_long->fd);
			ft_print_string("Map not Allowed!\n");
			return (true);
		}
		free(line);
		line = ft_get_next_line(so_long->fd);
		so_long->map_height++;
	}
	free(line);
	close(so_long->fd);
	return (false);
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
void	ft_free_maps(t_struct *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[i] && so_long->map_copy[i])
	{
		free(so_long->map[i]);
		free(so_long->map_copy[i]);
		i++;
	}
	free(so_long->map);
	free(so_long->map_copy);
}

int	ft_print_string(char *str)
{
	int	count;

	count = 0;
	write(1, "Error!\n", 7);
	if (str == NULL)
		str = "(null)";
	while (*str)
		count += write(1, str++, 1);
	return (count);
} 

int  main(int argc, char **argv)
{
	t_struct    so_long;

	ft_arg_checker(argc, argv);
	ft_memset(&so_long, 0, (sizeof(so_long)));
	if (ft_check_retangle(&so_long, argv[1]) ||
		ft_copy_map(&so_long, argv[1]) ||
		ft_full_check(&so_long))
		{
			ft_free_maps(&so_long);
			return (1);
		}
	so_long.mlx_ptr = mlx_init();
	if (!so_long.mlx_ptr)
		return (1);
	so_long.mlx_display = mlx_new_window(so_long.mlx_ptr, (so_long.map_weidth) * 30, (so_long.map_height) * 30, "so_long");
	if (!so_long.mlx_display)
	{
		mlx_destroy_display(so_long.mlx_ptr);
		free (so_long.mlx_ptr);
		return (1);
	}
	ft_set_images_pointers(&so_long);
	ft_place_assets(&so_long);
	mlx_hook(so_long.mlx_display, KeyRelease, KeyReleaseMask, ft_keypress, &so_long);
	mlx_loop(so_long.mlx_ptr);
	return (0);
}
