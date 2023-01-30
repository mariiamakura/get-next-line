/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:46:37 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/30 16:42:29 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char buf[1024];
	char *line;
	int	byte_was_read; //how many bytes read() could manage
	char	*pointer_n; //pointer to '\n' and everything that is after it 
	int	flag; //to break circle but complite it till the end
	static char	*remainder; //for what's left after we meet '\n' if buf is larger than 1 string

	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	if (remainder)
		line = ft_strdup(remainder);
	else
		line = ft_strnew(1);
	while (flag && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (byte_was_read <= 0)
			return (0);
		buf[byte_was_read] = '\0';
		if (pointer_n = ft_strchr(buf, '\n'))
		{
			*pointer_n = '\0';
			flag = 0;
			remainder = ft_strdup(pointer_n + 1);
		}
		line = ft_strjoin(line, buf);
	}
	return(line);
}


int main()
{
	char *error;
	int fd = open("test.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
/* 	close(fd); */
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}