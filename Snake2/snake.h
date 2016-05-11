#ifndef _SNH_
#define _SNH_

#include "pos.h"

class Snake {

private:
	//for
	int body1[20][2];
	int body2[20][2];
	int len;
	
	//int next[1][2];
public:
	//int head[1][2];
	//head[0][] = body[0][];
	int right;
	int left;
	int up;
	int down;
	Snake() {
		body1[0][0] = 54;
		body1[0][1] = 16;
		body1[0][0] = 53;
    body1[0][1] = 16;
    body1[0][0] = 52;
    body1[0][1] = 16;
    body1[0][0] = 51;
    body1[0][1] = 16;
    body1[0][0] = 50;
    body1[0][1] = 16;
		right = 1;
		left = 0;
		down = 0;
		up = 0;
		len = 5;
		}
	void render() {
		for(int a = 0; a < len; a = a+ 1 ){
			display.drawPixel(body1[a][0],body1[a][1],BLACK);
			display.drawPixel(body2[a][0],body2[a][1],BLACK);	
		} 
	}
	void update1(){
		for(int i = len;i > 0; i = i - 1){
			body1[i][0] = body1[i - 1][0];
		  body1[i][1] = body1[i - 1][1];
			body2[i][0] = body2[i - 1][0];
			body2[i][1] = body2[i - 1][1];
		}
    body1[0][0] = body1[1][0] - left + right;		
		body1[0][1] = body1[1][1] - up + down;		
		body2[0][0] = body1[0][0] - up + down;		
		body2[0][1] = body1[0][1] - left + right;		
	}
	int win_check(){
		if (len == 50){
			return 1;
		}
		else{
			return 0;
		}		
	}
	int kill_check(){
		if (body1[0][0] == 84 || body1[0][1] == 48 || body1[0][0] == -1 || body1[0][1] == -1){
			return 1;
		}  
		else{
			return 0;
		}	
	}
	void t_right(){
		right = 1;
		left = 0;
		down = 0;
		up = 0;
	}
	void t_left(){
		right = 0;
		left = 1;
		down = 0;
		up = 0;
	}	
	void t_up(){
		right = 0;
		left = 0;
		down = 0;
		up = 1;
	}	
	void t_down(){
		right = 0;
		left = 0;
		down = 1;
		up = 0;
	}
	void swallow(){
		len = len + 1;
    //serial.println(len)
		update1();
	}
	int score(){
		return len - 5;
	}
	pos posit(){
		pos pos1;
		pos1.cor1 = body1[0][0];
		pos1.cor2 = body1[0][1];
		return pos1;
	}
};

#endif
