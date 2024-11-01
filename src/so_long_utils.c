/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:56:38 by bruda-si          #+#    #+#             */
/*   Updated: 2024/11/01 13:15:55 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	write(1, "\n", 1);
	return (count);
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

void	*ft_memset(void *ptr, int ch, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)ptr;
	i = 0;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (str);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}
