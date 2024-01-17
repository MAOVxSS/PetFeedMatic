//Librerias a utilizar
#include "VariablesGlobales.h"
#include "ConfiguracionAlarmas.h"
#include <Arduino.h>
#include "InformacionAlertas.h"
#include "FuncionesMascota.h"
// Variables para almacenar las horas y minutos de las alarmas
int horaAlarma1 = 0;    // Valor inicial de la primera alarma
int minutoAlarma1 = 0;  // Valor inicial de los minutos para la primera alarma
int horaAlarma2 = 0;    // Valor inicial de la segunda alarma
int minutoAlarma2 = 0;  // Valor inicial de los minutos para la segunda alarma
//Auxiliar para las alarmas
bool alarma1Activada = false;
bool alarma2Activada = false;
//FUNCIÓN PARA CONTROLAR LAS HORAS DE LA ALARMA 1******************************************************
void establecerHoraAlarma1() {
  u8g.firstPage();
  do {
    //Se muestra en la lcd como se configura la hora y minuto
    u8g.setFont(u8g_font_chikita);
    mostrarHoraAlarma();
    instruccionesAlarma();
    u8g.drawStr(7, 15, "Alarma 1");
    u8g.drawStr(7, 30, "Hora:");
    char alarmaBuffer[10];
    sprintf(alarmaBuffer, "%02d:%02d", horaAlarma1, minutoAlarma1);
    u8g.drawStr(32, 30, alarmaBuffer);
    //Se controla el contador con los botones de subir y bajar
    if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
    if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
    if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
      arribaPresionado = 0;
      horaAlarma1++;
      if (horaAlarma1 > 24) {
        horaAlarma1 = 0;
      }
    } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
      abajoPresionado = 0;
      horaAlarma1--;
      if (horaAlarma1 < 0) {
        horaAlarma1 = 24;
      }
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA CONTROLAR LOS MINUTOS DE LA ALARMA 1****************************************************
void establecerMinutoAlarma1() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    mostrarHoraAlarma();
    instruccionesAlarma();
    u8g.drawStr(7, 15, "Alarma 1");
    u8g.drawStr(7, 30, "Minuto:");
    char buffer[10];
    sprintf(buffer, "%02d:%02d", horaAlarma1, minutoAlarma1);
    u8g.drawStr(38, 30, buffer);
    if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
    if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
    if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
      arribaPresionado = 0;
      minutoAlarma1++;
      if (minutoAlarma1 > 60) {
        minutoAlarma1 = 0;
      }
    } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
      abajoPresionado = 0;
      minutoAlarma1--;
      if (minutoAlarma1 < 0) {
        minutoAlarma1 = 60;
      }
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA CONTROLAR LAS HORAS DE LA ALARMA 2******************************************************
void establecerHoraAlarma2() {  // se maneja de 0 a 24 horas
  u8g.firstPage();
  do {
    //Se muestra en la lcd como se configura la hora y minuto
    u8g.setFont(u8g_font_chikita);
    mostrarHoraAlarma();
    instruccionesAlarma();
    u8g.drawStr(7, 15, "Alarma 2");
    u8g.drawStr(7, 30, "Hora:");
    char alarmaBuffer[10];
    sprintf(alarmaBuffer, "%02d:%02d", horaAlarma2, minutoAlarma2);
    u8g.drawStr(32, 30, alarmaBuffer);
    //Se controla el contador con los botones de subir y bajar
    if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
    if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
    if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
      arribaPresionado = 0;
      horaAlarma2++;
      if (horaAlarma2 > 24) {
        horaAlarma2 = 0;
      }
    } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
      abajoPresionado = 0;
      horaAlarma2--;
      if (horaAlarma2 < 0) {
        horaAlarma2 = 24;
      }
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA CONTROLAR LOS MINUTOS DE LA ALARMA 2****************************************************
void establecerMinutoAlarma2() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    mostrarHoraAlarma();
    instruccionesAlarma();
    u8g.drawStr(7, 15, "Alarma 2");
    u8g.drawStr(7, 30, "Minuto:");
    char buffer[10];
    sprintf(buffer, "%02d:%02d", horaAlarma2, minutoAlarma2);
    u8g.drawStr(38, 30, buffer);
    if (digitalRead(pinBotonArriba) == LOW) arribaPresionado = 1;
    if (digitalRead(pinBotonAbajo) == LOW) abajoPresionado = 1;
    if (digitalRead(pinBotonArriba) == HIGH && arribaPresionado == 1) {
      arribaPresionado = 0;
      minutoAlarma2++;
      if (minutoAlarma2 > 60) {
        minutoAlarma1 = 0;
      }
    } else if (digitalRead(pinBotonAbajo) == HIGH && abajoPresionado == 1) {
      abajoPresionado = 0;
      minutoAlarma2--;
      if (minutoAlarma2 < 0) {
        minutoAlarma2 = 60;
      }
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA VERIFICAR ALARMAS***********************************************************************
void verificarAlarmas() {
  //Se verifica si hay una alarma para activar
  DateTime now = rtc.now();  // Obtener la hora actual
  int hora = now.hour();
  int minuto = now.minute();
  // Verificar si la hora actual coincide con alguna de las alarmas
  if (hora == horaAlarma1 && minuto == minutoAlarma1 && !alarma1Activada) {
    servirAlimento(cantidadAlimento);
    Serial.print("Entro alarma1");
    alarma1Activada = true;
  } else if (hora == horaAlarma2 && minuto == minutoAlarma2 && !alarma2Activada) {
    servirAlimento(cantidadAlimento);
    alarma2Activada = true;
  }
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR LA HORA ACTUAL******************************************************************
void mostrarHoraAlarma() {
  if (rtc.begin()) {           // verficar si funciona RTC
    DateTime now = rtc.now();  // comprueba si el RTC está disponible
    /*int hour12 = (now.hour() > 12) ? now.hour() - 12 : now.hour();
      if (hour12 == 0) {
        hour12 = 12;
      } //Solo colocar en caso de querer la fecha en formato de 12 horas
      // Imprimir la fecha e: día/mes/año (últimos dos dígitos)
      /*char fechaBuffer[12];  // reserva memoria para la cadena de la fecha
      sprintf(fechaBuffer, "%02d/%02d/%02d", now.day(), now.month(), now.year() % 100);
      u8g.drawStr(50, 7, fechaBuffer);*/
    //Impresion de hora actual
    u8g.drawStr(65, 15, "Tiempo Actual");
    char horaBuffer[10];
    sprintf(horaBuffer, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    u8g.drawStr(65, 24, horaBuffer);
  }
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR INTRUCCIONES EN ALARMA**********************************************************
void instruccionesAlarma() {
  u8g.drawStr(20, 40, "Use los botones para");
  u8g.drawStr(20, 47, "  manejar la hora y ");
  u8g.drawStr(20, 54, "   seleccionarla ");
}
//*****************************************************************************************************