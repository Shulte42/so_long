/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shulte <shulte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/10/28 16:03:04 by shulte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_keypress(int keycode, t_struct *so_long)
{
    printf("The %d has been pressed \n\n", keycode);
    if (keycode == 65307)
    {
        ft_free_maps(so_long);
        mlx_destroy_window(so_long->mlx_ptr, so_long->mlx_display);
	    mlx_destroy_display(so_long->mlx_ptr);
	    free (so_long->mlx_ptr);
        exit (EXIT_SUCCESS);   
    }
    return (0);
}