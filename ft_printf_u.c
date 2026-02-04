/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:09:27 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/04 01:22:28 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_word(unsigned int numb)
{
	int		size;

	size = 0;
	if (numb == 0)
		return (1);
	while (numb)
	{
		numb = numb / 10;
		size++;
	}
	return (size);
}

static void	fill_word(int size, char *word, unsigned int numb)
{
	if (numb == 0)
		word[0] = '0';
	while (numb > 0)
	{
		word[--size] = (numb % 10) + '0';
		numb = numb / 10;
	}
}

static char	*unsigned_ft_itoa(unsigned int number)
{
	char	*word;
	int		size;

	size = 0;
	size = size_word(number);
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	word[size] = '\0';
	fill_word(size, word, number);
	return (word);
}

int	ft_free_word_positive(va_list arguments)
{
	char			*str;
	unsigned int	number;
	int				len;

	len = 0;
	number = va_arg(arguments, unsigned int);
	str = unsigned_ft_itoa(number);
	if (str)
	{
		len = ft_putstr_fd(str, 1);
		free(str);
	}
	return (len);
}
