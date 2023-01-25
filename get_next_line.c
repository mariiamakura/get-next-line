/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:53 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/25 18:55:14 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
    static char *buf;
	int i;
	int res;
	
	i = 0;
	res = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (BUFFER_SIZE > 0 || res > 0)
	{
		while (!(ft_strchr(buf, '\n')) == 1)
		{
			read(fd, buf, 1);
			printf ("%s", buf);
			i++;
		}
	BUFFER_SIZE =-1
	free(buf);
}

int main(/*int argc, char* argv[]*/)
{
	/* for files */
	/* int fd = open(argv[1], O_RDWR);*/
    int fd = open("test.txt", O_RDWR);
    /* printf ("%i\n", fd); */
	get_next_line(fd);

	/* for std inputs */
	/*if (argc == 2)
		get_next_line(0);
	else 
		printf("Error");*/
	close(fd);
}