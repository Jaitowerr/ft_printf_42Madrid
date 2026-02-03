#include "ft_printf.h"

// int main (void)
// {
	
// 	char	a = 'a';
// 	char	*b = "Jaitowerr";
// 	int		tel = 619789456;
	
// 	ft_printf("hola, nombre: %c y %s\n", 'A', "Jaitowerr");
// 	ft_printf("hola, nombre: %c y %s\n", a, b);

// 	ft_printf("hola, teléfono: %d y %i\n", tel, tel);
// 	ft_printf("");

// 	ft_printf("edad: %u", -30);

// 	return (0);
// }

// #include "ft_printf.h"
// #include <stdio.h>
// int main (void)
// {
// 	printf("%x", 200);
// }

// int main (void)
// {
//     unsigned int ui_max = 4294967295U;

//     printf("--- PRUEBAS DE %%u ---\n");

//     // Caso 1: Cero
//     ft_printf("Mio  (0): %u\n", 0);
//     printf("Real (0): %u\n", 0);
//     printf("\n");

//     // Caso 2: Máximo de un INT con signo (no debería haber problema)
//     ft_printf("Mio  (INT_MAX): %u\n", INT_MAX);
//     printf("Real (INT_MAX): %u\n", INT_MAX);
//     printf("\n");

//     // Caso 3: El número "mágico" (Justo uno más que INT_MAX)
//     // Aquí es donde ft_itoa fallaría pero unsigned_ft_itoa triunfa
//     ft_printf("Mio  (2147483648): %u\n", 2147483648U);
//     printf("Real (2147483648): %u\n", 2147483648U);
//     printf("\n");

//     // Caso 4: Máximo valor de un UNSIGNED INT (4.294.967.295)
//     ft_printf("Mio  (UINT_MAX): %u\n", ui_max);
//     printf("Real (UINT_MAX): %u\n", ui_max);
//     printf("\n");

//     // Caso 5: Pasar un número negativo
//     // Debe imprimir 4294967295 porque %u interpreta los bits como positivos
//     ft_printf("Mio  (-1): %u\n", -1);
//     printf("Real (-1): %u\n", -1);
//     printf("\n");

//     // Caso 6: El número que usaste antes
//     ft_printf("Mio  (30): %u\n", 30);
//     printf("Real (30): %u\n", 30);

//     return (0);
// }

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// int main (void)
// {
//     unsigned int n1 = 255;        // En hex es ff
//     unsigned int n2 = 4294967295; // En hex es ffffffff
//     unsigned int n3 = 0;          // En hex es 0

//     printf("--- PRUEBAS HEXADECIMAL ---\n\n");

//     // Caso 1: Un número pequeño que usa letras
//     ft_printf("Mio  (255 en x): %x\n", n1);
//     printf("Real (255 en x): %x\n", n1);
//     printf("\n");

//     // Caso 2: Mayúsculas
//     ft_printf("Mio  (255 en X): %X\n", n1);
//     printf("Real (255 en X): %X\n", n1);
//     printf("\n");

//     // Caso 3: El número cero
//     ft_printf("Mio  (0): %x\n", n3);
//     printf("Real (0): %x\n", n3);
//     printf("\n");

//     // Caso 4: El número máximo (UINT_MAX)
//     ft_printf("Mio  (Max): %x\n", n2);
//     printf("Real (Max): %x\n", n2);
//     printf("\n");

//     // Caso 5: Un número aleatorio grande para ver la mezcla de letras y números
//     unsigned int n4 = 123456789;
//     ft_printf("Mio  (123456789): %x\n", n4);
//     printf("Real (123456789): %x\n", n4);

//     return (0);
// }

// cc main.c ft_printf.c printf_c_s.c printf_d_i.c printf_u.c printf_x_x.c -o  prueba && ./prueba

#include <stdio.h>

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

// cc main.c ft_printf.c printf_c_s.c printf_d_i.c printf_u.c printf_p.c printf_x_x.c -o  prueba && ./prueba