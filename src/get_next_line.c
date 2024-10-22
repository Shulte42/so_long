/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruda-si <bruda-si@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:18 by bruda-si          #+#    #+#             */
/*   Updated: 2024/10/22 13:59:50 by bruda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_nlcut(char *new_line)
{
	int	i;

	i = 0;
	while (new_line[i])
	{
		if (new_line[i++] == '\n')
		{
			new_line[i] = '\0';
			break ;
		}
	}
	return (new_line);
}

int	ft_nlhandle(char *buffer)
{
	int	i;
	int	k;
	int	nl;

	i = 0;
	k = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[k++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return (nl);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		k;

	i = 0;
	k = 0;
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		s3[i++] = s2[k++];
	}
	s3[i] = '\0';
	free(s1);
	return (ft_nlcut(s3));
}

char	*ft_get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*new_line;
	int			bytes;

	bytes = 0;
	new_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		while (buffer[bytes])
			buffer[bytes] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		new_line = ft_strjoin(new_line, buffer);
		if (ft_nlhandle(buffer) == 1)
			break ;
	}
	return (new_line);
}