#include <Arduino.h>
#include "VariablesGlobales.h"
#include "MenuEncabezados.h"
#include "Imagenes.h"
#include "ConfiguracionAlarmas.h"

//Opciones del menu principal y submenu de etapa mascota
const char* menuPrincipalOpciones[] = { "Recomendaciones", "Alimentar Ahora", "Programar Alimento", "Informacion Actual", "Borrar programacion", "Reloj" };
const char* submenuEtapaMascotaOpciones[] = { "Cachorro 3-6 meses", "Adulto 1-5 anios", "Senior 6-10 anios" };
//Variables para manejar el desplazamiento del menú
int menuActual = 0;            // opción seleccionadan
int maxOpciones = 3;           // maximo numero de opciones en pantalla, para poder realizar el scrolling
int desplazamientoScroll = 0;  // variable para manejar el scroll
bool auxEncabezado = false;    //Define que encabezado se mostrara

//FUNCIÓN PARA MOSTRAR EL MENÚ ACTUAL******************************************************************
//La funcion toma como argumentos las opciones disponibles y la cantidad
void mostrarMenu(const char* opciones[], int numOpciones) {
  u8g.firstPage();  // limpia la pantalla y la prepara para el dibujo
  do {              // entra en un ciclo hasta que la funcion nextPage devuelva false, no hay más que mostrar
    if (auxEncabezado == false) {
      encabezadoMenuPrincipal();
      int j = 0;  //Se comienza el ciclo para el selector y que se desplaze
      for (int i = desplazamientoScroll; i < maxOpciones + desplazamientoScroll && i < numOpciones; i++) {
        if (i == menuActual) {
          u8g.drawStr(10, 32 + (j * 12), "> ");
        }
        u8g.drawStr(20, 32 + (j * 12), opciones[i]);
        j++;
      }
    } else if (auxEncabezado == true) {
      encabezadoEtapaMascota();
      int j = 0;  //Se comienza el ciclo para el selector y que se desplaze
      for (int i = desplazamientoScroll; i < maxOpciones + desplazamientoScroll && i < numOpciones; i++) {
        if (i == menuActual) {
          u8g.drawStr(10, 32 + (j * 12), "> ");
        }
        u8g.drawStr(20, 32 + (j * 12), opciones[i]);
        j++;
      }
    }
  } while (u8g.nextPage());
  verificarAlarmas();
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR EL ENCABEZADO DEL MENU PRINCIPAL************************************************
void encabezadoMenuPrincipal() {
  u8g.setFont(u8g_font_chikita);
  u8g.drawRFrame(0, 0, 128, 64, 3);    // Dibuja un marco para la pantalla
  u8g.drawStr(5, 15, "Petfeedmatic");  // dibuja en la pantalla
  logoPerro();                         //Se dibuja el logo con el perro
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR EL ENCABEZADO DEL SUBMENU DE ETAPA DE MASCOTA***********************************
void encabezadoEtapaMascota() {
  u8g.drawRFrame(0, 0, 128, 64, 3);      // Dibuja un marco para la pantalla
  u8g.setFont(u8g_font_chikita);         // establece el tipo de fuente
  u8g.drawStr(5, 15, "Etapa Mascota:");  // dibuja en la pantalla
  logoPerro();                           //Se dibuja el logo con el perro
}
//*****************************************************************************************************
//Calculo del tamaño de los menus
const int numOpcionesMenuPrincipal = sizeof(menuPrincipalOpciones) / sizeof(menuPrincipalOpciones[0]);
const int numOpcionesEtapasMascota = sizeof(submenuEtapaMascotaOpciones) / sizeof(submenuEtapaMascotaOpciones[0]);
