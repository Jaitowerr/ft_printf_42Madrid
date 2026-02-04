/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:17:38 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/04 13:59:11 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

static size_t	ft_strlen_local(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6));
	i = ft_strlen_local(s);
	return (write(fd, s, i));
}
