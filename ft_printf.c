/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:18:11 by aitorres          #+#    #+#             */
/*   Updated: 2026/01/30 19:18:11 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_printf(char const *s, ...)
int	ft_printf(char const *string)
{
	if (!string)
	{
		ft_putendl_fd("0", 1); // Usamos "0" como string
		return (0);
	}
	ft_putendl_fd((char *)string, 1);
	return (0); 
}

int main(void)
{
	char	*s = "hola";

	ft_printf(s);

	return (0);
}
