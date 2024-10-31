/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:40:05 by shulte            #+#    #+#             */
/*   Updated: 2024/10/31 16:48:19 by shulte           ###   ########.fr       */
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
	so_long->fd = open(fd, O_RDONLY, 0);
	so_long->height = 0;
	so_long->line = ft_get_next_line(so_long->fd);
	if (!so_long->line || so_long->line == NULL)
	{
		ft_print_string("Empty map!");
		exit(EXIT_FAILURE);
	}
	so_long->width = ft_strlen_gnl(so_long->line);
	while (so_long->line)
	{
		if (ft_strlen_gnl(so_long->line) != so_long->width)
		{
			free(so_long->line);
			close(so_long->fd);
			ft_print_string("Map not Allowed!\n");
			exit(EXIT_FAILURE);
		}
		free(so_long->line);
		so_long->line = ft_get_next_line(so_long->fd);
		so_long->height++;
	}
	free(so_long->line);
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
