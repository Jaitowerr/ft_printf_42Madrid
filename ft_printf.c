/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:18:11 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/03 19:33:31 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//20/16 1 %= 4-> e

static	int	classification(char const *s, size_t i, va_list arguments, long *count)
{
	if (s[++i] == 'c')
		return (ft_putchar_fd(va_arg(arguments, int), 1));		
	else if (s[++i] == 's')
		return (ft_putstr_fd(va_arg(arguments, char *), 1));		
	else if (s[++i] == 'p')
		return (pointer_address(arguments));
	else if (s[++i] == 'd' || s[++i] == 'i')
		return (free_word(arguments));		
	else if (s[++i] == 'u')
		return (free_word_positive(arguments));
	else if (s[++i] == 'x' || s[++i] == 'X')
		return (hexadecimal(arguments, s[++i]));
	else if (s[++i] == '%')
		ft_putstr_fd('%', 1);
	else if (s[++i] == '\0')
		return (-1);
}

int	ft_printf(char const *s, ...)
{
	size_t		i;
	long		*count;
	va_list		arguments;

	va_start(arguments, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			count += write (1, &s[i], 1);
			count++;
		}
		else
		{
			count += classification(s, i, arguments, count);	
			i++;
		}
		i++;
	}
	va_end(arguments);
	return (count);
}


