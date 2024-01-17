#include <Arduino.h>
#include "VariablesGlobales.h"
#include "Musica.h"
#include "Imagenes.h"
//FUNCIÓN PARA MOSTRAR LA INFORMACIÓN ACTUAL REGISTRADA Y ALMACENADA***********************************
void mostrarInfoActual() {
  u8g.firstPage();
  do {
    logoPerro();
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 10, "Info Actual");
    if (submenuEtapaMascota == -1) {  // si las variables estan vacias o nulas
      u8g.drawStr(20, 30, "No hay informacion");
      u8g.drawStr(20, 45, "Configure en");
      u8g.drawStr(20, 60, "Programar Alimento");
    } else {  // cuando haya información guardada
      char buffer[30];
      switch (submenuEtapaMascota) {
        case 1:
          sprintf(buffer, "Etapa: Cachorro");
          break;
        case 2:
          sprintf(buffer, "Etapa: Adulto");
          break;
        case 3:
          sprintf(buffer, "Etapa: Senior");
          break;
        default:
          sprintf(buffer, "Etapa: Desconocida");
          break;
      }
      //Mostrar la etapa de la mascota
      u8g.drawStr(10, 20, buffer);
      //Mostrar el peso de la mascota
      sprintf(buffer, "Peso: %d kg", pesoMascota, "kg");
      u8g.drawStr(10, 30, buffer);
      sprintf(buffer, "Alimento x Dia: %d gr", cantidadAlimento, "gr");
      u8g.drawStr(10, 40, buffer);
      //Mostrar la información de la Alarma 1
      sprintf(buffer, "Alarma 1: %02d:%02d", horaAlarma1, minutoAlarma1);
      u8g.drawStr(10, 50, buffer);
      //Mostrar la información de la Alarma 2
      sprintf(buffer, "Alarma 2: %02d:%02d", horaAlarma2, minutoAlarma2);
      u8g.drawStr(10, 60, buffer);
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR RECOMENDACIONES*****************************************************************
void mostrarRecomendaciones() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 15, "Recomendaciones");
    u8g.drawStr(9, 30, "Se recomienda que la");
    u8g.drawStr(9, 45, "porcion suministrada sea");
    u8g.drawStr(9, 60, "el 2% del peso del animal ");
    logoPerro();
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR MENSAJE DE EXITO****************************************************************
void mostrarMensajeExito() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 15, "!Configuracion exitosa!");
    u8g.drawStr(10, 30, "Revise la configuracion");
    u8g.drawStr(10, 45, "en Informacion Actual");
    u8g.drawStr(10, 60, "dentro del menu principal");
  } while (u8g.nextPage());
  efectoSonidoExito();
  delay(3000);
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR MENSAJE CUANDO EL SERVIDO SEA EXITOSO*******************************************
void mensajeServidoExitoso() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(30, 32, "!Servido Exitoso!");
  } while (u8g.nextPage());
  musicaFinalizado();
  noTone(pin_buzzer);
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR MENSAJE CUANDO EL SERVIDO SEA EXITOSO*******************************************
void mensajeServidoEnProceso() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 15, "!Sirviendo Alimento!");
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR MENSAJE CUANDO EL SERVIDO SEA EXITOSO*******************************************
void logoMusicaInicio() {
  u8g.firstPage();
  do {
    logoPerroInicio();
    musicaInicio();
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA MOSTRAR ERROR EN SERVIR ALIMENTO********************************************************
void mensajeErrorServidoAlimento() {
  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_chikita);
    u8g.drawStr(5, 20, "!ERROR!");
    u8g.drawStr(10, 20, "El peso ingresado");
    u8g.drawStr(15, 20, "Es incorrecto");
  } while (u8g.nextPage());
}
//*****************************************************************************************************