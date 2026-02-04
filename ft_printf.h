/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 17:45:13 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/04 14:04:09 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>	//para los va_

int		ft_printf(char const *s, ...);
int		ft_free_word(va_list arguments);
int		ft_free_word_positive(va_list arguments);
int		ft_hexadecimal(va_list arguments, char c);
int		ft_pointer_address(va_list arguments);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_pointer_address(va_list arguments);

#endif