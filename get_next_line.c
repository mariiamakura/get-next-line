/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:46:37 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/30 18:43:38 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}

char	*check_remainder(char *remainder, char **line)
{
	char *pointer_n;
	
	pointer_n = NULL;
	if (remainder)
	{
		if (pointer_n = ft_strchr(remainder, '\n'))
		{
			pointer_n = '\0';
			*line = ft_strdup(remainder);
			pointer_n++;
			ft_strcpy(remainder, pointer_n);
		}
		else
		{
			*line = ft_strdup(remainder);
			ft_strclr(remainder);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (pointer_n);
}

char *get_next_line(int fd)
{
	char buf[1024];
	char *line;
	int	byte_was_read; //how many bytes read() could manage
	char	*pointer_n; //pointer to '\n' and everything that is after it 
	static char	*remainder; //for what's left after we meet '\n' if buf is larger than 1 string
	char	*tmp;
	
	remainder = NULL;
	pointer_n = check_remainder(remainder, &line);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(0);
	while (!pointer_n && (byte_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_was_read] = '\0';
		if (pointer_n = ft_strchr(buf, '\n'))
		{
			*pointer_n = '\0';
			pointer_n++;
			remainder = ft_strdup(pointer_n);
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	return(line);
}


int main()
{
	char *error;
	int fd = open("test.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
 	printf("%s\n", get_next_line(fd));
	/* printf("%s\n", get_next_line(fd));
	close(fd);  
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));  */
} 