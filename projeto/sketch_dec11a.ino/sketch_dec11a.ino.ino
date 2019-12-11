#include <SoftwareSerial.h>

int led_verde = 7;
int buzzer = 2;
char caracter;

//pinos:
SoftwareSerial serial1(10, 11); // TX e RX do bluetooth HC-05

void setup() {
  pinMode(led_verde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  serial1.begin(9600); // bluetooth
  Serial.begin(9600); //monitor
}

void loop() {

  ler_BT();
  

  /*
  Serial.println("Informe um número");
  int teste = Serial.read();
  switch (teste){
    case 1: 
    pisca();
    break;
    case 2:
    nota_teste();
    break;
    
  }
*/
}

void ler_BT() {

  if (serial1.available()) {
    caracter = serial1.read();
    Serial.println(caracter);
   if(caracter == 'S'){
      noTone();
   }
    if(caracter == 'F'){
      nota_do();
    }
    if(caracter == 'B'){
      nota_re();
    }
    if(caracter == 'L'){
      nota_mi();
    }
     if(caracter == 'R'){
      nota_fa();
    }
    if(caracter == 'I'){
      nota_sol();
    }
    if(caracter == 'G'){
      nota_la();
    }
    if(caracter == 'J'){
      nota_si();
  }
  if(caracter == 'H'){
      nota_doOitava();
  }
  
  }
}

void pisca() {
  digitalWrite(led_verde, HIGH);
  delay(500);
  digitalWrite(led_verde, 0);
  delay(500);
}

void nota_do() {
  tone(buzzer, 262);
  delay(25);
  
}
void nota_re() {
  tone(buzzer, 294);
  delay(25);
}
void nota_mi() {
  tone(buzzer, 330);
  delay(25);
}
void nota_fa() {
  tone(buzzer, 349);
  delay(25);
}
void nota_sol() {
  tone(buzzer, 392);
  delay(25);
}
void nota_la() {
  tone(buzzer, 440);
  delay(25);
}
void nota_si() {
  tone(buzzer, 494);
  delay(25);
}
void nota_doOitava() {
  tone(buzzer, 523);
  delay(25);
}
void nota_teste() {
  tone(buzzer, 264);
  delay(500);
}

