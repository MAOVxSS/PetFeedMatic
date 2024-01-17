/*
  Dispensador de alimento para mascota (manual y automatico)
  Por: Miguel Alberto Ortiz Vazquez
*/
//Librerias a utilizar
#include <Wire.h>
#include "RelojDigitalAnalogico.h"
#include "VariablesGlobales.h"
#include "ConfiguracionAlarmas.h"
#include "MenuEncabezados.h"
#include "Imagenes.h"
#include "InformacionAlertas.h"
#include "FuncionesAuxiliares.h"
#include "FuncionesMascota.h"
#include "Configuracion.h"
#include "Musica.h"
U8GLIB_ST7920_128X64 u8g(6, 5, 4, 7);  //Definición y inicializacion de u8g
RTC_DS3231 rtc;                        //definir objeto para RTC
//Variables para evitar rebotes en los botones
int arribaPresionado = 0;
int abajoPresionado = 0;
int seleccionPresionado = 0;
int atrasPresionado = 0;
//Definición de los pines para los botones
const int pinBotonArriba = 47;
const int pinBotonAbajo = 49;
const int pinBotonSeleccion = 51;
const int pinBotonAtras = 53;
//Variable para controlar el logo de inicio al ejecutar el programa
bool auxInicio = false;
//#####################################################################################################
void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("No se ha detectado el RTC DS3231");
  }
  ConfiguracionArduino();
  // Inicializaciones del hardware y configuraciones
  u8g.firstPage();
  do {
    logoPerroInicio();
  } while (u8g.nextPage());
  musicaInicio();
  auxInicio = true;
}
//#####################################################################################################
//-----------------------------------------------------------------------------------------------------
void loop() {
  if (auxInicio) { //Una vez se haya mostrada la introduccion
    //Se apaga el motor hasta que se utilice
    digitalWrite(reset, LOW);
    //Se muestra el encabezado
    auxEncabezado = false;
    //Lectura de los botones, con método para evitar rebotes
    if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
    if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
    if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
    if (digitalRead(pinBotonAtras) == LOW) atrasPresionado = 1;
    //Subir y bajar por las opciones
    if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
      arribaPresionado = 0;
      if (menuActual > 0) {
        menuActual--;
        if (menuActual < desplazamientoScroll) {
          desplazamientoScroll--;
        }
      }
    } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
      abajoPresionado = 0;
      if (menuActual < numOpcionesMenuPrincipal - 1) {
        menuActual++;
        if (menuActual >= maxOpciones + desplazamientoScroll) {
          desplazamientoScroll++;
        }
      }
      //EJECUCIÓN DE LAS OPCIONES DEL MENU PRINCIPAL
    } else if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
      seleccionPresionado = 0;
      //OPCIÓN "Programar Alimento"***********************************************************************
      if (menuActual == 2) {
        desplazamientoScroll = 0;
        pesoMascota = 0;           // establecer el peso en 0
        submenuEtapaMascota = -1;  // reinicia la variable para el submenu
        opcionElegidaEtapa = -1;   // reinicia la opción elegida
        menuActual = 0;
        while (true) {
          establecerEtapaMascota();  // se llama a la función para la etapa
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            submenuEtapaMascota = menuActual + 1;  // +1 porque el índice comienza desde 0
            menuActual = 0;                        //igualar el menu al incial
            desplazamientoScroll = 0;              //Sube el scroll al inicio
            break;
          }
          delay(100);
        }
        while (true) {  //se llama a la función para el peso
          establecerPesoMascota();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            delay(100);
            break;
          }
          delay(100);
        }
        while (true) {  //se llama a las funciones para la alarma 1
          establecerHoraAlarma1();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            break;
          }
          delay(100);
        }
        while (true) {
          establecerMinutoAlarma1();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            break;
          }
          delay(100);
        }
        while (true) {  //se llama a la funcion para la alarma 2
          establecerHoraAlarma2();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            break;
          }
          delay(100);
        }
        while (true) {
          establecerMinutoAlarma2();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            break;
          }
          delay(100);
        }
        mostrarMensajeExito();  //Se muestra el mensaje de configuración exitosa

      } else if (menuActual == 3) {
        //OPCIÓN "INFO ACTUAL"****************************************************************************
        auxRetroceder = false;
        while (!auxRetroceder) {
          mostrarInfoActual();  // Mostrar la información actual de la mascota
          manejoRetroceso();    // Verificar si se presiona el botón de retroceso
          delay(100);
        }
        menuActual = 0;
        desplazamientoScroll = 0;
      } else if (menuActual == 0) {
        //OPCIÓN "RECOMENDACIONES"***************************************************************************
        auxRetroceder = false;
        while (!auxRetroceder) {
          mostrarRecomendaciones();  // Mostrar la información actual de la mascota
          manejoRetroceso();         // Verificar si se presiona el botón de retroceso
          delay(100);
        }
        menuActual = 0;
        desplazamientoScroll = 0;
      } else if (menuActual == 1) {
        //OPCIÓN "ALIMENTAR AHORA"****************************************************************************
        while (true) {  //se llama a la función para seleccionar el peso de la mascota
          alimentarAhora();
          if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
          if (digitalRead(pinBotonSeleccion) == HIGH && seleccionPresionado == 1) {
            seleccionPresionado = 0;
            break;
          }
          delay(100);
        }
        servirAlimento(cantidadAlimentarAhora); //Se llama a la funcion para servir el alimento
      } else if (menuActual == 4) {
        //OPCIÓN "BORRAR PROGRAMACIÓN"************************************************************************
        limpiarVariables();
      } else if (menuActual == 5) {
        //OPCIÓN "RELOJ"************************************************************************
        auxRetroceder = false;
        while (!auxRetroceder) {
          mostrarReloj();
          manejoRetroceso();
          delay(100);
        }
        menuActual = 0;
        desplazamientoScroll = 0;
      } else {
        //Mas opciones
        menuActual = 0;
        desplazamientoScroll = 0;
      }
    }
    mostrarMenu(menuPrincipalOpciones, numOpcionesMenuPrincipal);
  }
}
//-----------------------------------------------------------------------------------------------------
