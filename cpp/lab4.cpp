#include <ctime>
#include "lab4.hpp"

int main(){
	srand(time(NULL));
	tPoint point;
	tCircle circle;
	tLine line;
	tRectangle rectengle;
	tEllipse ellipse;
	tTriangle triangle;
	tRhombus rhombus;
	sf::RenderWindow Pavel(sf::VideoMode(1920, 1080),"Roma", sf::Style::Fullscreen);
	while(Pavel.isOpen()){
		Pavel.clear();
		circle.CreateCircle(Pavel);
		point.CreatePoint(Pavel);
		line.CreateLine(Pavel);
		rectengle.CreateRectangle(Pavel);
		ellipse.CreateEllipse(Pavel);
		triangle.CreateTriangle(Pavel);
		rhombus.CreateRhombus(Pavel);
		Pavel.display();
		point.line_move();
		circle.line_move();
		line.line_move();
		rectengle.line_move();
		ellipse.line_move();
		triangle.line_move();
		rhombus.line_move();
		/*
		point.roll_move();
		circle.roll_move();
		line.roll_move();
		rectengle.roll_move();
		ellipse.roll_move();
		triangle.roll_move();
		rhombus.roll_move();
		*/
		sf::Event event;
        	while (Pavel.pollEvent(event))
        	{
            		if (event.type == sf::Event::MouseButtonPressed)
                	Pavel.close();
        	}
	}
	return 0;
}
