#include "LedControl.h"

LedControl lc=LedControl(10,8,9,1);

#define delayTime 500

const bool apagado[8][8] = 
{
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

const bool seta[8][8] = 
{
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0}
};

const bool desenho1[8][8] = 
{
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,1,1,0},
  {1,0,0,1,1,0,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0}
};

const bool desenho2[8][8] = 
{
  {1,0,0,0,0,0,0,1},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,0,0,0,0,1,0},
  {1,0,0,0,0,0,0,1}
};

const bool desenho3[8][8] = 
{
  {1,1,1,0,0,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,0,0,0,0,0,0,1},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,0,0,1,1,1}
};

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  lc.setIntensity(0,5);

}

void loop() {
  // put your main code here, to run repeatedly:
  desenhar(0,seta);
  delay(2000);
  desenhar(0,desenho1);
  delay(2000);
  desenhar(0,desenho2);
  delay(2000);
  desenhar(0,desenho3);
  delay(2000);
  
}

void desenhar(byte disp, bool draw[8][8]){

  for(int y=0; y<=7; y++){
    for(int x=0; x<=7; x++){

      lc.setLed(disp,y,x,draw[y][x]);
      
    }
    
  }
  
}
