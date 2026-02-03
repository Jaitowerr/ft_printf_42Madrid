

# ft_printf_42Madrid
Función que replica la función original de printf

l prototipo de ft_printf() es:
int ft_printf(char const *, ...);
Estos son los requisitos:
• No se debe implementar la gestión del ‘buffer’ del printf() original.
• Se deben implementar las siguientes conversiones: cspdiuxX %
• La función se comparará con el printf() original para verificar su comportamiento.
• Hay que usar el comando ar para crear la librería.
El uso de libtool está prohibido.
• El archivo libftprintf.a deberá ser creado en la raíz de tu repositorio.
8
ft_printf Porque ft_putnbr() y ft_putstr() no son suficientes
Se deben implementar las siguientes conversiones:
• %c para imprimir un solo carácter.
• %s para imprimir una cadena de caracteres (como se define por defecto en C).
• %p el puntero void * dado como argumento se imprime en formato hexadecimal.
• %d para imprimir un número decimal (base 10).
• %i para imprimir un entero en base 10.
• %u para imprimir un número decimal (base 10) sin signo.
• %x para imprimir un número hexadecimal (base 16) en minúsculas.
• %X para imprimir un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.
