#include <ctime>
#include <vector>
#include "lab6.hpp"

int main(){
	srand(time(NULL));
	std::vector<tFigur*> array;
    tPoint p;
    array.push_back(&p);
    tLine l;
    array.push_back(&l);
    tCircle c;
    array.push_back(&c);
    tRectangle r;
    array.push_back(&r);
    tTriangle t;
    array.push_back(&t);
    tEllipse e;
    array.push_back(&e);
    tRhombus h;
    array.push_back(&h);
    tPoint point(50,60);
	tTriangle triangle(1200,100);
	sf::RenderWindow Pavel(sf::VideoMode(1920, 1080),"Roma", sf::Style::Fullscreen);
	while(Pavel.isOpen()){
		Pavel.clear();
		/* Перегрузка + аргументы по умолчанию
        point.draw(Pavel);
		triangle.draw(Pavel);
		*/
		for (auto i = array.begin(); i != array.end(); i++)
        {
            (*i)->draw(Pavel);
        }
		Pavel.display();
		/* Перегрузка + аргументы по умолчанию
        point.line_move();
		triangle.line_move();
		*/
		/*Пример движения*/
		for (auto i = array.begin(); i != array.end(); i++)
        {
            (*i)->line_move();
        }
        /* Пример вращение
		for (auto i = array.begin(); i != array.end(); i++)
        {
            (*i)->roll_move();
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
