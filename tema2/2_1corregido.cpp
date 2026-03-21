/*
En programación (especialmente en C), cuando un enunciado dice "comparar cadenas", 
casi el 100% de las veces se refiere a la comparación lexicográfica (orden alfabético), 
que es lo que hace la función estándar "strcmp";
*/


int compararCadenas(const char *s1, const char *s2) {
    // Mientras los caracteres apuntados sean iguales y s1 no sea el fin de cadena
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    // Devolvemos la diferencia de los valores ASCII
    // Si son iguales, restará el mismo valor (0) o '\0' - '\0' (0)
    return *(unsigned char *)s1 - *(unsigned char *)s2;
    // el asigned char es para eviar el acarreo negativo que tiene algunas letras
}

void insertarCadena(char *destino, const char *insertar, int pos) {
    char *p_dest = destino;
    const char *p_ins = insertar;
    
    // 1. Calcular longitudes usando punteros
    int len_dest = 0;
    while (*(p_dest + len_dest)) len_dest++;
    
    int len_ins = 0;
    while (*(p_ins + len_ins)) len_ins++;

    // 2. Desplazar el contenido original a la derecha (incluyendo el '\0')
    // Empezamos desde el final para no sobrescribir datos
    for (int i = len_dest; i >= pos; i--) {
        *(destino + i + len_ins) = *(destino + i);
    }

    // 3. Copiar la cadena 'insertar' en el hueco creado
    for (int i = 0; i < len_ins; i++) {
        *(destino + pos + i) = *(insertar + i);
    }
}


#include <stdio.h>

int main() {
    // Prueba de compararCadenas
    char cad1[] = "Hola";
    char cad2[] = "Hola";
    char cad3[] = "Holo";
    
    printf("Comparación (iguales): %d\n", compararCadenas(cad1, cad2)); // 0
    printf("Comparación (menor): %d\n", compararCadenas(cad1, cad3));   // < 0

    // Prueba de insertarCadena
    // Aseguramos espacio suficiente: "Hola Mundo" (10) + " Querido" (8) + '\0'
    char destino[50] = "Hola Mundo"; 
    char insertar[] = " Querido";
    
    printf("\nOriginal: %s\n", destino);
    insertarCadena(destino, insertar, 4); // Insertar después de "Hola"
    printf("Resultado: %s\n", destino);   // "Hola Querido Mundo"

    return 0;
}