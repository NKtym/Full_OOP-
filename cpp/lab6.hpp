#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#define HEIGHT 1080 
#define LENGTH 1920

class tFigur{
protected:
	float x;
	float y;
	int height;
	int length;
	int flagx;
	int flagy;
	float dirx;
	float diry;
	sf::Color c;
	float corner;
public:
	tFigur():dirx((float)(rand()%2)/10),diry((float)(rand()%2)/10),flagx(0),flagy(0),corner(0){
		sf::Color cool[]={sf::Color::Red, sf::Color::White, sf::Color::Blue, sf::Color::Yellow}; 
		c=cool[rand()%4]; 
		while(!(dirx+diry)){
			dirx=(float)(rand()%2)/10;
			diry=(float)(rand()%2)/10;
		}
	}
    tFigur(float a, float b, int dirsx = 1, int dirsy = 1):dirx((float)(dirsx)/10),diry((float)(dirsy)/10),flagx(0),flagy(0),corner(0), x(a), y(b){
		sf::Color cool[]={sf::Color::Red, sf::Color::White, sf::Color::Blue, sf::Color::Yellow}; 
		c=cool[rand()%4];
	}
	~tFigur(){}
	float getx();
	float gety();
	sf::Color getc();
	int getheight();
	int getlength();
	float getcorner();
	virtual void line_move();
	virtual void roll_move();
	virtual void draw(sf::RenderWindow &window);
};

class tPoint : public tFigur{
public:
	tPoint():tFigur(){
		height=10;
		length=10;
		x=rand()%(LENGTH-length);
		y=rand()%(HEIGHT-height);
	}
    tPoint(float a, float b):tFigur(a, b){
		height=10;
		length=10;
	}
	~tPoint(){}
	void draw(sf::RenderWindow &window) override;
};

class tCircle : public tFigur{
public:
	tCircle():tFigur(){
		height=200;
		length=200;
		x=rand()%(LENGTH-length);
		y=rand()%(HEIGHT-height);
	}
	tCircle(float a, float b):tFigur(a, b){
		height=200;
		length=200;
	}
	~tCircle(){}
	void draw(sf::RenderWindow &window) override;
};

class tLine : public tFigur
{
public:
    	tLine():tFigur(){
    		length = 200;
    		height = 2;
    		x=rand()%(LENGTH-length);
			y=rand()%(HEIGHT-height);
    	}
		tLine(float a, float b):tFigur(a, b){
			height=2;
			length=200;
		}
    	~tLine(){}
    	void draw(sf::RenderWindow &window) override;
};


class tRectangle : public tFigur
{
public:
    	tRectangle():tFigur(){
    		length = 400;
			height = 100;
    		x=rand()%(LENGTH-length);
			y=rand()%(HEIGHT-height);
    	}
		tRectangle(float a, float b):tFigur(a, b){
			height=100;
			length=400;
		}
    	~tRectangle(){}
    	void draw(sf::RenderWindow &window) override;
};

class tEllipse : public tFigur
{
public:
    	tEllipse():tFigur(){
    		length = 300;
			height = length / 2;
    		x=rand()%(LENGTH-length);
			y=rand()%(HEIGHT-height);
    	}
		tEllipse(float a, float b):tFigur(a, b){
			length=300;
			height=length / 2;
		}
    	~tEllipse(){}
    	void draw(sf::RenderWindow &window) override;
};

class tTriangle : public tFigur
{
public:
    	tTriangle():tFigur(){
    		length = 300;
			height = 200;
    		x=rand()%(LENGTH-length);
			y=rand()%(HEIGHT-height);
    	}
		tTriangle(float a, float b):tFigur(a, b){
			length=300;
			height=200;
		}
    	~tTriangle(){}
    	void draw(sf::RenderWindow &window) override;
};

class tRhombus : public tFigur
{
public:
    	tRhombus():tFigur(){
    		length = 200;
			height = 200;
    		x=rand()%(LENGTH-length);
			y=rand()%(HEIGHT-height);
    	}
		tRhombus(float a, float b):tFigur(a, b){
			length=200;
			height=200;
		}
    	~tRhombus(){}
    	void draw(sf::RenderWindow &window) override;
};

float tFigur::getx()
{
	return (float)x;
}

float tFigur::gety()
{
	return (float)y;
}

int tFigur::getheight()
{
	return height;
}

int tFigur::getlength()
{
	return length;
}

float tFigur::getcorner()
{
	return corner;
}

sf::Color tFigur::getc()
{
	return c;
};

void tFigur::line_move()
{
	if(x+dirx>=LENGTH-length/2){
		flagx = 1;
	}
	else if(x-dirx<=length/2){
		flagx = 0;
	}
	if(y+diry>=HEIGHT-height/2){
		flagy = 1;
	}
	else if(y-diry<=height/2){
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

void tFigur::roll_move(){
	corner+=0.01;
}

void tFigur::draw(sf::RenderWindow &window){}

void tPoint::draw(sf::RenderWindow &window)
{
    sf::CircleShape point(getlength() / 2);
    point.setFillColor(getc());
    point.setPosition(getx(), gety());
    point.setRotation(getcorner());
    point.setOrigin(getlength()/2,getheight()/2);
    window.draw(point);
}

void tCircle::draw(sf::RenderWindow &window)
{
    	sf::CircleShape circle(getlength() / 2);
    	circle.setFillColor(getc());
	circle.setPosition(getx(), gety());
    	circle.setRotation(getcorner());
    	circle.setOrigin(getlength()/2,getheight()/2);
    	window.draw(circle);
}

void tLine::draw(sf::RenderWindow &window)
{
	sf::RectangleShape line(sf::Vector2f(getlength(), 3));
	line.setFillColor(getc());
	line.setPosition(getx(), gety());
	line.setRotation(getcorner());
	line.setOrigin(getlength()/2,getheight()/2);
	window.draw(line);
}

void tRectangle::draw(sf::RenderWindow &window)
{
    	sf::RectangleShape rectangle(sf::Vector2f(getlength(), getheight()));
    	rectangle.setFillColor(getc());
    	rectangle.setPosition(getx(), gety());
    	rectangle.setRotation(getcorner());
    	rectangle.setOrigin(getlength()/2,getheight()/2);
    	window.draw(rectangle);
}


void tEllipse::draw(sf::RenderWindow &window)
{
    	sf::CircleShape ellipse(getlength() / 2);
    	ellipse.setScale(1, 0.5);
    	ellipse.setFillColor(getc());
    	ellipse.setPosition(getx(), gety());
    	ellipse.setRotation(getcorner());
    	ellipse.setOrigin(getlength()/2,getheight()/2+40);
    	window.draw(ellipse);
}

void tTriangle::draw(sf::RenderWindow &window)
{
    	sf::CircleShape triangle(getlength() / 2);
    	triangle.setPointCount(3);
    	triangle.setFillColor(getc());
    	triangle.setPosition(getx(), gety());
    	triangle.setRotation(getcorner());
    	triangle.setOrigin(getlength()/2,getheight()/2+40);
    	window.draw(triangle);
}

void tRhombus::draw(sf::RenderWindow &window)
{
    	sf::CircleShape rhombus(getlength() / 2);
    	rhombus.setPointCount(4);
    	rhombus.setFillColor(getc());
    	rhombus.setPosition(getx(), gety());
    	rhombus.setRotation(getcorner());
    	rhombus.setOrigin(getlength()/2,getheight()/2);
    	window.draw(rhombus);
}
