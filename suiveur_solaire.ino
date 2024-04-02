#include <Servo.h>.
#define dtime 14
#define trechold 50
#define TL A2
#define TR A3
#define BL A1
#define BR A0
#define HORLIM 220
#define VERLIM 220
int horpas = HORLIM / 2;
int verpas = VERLIM / 2;
Servo Servohor;              //The servo object
Servo Servover;   
void setup()
{
Servohor.attach(9);
Servover.attach(10);
}
void loop(){
track();
}
void track()
{
  //Input Reading
   int  tl = analogRead(TL);
 int  tr = analogRead(TR);
  int  bl = analogRead(BL);
   int  br = analogRead(BR);
   int avtop = (tl +tr ) / 2;
   int avtdawn = (bl +br ) / 2;  
   int avtleft = (tl +bl ) / 2;
   int avtright = (tr +br ) / 2;
 int difver =avtop - avtdawn ;
  int difhor =avtleft -  avtright ;
 if (( ( -1*trechold)<=difver)&& (difver <=trechold))
 {
Servover.detach();
 }
 else{
 Servover.attach(10);
  
   if (avtop > avtdawn)
   {
     verpas= --verpas;
      if (verpas > VERLIM)
      {
       Servover.detach();
        verpas = VERLIM;
      }
   }
   else if  ( avtop <avtdawn  )
   { verpas = ++verpas;
    if (verpas < 0 ) {
      Servover.detach();
        verpas = 0;
 } 
 }
 else if(avtop ==avtdawn){
 }
    Servover.write( verpas);
  }
  if ((( -1*trechold)<=difhor)&& (difhor<=trechold))
 {
Servohor.detach();
 }
 else{
 Servohor.attach(9);
  
   if (avtleft > avtright)
   {
     horpas= --horpas;
      if  ( horpas <  0){  
       Servohor.detach();
        horpas = 0;
      }  
       
   }
   else if  ( avtleft < avtright )
   { horpas= ++horpas;
     if (horpas>HORLIM )
     {
      Servohor.detach();
        horpas = HORLIM ;
 } 
 }
 else if(avtleft ==avtright){
 }
    Servohor.write( horpas);
  }
  delay(dtime);
  }