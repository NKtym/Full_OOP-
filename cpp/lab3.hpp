#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class tPoint{
public:
	tPoint():x(rand()%800),y(rand()%600),dirx((float)(rand()%2)/10),diry((float)(rand()%2)/10),flagx(0),flagy(0)
	{
		sf::Color cool[]={sf::Color::Red, sf::Color::White, sf::Color::Blue, sf::Color::Yellow}; 
		c=cool[rand()%4]; 
		while(!(dirx+diry)){
			dirx=(float)(rand()%2)/10;
			diry=(float)(rand()%2)/10;
		}
	}
	~tPoint(){}
	float getx(){
		return x;
	}
	float gety(){
		return y;
	}
	sf::Color getc(){
		return c;
	}
	void rand_move(){
		int random = rand()%4;
		if(random==0 && x<=796)
			x++;
		else if(random==1 && x>=4)
			x--;
		else if(random==2 && y<=596)
			y++;
		else if (random==3 && y>=4)
			y--;
	}
	void line_move(){
		if(x+dirx>769){
			flagx = 1;
		}
		else if(x-dirx<4){
			flagx = 0;
		}
		if(y+diry>596){
			flagy = 1;
		}
		else if(y-diry<4){
			flagy = 0;
		}
		if(!flagx)
			x+=dirx;
		else
			x-=dirx;
		if(!flagy)
			y+=diry;
		else
			y-=diry;
	}
private:
	float x;
	float y;
	sf::Color c;
	float dirx;
	float diry;
	int flagx;
	int flagy;
};
