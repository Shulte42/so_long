/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:54:58 by shulte            #+#    #+#             */
/*   Updated: 2024/10/23 13:01:02 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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
    
}   t_struct;

char	*ft_get_next_line(int fd);
int ft_check_components(t_struct *so_long);


#endif