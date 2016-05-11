#ifndef _DOH_
#define _DOH_

#include "pos.h"

class dot {
//private:
public:
	int x;
	int y;
	void setpos(int sx,int sy){
		x = sx;
		y = sy;
	}
	void render() {
		display.drawPixel(x,y,BLACK);
		display.drawPixel(x+1,y,BLACK);
		display.drawPixel(x,y+1,BLACK);
		display.drawPixel(x+1,y+1,BLACK);
	}
	pos posit(){
		pos pos1;
		pos1.cor1 = x;
		pos1.cor2 = y;
		return pos1;
	}
};

#endif
