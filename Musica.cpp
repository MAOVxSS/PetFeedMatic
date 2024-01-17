#include <Arduino.h>
#include "VariablesGlobales.h"

const int pin_buzzer = 10;


void musicaFinalizado() {
  tone(pin_buzzer, 195, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 261, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 329, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 391, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 523, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 659, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 783, 353.710935);
  delay(393.01215);
  delay(20.68485);
  tone(pin_buzzer, 659, 353.710935);
  delay(393.01215);
  delay(20.68485);
  tone(pin_buzzer, 207, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 261, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 311, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 415, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 523, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 622, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 830, 353.710935);
  delay(393.01215);
  delay(20.68485);
  tone(pin_buzzer, 622, 353.710935);
  delay(393.01215);
  delay(20.68485);
  tone(pin_buzzer, 233, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 293, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 349, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 466, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 587, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 698, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 932, 353.710935);
  delay(393.01215);
  delay(20.68485);
  tone(pin_buzzer, 932, 117.903645);
  delay(131.00405);
  delay(6.03308125);
  tone(pin_buzzer, 932, 117.903645);
  delay(131.00405);
  delay(6.89495);
  tone(pin_buzzer, 932, 117.127963125);
  delay(130.14218125);
  delay(8.6186875);
  tone(pin_buzzer, 659, 353.710935);
  delay(393.01215);
}
void efectoSonidoExito() {
  tone(pin_buzzer, 1318, 61.363575);
  delay(68.18175);
  delay(68.18175);
  tone(pin_buzzer, 1567, 61.363575);
  delay(68.18175);
  delay(68.18175);
  tone(pin_buzzer, 2637, 61.363575);
  delay(68.18175);
  delay(68.18175);
  tone(pin_buzzer, 2093, 61.363575);
  delay(68.18175);
  delay(68.18175);
  tone(pin_buzzer, 2349, 61.363575);
  delay(68.18175);
  delay(68.18175);
  tone(pin_buzzer, 3135, 613.63575);
  delay(681.8175);
}
void musicaInicio() {
  tone(pin_buzzer, 146, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 146, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 146, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 195, 534.375);
  delay(593.75);
  delay(531.25);
  tone(pin_buzzer, 195, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 220, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 246, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 261, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 293, 808.59375);
  delay(898.4375);
  delay(226.5625);
  tone(pin_buzzer, 293, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 293, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 293, 84.375);
  delay(93.75);
  delay(31.25);
  tone(pin_buzzer, 391, 534.375);
  delay(593.75);
  delay(531.25);
  tone(pin_buzzer, 391, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 440, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 493, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 523, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 587, 267.1875);
  delay(296.875);
  delay(78.125);
  tone(pin_buzzer, 184, 196.875);
  delay(218.75);
  delay(62.5);
  tone(pin_buzzer, 184, 63.28125);
  delay(70.3125);
  delay(23.4375);
  tone(pin_buzzer, 246, 267.1875);
  delay(296.875);
}