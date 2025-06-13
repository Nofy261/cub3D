/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:58:18 by nolecler          #+#    #+#             */
/*   Updated: 2025/06/11 19:35:24 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strjoinfree(char *stash, char *buffer)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	result = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (stash[i])
		result[k++] = stash[i++];
	j = 0;
	while (buffer[j])
		result[k++] = buffer[j++];
	result[k] = '\0';
	free(stash);
	return (result);
}

static char	*read_line(char *stash, int fd)
{
	int		bytes_read;
	char	*buffer;

	if (stash == NULL)
		stash = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && stash[0] == 0))
		{
			free (stash);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoinfree(stash, buffer);
		free (buffer);
	}
	buffer = NULL;
	return (stash);
}

static char	*extract_line(char *stash)
{
	int		i;
	char	*result;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	result = ft_substr(stash, 0, i);
	return (result);
}

static char	*rest_of_line(char *stash)
{
	int		i;
	char	*result;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	result = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(stash, fd);
	line = extract_line(stash);
	stash = rest_of_line(stash);
	if (stash && stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
