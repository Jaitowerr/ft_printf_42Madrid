/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorres <aitorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 23:48:33 by aitorres          #+#    #+#             */
/*   Updated: 2026/02/03 23:58:07 by aitorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//test para printf_c_s.c


#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;

	printf("--- TEST C y S ---\n");
	ret = ft_putchar_fd('A', 1);
	printf("\nRetorno putchar: %d (Debe ser 1)\n", ret);

	ret = ft_putstr_fd("Hola 42", 1);
	printf("\nRetorno putstr: %d (Debe ser 7)\n", ret);
	
	ret = ft_putstr_fd("", 1);
	printf("\nRetorno putstr vacío: %d (Debe ser 0)\n", ret);
	return (0);
}


//cc -Wall -Wextra -Werror main.c ft_printf.c printf_c_s.c printf_d_i.c printf_p.c printf_u.c printf_x_x.c -o test_printf && ./test_printf


//test para printf_d_i.c
/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// Simulamos el va_list para probar la función free_word
// Si no quieres líos con va_list, prueba ft_itoa directamente:
int main(void)
{
	printf("--- TEST D e I ---\n");
	// Nota: Como free_word necesita va_list, probamos la lógica interna
	// Si ya tienes ft_printf.c listo, usa el main general anterior.
	// Si no, aquí probamos los casos críticos:
	ft_printf("Cero: %d\n", 0);
	ft_printf("Negativo: %d\n", -123);
	ft_printf("Max Int: %d\n", INT_MAX);
	ft_printf("Min Int: %d\n", INT_MIN);
	return (0);
}
*/

//cc -Wall -Wextra -Werror main.c ft_printf.c printf_c_s.c printf_d_i.c printf_p.c printf_u.c printf_x_x.c -o test_printf && ./test_printf


//Test para print_p.c

/*
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int a = 42;
	int ret_mio, ret_real;

	printf("--- TEST P (Punteros) ---\n");
	
	printf("Mio:  ");
	ret_mio = ft_printf("%p", &a);
	printf("\nReal: ");
	ret_real = printf("%p", &a);
	printf("\nRetornos -> Mio: %d | Real: %d\n\n", ret_mio, ret_real);

	printf("NULL Mio:  ");
	ret_mio = ft_printf("%p", NULL);
	printf("\nNULL Real: ");
	ret_real = printf("%p", NULL);
	printf("\nRetornos -> Mio: %d | Real: %d\n", ret_mio, ret_real);

	return (0);
}
*/
/*
int	main(void)
{
	void	*ptr1 = (void *)0x7ffeefbff618;
	void	*ptr2 = NULL;
	int		a = 42;
	void	*ptr3 = &a;
	int		res_ft;
	int		res_std;

	
	printf("--- TEST 1: Puntero normal ---\n");
	res_ft = ft_printf("FT : %p\n", ptr1);
	res_std = printf("STD: %p\n", ptr1);
	printf("Retorno -> FT: %d | STD: %d\n\n", res_ft, res_std);

	printf("--- TEST 2: Puntero NULL ---\n");
	res_ft = ft_printf("FT : %p\n", ptr2);
	res_std = printf("STD: %p\n", ptr2);
	printf("Retorno -> FT: %d | STD: %d\n\n", res_ft, res_std);

	printf("--- TEST 3: Dirección de una variable local ---\n");
	res_ft = ft_printf("FT : %p\n", ptr3);
	res_std = printf("STD: %p\n", ptr3);
	printf("Retorno -> FT: %d | STD: %d\n\n", res_ft, res_std);

	printf("--- TEST 4: Varios punteros seguidos ---\n");
	res_ft = ft_printf("FT : %p %p\n", ptr1, ptr3);
	res_std = printf("STD: %p %p\n", ptr1, ptr3);
	printf("Retorno -> FT: %d | STD: %d\n", res_ft, res_std);

	return (0);
}
*/

//cc -Wall -Wextra -Werror main.c ft_printf.c printf_c_s.c printf_d_i.c printf_p.c printf_u.c printf_x_x.c -o test_printf && ./test_printf

//Test para printf_x_x.c

/*
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("--- TEST x y X ---\n");
	ft_printf("Minus: %x (debe ser ff)\n", 255);
	ft_printf("Mayus: %X (debe ser FF)\n", 255);
	ft_printf("Cero:  %x\n", 0);
	ft_printf("Grande: %x (debe ser 7fffffff)\n", 2147483647);
	return (0);
}
*/

//cc -Wall -Wextra -Werror main.c ft_printf.c printf_c_s.c printf_d_i.c printf_p.c printf_u.c printf_x_x.c -o test_printf && ./test_printf

//Test para printf_u.c

/*
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("--- TEST U (Unsigned) ---\n");
	ft_printf("Mio (Max Unsigned): %u\n", 4294967295U);
	printf("Real (Max Unsigned): %u\n", 4294967295U);
	
	// Prueba pasarle un negativo a ver si lo convierte a positivo grande
	ft_printf("Mio (Pasando -1): %u\n", -1);
	printf("Real (Pasando -1): %u\n", -1);
	return (0);
}
*/

//cc -Wall -Wextra -Werror main.c ft_printf.c printf_c_s.c printf_d_i.c printf_p.c printf_u.c printf_x_x.c -o test_printf && ./test_printf














/*
#include <stdio.h>


// cc main.c ft_printf.c printf_c_s.c printf_d_i.c printf_u.c printf_p.c printf_x_x.c -o  prueba && ./prueba

*/