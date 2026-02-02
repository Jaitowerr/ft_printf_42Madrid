/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:17:38 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/02 14:04:22 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// ft_printf(%c %s, 'a' , "hola");

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static size_t	ft_strlen_local(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = ft_strlen_local(s);
	write(fd, s, i);
}