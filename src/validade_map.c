/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:40:28 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/23 15:12:48 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int ft_check_components(t_struct *so_long)//contagem de linhas incorrerta
{
    int x;
    int y;

    y = 0;
    while (so_long->map[y])
    {
        // printf("Linha Y:%d\n", y);
        x = 0;
        while (so_long->map[y][x])
        {
            // printf("coluna:%d \n", x);
            // printf("char:%c\n", so_long->map[y][x]);
            if (so_long->map[y][x] != '1' &&
                so_long->map[y][x] != 'E' &&
                so_long->map[y][x] != 'C' &&
                so_long->map[y][x] != '0' &&
                so_long->map[y][x] != 'P' &&
                so_long->map[y][x] != '\n')
                {
                    write(1, "A Component inside the Map is invalid!\n", 39);
                    return (0);
                }
            x++;
        }
        y++;
    }
    return (1);
}


