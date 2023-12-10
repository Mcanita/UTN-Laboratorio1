#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "windows.h"
#pragma warning(disable : 4996)

using namespace std;


#include "rlutil.h"
#include "funciones.h"
#include "jugadores.h"


int main()
{
    int y = 0;
    char Jugador1[20], Jugador2[20];
    char puesto_1[20] = { 0 }, puesto_2[20] = { 0 }, puesto_3[20] = { 0 };
    int ListaDePuntos[3] = { 0 }; // n0 = Primer Puesto, n1 = Segundo Puesto, n2= Tercer Puesto
    int tiradas[3] = { 0 }, CANTdeRONDASaJUGAR;

    DibujarContornoJuego(); rlutil::hidecursor(); DibujarTitulodeJuego(); Dibujar_Cuadro_2(42, 13, 38, 10); Dibujar_Cuadro_2(44, 14, 34, 8);


    char soundfile[] = "C:\musicaGenerala.wav"; // Musica de Inicio del Programa
    cout<<PlaySound((LPCSTR)soundfile,NULL,SND_FILENAME | SND_ASYNC);
    // Si no compila el audio 1º Ir a Project/Projet build options/Linker settings || 2º Click en Add, y colocar "winmm" sin comillas || Aceptar y listo

    do // Inicio de Do While
    {
        /// MENU DE OPCIONES
        rlutil::locate(49, 16); cout << "---- Menu de Opciones ----" << endl;
        showItem("1 Jugador", 54, 18, y == 0);
        showItem("2 Jugadores", 54, 19, y == 1);
        showItem("Puntuaciones Mas Altas", 54, 20, y == 2);
        showItem("SALIR", 54, 21, y == 3);

        /// Cursor de Opciones
        rlutil::locate(52, 18 + y);
        printf("%c", 175); cout << endl; int key = rlutil::getkey(); // >>

        switch (key) {
        case 14: // ARRIBA
            rlutil::locate(52, 18 + y); cout << " ";
            y--;
            if (y < 0) { y = 0; }
            break;
        case 15: // ABAJO
            rlutil::locate(52, 18 + y); cout << " ";
            y++;
            if (y > 3) { y = 3; }
            break;
        case 1: // ENTER
            switch (y)
            {
            case 0:
                limpiarPantalla(49, 16, 28, 6);
                int opcion;
                rlutil::showcursor();
                rlutil::locate(51, 17); cout << "1 - Carga Manual";
                rlutil::locate(51, 18); cout << "2 - Aleatorio";
                rlutil::locate(51, 20); cout << "OPCION:";
                rlutil::locate(59, 20); cin >> opcion;

                limpiarPantalla(49, 16, 28, 6);
                rlutil::locate(48, 17); cout << "CANTIDAD DE RONDAS A JUGAR?";
                rlutil::locate(55, 20); cout << "Cantidad = "; cin >> CANTdeRONDASaJUGAR; rlutil::hidecursor();

                IngresarNombredeJugador(Jugador1);
                JuegoIndividual(Jugador1, opcion, CANTdeRONDASaJUGAR, ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas);
                DibujarContornoJuego(); rlutil::hidecursor(); DibujarTitulodeJuego(); Dibujar_Cuadro_2(42, 13, 38, 10); Dibujar_Cuadro_2(44, 14, 34, 8);
                break;
            case 1:
                limpiarPantalla(49, 16, 28, 6);
                int opcion2;
                rlutil::showcursor();
                rlutil::locate(51, 17); cout << "1 - Carga Manual";
                rlutil::locate(51, 18); cout << "2 - Aleatorio";
                rlutil::locate(51, 20); cout << "OPCION:";
                rlutil::locate(59, 20); cin >> opcion2;
                limpiarPantalla(49, 16, 28, 6);
                rlutil::locate(48, 17); cout << "CANTIDAD DE RONDAS A JUGAR?";
                rlutil::locate(55, 20); cout << "Cantidad = "; cin >> CANTdeRONDASaJUGAR; rlutil::hidecursor();

                IngresarNombredeJugador(Jugador1);
                rlutil::locate(37, 19);
                IngresarNombredeJugador2(Jugador2);
                Multijugador(Jugador1, Jugador2, opcion2, CANTdeRONDASaJUGAR, ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas);
                DibujarContornoJuego(); rlutil::hidecursor(); DibujarTitulodeJuego(); Dibujar_Cuadro_2(42, 13, 38, 10); Dibujar_Cuadro_2(44, 14, 34, 8);
                break;
            case 2:
                limpiarPantalla(45, 15, 33, 9);
                MostrarListaDePosiciones(ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas);
                rlutil::locate(55, 22); cout << "Continuar..."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();
                limpiarPantalla(45, 15, 33, 9);
                break;
            case 3:
                rlutil::cls();
                return 0;
                break;
            } // Fin Switch funciones

            break;
        } // Fin Switch Menu

    } while (true); // Fin del Do While

} // Fin de main
