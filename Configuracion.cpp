#include <Arduino.h>
#include "VariablesGlobales.h"
void ConfiguracionArduino() {
  digitalWrite(rele, HIGH);  // quita la energia al driver
  digitalWrite(reset, LOW);  // se apaga el motor hasta que se utilice
  u8g.setFont(u8g_font_chikita);
  //u8g.setColorIndex(1);
  pinMode(pinBotonArriba, INPUT_PULLUP);
  pinMode(pinBotonAbajo, INPUT_PULLUP);
  pinMode(pinBotonSeleccion, INPUT_PULLUP);
  pinMode(pinBotonAtras, INPUT_PULLUP);
  pinMode(pasos, OUTPUT);      //definimos pasos como salida digital
  pinMode(direccion, OUTPUT);  //definimos direccion como salida digital
  pinMode(reset, OUTPUT);      //definimos reset como salida digital
  pinMode(rele, OUTPUT);       //definimos rele como salida digital
  pinMode(pin_buzzer, OUTPUT);
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}