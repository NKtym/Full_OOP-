#pragma once 
#include <iostream>

class Node{
protected:
    int data;
    Node *next;
public:
    Node():next(NULL),data(0){}
    Node(int data):next(NULL),data(data){}
    ~Node(){}
    friend class List;
    friend class Stack;
    friend class Queue;
};

class List{
    protected:
        Node *head;
    public:
        List():head(new (Node)){}
        List(int datas):head(new (Node)){
            head->data=datas;
        }
        ~List(){}
        class NullNode{};
        class NoNumber{};
        virtual void push_node(int data){
            Node *new_node = new Node(data);
            if(head == nullptr){
                head = new_node;
                return;
            }
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new_node;
        }
        virtual void delete_node(int number){
                Node *temp1 = head, *temp2 = NULL;
                int list_len = 0;
                if (head == NULL)
                {
                    throw NullNode();
                    return;
                }
                while (temp1 != NULL)
                {
                    temp1 = temp1->next;
                    list_len++;
                }
                if (list_len < number || number == 0)
                {
                    throw NoNumber();
                    return;
                }
                temp1 = head;
                if (number == 1)
                {
                    head = head->next;
                    delete temp1;
                    return;
                }
                while (number > 1)
                {
                    temp2 = temp1;
                    temp1 = temp1->next;
                    number--;
                }
                temp2->next = temp1->next;
                delete temp1;
            }
        virtual void print(){
            if (head == NULL){
                throw NullNode();
                return;
            }
            Node *temp = head;
            std::cout << "List:";
            while (temp != NULL){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
        friend class Stack;
};

class Stack{
protected:
    Node* head;
public:
    Stack():head(new (Node)){}
    Stack(int datas):head(new (Node)){
        head->data=datas;
    }
    ~Stack(){}
    class NullNode{};
    void push_node(int data){
        Node *new_node = new Node(data);
        if(head == nullptr){
            head = new_node;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
    void delete_node(){
        if(head == nullptr){
            throw NullNode();
            return;
        }
        head = head->next;
    }
    void print(){
            if (head == NULL){
                throw NullNode();
                return;
            }
            Node *temp = head;
            std::cout << "Stack:";
            while (temp != NULL){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
    }
};

class Queue{
protected:
    Node* tail;
public:
    Queue():tail(new (Node)){}
    Queue(int datas):tail(new (Node)){
        tail->data=datas;
    }
    ~Queue(){}
    class NullNode{};
    void push_node(int data){
        Node *new_node = new Node(data);
        if(tail == nullptr){
            tail = new_node;
            return;
        }
        Node *temp = new_node;
        temp->next = tail;
        tail = temp;
    }
    void delete_node(){
        if (tail == NULL){
            throw NullNode();
            return;
        }
        tail = tail->next;
    }
    void print(){
        if (tail == NULL){
            throw NullNode();
            return;
        }
        Node *temp = tail;
        std::cout << "Queue:";
        while (temp != NULL){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";       
    }
};