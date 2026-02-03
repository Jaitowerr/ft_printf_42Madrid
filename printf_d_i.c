/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:39:25 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/02 15:22:42 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_word(long numb)
{
	int	size;

	size = 0;
	while (numb > 9)
	{
		numb = numb / 10;
		size++;
	}
	if (numb >= 0 && numb <= 9)
		size++;
	return (size);
}

static void	fill_word(int size, char *word, int sig, long numb)
{
	int	i;

	i = 0;
	if (sig < 0)
		word[i++] = '-';
	while (numb > 9)
	{
		word[--size] = (numb % 10) + '0';
		numb = numb / 10;
	}
	if (numb >= 0 && numb <= 9)
		word[--size] = numb + '0';
}

static char	*ft_itoa(int n)
{
	char	*word;
	long	numb;
	int		size;
	int		sig;

	sig = 0;
	numb = n;
	size = 0;
	if (numb < 0)
	{
		sig = -1;
		numb = -numb;
		size = size_word(numb) + 1;
	}
	else
		size = size_word(numb);
	word = malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	word[size] = '\0';
	fill_word(size, word, sig, numb);
	return (word);
}

void	free_word(va_list arguments)
{
	char	*str;

	str = ft_itoa(va_arg(arguments, int));
	ft_putstr_fd(str, 1);
	free (str);		
}