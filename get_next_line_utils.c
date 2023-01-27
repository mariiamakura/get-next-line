/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:24:57 by mparasku          #+#    #+#             */
/*   Updated: 2023/01/27 19:04:12 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
