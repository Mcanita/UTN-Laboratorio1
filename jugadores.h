#pragma once
#pragma warning(disable : 4996)
#ifndef JUGADORES_H_INCLUDED
#define JUGADORES_H_INCLUDED
#include "rlutil.h"
#include "windows.h"
using namespace std;

int puntos, cantidad_de_tiradas = 0;
int ListaDePuntos[3] = { 0 }; // n0 = Primer Puesto, n1 = Segundo Puesto, n2= Tercer Puesto
char puesto_1[20] = { 0 }, puesto_2[20] = { 0 }, puesto_3[20] = { 0 };

void JuegoIndividual(char nombre[20], int opcion, int CantidadDeRondasAJugar, int ListaDePuntos[], char puesto_1[], char puesto_2[], char puesto_3[],int tiradas[])
{
    int TirosTotales = 0, Ronda = 0, Total_Puntos = 0, PuntosDisponibles[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    bool chek = false; // Bandera que indica que si se logro sacar Generala Servida y Termina el juego
    int vDados[5]; // Vector que guarda el resultado de los 5 de Dados
    
    while ((Ronda < CantidadDeRondasAJugar) && (!chek))
    {
        bool control = true; bool fin = true;
        int y = 0, oportunidades = 2, key, tirada = 1;
        int puntosTemporales[10] = { -1 };
        rlutil::cls();
        DibujarContornoJuego();
        Dibujar_Cuadro_2(25, 3, 70, 0);
        rlutil::locate(26, 4); // locate posiciona el texto con dos parametros (x,y) X = numero de columna, Y = numero de fila
        std::cout << " TURNO DE: " << nombre; rlutil::locate(47, 4); std::cout << "|| RONDA: " << Ronda + 1 << " || TIRADA N" << (char)167 << " " << tirada << " || PUNTAJE TOTAL: " << Total_Puntos << endl;
        TirosTotales++;

        if (opcion == 1){
            cargarVectorManualmente(vDados, 5);
        }
        else{
            cargarAleatorio(vDados, 5); // Generamos un Tiro de 5 Dados
        }
        
        imprimirTiradaDeDados(vDados, 5);
        chek = chekGenerala(1, vDados); //chekeamos si se hizo generala servida

        if (chek == false) {

            ///  MOSTRAR LA TABLA DE PUNTAJES SUMADOS  ///
            rlutil::locate(3, 22); cout << "COMBINACION"; rlutil::locate(7, 23); printf("DE"); rlutil::locate(4, 24); printf("TU TIRADA");
            rlutil::locate(3, 21); cout << "-----------"; rlutil::locate(3, 25); cout << "-----------";
            Dibujar_Cuadro_2(14, 18, 15, 9);
            comprobarPuntosActuales(puntosTemporales, vDados);
            mostrarPuntosAct(puntosTemporales, 16);

            //// MOSTRAMOS A LA DERECHA EL CUADRO DE PUNTOS DISPINBLES DEL JUGADOR
            Dibujar_Cuadro_2(91, 18, 15, 9);
            mostrarPuntosAct(PuntosDisponibles, 93);
            rlutil::locate(109, 22); printf("Lista de"); rlutil::locate(110, 23); printf("Puntos"); rlutil::locate(109, 24); printf("Anotados");
            rlutil::locate(108, 21); cout << "-----------"; rlutil::locate(108, 25); cout << "-----------";

            do {

                //// MOSTRAMOS EN EL CENTRO INFERIOR EL CUADRO DE TIRADAS TOTALES Y OPORTUNIDADES DE LANZAMIENTO
                Dibujar_Cuadro_2(33, 27, 54, 0);
                rlutil::locate(35, 28); cout << "CANTIDAD TOTAL DE TIRADAS = " << TirosTotales << "  ||  OPORTUNIDADES = " << oportunidades;

                if (oportunidades == 0)
                {
                    limpiarPantalla(33, 19, 58, 11); // Del Medio
                    key = 1;
                    y = 2;
                }
                else // PREGUNTA SI QUIERE TIRAR OTRA VEZ?
                {
                    rlutil::locate(44, 19); std::cout << "Desea Arrojar Nuevamente Los Dados?"; rlutil::locate(59, 22); std::cout << "SI"; rlutil::locate(59, 24); std::cout << "NO";
                    rlutil::locate(36, 20); std::cout << "--------------------------------------------------";
                    rlutil::locate(56, 22 + y); printf(">>"); std::cout << endl; key = rlutil::getkey();
                }

                switch (key) // ANIMACION = SI o NO
                {
                case 14: // UP
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y -= 2;
                    if (y < 0) { y = 0; }
                    break;

                case 15: // DOWN
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y += 2;
                    if (y > 2) { y = 2; }
                    break;

                case 1:
                    if (y == 0) // Si Quiere Tirar de Nuevo
                    {
                        limpiarPantalla(33, 19, 58, 11); // Del Medio

                        Dibujar_Cuadro_2(69, 19, 19, 0);
                        rlutil::locate(70, 20); std::cout << " Oportunidades = " << oportunidades;
                        oportunidades--;
                        TirosTotales++;
                        tirada++;

                        if (opcion == 1) {
                            cargarVectorManualmente(vDados, 5);
                        }
                        else {
                            //cargarAleatorio(vDados, 5); // Generamos un Tiro de 5 Dados
                            VolverAtirarDados(vDados);
                        }
                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                        rlutil::locate(35, 21); std::cout << "-------- DADOS SELECCIONADOS CORRECTAMENTE ---------";
                        rlutil::locate(44, 26); std::cout << "Presione ENTER para Continuar...."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();
                        rlutil::locate(72, 4); cout << tirada; // Mostramos en el cuadro Superior el numero de Tirada

                        imprimirTiradaDeDados(vDados, 5);
                        comprobarPuntosActuales(puntosTemporales, vDados);
                        mostrarPuntosAct(puntosTemporales, 16);

                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                    }
                    else // No Quiere tirar mas dados
                    {
                        limpiarPantalla(32, 19, 58, 11); // Del Medio
                        int z = 0, cursor = 0;
                        bool anular = true;
                        rlutil::locate(49, 19); std::cout << "SELECCIONE UNA OPCION";
                        rlutil::locate(42, 20); std::cout << "-----------------------------------";
                        rlutil::locate(47, 23); std::cout << "SUMAR COMBINACION DISPONBLE";
                        rlutil::locate(49, 26); std::cout << "ANULAR UNA COMBINACION";

                        do
                        {
                            rlutil::locate(44, 23 + z); cout << ">>" << endl;
                            cursor = rlutil::getkey();

                            switch (cursor)
                            {
                            case 14:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z -= 3;
                                if (z < 0) { z = 0; }
                                break;
                            case 15:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z += 3;
                                if (z > 3) { z = 3; }
                                break;
                            case 1: // Z == 3 ANULAR COMBINACION   ----  Z == 0  SUMAR PUNTOS

                                if (z == 3) // quiere anular Puntos
                                {
                                    limpiarPantalla(36, 19, 55, 10); // Del Medio
                                    mostrarPuntosParaAnular(PuntosDisponibles);

                                    int u = 0, updown = 0;
                                    bool segundoCursor = true;

                                    do
                                    {
                                        rlutil::locate(39, 23); std::cout << "Seleccione la combinacion que desee anular:";
                                        rlutil::locate(35, 24); std::cout << "---------------------------------------------------";
                                        rlutil::locate(88, 19 + updown); cout << ">>>" << endl;
                                        u = rlutil::getkey();

                                        switch (u)
                                        {
                                        case 14:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown--;
                                            if (updown < 0) { updown = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown++;
                                            if (updown > 9) { updown = 9; }
                                            break;
                                        case 1:
                                            if (PuntosDisponibles[updown] >= 0)
                                            {
                                                ERRORanularPuntos();
                                            }
                                            else {
                                                limpiarPantalla(93, 19, 14, 10); // Borra los puntos ya Anotados del cuadro derecho
                                                PuntosDisponibles[updown] = 0;
                                                segundoCursor = false;
                                                fin = false;
                                                control = false;
                                            }
                                            limpiarPantalla(31, 19, 60, 10); // Del Medio
                                            break;
                                        }

                                    } while (segundoCursor);

                                }
                                else if (z == 0) //Quiere Sumar PUNTOS
                                {
                                    limpiarPantalla(32, 19, 58, 11); // Del Medio
                                    Dibujar_Cuadro_2(40, 20, 39, 4);
                                    // Preguntamos que Puntos quiere sumar
                                    rlutil::locate(48, 22); std::cout << "Segun los Puntos Actuales";
                                    rlutil::locate(44, 24); std::cout << "Elije Cuales Puntos Quieres Anotar";

                                    do {
                                        // CURSOR DE SELECCION DE PUNTOS
                                        rlutil::locate(31, 19 + y); std::cout << "<<<"; key = rlutil::getkey();

                                        switch (key)
                                        {
                                        case 14:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y--;
                                            if (y < 0) { y = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y++;
                                            if (y > 9) { y = 9; }
                                            break;
                                        case 1:

                                            rlutil::locate(31, 19 + y); std::cout << "   "; // Borra el cursor que selecciono tanto ocupado como no

                                            if (puntosTemporales[y] == 0)
                                            {
                                                ERRORpuntosCERO();
                                            }
                                            else {

                                                if (comprobarEspacioDisponible(puntosTemporales, PuntosDisponibles, y) == false)
                                                {
                                                    ERRORespacioOcupado();
                                                }
                                                else
                                                {
                                                    // y = 0 a 5, es juego de 1 a 6 -- y = 6 a 9 es escalera, poker, full, generala
                                                    PuntosDisponibles[y] = puntosTemporales[y];
                                                    Total_Puntos += puntosTemporales[y]; // acumulador de puntos por ronda
                                                    fin = false;
                                                    control = false; // Terminamos la tirada y continua a la siguiente Ronda
                                                }
                                            }
                                            break;
                                        }

                                    } while (fin);

                                }
                                break;
                            } // fin del switch case que Pregunta si tira dados de nuevo

                        } while (control); // Fin del Do While De CONTROL

                        Ronda++; // contador de rondas 
                    }
                    break;
                } // Fin Swich Case que controla el si no

            } while (fin);

        } // Fin del IF que controla la generala servida de cada Ronda
        else {
            Total_Puntos += 50; // Saco Generala Servida en la Ronda
            Ronda++;
        }

        if (Ronda < CantidadDeRondasAJugar)
        {
            rlutil::cls();
            DibujarContornoJuego();
            Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
            rlutil::locate(37, 10); std::cout << "------------- FINAL DE RONDA N" << (char)167 << " " << Ronda << " -------------";
            rlutil::locate(51, 15); std::cout << "PUNTOS ACTUALES = " << Total_Puntos;
            rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
        }

    } // Fin Del Juego Principal

    /// CUADRO DE FIN JUEGO CON NOMBRE Y PUNTAJE

    if (chek)
    {
        limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
        rlutil::showcursor();
        rlutil::locate(42, 10); std::cout << "-------- TERMINASTE EL JUEGO --------";
        rlutil::locate(43, 13); std::cout << nombre << ", SACASTE GENERALA SERVIDA !!";
        rlutil::locate(52, 15); std::cout << "LANZAMIENTOS: " << TirosTotales;
        rlutil::locate(50, 16); std::cout << "TOTAL DE PUNTOS: " << Total_Puntos;
        rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
        rlutil::hidecursor();
    }
    else
    {
        limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
        rlutil::showcursor();
        rlutil::locate(42, 10); std::cout << "-------- TERMINASTE EL JUEGO --------";
        rlutil::locate(48, 13); std::cout << "PUNTAJE " << nombre << ": " << Total_Puntos << " PUNTOS";
        rlutil::locate(53, 15); std::cout << "LANZAMIENTOS: " << TirosTotales;
        rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
        limpiarPantalla(3, 2, 116, 28);
    }


    PuntajeActual(nombre, Total_Puntos, ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas,TirosTotales);

}

void Multijugador(char nombre[20], char nombre2[20], int opcion2, int CantidadDeRondasAJugar, int ListaDePuntos[], char puesto_1[], char puesto_2[], char puesto_3[],int tiradas[])
{
    int TirosTotales = 0, Ronda = 0, Total_Puntos = 0, PuntosDisponibles[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    int TirosTotales2 = 0, Total_Puntos2 = 0, PuntosDisponibles2[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
    bool generalaServida1 = false, generalaServidaJugador2 = false;
    int vDados[5];


    while ((Ronda < CantidadDeRondasAJugar) && (!generalaServida1) && (!generalaServidaJugador2))
    {
        bool control = true; bool fin = true;
        int y = 0, oportunidades = 2, key, tirada = 1, tirada2 = 1;
        int puntosTemporales[10] = { -1 };
        rlutil::cls();
        DibujarContornoJuego();
        Dibujar_Cuadro_2(25, 3, 70, 0);
        rlutil::locate(26, 4); // locate posiciona el texto con dos parametros (x,y) X = numero de columna, Y = numero de fila
        std::cout << " TURNO DE: " << nombre; rlutil::locate(47, 4); std::cout << "|| RONDA: " << Ronda + 1 << " || TIRADA N" << (char)167 << " " << tirada << " || PUNTAJE TOTAL: " << Total_Puntos << endl;
        TirosTotales++;

        if (opcion2 == 1) {
            cargarVectorManualmente(vDados, 5);
        }
        else {
            cargarAleatorio(vDados, 5);
        }

        imprimirTiradaDeDados(vDados, 5);
        generalaServida1 = chekGenerala(1, vDados);

        if (generalaServida1 == false) {

            rlutil::locate(3, 22); cout << "COMBINACION"; rlutil::locate(7, 23); printf("DE"); rlutil::locate(4, 24); printf("TU TIRADA");
            rlutil::locate(3, 21); cout << "-----------"; rlutil::locate(3, 25); cout << "-----------";
            Dibujar_Cuadro_2(14, 18, 15, 9);
            comprobarPuntosActuales(puntosTemporales, vDados);
            mostrarPuntosAct(puntosTemporales, 16);

            Dibujar_Cuadro_2(91, 18, 15, 9);
            mostrarPuntosAct(PuntosDisponibles, 93);
            rlutil::locate(109, 22); printf("Lista de"); rlutil::locate(110, 23); printf("Puntos"); rlutil::locate(109, 24); printf("Anotados");
            rlutil::locate(108, 21); cout << "-----------"; rlutil::locate(108, 25); cout << "-----------";

            do {

                Dibujar_Cuadro_2(33, 27, 54, 0);
                rlutil::locate(35, 28); cout << "CANTIDAD TOTAL DE TIRADAS = " << TirosTotales << "  ||  OPORTUNIDADES = " << oportunidades;

                if (oportunidades == 0)
                {
                    limpiarPantalla(33, 19, 58, 11); // Del Medio
                    key = 1;
                    y = 2;
                }
                else // PREGUNTA SI QUIERE TIRAR OTRA VEZ?
                {
                    rlutil::locate(44, 19); std::cout << "Desea Arrojar Nuevamente Los Dados?"; rlutil::locate(59, 22); std::cout << "SI"; rlutil::locate(59, 24); std::cout << "NO";
                    rlutil::locate(36, 20); std::cout << "--------------------------------------------------";
                    rlutil::locate(56, 22 + y); printf(">>"); std::cout << endl; key = rlutil::getkey();
                }

                switch (key) // ANIMACION = SI o NO
                {
                case 14: // UP
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y -= 2;
                    if (y < 0) { y = 0; }
                    break;

                case 15: // DOWN
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y += 2;
                    if (y > 2) { y = 2; }
                    break;

                case 1:
                    if (y == 0) // Si Quiere Tirar de Nuevo
                    {
                        limpiarPantalla(33, 19, 58, 11); // Del Medio

                        Dibujar_Cuadro_2(69, 19, 19, 0);
                        rlutil::locate(70, 20); std::cout << " Oportunidades = " << oportunidades;
                        oportunidades--;
                        TirosTotales++;
                        tirada++;

                        if (opcion2 == 1) {
                            cargarVectorManualmente(vDados, 5);
                        }
                        else {

                            VolverAtirarDados(vDados);
                        }
                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                        rlutil::locate(35, 21); std::cout << "-------- DADOS SELECCIONADOS CORRECTAMENTE ---------";
                        rlutil::locate(44, 26); std::cout << "Presione ENTER para Continuar...."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();
                        rlutil::locate(72, 4); cout << tirada;

                        imprimirTiradaDeDados(vDados, 5);
                        comprobarPuntosActuales(puntosTemporales, vDados);
                        mostrarPuntosAct(puntosTemporales, 16);

                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                    }
                    else // No Quiere tirar mas dados
                    {
                        limpiarPantalla(32, 19, 58, 11); // Del Medio
                        int z = 0, cursor = 0;
                        bool anular = true;
                        rlutil::locate(49, 19); std::cout << "SELECCIONE UNA OPCION";
                        rlutil::locate(42, 20); std::cout << "-----------------------------------";
                        rlutil::locate(47, 23); std::cout << "SUMAR COMBINACION DISPONBLE";
                        rlutil::locate(49, 26); std::cout << "ANULAR UNA COMBINACION";

                        do
                        {
                            rlutil::locate(44, 23 + z); cout << ">>" << endl;
                            cursor = rlutil::getkey();

                            switch (cursor)
                            {
                            case 14:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z -= 3;
                                if (z < 0) { z = 0; }
                                break;
                            case 15:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z += 3;
                                if (z > 3) { z = 3; }
                                break;
                            case 1: // Z == 3 ANULAR COMBINACION   ----  Z == 0  SUMAR PUNTOS

                                if (z == 3) // quiere anular Puntos
                                {
                                    limpiarPantalla(36, 19, 55, 10); // Del Medio
                                    mostrarPuntosParaAnular(PuntosDisponibles);

                                    int u = 0, updown = 0;
                                    bool segundoCursor = true;

                                    do
                                    {
                                        rlutil::locate(39, 23); std::cout << "Seleccione la combinacion que desee anular:";
                                        rlutil::locate(35, 24); std::cout << "---------------------------------------------------";
                                        rlutil::locate(88, 19 + updown); cout << ">>>" << endl;
                                        u = rlutil::getkey();

                                        switch (u)
                                        {
                                        case 14:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown--;
                                            if (updown < 0) { updown = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown++;
                                            if (updown > 9) { updown = 9; }
                                            break;
                                        case 1:
                                            if (PuntosDisponibles[updown] >= 0)
                                            {
                                                ERRORanularPuntos();
                                            }
                                            else {
                                                limpiarPantalla(93, 19, 14, 10); // Borra los puntos ya Anotados del cuadro derecho
                                                PuntosDisponibles[updown] = 0;
                                                segundoCursor = false;
                                                fin = false;
                                                control = false;
                                            }
                                            limpiarPantalla(31, 19, 60, 10); // Del Medio
                                            break;
                                        }

                                    } while (segundoCursor);

                                }
                                else if (z == 0) //Quiere Sumar PUNTOS
                                {
                                    limpiarPantalla(32, 19, 58, 11); // Del Medio
                                    Dibujar_Cuadro_2(40, 20, 39, 4);

                                    rlutil::locate(48, 22); std::cout << "Segun los Puntos Actuales";
                                    rlutil::locate(44, 24); std::cout << "Elije Cuales Puntos Quieres Anotar";

                                    do {
                                        rlutil::locate(31, 19 + y); std::cout << "<<<"; key = rlutil::getkey();

                                        switch (key)
                                        {
                                        case 14:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y--;
                                            if (y < 0) { y = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y++;
                                            if (y > 9) { y = 9; }
                                            break;
                                        case 1:

                                            rlutil::locate(31, 19 + y); std::cout << "   "; // Borra el cursor que selecciono tanto ocupado como no

                                            if (puntosTemporales[y] == 0)
                                            {
                                                ERRORpuntosCERO();
                                            }
                                            else {

                                                if (comprobarEspacioDisponible(puntosTemporales, PuntosDisponibles, y) == false)
                                                {
                                                    ERRORespacioOcupado();
                                                }
                                                else
                                                {
                                                    PuntosDisponibles[y] = puntosTemporales[y];
                                                    Total_Puntos += puntosTemporales[y];
                                                    fin = false;
                                                    control = false; // Terminamos la tirada y continua a la siguiente Ronda
                                                }
                                            }
                                            break;
                                        }

                                    } while (fin);

                                }
                                break;
                            } // fin del switch case que Pregunta si tira dados de nuevo

                        } while (control); // Fin del Do While De CONTROL
                        
                        Ronda++; // contador de rondas
                    }
                    break;
                } // Fin Swich Case que controla el si no

            } while (fin);

        } // Fin del IF que controla la generala servida de cada Ronda
        
        if (generalaServida1) {
            Total_Puntos += 50; // Saco Generala Servida en la Ronda
            if (Ronda==0) { Ronda++; }
            limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
            rlutil::showcursor();
            rlutil::locate(55, 10); std::cout << "RONDA N" << (char)167 << " " << Ronda;
            rlutil::locate(43, 12); std::cout << nombre << ", SACASTE GENERALA SERVIDA !!";
            rlutil::locate(52, 13); std::cout << "LANZAMIENTOS: " << TirosTotales;
            rlutil::locate(50, 14); std::cout << "TOTAL DE PUNTOS: " << Total_Puntos;
            rlutil::locate(50, 17); std::cout << "PROXIMO TURNO: " << nombre2;
            rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
            rlutil::hidecursor();
        }
        else {
            limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
            rlutil::showcursor();
            rlutil::locate(55, 10); std::cout << "RONDA N" << (char)167 << " " << Ronda;
            rlutil::locate(45, 12); std::cout << "JUGADOR >> " << nombre << " << " << Total_Puntos << " PUNTOS";
            rlutil::locate(52, 13); std::cout << "LANZAMIENTOS: " << TirosTotales;
            rlutil::locate(53, 16); std::cout << "SIGUIENTE TURNO";
            rlutil::locate(39, 17); std::cout << "------------------------------------------";
            rlutil::locate(45, 18); std::cout << "JUGADOR >> " << nombre2 << " << " << Total_Puntos2 << " PUNTOS";
            rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar..."; rlutil::anykey();
            rlutil::hidecursor();
        }


        rlutil::cls();
        DibujarContornoJuego();
        Dibujar_Cuadro_2(25, 3, 70, 0);
        rlutil::locate(26, 4); // locate posiciona el texto con dos parametros (x,y) X = numero de columna, Y = numero de fila
        std::cout << " TURNO DE: " << nombre2; rlutil::locate(47, 4); std::cout << "|| RONDA: " << Ronda << " || TIRADA N" << (char)167 << " " << tirada2 << " || PUNTAJE TOTAL: " << Total_Puntos2 << endl;
        TirosTotales2++;
        oportunidades = 2; fin = true; y = 0; control = true;

        if (opcion2 == 1) {
            cargarVectorManualmente(vDados, 5);
        }
        else {
            cargarAleatorio(vDados, 5);
        }

        imprimirTiradaDeDados(vDados, 5);
        generalaServidaJugador2 = chekGenerala(1, vDados);

        if (generalaServida1 == false && generalaServidaJugador2 == false) {

            rlutil::locate(3, 22); cout << "COMBINACION"; rlutil::locate(7, 23); printf("DE"); rlutil::locate(4, 24); printf("TU TIRADA");
            rlutil::locate(3, 21); cout << "-----------"; rlutil::locate(3, 25); cout << "-----------";
            Dibujar_Cuadro_2(14, 18, 15, 9);
            comprobarPuntosActuales2(puntosTemporales, vDados);
            mostrarPuntosAct2(puntosTemporales, 16);

            Dibujar_Cuadro_2(91, 18, 15, 9);
            mostrarPuntosAct2(PuntosDisponibles2, 93);
            rlutil::locate(109, 22); printf("Lista de"); rlutil::locate(110, 23); printf("Puntos"); rlutil::locate(109, 24); printf("Anotados");
            rlutil::locate(108, 21); cout << "-----------"; rlutil::locate(108, 25); cout << "-----------";

            do {

                Dibujar_Cuadro_2(33, 27, 54, 0);
                rlutil::locate(35, 28); cout << "CANTIDAD TOTAL DE TIRADAS = " << TirosTotales2 << "  ||  OPORTUNIDADES = " << oportunidades;

                if (oportunidades == 0)
                {
                    limpiarPantalla(33, 19, 58, 11); // Del Medio
                    key = 1;
                    y = 2;
                }
                else // PREGUNTA SI QUIERE TIRAR OTRA VEZ?
                {
                    rlutil::locate(44, 19); std::cout << "Desea Arrojar Nuevamente Los Dados?"; rlutil::locate(59, 22); std::cout << "SI"; rlutil::locate(59, 24); std::cout << "NO";
                    rlutil::locate(36, 20); std::cout << "--------------------------------------------------";
                    rlutil::locate(56, 22 + y); printf(">>"); std::cout << endl; key = rlutil::getkey();
                }

                switch (key) // ANIMACION = SI o NO
                {
                case 14: // UP
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y -= 2;
                    if (y < 0) { y = 0; }
                    break;

                case 15: // DOWN
                    rlutil::locate(56, 22 + y); cout << "  ";
                    y += 2;
                    if (y > 2) { y = 2; }
                    break;

                case 1:
                    if (y == 0) // Si Quiere Tirar de Nuevo
                    {
                        limpiarPantalla(33, 19, 58, 11); // Del Medio

                        Dibujar_Cuadro_2(69, 19, 19, 0);
                        rlutil::locate(70, 20); std::cout << " Oportunidades = " << oportunidades;
                        oportunidades--;
                        TirosTotales2++;
                        tirada2++;

                        if (opcion2 == 1) {
                            cargarVectorManualmente(vDados, 5);
                        }
                        else {
                            VolverAtirarDados(vDados);
                        }
                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                        rlutil::locate(35, 21); std::cout << "-------- DADOS SELECCIONADOS CORRECTAMENTE ---------";
                        rlutil::locate(44, 26); std::cout << "Presione ENTER para Continuar...."; rlutil::showcursor(); rlutil::anykey(); rlutil::hidecursor();
                        rlutil::locate(72, 4); cout << tirada2;

                        imprimirTiradaDeDados(vDados, 5);
                        comprobarPuntosActuales2(puntosTemporales, vDados);
                        mostrarPuntosAct2(puntosTemporales, 16);

                        limpiarPantalla(33, 19, 58, 11); // Del Medio
                    }
                    else // No Quiere tirar mas dados
                    {
                        limpiarPantalla(32, 19, 58, 11); // Del Medio
                        int z = 0, cursor = 0;
                        bool anular = true;
                        rlutil::locate(49, 19); std::cout << "SELECCIONE UNA OPCION";
                        rlutil::locate(42, 20); std::cout << "-----------------------------------";
                        rlutil::locate(47, 23); std::cout << "SUMAR COMBINACION DISPONBLE";
                        rlutil::locate(49, 26); std::cout << "ANULAR UNA COMBINACION";

                        do
                        {
                            rlutil::locate(44, 23 + z); cout << ">>" << endl;
                            cursor = rlutil::getkey();

                            switch (cursor)
                            {
                            case 14:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z -= 3;
                                if (z < 0) { z = 0; }
                                break;
                            case 15:
                                rlutil::locate(44, 23 + z); cout << "  ";
                                z += 3;
                                if (z > 3) { z = 3; }
                                break;
                            case 1: // Z == 3 ANULAR COMBINACION   ----  Z == 0  SUMAR PUNTOS

                                if (z == 3) // quiere anular Puntos
                                {
                                    limpiarPantalla(36, 19, 55, 10); // Del Medio
                                    mostrarPuntosParaAnular2(PuntosDisponibles2);

                                    int u = 0, updown = 0;
                                    bool segundoCursor = true;

                                    do
                                    {
                                        rlutil::locate(39, 23); std::cout << "Seleccione la combinacion que desee anular:";
                                        rlutil::locate(35, 24); std::cout << "---------------------------------------------------";
                                        rlutil::locate(88, 19 + updown); cout << ">>>" << endl;
                                        u = rlutil::getkey();

                                        switch (u)
                                        {
                                        case 14:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown--;
                                            if (updown < 0) { updown = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(88, 19 + updown); cout << "   ";
                                            updown++;
                                            if (updown > 9) { updown = 9; }
                                            break;
                                        case 1:
                                            if (PuntosDisponibles2[updown] >= 0)
                                            {
                                                ERRORanularPuntos();
                                            }
                                            else {
                                                limpiarPantalla(93, 19, 14, 10); // Borra los puntos ya Anotados del cuadro derecho
                                                PuntosDisponibles2[updown] = 0;
                                                segundoCursor = false;
                                                fin = false;
                                                control = false;
                                            }
                                            limpiarPantalla(31, 19, 60, 10); // Del Medio
                                            break;
                                        }

                                    } while (segundoCursor);

                                }
                                else if (z == 0) //Quiere Sumar PUNTOS
                                {
                                    limpiarPantalla(32, 19, 58, 11); // Del Medio
                                    Dibujar_Cuadro_2(40, 20, 39, 4);
                                    rlutil::locate(48, 22); std::cout << "Segun los Puntos Actuales";
                                    rlutil::locate(44, 24); std::cout << "Elije Cuales Puntos Quieres Anotar";

                                    do {
                                        // CURSOR DE SELECCION DE PUNTOS
                                        rlutil::locate(31, 19 + y); std::cout << "<<<"; key = rlutil::getkey();

                                        switch (key)
                                        {
                                        case 14:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y--;
                                            if (y < 0) { y = 0; }
                                            break;
                                        case 15:
                                            rlutil::locate(31, 19 + y); std::cout << "   ";
                                            y++;
                                            if (y > 9) { y = 9; }
                                            break;
                                        case 1:

                                            rlutil::locate(31, 19 + y); std::cout << "   "; // Borra el cursor que selecciono tanto ocupado como no

                                            if (puntosTemporales[y] == 0)
                                            {
                                                ERRORpuntosCERO();
                                            }
                                            else {

                                                if (comprobarEspacioDisponible(puntosTemporales, PuntosDisponibles2, y) == false)
                                                {
                                                    ERRORespacioOcupado();
                                                }
                                                else
                                                {
                                                    PuntosDisponibles2[y] = puntosTemporales[y];
                                                    Total_Puntos2 += puntosTemporales[y];
                                                    fin = false;
                                                    control = false;
                                                }
                                            }
                                            break;
                                        }

                                    } while (fin);

                                }
                                break;
                            } // fin del switch case que Pregunta si tira dados de nuevo

                        } while (control); // Fin del Do While De CONTROL

                    }
                    break;
                } // Fin Swich Case que controla el si no

            } while (fin);

        } // Fin del IF que controla la generala servida de cada Ronda

        if (generalaServidaJugador2) // Saco Generala Servida en la Ronda
        {
            Total_Puntos2 += 50; 
            limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
            rlutil::showcursor();
            rlutil::locate(37, 10); std::cout << "------------- FINAL DE RONDA N" << (char)167 << " " << Ronda << " -------------";
            rlutil::locate(43, 13); std::cout << nombre2 << ", SACASTE GENERALA SERVIDA !!";
            rlutil::locate(52, 15); std::cout << "LANZAMIENTOS: " << TirosTotales2;
            rlutil::locate(50, 16); std::cout << "TOTAL DE PUNTOS: " << Total_Puntos2;
            rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
            rlutil::hidecursor();
        }
        else {
            if (generalaServida1 == false && generalaServidaJugador2 == false)
            {
                limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
                rlutil::showcursor();
                rlutil::locate(37, 10); std::cout << "------------- FINAL DE RONDA N" << (char)167 << " " << Ronda << " -------------";

                rlutil::locate(45, 12); std::cout << "JUGADOR >> " << nombre2 << " << " << Total_Puntos2 << " PUNTOS";
                rlutil::locate(52, 13); std::cout << "LANZAMIENTOS: " << TirosTotales2;
                    if (Ronda < CantidadDeRondasAJugar)
                    {
                        rlutil::locate(53, 16); std::cout << "SIGUIENTE RONDA";
                        rlutil::locate(39, 17); std::cout << "------------------------------------------";
                        rlutil::locate(45, 18); std::cout << "JUGADOR >> " << nombre << " << " << Total_Puntos << " PUNTOS";
                    }
                rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
                rlutil::hidecursor();
            }
        }
    }

    if (generalaServida1 == true && generalaServidaJugador2 == false)
    {
        limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
        rlutil::showcursor();
        rlutil::locate(41, 10); std::cout << "-------- GANASTE EL JUEGO " << nombre << " --------";
        rlutil::locate(51, 13); std::cout << "PUNTAJE " << ": " << Total_Puntos << " PUNTOS";
        rlutil::locate(53, 15); std::cout << "LANZAMIENTOS: " << TirosTotales;
        rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
        limpiarPantalla(3, 2, 116, 28);
    }
    else if (generalaServida1 == false && generalaServidaJugador2 == true)
    {
        limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
        rlutil::showcursor();
        rlutil::locate(41, 10); std::cout << "------- GANASTE EL JUEGO " << nombre2 << " -------";
        rlutil::locate(51, 13); std::cout << "PUNTAJE " << ": " << Total_Puntos2 << " PUNTOS";
        rlutil::locate(53, 15); std::cout << "LANZAMIENTOS: " << TirosTotales2;
        rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
        limpiarPantalla(3, 2, 116, 28);
    }
    else {
        if (Total_Puntos > Total_Puntos2 || generalaServida1 == true && generalaServidaJugador2 == false) {

            limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
            rlutil::showcursor();
            rlutil::locate(41, 10); std::cout << "-------- GANASTE EL JUEGO " << nombre << " --------";
            rlutil::locate(51, 13); std::cout << "PUNTAJE " << ": " << Total_Puntos << " PUNTOS";
            rlutil::locate(53, 15); std::cout << "LANZAMIENTOS: " << TirosTotales;
            rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
            limpiarPantalla(3, 2, 116, 28);
        }
        else {
            if (Total_Puntos == Total_Puntos2) {
                if (TirosTotales < TirosTotales2) {

                    limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
                    rlutil::showcursor();
                    rlutil::locate(44, 10); std::cout << "-------- HA SIDO EMPATE !! --------";
                    rlutil::locate(43, 14); std::cout << "EL GANADOR POR TOTAL DE TIROS ES " << nombre;
                    rlutil::locate(43, 16); std::cout << "---- CANTIDAD DE TIROS : " << TirosTotales << " -------";
                    rlutil::locate(48, 18); std::cout << "(" << nombre2 << " LANZO " << TirosTotales2 << " VECES)";
                    rlutil::locate(42, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
                    limpiarPantalla(3, 2, 116, 28);
                }
                else {
                    limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
                    rlutil::showcursor();
                    rlutil::locate(42, 10); std::cout << "-------- HA SIDO EMPATE !! --------";
                    rlutil::locate(41, 14); std::cout << "EL GANADOR POR TOTAL DE TIROS ES " << nombre2;
                    rlutil::locate(43, 16); std::cout << "---- CANTIDAD DE TIROS : " << TirosTotales2 << " -------";
                    rlutil::locate(48, 18); std::cout << "(" << nombre << " LANZO " << TirosTotales << " VECES)";
                    rlutil::locate(42, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
                    limpiarPantalla(3, 2, 116, 28);

                }
            }
            else {
                limpiarPantalla(3, 2, 116, 28); Dibujar_Cuadro_2(29, 6, 62, 16); Dibujar_Cuadro_2(31, 7, 58, 14);
                rlutil::showcursor();
                rlutil::locate(41, 10); std::cout << "------- GANASTE EL JUEGO " << nombre2 << " -------";
                rlutil::locate(51, 13); std::cout << "PUNTAJE " << ": " << Total_Puntos2 << " PUNTOS";
                rlutil::locate(53, 15); std::cout << "LANZAMIENTOS: " << TirosTotales2;
                rlutil::locate(43, 20); std::cout << "Precione Una Tecla Para Continuar... "; rlutil::anykey();
                limpiarPantalla(3, 2, 116, 28);
            }
        }
    }
    PuntajeActual(nombre, Total_Puntos, ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas,TirosTotales); // Ubicamos tanto al jugador 1 y jugador 2 a su respectivo lugar en la tabla
    PuntajeActual(nombre2, Total_Puntos2, ListaDePuntos, puesto_1, puesto_2, puesto_3,tiradas,TirosTotales2);

}

#endif // JUGADORES_H_INCLUDED