#include "HX711.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  //


const int DOUT=3;
const int CLK=2;

HX711 balanza;

void setup() {
  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  balanza.begin(DOUT, CLK);
  Serial.print("Lectura del valor del ADC:  ");
  Serial.println(balanza.read());
  Serial.println("No ponga ningun  objeto sobre la balanza");
  Serial.println("Destarando...");
  Serial.println("...");
  balanza.set_scale(1); // Establecemos la escala
  balanza.tare(20);  //El peso actual es considerado Tara.
  
  Serial.println("Listo para pesar");  
}

void loop() {
  float a = balanza.get_value(10);
  Serial.print("Peso: ");
  lcd.clear();
  lcd.print("Peso:  ");
  Serial.print(a);
  lcd.print(a);
  Serial.println(" kg");
  lcd.print("kg");
  delay(200);
}