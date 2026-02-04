/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:18:11 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/04 01:27:55 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	classification(char s, va_list arguments)
{
	if (s == 'c')
		return (ft_putchar_fd(va_arg(arguments, int), 1));
	else if (s == 's')
		return (ft_putstr_fd(va_arg(arguments, char *), 1));
	else if (s == 'p')
		return (ft_pointer_address(arguments));
	else if (s == 'd' || s == 'i')
		return (ft_free_word(arguments));
	else if (s == 'u')
		return (ft_free_word_positive(arguments));
	else if (s == 'x' || s == 'X')
		return (ft_hexadecimal(arguments, s));
	else if (s == '%')
		return (write(1, "%", 1));
	// else if (s == '\0')
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list		arguments;
	int			i;
	int			count;

	va_start(arguments, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
			count += write (1, &s[i], 1);
		else
			count += classification(s[++i], arguments);
		i++;
	}
	va_end(arguments);
	return (count);
}


