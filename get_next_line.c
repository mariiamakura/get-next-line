/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:03:28 by mparasku          #+#    #+#             */
/*   Updated: 2023/02/02 17:21:12 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (0);
}

char	*remove_line(char *buf_start)
{
	int		i;
	int		j;
	char	*new_buf;

	i = 0;
	j = 0;
	if (!buf_start)
		return (0);
	while (buf_start[i] && buf_start[i] != '\n')
		i++;
	if (buf_start[i] == '\0')
		return (ft_free(buf_start));
	if (buf_start[i] == '\n')
		i++;
	new_buf = (char *)malloc((ft_strlen(buf_start) - i + 1) * sizeof(char));
	if (!new_buf)
		return (0);
	while (buf_start[i + j])
	{
		new_buf[j] = buf_start[i + j];
		j++;
	}
	new_buf[j] = '\0';
	free (buf_start);
	return (new_buf);
}

char	*read_line(char *buf_start)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf_start || !buf_start[0])
		return (0);
	while (buf_start[i] && buf_start[i] != '\n')
		i++;
	if (buf_start[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (buf_start[i] && buf_start[i] != '\n')
	{
		line[i] = buf_start[i];
		i++;
	}
	if (buf_start[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	int			fd_read;
	static char	*buf_start;

	fd_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (0);
	while (!(ft_strchr(buf_start, '\n')) && fd_read != 0)
	{
		fd_read = read(fd, temp, BUFFER_SIZE);
		if (fd_read < 0)
			return (ft_free(temp));
		temp[fd_read] = '\0';
		buf_start = ft_strjoin(buf_start, temp);
	}
	free(temp);
	temp = read_line(buf_start);
	buf_start = remove_line(buf_start);
	return (temp);
}

/* int main()
{
	int	fd;
	char *str;
	
	fd = open("test.txt", O_RDWR);
	str = get_next_line(fd);
	printf("%s", str);

	free (str);
	close (fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
 */
/* to see leaks
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out */ 