/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:30:35 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/03 19:20:08 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen_local(const char *string)
{
	size_t	length;

	length = 0;
	while (string[length] != '\0')
		length++;
	return (length);
}

static int	size_word(unsigned long numb)
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

static void	fill_word(int size, char *word, unsigned long numb, char *str)
{
	if (numb == 0)
		word[0] = str[(numb % 16)];
	while (numb > 0)
	{
		word[--size] = str[(numb % 16)];
		numb = numb / 16;
	}
}

static	char *unsigned_hexadecimal(unsigned long number, char *str)
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

int	pointer_address(va_list arguments)
{
	char			*str;
	char			*word;
	unsigned long	ptr;
	long			len;
	
	len = 10;
	ptr = (unsigned long)va_arg(arguments, void *);
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	str = "0123456789abcdef";
	word = unsigned_hexadecimal(ptr, str);
	if(word)
	{
		ft_putstr_fd(word, 1);
		len = ft_strlen_local(word) + 2;
		free(word);
	}
	return (len + 2);
}
