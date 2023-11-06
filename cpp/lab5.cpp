#include <ctime>
#include "lab5.hpp"

int main(){
	srand(time(NULL));
	tPoint point[5];
	tCircle circle[5];
	tLine line[5];
	tRectangle rectengle[5];
	tEllipse ellipse[5];
	tTriangle triangle[5];
	tRhombus rhombus[5];
	sf::RenderWindow Pavel(sf::VideoMode(1920, 1080),"Roma", sf::Style::Fullscreen);
	while(Pavel.isOpen()){
		Pavel.clear();
		for (int i = 0; i < 5; i++)
        	{
            		point[i].draw(Pavel);
            		circle[i].draw(Pavel);
            		line[i].draw(Pavel);
            		rectengle[i].draw(Pavel);
            		ellipse[i].draw(Pavel);
            		triangle[i].draw(Pavel);
            		rhombus[i].draw(Pavel);
		}
		Pavel.display();
		for (int i = 0; i < 5; i++)
        	{
            		point[i].line_move();
            		circle[i].line_move();
            		line[i].line_move();
            		rectengle[i].line_move();
            		ellipse[i].line_move();
            		triangle[i].line_move();
            		rhombus[i].line_move();
        	}
		/*
        	for (int i = 0; i < 5; i++)
        	{
        		point[i].roll_move();
        		circle[i].roll_move();
        		line[i].roll_move();
        		rectengle[i].roll_move();
        		ellipse[i].roll_move();
        		triangle[i].roll_move();
        		rhombus[i].roll_move();
        	}
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
