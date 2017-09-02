#include "LedControlMS.h"
#define NumMatrix 1

int a=0,b=0,a1=0,b1=0; //variables para el led pwm

char button0=3, button1=4, button2=5, button3=6, sel=2; //variables de los botones

int row = 7,col=7,arriba=0,abajo=0,derecha=0,izquierda=0; //variables para mover punto

int dibujo[8][8]= {0} ;

 LedControl lc = LedControl(13,12,11, NumMatrix); 
void setup(void)
{
 
  
  pinMode(sel, INPUT);      //Set the Joystick 'Select'button as an input
  digitalWrite(sel, HIGH);  //Enable the pull-up resistor on the select button
  
  pinMode(button0, INPUT_PULLUP);      //Set the Joystick button 0 as an input
  digitalWrite(button0, LOW);  //Enable the pull-up resistor on button 0

  pinMode(button1, INPUT);      //Set the Joystick button 1 as an input
  digitalWrite(button1, LOW);  //Enable the pull-up resistor on button 1
  
  pinMode(button2, INPUT);      //Set the Joystick button 2 as an input
  digitalWrite(button2, HIGH);  //Enable the pull-up resistor on button 2

  pinMode(button3, INPUT);      //Set the Joystick button 3 as an input
  digitalWrite(button3, LOW);  //Enable the pull-up resistor on button 3

  
  Serial.begin(9600);           //Turn on the Serial Port at 9600 bps

  for (int i=0; i< NumMatrix ; i++)
   {
       lc.shutdown(i,false);  // Activar la matriz
       lc.setIntensity(i,8);  // Poner el brillo a un valor intermedio
       lc.clearDisplay(i);    // Y borrar todo
   }
}


void loop(){
  // put your main code here, to run repeatedly:
    
    led();
    direccionv();
    direccionh();
    matriz();
    lc.setLed(0,col,row,true);
    delay(50);
    reset();
    lc.clearAll();

  
}

void led(){
  
  a = analogRead(A0);       
  b = analogRead(A1);

  a1= map(a,0,1023,0,255);
  b1= map(b,0,1023,0,255);

  analogWrite(8,a1);
  analogWrite(9,b1);

}

void matriz(){
  if(arriba == 1 && row<7){row++;}
  if(abajo == 1 && row>0){row--;}
  if(derecha == 1 && col<7){col++;}
  if(izquierda == 1 && col>0){col--;}
}

void direccionh(){
  if(b>1000){
    abajo=1;  
  }else if(b<100){
    arriba=1;
  } 
}

void direccionv(){
    if(a>1000){
    izquierda=1;
  }else if(a<25){
    derecha=1;
  } 
}



void reset(){
  arriba = 0;
  abajo = 0;
  derecha = 0;
  izquierda = 0;
}

