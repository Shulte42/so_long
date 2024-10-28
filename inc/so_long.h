/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:58 by shulte            #+#    #+#             */
/*   Updated: 2024/10/28 15:32:46 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define KEY_ESC 65307


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/inc/libft.h"
// # include "get_next_line.h"

typedef struct t_struct
{
	void    *mlx_display;
	void    *mlx_ptr;
	char    **map;
	char    **map_copy;
	int     fd;
	int     map_height;
	int     map_weidth;
	int     player_x;
	int     player_y;
	int		player;
	int		collectables;
	int		exit;
	
}   t_struct;

bool	ft_full_check(t_struct *so_long);
char	*ft_get_next_line(int fd);
bool	ft_check_components(t_struct *so_long);
bool	ft_check_player(t_struct *so_long);
bool	ft_check_collectables(t_struct	*so_long);
bool	ft_check_exit(t_struct *so_long);
int	ft_print_string(char *str);
void	ft_free_maps(t_struct *game);
bool	ft_check_walls(t_struct *so_long);
int ft_keypress(int keysym, t_struct *so_long);





#endif