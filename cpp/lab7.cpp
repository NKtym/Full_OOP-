#include "7.hpp"

int main(){
    try{
        List e(1);
        e.delete_node(1);
        e.print();
    }
    catch(List::NullNode){
        std::cout << "-Error- Null node" << std::endl;
    }
    catch(List::NoNumber){
        std::cout << "-Error- No number in node" << std::endl;
    }
    try{
	List l(1);
    l.push_node(2);
    l.push_node(3);
    l.push_node(4);
	l.print();
	l.delete_node(2);
	l.print();
    }
    catch(List::NullNode){
        std::cout << "Null node" << std::endl;
    }
    try{
    Stack s;
    s.push_node(2);
    s.push_node(3);
    s.push_node(4);
	s.print();
	s.delete_node();
	s.print();
    s.delete_node();
	s.print();
    }
    catch(Stack::NullNode){
        std::cout << "Null node" << std::endl;
    }
    try{
    Queue q(1);
    q.push_node(2);
    q.push_node(3);
    q.push_node(4);
	q.print();
	q.delete_node();
	q.print();
    q.delete_node();
	q.print();
    }
    catch(Queue::NullNode){
        std::cout << "Null node" << std::endl;
    }
    return 0;
}