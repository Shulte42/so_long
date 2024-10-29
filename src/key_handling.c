/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:13:29 by shulte            #+#    #+#             */
/*   Updated: 2024/10/29 09:43:39 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_keypress(int keysym, t_struct *so_long)
{
    printf("The %d has been pressed \n\n", keysym);
    if (keysym == XK_Escape)
    {
        ft_free_maps(so_long);
        mlx_destroy_window(so_long->mlx_ptr, so_long->mlx_display);
	    mlx_destroy_display(so_long->mlx_ptr);
	    free (so_long->mlx_ptr);
        exit (EXIT_SUCCESS);   
    }
    return (0);
}