#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> // include i/o class header
hd44780_I2Cexp lcd;
void setup() {
pinMode(2, OUTPUT); // RELE
pinMode(8, INPUT); // Puls A
pinMode(7, INPUT); //  APAGADO
digitalWrite(2, HIGH);
  // inicializa PANTALLA
lcd.begin(20, 4);
lcd.setCursor(0, 0);
lcd.print("     BIENVENIDO  ");
lcd.setCursor(0, 1);
lcd.print("     ˛ ˜ ˝ ");
delay(2000);
lcd.setCursor(0, 0);
lcd.print(" PULSE UN BOTON");
lcd.setCursor(0, 1);
lcd.print(" PARA CONTINUAR");

}

void loop() {

int PulsA=digitalRead(8);
int Pulsoff=digitalRead(7);

if (Pulsoff==LOW&&PulsA==HIGH){
digitalWrite(2, LOW);
delay(1000);
lcd.setCursor(0, 0);
lcd.print(" o       MOTOR  ");
lcd.setCursor(0, 1);
lcd.print("       ENCENDIDO");
delay(100);
lcd.setCursor(0, 0);
lcd.print("  o      MOTOR  ");
lcd.setCursor(0, 1);
lcd.print("       ENCENDIDO");
delay(100);
lcd.setCursor(0, 0);
lcd.print("         MOTOR  ");
lcd.setCursor(0, 1);
lcd.print("  o    ENCENDIDO");
delay(100);
lcd.setCursor(0, 0);
lcd.print("         MOTOR  ");
lcd.setCursor(0, 1);
lcd.print(" o     ENCENDIDO");
}
if (PulsA==LOW&&Pulsoff==HIGH){
digitalWrite(2, HIGH);
delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(" zZz     MOTOR  ");
  lcd.setCursor(0, 1);
  lcd.print(" ---    APAGADO ");
  delay(700);
    lcd.setCursor(0, 0);
  lcd.print(" ZzZ     MOTOR  ");
  lcd.setCursor(0, 1);
  lcd.print(" ---    APAGADO ");
  delay(700);
}
if (PulsA=HIGH&&Pulsoff==LOW){
digitalWrite(2, HIGH);
delay(1000);
  lcd.setCursor(0, 0);
  lcd.print(" zZz     MOTOR  ");
  lcd.setCursor(0, 1);
  lcd.print(" ---    APAGADO ");
  delay(700);
    lcd.setCursor(0, 0);
  lcd.print(" ZzZ     MOTOR  ");
  lcd.setCursor(0, 1);
  lcd.print(" ---    APAGADO ");
  delay(700);
}
}
