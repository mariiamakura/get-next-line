/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:53 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/27 19:19:25 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int print_lines(char *str, int new_line) //
{
	int	n_count;
	int	i;
	
	n_count = 0;
	i = 0;

	while (str[i])
	{
		if (n_count == new_line)
		{
			ft_putchar(str[i]);
			if (str[i] == '\n')
			{
				return(1);
				break;
			}
			i++;
		}
		else
		{
			if (str[i] == '\n')
			{
				n_count++;
			}
			i++;
		}
	}
}


char *get_next_line(int fd)
{

	char *buf;
	int i;
	int res_read; //counting N-bytes that were read. If 0 - nothing left to read
	static int new_line;

	res_read = 1;
	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(256 * sizeof(char)); // buf is fixed to 256
    if (!buf)
        return (NULL);
	while (res_read > 0)
	{
		res_read = read(fd, buf, BUFFER_SIZE); //ТУТ доработать, чтобы при повторном вызове функции печаталась часть: которая осталась в буфере
		/* printf("res_read: %i\n", res_read);
		printf("static: %i\n", new_line); */
		new_line += print_lines(buf, new_line);
	}
}

int main(/*int argc, char* argv[]*/)
{
	char *error;
	/* for files */
	/* int fd = open(argv[1], O_RDWR);*/
	int fd = open("test.txt", O_RDWR);
	/* printf ("%i\n", fd); */
	error = get_next_line(fd);
	printf("New call ------------------------------------------------------\n");
	error = get_next_line(fd);
	

	/* for std inputs */
	/*if (argc == 2)
		get_next_line(0);
	else
		printf("Error");*/
	/* close(fd); */
}