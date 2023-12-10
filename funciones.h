#pragma once
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#pragma warning(disable : 4996)
#include <string.h>
#include "rlutil.h"
using namespace std;

// Llamado de las Funciones

void showItem(const char* text, int posx, int posy, bool selected);
void cargarVectorManualmente(int v[], int tam); // Funcion para cargar un vector manualmente
void cargarAleatorio(int v[], int tam); // Carga los dados aleatorios en el Vector
void VectorValorCero(int vec[], int tam); // Establece los indices del vector a = 0
int BuscarValorMaximo(int vec[], int tam); // Busca el valor maximo de un vector
int NumeroRepetido(int numero, int v[]); // Comprueba solo un numero repetido dentro de algun VECTOR
void Imprimir_1_al_6(int vDados[]); // imprime la suma de los dados repetidos del 1 al 6
int SumaDePuntos_CarasRepetidas(int v[]); // Suma las Caras Repetidas de los dados y devuelve la suma de caras repetidas con mas Puntaje
int escalera(int v[], int tam); // Comprueba si hay valores ascendentes. Devuelve + 25 / 0 puntos
int full(int v[]); // Comprueba si hay tres dados repetidos mas otros 2 repetidos. Devuelve +30 / 0 puntos
int poker(int v[]); // Comprueba si Hay 4 dados repetidos para formar Poker. Devuelve +40 / 0 puntos
int generala(int v[]); // Comprueba si hay 5 numero Repetidos en el vector. Devuelve +50 / 0 puntos
void VolverAtirarDados(int v[]); // Luego de elegir si se de sea volver a tirar dados, segun la cantidad de dados, reemplazamos los valores de la tirada
int calcularCantidadDePuntos(int v[]); // Calcula el Maximo Valor del Puntaje Obtenido
bool chekGenerala(int tiro, int vDados[]); // Controla el Juego determinando si el Jugador saco Generala Servida en el Primer Tiro
void imprimirDadosSinImagen(int v[], int tam);
void comprobarPuntosActuales(int puntosTemporales[], int vDados[]);
void mostrarPuntosAct(int Temporales_o_Disponibles[], int pos_x);

/// Codigo para Dibujar los dados del 1 al 6
void DibujarDadoNumero_1(int posicion);
void DibujarDadoNumero_2(int posicion);
void DibujarDadoNumero_3(int posicion);
void DibujarDadoNumero_4(int posicion);
void DibujarDadoNumero_5(int posicion);
void DibujarDadoNumero_6(int posicion);

void DibujarCuadrado(int z); // Dibuja el Cuadrado Externo del Dado
int pos(int z, bool xy); // Detecta la posicion del dado (Posicion: 1-2-3-4-5) y ubica el dibujo en su respectivo lugar
void imprimirTiradaDeDados(int v[], int tam); // Recibe la tirada de dados, y dependiendo que cara del dado es, imprime el dado correspondiente
void DibujarContornoJuego(); // Dibuja el borde de la consola
void Dibujar_Cuadro_de_Nombre(); // Dibuja el cuadro para introducir el nombre
void Dibujar_Cuadro_2(int x, int y, int ancho, int alto); // Dibuja un cuadro indicando los parametros
void MostrarNombre(char v[], int tam); // Muestra una cadena de caracteres
bool comprobarEspacioDisponible(int puntosTemporales[10], int PuntosDisponibles[10], int posicion); // Comprueba si el espacio que selecciona el usuario esta disponible o no
void limpiarPantalla(int x, int y, int ancho, int altura); // limpia la pantalla segun parametros
int dadoSeleccionadoRepetido(int numeroDeDado, int vector[4]); // Controla que el usuario no ingrese un dado que ya selecciono
void DibujarTitulodeJuego(); // Dibuja GENERALA
void IngresarNombredeJugador(char nombre[20]); // Guarda el nombre del jugador en una variable
void IngresarNombredeJugador2(char nombre2[20]); // Ingresar nombre del segundo Jugador
void ERRORpuntosCERO(); // Cartel de Error cuando selecciona un puntaje en 0
void mostrarPuntosParaAnular(int PuntosDisponibles[10]);
void ERRORanularPuntos();
void ERRORespacioOcupado();
void MostrarListaDePosiciones(int ListaDePuntos[3], char puesto_1[20], char puesto_2[20], char puesto_3[20]);
void PuntajeActual(char jugador[20], int puntos, int ListaDePuntos[3], char puesto_1[20], char puesto_2[20], char puesto_3[20]);
int dadoSeleccionadoRepetido(int numeroDeDado, int vector[4]);
int SumaDePuntos_CarasRepetidas(int v[]);



/// Implementacion de las Funciones ///

