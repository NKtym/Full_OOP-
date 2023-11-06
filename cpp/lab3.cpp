#include <ctime>
#include "lab3.hpp"

int main(){
	srand(time(NULL));
	tPoint arr[100];
	sf::RenderWindow Pavel(sf::VideoMode(800,600),"Roma");
	while(Pavel.isOpen()){
		for(int i = 0; i<100; i++){
			sf::CircleShape Artem(2);
			Artem.setFillColor(arr[i].getc());
			Artem.setPosition(arr[i].getx(),arr[i].gety());
			//arr[i].rand_move();
			arr[i].line_move();
			//std::cout<<arr[i].getx()<<'\n';
			//std::cout<<arr[i].gety()<<'\n';
			Pavel.draw(Artem);
		}
		Pavel.display();
		Pavel.clear();
		sf::Event event;
		while(Pavel.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				Pavel.close();
			}
			Pavel.clear();
		}
	}
	return 0;
}
