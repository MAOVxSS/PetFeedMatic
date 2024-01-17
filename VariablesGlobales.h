#ifndef VARIABLESGLOBALES_H
#define VARIABLESGLOBALES_H

#include <U8glib.h>
#include <RTClib.h>
//Solo se define, no se inicialiaza
extern U8GLIB_ST7920_128X64 u8g;  //Definición de u8g
extern RTC_DS3231 rtc;            //definir objeto para RTC
//Variables para los botones y evitar rebotes
extern const int pinBotonArriba;
extern const int pinBotonAbajo;
extern const int pinBotonSeleccion;
extern const int pinBotonAtras;
//Variables para evitar rebotes en los botones
extern int arribaPresionado;
extern int abajoPresionado;
extern int seleccionPresionado;
extern int atrasPresionado;
// Variables para almacenar las horas y minutos de las alarmas
extern int horaAlarma1;       // Valor inicial de la primera alarma
extern int minutoAlarma1;     // Valor inicial de los minutos para la primera alarma
extern int horaAlarma2;       // Valor inicial de la segunda alarma
extern int minutoAlarma2;     // Valor inicial de los minutos para la segunda alarma
extern bool alarma1Activada;  // Auxiliar para saber si se activo la alarma
extern bool alarma2Activada;
//Definicion de menu principal y submenu
extern const char* menuPrincipalOpciones[];
extern const char* submenuEtapaMascotaOpciones[];
//Tamaño de los arreglos de cada menú
extern const int numOpcionesMenuPrincipal;
extern const int numOpcionesEtapasMascota;
//Variables para manejar el desplazamiento del menú
extern int menuActual;            // opción seleccionadan
extern int maxOpciones;           // maximo numero de opciones en pantalla, para poder realizar el scrolling
extern int desplazamientoScroll;  // variable para manejar el scroll
extern bool auxEncabezado;        //Define que encabezado se mostrara
//Variables para las funciones de etapa, peso ...
extern int opcionElegidaEtapa;       // guarda el id de la etapa elegida
extern int submenuEtapaMascota;      // almacenar la etapa en variable extra
extern int pesoMascotaSeleccionado;  // contador de peso
extern int pesoMascota;              // almacenar el peso
extern int cantidadAlimento;         //Cantidad de alimento en "Programar Alimento"
extern int cantidadAlimentarAhora;      // Cantidad de alimento a suministrar en la opcion "Alimentar Ahora"
extern int pesoMascotaAlimentarAhora;   // Peso de la mascota en la opcion "Alimentar Ahora"
extern int pesoMascotaSeleccionadoAlimentarAhora;
//Variables para funciones auxiliares
extern bool auxRetroceder;   // variable para manejar el estado de retroceso
extern const int velocidad;  //velocidad de giro del motor, cuanto menos valor + velocidad
extern const int pasos;      // controla el numero de pasos a dar
extern const int direccion;  // controla la direccion de los pasos a dar
extern const int reset;      // para colocar en enable al motor
extern const int rele;       //Control del rele para administrar o no voltaje al driver
extern int totalPasos;       //pasos para completar un avance
//Pin para controlar el buzzer
extern const int pin_buzzer; 

#endif