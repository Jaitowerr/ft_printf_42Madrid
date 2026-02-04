*Este proyecto ha sido creado como parte del currículo de 42 por aitorres*

# 📝 Descripción
El proyecto **ft_printf** consiste en la recreación de la función `printf` de la biblioteca estándar de C (`stdio.h`). El objetivo principal es profundizar en el conocimiento de las **funciones variádicas** en C, el manejo de argumentos variables mediante macros y la conversión eficiente de diversos tipos de datos a formato de texto.

Así mismo, mejorar en el control de errores para el trabajo futuro y saber porque falla el código, porque se satura la ram, etc...

La función desarrollada es capaz de procesar una cadena de formato y un número indeterminado de argumentos, devolviendo el número total de caracteres impresos, tal como lo hace la función original.
<br><br><br>

       int ft_printf(char const *, ...)
<br>

### Conversiones implementadas
* `%c`: Un único carácter.
* `%s`: Una cadena de caracteres.
* `%p`: Una dirección de memoria en formato hexadecimal.
* `%d` e `%i`: Números enteros con signo.
* `%u`: Números decimales sin signo.
* `%x` / `%X`: Números hexadecimales en minúsculas y mayúsculas respectivamente.
* `%%`: Imprime el símbolo del porcentaje.

 
<br><br><br>
# 🛠️ Instrucciones


### <ins>Compilación<ins>
Para compilar la librería, navega a la raíz del proyecto y ejecuta el comando `make`.

El **Makefile** ha sido configurado para compilar los archivos fuente y generar la librería estática requerida:

Esto generará el archivo `libftprintf.a`. Puedes limpiar los archivos objetos con `make clean` o realizar una limpieza total (objetos y librería.a) con `make fclean`.

### <ins>Instalación y Ejecución<ins>
Para integrar ft_printf en tus propios programas:

Incluye el encabezado en tu código: #include "ft_printf.h".

Compila tu archivo fuente vinculando la librería estática generada:

<br>

    cc main.c libftprintf.a -o mi_programa &&./mi_programa
<br>


## 🧠 Algoritmo y Estructura de Datos

### <ins>Elección de la Estructura</ins>

Para este proyecto se ha optado por una estructura modular funcional.

Dado que el procesamiento del string es lineal y secuencial, no se ha requerido el uso de estructuras de datos complejas como árboles o listas enlazadas.

En su lugar, se utiliza la pila (stack) de memoria mediante la librería <stdarg.h> para gestionar los argumentos variables.

<br>

### <ins>Justificación del Algoritmo</ins>

El algoritmo implementado sigue una lógica de iteración simple con despacho de funciones:

  * Lectura Secuencial: Se recorre la cadena char *s carácter a carácter.

  * Detección de Flags: Al encontrar un %, el algoritmo detiene la impresión directa y llama a una función de clasificación.

  * Clasificación: Esta función identifica el especificador de formato y redirige el flujo hacia la función de conversión específica (ej. para hexadecimal, enteros, etc.).

  * Gestión de Retorno: Cada subfunción devuelve el número de caracteres escritos mediante llamadas a write, permitiendo que ft_printf mantenga un conteo acumulado preciso para su valor de retorno final.

<br><br><br>
# 📚 Recursos
Referencias:
* Man printf(3): Manual oficial de Linux para entender el comportamiento y los valores de retorno.
* ISO/IEC 9899: Estándar del lenguaje C para la definición de tipos y conversiones.
* Kernighan & Ritchie: "The C Programming Language" para la base teórica de las funciones con elipsis.
* [Guía printf 42 Madrid](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf) 


### Uso de IA

En el desarrollo de este proyecto se ha utilizado Inteligencia Artificial (Gemini) para las siguientes tareas:
* Interpretación de Errores: Diagnóstico de mensajes de error de compilación relacionados con punteros y tipos de datos (const char * vs char).
* Generación de Tests: Diseño de casos de prueba para comparar los valores de retorno exactos con la función original, especialmente en casos críticos como INT_MIN y punteros NULL.
* Comprensión de código.
