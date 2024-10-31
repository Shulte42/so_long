/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:58 by shulte            #+#    #+#             */
/*   Updated: 2024/10/31 17:35:48 by shulte           ###   ########.fr       */
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
# define FLOOR "./assets/ocean_floor.xpm"
# define PLAYER "./assets/player_ocean.xpm"
# define WALLS "./assets/walls.xpm"
# define COLLEC "./assets/collectable.xpm"
# define EXIT "./assets/exit.xpm"
# define PIW mlx_put_image_to_window
# define XFTI mlx_xpm_file_to_image
# define MNW mlx_new_window

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

typedef struct g_struct
{
	void	*mlx_win;
	void	*mlx_ptr;

	void	*floor_ptr;
	void	*pl_ptr;
	void	*walls_ptr;
	void	*collec_ptr;
	void	*exit_ptr;

	char	**map;
	char	**map_copy;
	char	*line;

	int		fd;
	int		height;
	int		width;
	int		pl_x;
	int		pl_y;
	int		player;
	int		steps;
	int		flood_player;
	int		collectables;
	int		c_collected;
	int		flood_collectables;
	int		exit;
	int		flood_exit;

}	t_struct;

//key_handling
int		ft_keypress(int keysym, t_struct *so_long);
//Validade_map
bool	ft_check_components(t_struct *so_long);
bool	ft_check_player(t_struct *so_long);
bool	ft_check_collectables(t_struct	*so_long);
bool	ft_check_exit(t_struct *so_long);
bool	ft_check_walls(t_struct *so_long);

//Validade map 2
bool	ft_copy_map(t_struct *so_long, char *fd);
void	ft_check_retangle(t_struct *so_long, char *fd);
void	ft_arg_checker(int argc, char **argv);

//Map_construct
int		ft_flood_fill(t_struct *so_long, int y, int x);
void	ft_set_images_pointers(t_struct *so_long);
void	ft_place_assets(t_struct *so_long);
bool	ft_full_check(t_struct *so_long);
//So_long_utils
void	ft_free_maps(t_struct *game);
int		ft_print_string(char *str);
bool	ft_strcmp(char	*file, char	*format);
void	*ft_memset(void *ptr, int ch, size_t n);
int		ft_strlen_gnl(char *str);
//Get_next_line
char	*ft_get_next_line(int fd);

#endif