void showItem(const char* text, int posx, int posy, bool selected)
{
    if (selected) {
        /*COLOR DE FONDO*/rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA); // LIGHTMAGENTA , MAGENTA , CYAN , LIGHTBLUE , LIGHTRED
    }
    else {
        rlutil::setBackgroundColor(rlutil::BLACK);
    }

    rlutil::locate(posx, posy);
    std::cout << " " << text << " " << std::endl;

    rlutil::setBackgroundColor(rlutil::BLACK);
}
void DibujarContornoJuego()
{
    /*COLOR DE FONDO*/rlutil::setBackgroundColor(rlutil::BLACK); // LIGHTMAGENTA , MAGENTA , CYAN , LIGHTBLUE , LIGHTRED
    /*COLOR DE TEXTO*/rlutil::setColor(rlutil::WHITE);

    for (int i = 0; i < 120; i++) // Linea Superior
    {
        printf("%c", 177);
    }

    for (int i = 1; i < 29; i++) // Lineas Laterales
    {
        rlutil::locate(1, i + 1);
        printf("%c%c                                                                                                                    %c%c", 177, 177, 177, 177);
    }

    rlutil::locate(1, 30);
    for (int i = 0; i < 119; i++) // Linea Inferior
    {
        printf("%c", 177);
    }

}
void cargarVectorManualmente(int v[], int tam)
{
    limpiarPantalla(33, 19, 58, 11); // Del Medio
    Dibujar_Cuadro_2(51,21,16,4);
    rlutil::showcursor();
    for (int i = 0; i < tam; i++)
    {
        rlutil::locate(53, 22+i); cout << "Dado " << i+1 << ": -->>"; rlutil::locate(66,22+i); std::cin >> v[i];
    }
    rlutil::hidecursor();
    limpiarPantalla(33, 19, 58, 11); // Del Medio
}
void cargarAleatorio(int v[], int tam)
{
    srand(time(NULL)); // Funcion para generar numeros aleatorios enteros
    for (int i = 0; i < tam; i++)
    {
        v[i] = 1 + (rand() % 6); // guarda un numero aleatorio entre 1 y el 6
    }
}
void VectorValorCero(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = 0;
    }
}
int NumeroRepetido(int numero, int v[])
{
    int C = 0, resultado = 0; // C = contador de numeros repetidos, resultado = Suma de todos los numeros repetidos
    for (int i = 0; i < 5; i++) // 5 = Resultado de los 5 Dados
    {
        if (numero == v[i])
        {
            C++;
            if (C > 1)
            {
                resultado = C * numero;
            }
            else
            {
                resultado = numero;
            }
        }
    }
    return resultado;
}
void Imprimir_1_al_6(int vDados[])
{
    cout << endl << "UNO: " << NumeroRepetido(1, vDados);
    cout << endl << "DOS: " << NumeroRepetido(2, vDados);
    cout << endl << "TRES: " << NumeroRepetido(3, vDados);
    cout << endl << "CUATRO: " << NumeroRepetido(4, vDados);
    cout << endl << "CINCO: " << NumeroRepetido(5, vDados);
    cout << endl << "SEIS: " << NumeroRepetido(6, vDados);
}
int SumaDePuntos_CarasRepetidas(int v[])
{
    int i, resultado = 0;
    int vPuntos[6];
    VectorValorCero(vPuntos, 6);
    for (i = 0; i < 6; i++)
    {
        vPuntos[i] = NumeroRepetido(i + 1, v);
    }
    resultado = BuscarValorMaximo(vPuntos, 6);
    return resultado;
}
int BuscarValorMaximo(int vec[], int tam)
{
    int maximo = vec[0];
    for (int i = 1; i < tam; i++)
    {
        if (vec[i] > maximo)
        {
            maximo = vec[i];
        }
    }
    return maximo;
}
int escalera(int v[], int tam)
{
    int vectorCopia[5];
    for (int i = 0; i < 5; i++)
    {
        vectorCopia[i] = v[i]; // Copio los valores del Vector de Dados en otra variable para poder manupular la copia y no el original
    }

    int posmin, aux, puntos = 0;
    for (int i = 0; i < tam - 1; i++) // ordeno la tirada de dados de menor a mayor para poder calcular mejor la escalera
    {
        posmin = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (vectorCopia[j] < vectorCopia[posmin]) posmin = j;
        }
        aux = vectorCopia[i];
        vectorCopia[i] = vectorCopia[posmin];
        vectorCopia[posmin] = aux;
    }

    int indice = 0, C = 0, inicio = 1, hasta = 5;

    if (vectorCopia[0] == 2) // si en el vector quedo ordenado con el 2 en primera posicion, calcula si esta el 2,3,4,5,6 para escalera
    {
        inicio = 2; hasta = 6;
    } // si no entonces el menor es la cara 1 y comprueba, 1,2,3,4,5 para escalera

    for (inicio; inicio <= hasta; inicio++)
    {
        if (vectorCopia[indice] == inicio)
        {
            C++;
        }

        indice++;
    }

    if (C == 5)
    {
        puntos = 25;
    }

    return puntos;
}
int full(int v[])
{
    int puntos = 0;
    int A = 0, B = 0;
    for (int i = 0; i < 5; i++)
    {
        int C = 0;
        for (int z = 0; z < 5; z++)
        {
            if (v[i] == v[z])
            {
                C++;
            }
        } // Fin del ciclo Interno
        if (C == 3)
        {
            A = 3; // Si en algun momento el contador llego a 3 es que hay tres dados repetidos
        }
        else {
            if (C == 2)
            {
                B = 2; // Si en algun momento el contador llego a 2 es que dos dados repetidos
            }
        }
    } // Fin del Ciclo Externo
    if (A == 3 && B == 2)
    {
        puntos = 30; // solo sumara 30 puntos cuando haya 3 dados iguales mas otros 2 iguales
    }
    return puntos;
}
int poker(int v[])
{
    int puntos = 0;
    for (int i = 0; i < 2; i++)
    {
        int P = 0;
        for (int x = 0; x < 5; x++)
        {
            if (v[i] == v[x])
            {
                P++;
            }
        } // Fin Ciclo Interno
        if (P == 4) // Si el contador llega a 4 en cualquiera de las dos instancias devuelve 40
        {
            puntos = 40;
        }
    } // Fin Ciclo Externo
    return puntos;
}
int generala(int v[])
{
    int resultado = 0, A = v[0], cont = 1;
    for (int i = 1; i < 5; i++)
    {
        if (v[i] == A)
        {
            cont++;
        }
    }
    if (cont == 5)
    {
        resultado = 50; // Si se contaron 5 numeros Repetidos cuenta +50 pts
    }
    return resultado;
}
int dadoSeleccionadoRepetido(int numeroDeDado, int vector[4])
{
    int cantidad = 0;

    for (int i = 0; i < 4; i++)
    {
        if (vector[i]==numeroDeDado)
        {
            cantidad++;
        }

    }

    return cantidad;
}
void VolverAtirarDados(int v[])
{
    int i, j, c = 0, nroDado, cantidad;
    int vectorTemporal[4] = { 0 };
    int indice = 0;
    int control[4] = { 0 };
    srand(time(NULL));
    
    for (int i = 1; i < 6; i++) // Borra la pantalla de pregunta SI-NO y dibuja los numeros de Dados
    {
        //rlutil::locate(44, 19 + i); std::cout << "                         ";
        rlutil::locate(11 + c, 17); std::cout << "Dado " << i << (char)167;
        c += 23;
    }

    //limpiarPantalla(37, 19, 54, 0); // Del Medio

    // ¿Cuantos Dados?
    rlutil::showcursor();
    rlutil::locate(37, 20); std::cout << "Cuantos Dados? "; rlutil::locate(53, 20); std::cin >> cantidad;

    if (cantidad >= 5)
    {
        limpiarPantalla(4, 7, 113,10); // DADOS
        for (int i = 0; i < 5; i++)
        {
            v[i] = 1 + (rand() % 6);
        }

    }
    else {
        for (i = 1; i <= cantidad; i++)
        {
            // Cuales de ellos?
            rlutil::locate(37, 23); std::cout << "Cual de ellos?";

            rlutil::locate(53, 22 + i); std::cout << "Dado Nro: -->"; rlutil::locate(68, 22 + i); std::cin >> nroDado;

            if (cantidad>1)
            {
                while (dadoSeleccionadoRepetido(nroDado,vectorTemporal)>0 || nroDado > 5 || nroDado < 0)
                {
                    rlutil::locate(42,28); cout << "Nro de Dado Invalido, Selecciona Otro";
                    rlutil::locate(68, 22 + i); std::cout << "  ";
                    rlutil::locate(68, 22 + i); std::cin >> nroDado;
                }
                    vectorTemporal[indice] = nroDado; indice++;
                    rlutil::locate(42, 28); cout << "                                     "; // Borramos mensaje Invalido
            }

            v[nroDado - 1] = 1 + (rand() % 6);

            // Dependiendo que dado quiere tirar, Borra la pantalla en su lugar correspondiente
            switch (nroDado)
            {
            case 1:
                j = 0;
                break;
            case 2:
                j = 24;
                break;
            case 3:
                j = 46;
                break;
            case 4:
                j = 69;
                break;
            case 5:
                j = 93;
                break;
            }

            for (int x = 0; x < 11; x++)
            {
                rlutil::locate(4 + j, 7 + x); std::cout << "                    ";
            }
        }

    }

    // Borra la los numeros de los dados
    for (i = 0; i < 3; i++)
    {
        rlutil::locate(5+i*20, 17); cout << "                                                                     ";
    }

}
int calcularCantidadDePuntos(int v[])
{
    int puntos = 0, vPuntos[5];
    /* vPuntos //
    Indice 0 = Caras repetidas del 1 al 6
    Indice 1 = Escalera
    Indice 2 = Full
    Indice 3 = Poker
    Indice 4 = Generala
    */

    vPuntos[0] = SumaDePuntos_CarasRepetidas(v);
    vPuntos[1] = escalera(v, 5);
    vPuntos[2] = full(v);
    vPuntos[3] = poker(v);
    vPuntos[4] = generala(v);

    puntos = BuscarValorMaximo(vPuntos, 5);

    return puntos;
}
bool chekGenerala(int tiro, int vDados[])
{
    bool chek = false;
    int resultado = generala(vDados); // Chekea si se cumple generala en el tiro de dados
    if ((resultado != 0) && (tiro == 1)) // si en la funcion viene el 1 como parametro y resultado dio 50
    {
        chek = true; // entonces se cumplio generala servida, retorna verdadero y en el juego principal corta el ciclo y gana el jugador
    }
    return chek;
}
void imprimirDadosSinImagen(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << "Dado " << i + 1 << " = " << v[i] << endl;
    }
}
void imprimirTiradaDeDados(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        switch (v[i])
        {
        case 1:
            DibujarDadoNumero_1(i + 1);
            break;
        case 2:
            DibujarDadoNumero_2(i + 1);
            break;
        case 3:
            DibujarDadoNumero_3(i + 1);
            break;
        case 4:
            DibujarDadoNumero_4(i + 1);
            break;
        case 5:
            DibujarDadoNumero_5(i + 1);
            break;
        case 6:
            DibujarDadoNumero_6(i + 1);
            break;
        }
    }
}
void DibujarDadoNumero_1(int posicion)
{
    /// posicion 1 =        '07',           '15'
    /// posicion 2 = 13+15 ('30')    (28+8) =38
    /// posicion 3 = 36+15 ('53')    (51+8) =61
    /// posicion 4 = 59+15 ('76')    (74+8) =84
    /// posicion 5 = 82+15 ('99')    (97+8) =107

    int x=0, y=0;

    switch (posicion)
    {
    case 1:
        x = 5;
        y = 13;
        break;
    case 2:
        x = 28;
        y = 36;
        break;
    case 3:
        x = 51;
        y = 59;
        break;
    case 4:
        x = 74;
        y = 82;
        break;
    case 5:
        x = 97;
        y = 105;
        break;
    }

    DibujarCuadrado(x);


    rlutil::locate(y, 11); printf("%c%c%c", 219, 219, 219); // Completo
    rlutil::locate(y, 12); printf("%c%c%c", 223, 223, 223); // Inferior

}
void DibujarDadoNumero_2(int posicion) //10   16
{
    int x, y;

    x = pos(posicion, true);
    y = pos(posicion, false);

    DibujarCuadrado(x);
    /*
            rlutil::locate(10+y,7);printf("%c%c%c",220,220,220); // Inferior
            rlutil::locate(10+y,8);printf("%c%c%c",219,219,219); // Completo

            rlutil::locate(16+y,10);printf("%c%c%c",220,220,220); // Inferior
            rlutil::locate(16+y,11);printf("%c%c%c",219,219,219); // Completo
    */

    rlutil::locate(8 + y, 8); printf("%c%c%c", 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 9); printf("%c%c%c", 219, 219, 219); // Completo

    rlutil::locate(18 + y, 13); printf("%c%c%c", 220, 220, 220); // Inferior
    rlutil::locate(18 + y, 14); printf("%c%c%c", 219, 219, 219); // Completo

}
void DibujarDadoNumero_3(int posicion)
{
    int x, y;

    x = pos(posicion, true);
    y = pos(posicion, false);

    DibujarCuadrado(x);


    rlutil::locate(8 + y, 8); printf("%c%c%c", 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 9); printf("%c%c%c", 219, 219, 219); // Completo


    rlutil::locate(13 + y, 11); printf("%c%c%c", 219, 219, 219); // Completo
    rlutil::locate(13 + y, 12); printf("%c%c%c", 223, 223, 223); // Superior

    rlutil::locate(18 + y, 13); printf("%c%c%c", 220, 220, 220); // Inferior
    rlutil::locate(18 + y, 14); printf("%c%c%c", 219, 219, 219); // Completo

}
void DibujarDadoNumero_4(int posicion)
{
    int x, y;

    x = pos(posicion, true);
    y = pos(posicion, false);

    DibujarCuadrado(x);

    rlutil::locate(8 + y, 9); printf(" %c%c%c     %c%c%c", 219, 219, 219, 219, 219, 219); // Completo
    rlutil::locate(8 + y, 10); printf(" %c%c%c     %c%c%c", 223, 223, 223, 223, 223, 223); // Superior

    rlutil::locate(8 + y, 13); printf(" %c%c%c     %c%c%c", 219, 219, 219, 219, 219, 219); // Completo
    rlutil::locate(8 + y, 14); printf(" %c%c%c     %c%c%c", 223, 223, 223, 223, 223, 223); // Superior

}
void DibujarDadoNumero_5(int posicion)
{
    int x, y;

    x = pos(posicion, true);
    y = pos(posicion, false);

    DibujarCuadrado(x);

    rlutil::locate(8 + y, 8); printf("%c%c%c       %c%c%c", 220, 220, 220, 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 9); printf("%c%c%c       %c%c%c", 219, 219, 219, 219, 219, 219); // Completo


    rlutil::locate(13 + y, 11); printf("%c%c%c", 219, 219, 219); // Completo
    rlutil::locate(13 + y, 12); printf("%c%c%c", 223, 223, 223); // Superior

    rlutil::locate(8 + y, 13); printf("%c%c%c       %c%c%c", 220, 220, 220, 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 14); printf("%c%c%c       %c%c%c", 219, 219, 219, 219, 219, 219); // Completo

}
void DibujarDadoNumero_6(int posicion)
{
    int x, y;

    x = pos(posicion, true);
    y = pos(posicion, false);

    DibujarCuadrado(x);


    rlutil::locate(8 + y, 8); printf("%c%c%c       %c%c%c", 220, 220, 220, 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 9); printf("%c%c%c       %c%c%c", 219, 219, 219, 219, 219, 219); // Completo
    rlutil::locate(8 + y, 11); printf("%c%c%c       %c%c%c", 219, 219, 219, 219, 219, 219); // Completo
    rlutil::locate(8 + y, 12); printf("%c%c%c       %c%c%c", 223, 223, 223, 223, 223, 223); // Superior
    rlutil::locate(8 + y, 13); printf("%c%c%c       %c%c%c", 220, 220, 220, 220, 220, 220); // Inferior
    rlutil::locate(8 + y, 14); printf("%c%c%c       %c%c%c", 219, 219, 219, 219, 219, 219); // Completo

}
void DibujarCuadrado(int z)
{
    rlutil::locate(z, 7);        // Linea Superior //
    for (int i = 0; i <= 18; i++) {
        printf("%c", 220);
    }

    for (int i = 6; i <= 13; i++) {   // Lineas Laterales //
        rlutil::locate(z, i + 2); printf("%c                 %c", 219, 219);
    }

    rlutil::locate(z + 1, 15);     // Linea Inferior //
    for (int i = 0; i <= 16; i++) {
        printf("%c", 220);
    }
}
int pos(int z, bool xy)
{
    int resultado;
    switch (z)
    {
    case 1:
        if (xy) { resultado = 5; }
        else { resultado = 0; }
        break;
    case 2:
        if (xy) { resultado = 28; }
        else { resultado = 23; }
        break;
    case 3:
        if (xy) { resultado = 51; }
        else { resultado = 46; }
        break;
    case 4:
        if (xy) { resultado = 74; }
        else { resultado = 69; }
        break;
    case 5:
        if (xy) { resultado = 97; }
        else { resultado = 92; }
        break;
    }
    return resultado;
}
void Dibujar_Cuadro_de_Nombre()
{
    rlutil::locate(38, 18); // izquierdo hacia abajo !=
    printf("%c", 201);
    rlutil::locate(39, 18); // linea Superior
    for (int i = 0; i < 40; i++)
    {
        printf("%c", 205);
    }
    rlutil::locate(79, 18); // Derecho hacia abajo =!
    printf("%c", 187);



    rlutil::locate(38, 19); // Lateral 1
    printf("%c", 186);
    rlutil::locate(79, 19); // Lateral 2
    printf("%c", 186);



    rlutil::locate(38, 20); // izquierdo hacia arriba !=
    printf("%c", 200);
    rlutil::locate(39, 20); // linea inferior
    for (int i = 0; i < 40; i++)
    {
        printf("%c", 205);
    }
    rlutil::locate(79, 20); // Derecho hacia arriba =!
    printf("%c", 188);
}
void Dibujar_Cuadro_2(int x, int y, int ancho, int alto)
{
    rlutil::locate(x, y); // izquierdo hacia abajo !=
    printf("%c", 201);
    rlutil::locate(x + 1, y); /// LINEA SUPERIOR
    for (int i = 0; i <= ancho; i++)
    {
        printf("%c", 205);
    }
    rlutil::locate(x + ancho + 1, y); // Derecho hacia abajo =!
    printf("%c", 187);

    ///////////////////////////////////////////////////
/// LATERALES
    for (int i = 1; i <= alto + 1; i++) {
        rlutil::locate(x, y + i); // Lateral 1
        printf("%c", 186);
        rlutil::locate(x + ancho + 1, y + i); // Lateral 2
        printf("%c", 186);
    }

    ///////////////////////////////////////////////////

    rlutil::locate(x, y + 2 + alto); // izquierdo hacia arriba !=
    printf("%c", 200);
    rlutil::locate(x + 1, y + 2 + alto); /// LINEA INFERIOR
    for (int i = 0; i <= ancho; i++)
    {
        printf("%c", 205);
    }
    rlutil::locate(x + ancho + 1, y + 2 + alto); // Derecho hacia arriba =!
    printf("%c", 188);
}
void MostrarNombre(char v[], int tam)
{
    int c = 0;
    while ((c < tam) && (v[c] != '\0'))
    {
        cout << v[c];
        c++;
    }
}
void PuntajeActual(char jugador[20],int puntos, int ListaDePuntos[3], char puesto_1[20], char puesto_2[20], char puesto_3[20],int tiradas[], int TotTiros)
{

        /// ORGANIZACION DE PUNTOS

        if (puntos > ListaDePuntos[0]) // si es mayor al primer puesto, todos se desplazan un lugar reemplazando el primer puesto por el nuevo valor
        {
            if (strcmp(jugador, puesto_1) == 0) { // ¿el usuario es el mismo que esta en el primer puesto? en tal caso solo reemplazamos su primer puesto y los demas no los tocamos
                strcpy(puesto_1, jugador); // copiamos la cadena del puesto uno por el jugador actual
                ListaDePuntos[0] = puntos; // con su puntaje mayor
                tiradas[0] = TotTiros;
            }
            else if (strcmp(jugador, puesto_2) == 0) // si no ¿ este jugador es el mismo del 2º puesto? // en tal caso como es mayor al primer lugar solo desplazamos 1º y 2º puesto dejando el 3º lugar intacto
            {
                strcpy(puesto_2, puesto_1); // primero reemplazamos el jugador 2 para no perder el nombre del puesto 1
                strcpy(puesto_1, jugador);
                ListaDePuntos[1] = ListaDePuntos[0]; // lo mismo con los puntos
                ListaDePuntos[0] = puntos;
                tiradas[1] = tiradas[0];
                tiradas[0] = TotTiros;
            }
            else { // caso contrario, estamos frente a un nuevo jugador y desplazamos todos los valores un puesto hacia abajo
                ListaDePuntos[2] = ListaDePuntos[1];
                strcpy(puesto_3, puesto_2);
                tiradas[2] = tiradas[1];

                ListaDePuntos[1] = ListaDePuntos[0];
                strcpy(puesto_2, puesto_1);
                tiradas[1] = tiradas[0];

                ListaDePuntos[0] = puntos;
                strcpy(puesto_1, jugador);
                tiradas[0] = TotTiros;
            }

        }
        else {
            if (puntos > ListaDePuntos[1] && !(strcmp(jugador, puesto_1) == 0))
                // sino, si es mayor al segundo solo se desplaza el segundo puesto al tercero, y el segundo puesto queda el nuevo valor (SIEMPRE Y CUANDO NO SEA EL MISMO JUGADOR)
            {
                if (strcmp(jugador, puesto_2) == 0) { // ¿el usuario es el mismo que esta en el segundo puesto? en tal caso solo reemplazamos su segundo puesto y el 3º lugar no los tocamos
                    strcpy(puesto_2, jugador);
                    ListaDePuntos[1] = puntos;
                    tiradas[1] = TotTiros;
                }
                else {
                    ListaDePuntos[2] = ListaDePuntos[1]; // es un usuario diferente por ende desplazamos un nivel hacia abajo
                    strcpy(puesto_3, puesto_2);
                    tiradas[2] = tiradas[1];

                    ListaDePuntos[1] = puntos;
                    strcpy(puesto_2, jugador);
                    tiradas[1] = TotTiros;
                }
            }
            else {
                if (puntos > ListaDePuntos[2] && !(strcmp(jugador, puesto_1) == 0) && !(strcmp(jugador, puesto_2) == 0))
                    // sino, si es mayor al tercer puesto, hay que preguntar si NO ES EL MISMO JUGADOR del 1º o 2º puesto para asegurarnos que es un nuevo jugador
                {
                    ListaDePuntos[2] = puntos;
                    strcpy(puesto_3, jugador);
                    tiradas[2] = TotTiros;
                } // si ninguna condicion se cumple solo se ignora este nuevo puntaje
            }
        }

}
void MostrarListaDePosiciones(int ListaDePuntos[3], char puesto_1[20], char puesto_2[20], char puesto_3[20],int tiradas[3]) {

    rlutil::locate(46, 16); printf("1%c %s, Pts: %d | Tiros: %d", 248, puesto_1, ListaDePuntos[0], tiradas[0]);
    rlutil::locate(46, 18); printf("2%c %s, Pts: %d | Tiros: %d", 248, puesto_2, ListaDePuntos[1], tiradas[1]);
    rlutil::locate(46, 20); printf("3%c %s, Pts: %d | Tiros: %d", 248, puesto_3, ListaDePuntos[2], tiradas[2]);

    //printf("%s",jugador); // %s = cadena de caracteres o String, 2º parametro, vector de caracteres a imprimir en pantalla
    //puts("\nHOLA MUNDO");
}
void comprobarPuntosActuales(int puntosTemporales[], int vDados[])
{
    puntosTemporales[0] = NumeroRepetido(1, vDados);
    puntosTemporales[1] = NumeroRepetido(2, vDados);
    puntosTemporales[2] = NumeroRepetido(3, vDados);
    puntosTemporales[3] = NumeroRepetido(4, vDados);
    puntosTemporales[4] = NumeroRepetido(5, vDados);
    puntosTemporales[5] = NumeroRepetido(6, vDados);
    puntosTemporales[6] = escalera(vDados, 5);
    puntosTemporales[7] = full(vDados);
    puntosTemporales[8] = poker(vDados);
    puntosTemporales[9] = generala(vDados);
}
void comprobarPuntosActuales2(int puntosTemporales[], int vDados[])
{
    puntosTemporales[0] = NumeroRepetido(1, vDados);
    puntosTemporales[1] = NumeroRepetido(2, vDados);
    puntosTemporales[2] = NumeroRepetido(3, vDados);
    puntosTemporales[3] = NumeroRepetido(4, vDados);
    puntosTemporales[4] = NumeroRepetido(5, vDados);
    puntosTemporales[5] = NumeroRepetido(6, vDados);
    puntosTemporales[6] = escalera(vDados, 5);
    puntosTemporales[7] = full(vDados);
    puntosTemporales[8] = poker(vDados);
    puntosTemporales[9] = generala(vDados);
}
void mostrarPuntosAct(int Temporales_o_Disponibles[],int pos_x)
{
    limpiarPantalla(pos_x+10,19,3,10);
    rlutil::locate(pos_x, 19); cout << "Suma de 1: " << Temporales_o_Disponibles[0];
    rlutil::locate(pos_x, 20); cout << "Suma de 2: " << Temporales_o_Disponibles[1];
    rlutil::locate(pos_x, 21); cout << "Suma de 3: " << Temporales_o_Disponibles[2];
    rlutil::locate(pos_x, 22); cout << "Suma de 4: " << Temporales_o_Disponibles[3];
    rlutil::locate(pos_x, 23); cout << "Suma de 5: " << Temporales_o_Disponibles[4];
    rlutil::locate(pos_x, 24); cout << "Suma de 6: " << Temporales_o_Disponibles[5];
    rlutil::locate(pos_x, 25); cout << "ESCALERA : " << Temporales_o_Disponibles[6];
    rlutil::locate(pos_x, 26); cout << "FULL     : " << Temporales_o_Disponibles[7];
    rlutil::locate(pos_x, 27); cout << "POKER    : " << Temporales_o_Disponibles[8];
    rlutil::locate(pos_x, 28); cout << "GENERALA : " << Temporales_o_Disponibles[9];

    if (pos_x > 16)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Temporales_o_Disponibles[i] < 0)
            {
                rlutil::locate(pos_x, 19 + i); cout << "              ";
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (Temporales_o_Disponibles[i] == 0)
            {
                rlutil::locate(pos_x, 19 + i); cout << "              ";
            }
        }
    }
}
void mostrarPuntosAct2(int Temporales_o_Disponibles[], int pos_x)
{
    limpiarPantalla(pos_x + 10, 19, 3, 10);
    rlutil::locate(pos_x, 19); cout << "Suma de 1: " << Temporales_o_Disponibles[0];
    rlutil::locate(pos_x, 20); cout << "Suma de 2: " << Temporales_o_Disponibles[1];
    rlutil::locate(pos_x, 21); cout << "Suma de 3: " << Temporales_o_Disponibles[2];
    rlutil::locate(pos_x, 22); cout << "Suma de 4: " << Temporales_o_Disponibles[3];
    rlutil::locate(pos_x, 23); cout << "Suma de 5: " << Temporales_o_Disponibles[4];
    rlutil::locate(pos_x, 24); cout << "Suma de 6: " << Temporales_o_Disponibles[5];
    rlutil::locate(pos_x, 25); cout << "ESCALERA : " << Temporales_o_Disponibles[6];
    rlutil::locate(pos_x, 26); cout << "FULL     : " << Temporales_o_Disponibles[7];
    rlutil::locate(pos_x, 27); cout << "POKER    : " << Temporales_o_Disponibles[8];
    rlutil::locate(pos_x, 28); cout << "GENERALA : " << Temporales_o_Disponibles[9];

    if (pos_x > 16)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Temporales_o_Disponibles[i] < 0)
            {
                rlutil::locate(pos_x, 19 + i); cout << "              ";
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (Temporales_o_Disponibles[i] == 0)
            {
                rlutil::locate(pos_x, 19 + i); cout << "              ";
            }
        }
    }


}
bool comprobarEspacioDisponible(int puntosTemporales[10], int PuntosDisponibles[10], int posicion)
{
    bool disponible = false;

    if (PuntosDisponibles[posicion] == -1)
    {
        PuntosDisponibles[posicion] = puntosTemporales[posicion];
        disponible = true;
    }

    return disponible;
}
void mostrarPuntosParaAnular(int PuntosDisponibles[10])
{
    limpiarPantalla(93,19,14,10); // Borra los puntos ya Anotados del cuadro derecho

    for (int i = 0; i < 10; i++)
    {
        if (PuntosDisponibles[i] < 0)
        {
            switch (i)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                rlutil::locate(93,19+i); cout << "Suma de " << i + 1 << ":";
                break;
            case 6:
                rlutil::locate(93, 19 + i); cout << "Escalera:";
                break;
            case 7:
                rlutil::locate(93, 19 + i); cout << "Full:";
                break;
            case 8:
                rlutil::locate(93, 19 + i); cout << "Poker:";
                break;
            case 9:
                rlutil::locate(93, 19 + i); cout << "Generala:";
                break;
            }

        }

    }

}
void mostrarPuntosParaAnular2(int PuntosDisponibles2[10])
{
    limpiarPantalla(93, 19, 14, 10); // Borra los puntos ya Anotados del cuadro derecho

    for (int i = 0; i < 10; i++)
    {
        if (PuntosDisponibles2[i] < 0)
        {
            switch (i)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                rlutil::locate(93, 19 + i); cout << "Suma de " << i + 1 << ":";
                break;
            case 6:
                rlutil::locate(93, 19 + i); cout << "Escalera:";
                break;
            case 7:
                rlutil::locate(93, 19 + i); cout << "Full:";
                break;
            case 8:
                rlutil::locate(93, 19 + i); cout << "Poker:";
                break;
            case 9:
                rlutil::locate(93, 19 + i); cout << "Generala:";
                break;
            }

        }

    }

}
void limpiarPantalla(int x, int y, int ancho, int altura) 
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < ancho; j++)
        {
            rlutil::locate(x+j, y+i); std::cout << " ";
        }
    }
}
void DibujarTitulodeJuego() {
    rlutil::locate(4, 4); cout << "@@@@@@@@@@@   @@@@@@@@@@@   @@@       @@   @@@@@@@@@@@   @@@@@@@@@           @         @@                  @";
    rlutil::locate(4, 5); cout << "@@            @@            @@ @@     @@   @@            @@      @@         @@@        @@                 @@@";
    rlutil::locate(4, 6); cout << "@@            @@            @@  @@    @@   @@            @@     @@@        @@ @@       @@                @@ @@";
    rlutil::locate(4, 7); cout << "@@    @@@@@   @@@@@@@@      @@   @@   @@   @@@@@@@@      @@ @@@@@         @@   @@      @@               @@   @@";
    rlutil::locate(4, 8); cout << "@@       @@   @@            @@    @@  @@   @@            @@     @@       @@@@@@@@@     @@              @@@@@@@@@";
    rlutil::locate(4, 9); cout << "@@       @@   @@            @@     @@ @@   @@            @@      @@     @@       @@    @@             @@       @@ ";
    rlutil::locate(4, 10); cout << "@@@@@@@@@@@   @@@@@@@@@@@   @@      @@@@   @@@@@@@@@@@   @@       @@   @@         @@   @@@@@@@@@@@   @@         @@";
}
void IngresarNombredeJugador(char nombre[20]) {
    /// INICIO DEL JUEGO
    /// CUADRO INICIAL PARA INTRODUCIR EL NOMBRE DEL JUGADOR
    limpiarPantalla(42,13,40,13);
    Dibujar_Cuadro_de_Nombre();
    rlutil::locate(40, 17); cout << "JUGADOR # 1";
    rlutil::locate(40, 19);
    cin.ignore(); // descarta el último '\n', sino no entra al getline correctamente
    printf("Ingrese su Nombre: "); rlutil::showcursor(); std::cin.getline(nombre, 20, '\n'); rlutil::hidecursor();
        /* funcion con tres parametros,
        1 - Variable en donde queremos guardar,
        2 - Cantidad de Espacio Reservado en memoria,
        3 - Cuando termina de cargar elementos, en este caso en un salto de linea ("\n")*/
}
void IngresarNombredeJugador2(char nombre2[20]) {
    /// INICIO DEL JUEGO
    /// CUADRO INICIAL PARA INTRODUCIR EL NOMBRE DEL JUGADOR
    rlutil::locate(40, 17); cout << "JUGADOR # 2";
    rlutil::locate(40, 19); cout << "                               ";
    rlutil::locate(40, 19); cout << "Ingrese su Nombre: ";

    rlutil::showcursor(); rlutil::locate(59, 19); std::cin.getline(nombre2, 20, '\n'); rlutil::hidecursor();


}
void ERRORpuntosCERO() {
    limpiarPantalla(37, 19, 54, 10); // Del Medio

    rlutil::locate(54, 20); printf("%c%c%c ERROR !!!", 173, 173, 173);

    rlutil::locate(41, 23); std::cout << "SELECCION INVALIDA, VUELVE A INTENTARLO";


    rlutil::locate(43, 26); std::cout << "PRESIONE UNA TECLA PARA CONTINUAR..."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();

    limpiarPantalla(32, 19, 58, 11); // Del Medio

    Dibujar_Cuadro_2(40, 20, 39, 4);
    // Preguntamos que Puntos quiere sumar
    rlutil::locate(48, 22); std::cout << "Segun los Puntos Actuales";
    rlutil::locate(44, 24); std::cout << "Elije Cuales Puntos Quieres Anotar";
}
void ERRORespacioOcupado() {
    limpiarPantalla(37, 19, 54, 10); // Del Medio

    rlutil::locate(47, 22); std::cout << "Este espacio ya esta ocupado";
    rlutil::locate(48, 24); std::cout << "Por Favor, Seleccione Otro"; rlutil::anykey();

    limpiarPantalla(37, 19, 54, 10); // Del Medio

    // Preguntamos que Puntos quiere sumar
    rlutil::locate(48, 20); std::cout << "Segun los Puntos Actuales";
    rlutil::locate(42, 22); std::cout << "Selecciona que Puntaje Quieres Anotar";
}
void ERRORanularPuntos() {
    rlutil::locate(39, 23); std::cout << "                                           ";

    rlutil::locate(54, 20); printf("%c%c%c ERROR !!!", 173, 173, 173);

    rlutil::locate(41, 23); std::cout << "SELECCION INVALIDA, VUELVE A INTENTARLO";


    rlutil::locate(43, 26); std::cout << "PRESIONE UNA TECLA PARA CONTINUAR..."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();
}

#endif // FUNCIONES_H_INCLUDED