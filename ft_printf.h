/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:45:13 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/03 19:33:11 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>	//para los va_
# include <stdint.h>
# include <stdio.h>		//comentar
# include <limits.h>	//comentar

// #include <stdarg.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <stddef.h>
// #include <limits.h>

int		ft_printf(char const *s, ...);
// void	ft_putendl_fd(char *s, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
// char	*ft_itoa(int n);
void	free_word(va_list arguments);
int		free_word_positive(va_list arguments);
void	hexadecimal(va_list arguments, char c);
int		pointer_address(va_list arguments);

#endif