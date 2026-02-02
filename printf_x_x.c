/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:30:24 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/02 16:12:31 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_word(unsigned int numb)
{
	int		size;

	size = 0;
	if (numb == 0)
		return (1);
	while(numb)
	{
		numb = numb / 16;
		size++;
	}
	return (size);
}

static void	fill_word(int size, char *word, unsigned int numb, char *str)
{
	if (numb == 0)
		word[0] = str[(numb % 16)];
	while (numb > 0)
	{
		word[--size] = str[(numb % 16)];
		numb = numb / 16;
	}
}

static	char *unsigned_hexadecimal(unsigned int number, char *str)
{
	char	*word;
	int		size;

	size = 0;
	size = size_word(number);
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	word[size] = '\0';
	fill_word(size, word, number, str);
	return (word);
}




void	hexadecimal(va_list arguments, char c)
{
	char	*str;
	char	*word;
	unsigned int	number;
	
	number = va_arg(arguments, unsigned int);
	if (c == 'x')
	{
		str = "0123456789abcdef";
		word = unsigned_hexadecimal(number, str);
	}
	else 
	{
		str = "0123456789ABCDEF";
		word = unsigned_hexadecimal(number, str);
	}
	if(str)
	{
		ft_putstr_fd(word, 1);
		free(word);
	}
}

