/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:58 by shulte            #+#    #+#             */
/*   Updated: 2024/10/30 10:26:39 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define KEY_ESC 65307
# define WEIGHT  400
# define HEIGHT  400

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
	
	void	*floor_ptr;
	void	*player_ptr;
	void	*walls_ptr;
	void	*collectables_ptr;
	void	*exit_ptr;
	
	char    **map;
	char    **map_copy;
	
	int     fd;
	int     map_height;
	int     map_weidth;
	int     player_x;
	int     player_y;
	int		player;
	int		flood_player;
	int		collectables;
	int		flood_collectables;
	int		exit;
	int		flood_exit;
	
}   t_struct;

void    ft_set_images_pointers(t_struct *so_long);
void	ft_free_maps(t_struct *game);
bool	ft_full_check(t_struct *so_long);
bool	ft_check_components(t_struct *so_long);
bool	ft_check_player(t_struct *so_long);
bool	ft_check_collectables(t_struct	*so_long);
bool	ft_check_exit(t_struct *so_long);
bool	ft_check_walls(t_struct *so_long);
char	*ft_get_next_line(int fd);
int	ft_print_string(char *str);
int ft_keypress(int keysym, t_struct *so_long);
int	ft_flood_fill(t_struct *so_long, int y, int x);
void    ft_place_assets(t_struct *so_long);




#endif