#include <Servo.h>

// Pins dos Servos
#define base_pin 3
#define b1_pin 5
#define b2_pin 6
#define garra_pin 9

#define DELAY 30 

// Pins dos botões: b1 - esquerdo ; b2 - direito
int base_b1 = 13;
int base_b2 = 12;
int braco1_b1 = 11;
int braco1_b2 = 10;
int braco2_b1 = 8;
int braco2_b2 = 7;
int garra_b = 4;

// Definição dos Servos
Servo base;
Servo braco1;
Servo braco2;
Servo garra;

int pos_base = 90;
int pos_braco1 = 95;
int pos_braco2 = 95;


void setup() {

  base.attach(base_pin);
  braco1.attach(b1_pin);
  braco2.attach(b2_pin);
  garra.attach(garra_pin);

  base.write(90);
  braco1.write(95);
  braco2.write(95);
  garra.write(80);
  Serial.begin(9600);

  pinMode(base_b1,INPUT);
  pinMode(base_b2,INPUT);
  pinMode(braco1_b1, INPUT);
  pinMode(braco1_b2, INPUT);
  pinMode(braco2_b1, INPUT);
  pinMode(braco2_b2, INPUT);
  pinMode(garra_b, INPUT);
}

void loop() {
  
  trataServo(base, base_b1, base_b2,&pos_base,0,170);
  trataServo(braco1, braco1_b1, braco1_b2, &pos_braco1, 90,180);
  trataServo(braco2, braco2_b1, braco2_b2, &pos_braco2, 50,180);

  if(digitalRead(garra_b))
    garra.write(110);
  else
    garra.write(65);
 
}





void trataServo (Servo servo, int b1, int b2, int* pos, int Vmin, int Vmax)
{

  if(*pos == Vmin)
    *pos = Vmin+5;

  if(*pos == Vmax)
    *pos = Vmax-5;

  if(digitalRead(b1)) {
    
    if(*pos > Vmin+1 && *pos < Vmax-1) {
      servo.write((*pos)++);
      Serial.println(*pos);  
      delay(DELAY);
    }

  }

  if(digitalRead(b2)) {
    
     if(*pos > Vmin && *pos < Vmax) {
          servo.write((*pos)--);
          Serial.println(*pos);  
          delay(DELAY);
        }    
  }

}

