#ifndef _SNAKEH_
#define _SNAKEH_

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7,6,5,3,4);

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  
#include "snake.h"
#include "dot.h"
#include "pos.h"

Snake s;
dot d;
int rl,ud;
pos do1,sn;
int dot_gen = 1;
int button_cont = 0;
int joy_cont = 0;
int RL_PIN = 13;
int UD_PIN = 12;
//int ms = 0; //can be used to select difficulty by controlling the delay in some form

void loop(){}

void setup() {
  Serial.begin(9600);
  display.begin();
  display.setContrast(30);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  //Welcome Screen
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(15,11);
  display.println("Welcome to Snaketron 500");
  display.display();
  delay(2000);
  
  //Mode Selection
//  while (button_cont == 0){
//    if (joy_cont == 1 && ms == 0){
//      ms = 1;
//    }
//    else if (joy_cont == 1 && ms == 1){
//      ms = 0; 
//    }
//  }
  
  //Scoreboard Display
//  display1.setTextSize(1);
//  display1.setTextColor(WHITE);
//  display1.setCursor(55,11);
//  display1.println("Score:");
//  display1.setCursor(65,11);
//  display1.println(s.score());
  
  //Game Start Animation
  
  //resetGame();
  
  while(s.win_check() + s.kill_check() == 0) {
    if (dot_gen == 1){
    int x = random(0,83);
    int y = random(0,47);
    d.setpos(x,y);
    dot_gen = 0;
    }
    getInput();
    drawLCD();
    delay(100);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(10,10);
  display.println("Game Over!");
  display.display();
  delay(1000);
  drawLCDend();
  }

void getInput() {
	rl = digitalRead(RL_PIN);
	ud = digitalRead(UD_PIN);
  if (rl == HIGH && (s.left == 1 || s.down == 1 || s.up == 1)) { // push right
		s.t_right();
	} 
	else if (rl == HIGH && s.right == 1) { // push left
		s.t_left();
	} 
	else if (ud == HIGH && (s.down == 1 || s.right == 1 || s.left == 1)) { // push up
		s.t_up();
	} 
	else if (ud == HIGH && s.up == 1) { // push down
		s.t_down();
	}
}

void drawLCD() {
	display.clearDisplay();
	d.render();
	s.render();   
	do1 = d.posit();	
	sn = s.posit();	
	if ((do1.cor1 == sn.cor1 || do1.cor1 == sn.cor1 + 1 || do1.cor1 == sn.cor1 - 1) && (do1.cor2 == sn.cor2 || do1.cor2 == sn.cor2 + 1 || do1.cor2 == sn.cor2 - 1)){
	s.swallow();
  //Serial.println(s.score());
	dot_gen = 1;
	}
	else {
	s.update1();
	}
	//if (s.win_check() + s.kill_check() == 0){
	//}
	//else{
	display.display();
}

void drawLCDend(){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1);
  display.setCursor(21,11);
  display.println("Score:");
  display.setCursor(66,11);
  display.println(s.score());
  display.display();
}
#endif
