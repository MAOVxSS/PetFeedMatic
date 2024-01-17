#include <Arduino.h>
#include "VariablesGlobales.h"
#include "Imagenes.h"
#include "MenuEncabezados.h"
#include "FuncionesAuxiliares.h"
#include "InformacionAlertas.h"

//Variables para las funciones de etapa, peso ...
int opcionElegidaEtapa = -1;        // Guarda el id de la etapa elegida
int submenuEtapaMascota = -1;       // Almacenar la etapa en variable extra
int pesoMascotaSeleccionado = 0;    // Contador de peso de la mascota
int pesoMascota = 0;                // Almacenar el peso de la mascota
int cantidadAlimento = 0;           // Cantidad de alimento recomendado para la mascota segun su peso
int cantidadAlimentarAhora = 0;     // Cantidad de alimento a suministrar en la opcion "Alimentar Ahora"
int pesoMascotaAlimentarAhora = 0;  // Peso de la mascota en la opcion "Alimentar Ahora"
int pesoMascotaSeleccionadoAlimentarAhora = 0;

//FUNCIÓN PARA MANEJAR LA ETAPA DE LA MASCOTA**********************************************************
void establecerEtapaMascota() {
  auxEncabezado = true;
  //Lectura de los botones para saber sus estados
  if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
  if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
  if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;

  if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {  //Subir selección
    arribaPresionado = 0;
    menuActual--;
    if (menuActual < 0) {
      /* si el menuActual llega a -1, se iguala a la ultima opción, 
      estableciendolo en el indice de la ultima opción */
      menuActual = numOpcionesEtapasMascota;
    }
  } else if ((digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1)) {  // bajar selección
    abajoPresionado = 0;
    menuActual++;
    if (menuActual >= numOpcionesEtapasMascota) {
      menuActual = 0;
    }
  }
  //Muestra el menu en la lcd
  mostrarMenu(submenuEtapaMascotaOpciones, numOpcionesEtapasMascota);
}
//*****************************************************************************************************
//FUNCIÓN PARA MANEJAR EL PESO DE LA MASCOTA***********************************************************
void establecerPesoMascota() {
  if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
  if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
  if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
  //Con los botones se aumenta o dismuye la seleccion del peso, hasta seleccionarla
  //El valor maximo es 60 pero se puede modificar
  if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
    arribaPresionado = 0;
    pesoMascotaSeleccionado++;
    if (pesoMascotaSeleccionado > 60) {
      pesoMascotaSeleccionado = 60;
    }
  } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
    abajoPresionado = 0;
    pesoMascotaSeleccionado--;
    if (pesoMascotaSeleccionado < 0) {
      pesoMascotaSeleccionado = 0;
    }
  }
  cantidadAlimento = ((pesoMascota * 1000) * 2) / 100;
  // Mostrar el peso de la mascota en la pantalla
  u8g.firstPage();
  do {
    logoPerro();
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 15, "Peso de la Mascota:");
    char pesoBuffer[10];
    sprintf(pesoBuffer, "Peso: %d (kilos)", pesoMascotaSeleccionado, "(kilos)");
    pesoMascota = pesoMascotaSeleccionado;  // se guarda el peso de la mascota en otra variable
    u8g.drawStr(20, 40, pesoBuffer);
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA MANEJAR EL DISPENSADO DE ALIMENTO*******************************************************
void servirAlimento(int peso) {
  Serial.print(peso);
  int aux = 0;          //Auxiliar para seleccionar el rango de peso de la mascota
  int auxPeso = 0;      //Auxiliar para saber cuantas veces girar el motor
  auxPeso = peso / 20;  //Se divide entre 20 porque cada giro de motor proporciona un aproximado de 20g
  Serial.print(auxPeso);
  if (auxPeso == 0) {
    void mensajeErrorServidoAlimento();  //Si el peso ingresado es 0
  } else {
    mensajeServidoEnProceso();
    /*Las veces en que se abre la compuerta de alimento
                        tienen que ser con intervalos pequeños y sin tantos pasos
                        para evitar cuellos de botella */
    for (int i = 0; i < auxPeso; i++) {
      girarMotor();
      delay(1300);
    }
    mensajeServidoExitoso();  //Se reproduce la musica para saber que el alimento esta servido 
  }
}
//*****************************************************************************************************
//FUNCIÓN PARA MANEJAR EL DISPENSADO DE ALIMENTO*******************************************************
void alimentarAhora() {
  if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
  if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
  if (digitalRead(pinBotonSeleccion) == LOW) seleccionPresionado = 1;
  //Con los botones se aumenta o dismuye la seleccion del peso, hasta seleccionarla
  //El valor maximo es 60 pero se puede modificar
  if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
    arribaPresionado = 0;
    pesoMascotaSeleccionadoAlimentarAhora++;
    if (pesoMascotaSeleccionadoAlimentarAhora > 60) {
      pesoMascotaSeleccionadoAlimentarAhora = 60;
    }
  } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
    abajoPresionado = 0;
    pesoMascotaSeleccionadoAlimentarAhora--;
    if (pesoMascotaSeleccionadoAlimentarAhora < 0) {
      pesoMascotaSeleccionadoAlimentarAhora = 0;
    }
  }
  cantidadAlimentarAhora = ((pesoMascotaAlimentarAhora * 1000) * 2) / 100;
  // Mostrar el peso de la mascota en la pantalla
  u8g.firstPage();
  do {
    logoPerro();
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 15, "Peso de la Mascota:");
    char pesoBuffer[10];
    sprintf(pesoBuffer, "Peso: %d (kilos)", pesoMascotaSeleccionadoAlimentarAhora, "(kilos)");
    pesoMascotaAlimentarAhora = pesoMascotaSeleccionadoAlimentarAhora;  // se guarda el peso de la mascota en otra variable
    u8g.drawStr(20, 40, pesoBuffer);
  } while (u8g.nextPage());
}
//*****************************************************************************************************
