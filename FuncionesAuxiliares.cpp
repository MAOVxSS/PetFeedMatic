#include <Arduino.h>
#include "VariablesGlobales.h"
#include "Imagenes.h"

bool auxRetroceder = false;   //Maneja el boton de retroceso
const int velocidad = 12000;  //velocidad de giro del motor, cuanto menos valor + velocidad
const int pasos = 2;          // pin para STEP
const int direccion = 3;      // pin para DIR
const int reset = 8;          // para colocar en enable al motor
const int rele = 9;           //Control del rele para administrar o no voltaje al driver
int totalPasos = 50;          //pasos para completar un avance

//FUNCIÓN PARA CONTROLAR EL ESTADO DEL BOTON DE RETROCESO**********************************************
void manejoRetroceso() {
  if (digitalRead(pinBotonAtras) == LOW) atrasPresionado = 1;
  // siempre que se presione el boton, se cambiara el estado de aux
  if (digitalRead(pinBotonAtras) == HIGH && atrasPresionado == 1) {
    atrasPresionado = 0;
    while (digitalRead(pinBotonAtras) == HIGH && atrasPresionado == 1) {
      atrasPresionado = 0;
      delay(50);
    }
    auxRetroceder = true;
  }
}
//*****************************************************************************************************
//FUNCIÓN PARA LIMPIAR VARIABLES***********************************************************************
void limpiarVariables() {
  submenuEtapaMascota = -1;
  pesoMascota = 0;
  horaAlarma1 = 0;
  minutoAlarma1 = 0;
  horaAlarma2 = 0;
  minutoAlarma2 = 0;
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(15, 15, "!Limpieza exitosa!");
    u8g.drawStr(10, 30, "Vuelva a programar en la");
    u8g.drawStr(10, 45, "opcion Programar Alimento");
    u8g.drawStr(10, 60, "dentro del menu principal");
  } while (u8g.nextPage());
  delay(5000);
}
//*****************************************************************************************************
//FUNCIÓN GIRAR EL MOTOR*******************************************************************************
void girarMotor() {
  digitalWrite(rele, LOW);       // proporciona energia al driver
  digitalWrite(reset, HIGH);     // enciende el motor
  digitalWrite(direccion, LOW);  //establece la direccion de giro
  for (int i = 0; i < totalPasos; i++) {
    digitalWrite(pasos, HIGH);
    digitalWrite(pasos, LOW);
    delayMicroseconds(velocidad);
  }
  //delay(cantidadAlimento*5);        //espera dependiendo de la cant de alimento

  /*digitalWrite(direccion, HIGH);  // establece la dirección opuesta
  for (int i = 0; i < totalPasos; i++) {
    digitalWrite(pasos, HIGH);
    digitalWrite(pasos, LOW);
    delayMicroseconds(velocidad);
  }*/
  digitalWrite(rele, HIGH);  // quita energia al driver
}
//*****************************************************************************************************