/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:18:11 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/02 16:08:45 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//20/16 1 %= 4-> e

static	int	classification(char const *s, size_t i, va_list arguments)
{
	i++;
		
	if (s[i] == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1);		
	else if (s[i] == 's')
		ft_putstr_fd(va_arg(arguments, char *), 1);		
	else if (s[i] == 'p')
		return (0);		
	else if (s[i] == 'd' || s[i] == 'i')
		free_word(arguments);		
	else if (s[i] == 'u')
		free_word_positive(arguments);		
	else if (s[i] == 'x' || s[i] == 'X')
		hexadecimal(arguments, s[i]);
	else if (s[i] == '%')
		return (0);		
	
	return (i);
}

int	ft_printf(char const *s, ...)
{
	size_t		i;
	size_t		i_argv;
	va_list		arguments;

	va_start(arguments, s);
	i_argv = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			write (1, &s[i], 1);
		else
		{
			classification(s, i, arguments);	
			i++;
		}
		i++;
	}
	va_end(arguments);
	return (0);
}


