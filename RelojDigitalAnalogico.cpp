#include <Wire.h>
#include <Arduino.h>
#include "RelojDigitalAnalogico.h"
#include "VariablesGlobales.h"
//Definir objetos, para reloj y pantalla lcd
char* dia_semana[] = { //Dias de la semana 
  "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"
};
//Variables para controlar la posicion de las manecillas del reloj análogico
int X2 = 0;
int Y2 = 0;
int X3 = 0;
int Y3 = 0;
float angulo = 0;
//Manejo de los "0" en el reloj digital par siempre tener 2 digitos
int posicionHora = 0;
int posicionMinuto = 0;
//Dimensiones y posicion de la pantalla lcd
int anchoPantalla = 128;
int centroAnchoPantalla = 96;
int alturaPantalla = 64;
int centroAlturaPantalla = 32;
//FUNCIÓN QUE MUESTRA LA PANTALLA DE RELOJ*************************************************************
void mostrarReloj() {
  u8g.firstPage();
  do {
    if (rtc.begin()) {
      u8g.drawRFrame(0, 0, anchoPantalla, alturaPantalla, 3);
      DateTime now = rtc.now();
      //Dibujo de la fecha actual
      u8g.setFont(u8g_font_5x8);
      u8g.setPrintPos(8, 55);
      u8g.print(now.day());
      u8g.drawStr(19, 55, "/");
      u8g.setPrintPos(24, 55);
      u8g.print(now.month());
      u8g.drawStr(35, 55, "/");
      u8g.setPrintPos(41, 55);
      u8g.print(now.year());
      u8g.setPrintPos(20, 41);
      //Se establece que dia de la semana es
      u8g.print(dia_semana[(now.dayOfTheWeek())]);
      //Dibujo del reloj analogico con su fondo
      u8g.drawRBox(3, 4, 62, 21, 2);
      u8g.setColorIndex(0);
      u8g.setFont(u8g_font_fub17);
      u8g.drawStr(29, 21, ":");
      //Verficar que siempre haya dos digitos en los min y h
      if (now.hour() < 10) {
        u8g.drawStr(3, 23, "0");
        posicionMinuto = 16;
      } else posicionMinuto = 3;
      u8g.setPrintPos(posicionMinuto, 23);
      u8g.print(now.hour());
      if (now.minute() < 10) {
        u8g.drawStr(38, 23, "0");
        posicionHora = 51;
      } else posicionHora = 38;
      u8g.setPrintPos(posicionHora, 23);
      u8g.print(now.minute());
      u8g.setColorIndex(1); //color de los numeros (blanco)
      //Dibujo del reloj análogico
      u8g.drawCircle(centroAnchoPantalla, centroAlturaPantalla, 27);
      u8g.drawCircle(centroAnchoPantalla, centroAlturaPantalla, 1);
      u8g.setFont(u8g_font_6x13);
      u8g.setFontPosTop(); //Se establece la posicion de dibujo, esquina superior izq
      u8g.drawStr(90, 9, "12"); //Referencias horarias
      u8g.drawStr(114, 25, "3");
      u8g.drawStr(94, 44, "6");
      u8g.drawStr(74, 25, "9");
      //Se dibujan los minutos como manecilla en el reloj
      for (int manecillaMinuto = 0; manecillaMinuto < 12; manecillaMinuto++) {
        //Posicion de la manecilla respecto al centro del circulo
        angulo = manecillaMinuto / 12.0 * 2 * 3.1415;
        X2 = centroAnchoPantalla + 25 * cos(angulo);
        Y2 = centroAlturaPantalla + 25 * sin(angulo);
        X3 = centroAnchoPantalla + 25 * cos(angulo);
        Y3 = centroAlturaPantalla + 25 * sin(angulo);
        u8g.drawLine(X2, Y2, X3, Y3);
      }
      //Actualizacion de la manceilla por horas, minutos y segundos
      dibujoManecilla(now.hour() - 1, 12.0, 10);
      dibujoManecilla(now.minute() - 5, 60.0, 19);
      dibujoManecilla(now.second() - 5, 60, 21);
    }
  } while (u8g.nextPage());
}
//*****************************************************************************************************
//FUNCIÓN PARA DIBUJAR LAS MANECILLA DEL RELOJ*********************************************************
void dibujoManecilla(float valor, float rotacion, int radioMax) {
  angulo = valor * 2.0 * 3.1415 / rotacion - 1, 5707;
  X2 = centroAnchoPantalla + radioMax * cos(angulo);
  Y2 = centroAlturaPantalla + radioMax * sin(angulo);
  u8g.drawLine(centroAnchoPantalla, centroAlturaPantalla, X2, Y2);
}
//*****************************************************************************************************
