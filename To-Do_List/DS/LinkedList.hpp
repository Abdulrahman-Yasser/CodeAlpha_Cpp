#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>
#include <iostream>
#include "../ToDo_Element_with_wrapper/to-do_Element.hpp"



class LinkedList{
private:

    class Node{
    public:
        TO_DO_ELEMENT_WR_NS::To_Do_Element *data;
        Node* next;

        Node(){
            data = nullptr;
            next = nullptr;
        }
        Node(TO_DO_ELEMENT_WR_NS::To_Do_Element *d){
            this->data = d;
            this->next = nullptr;
        }
        Node(TO_DO_ELEMENT_WR_NS::To_Do_Element d){
            this->data = new TO_DO_ELEMENT_WR_NS::To_Do_Element(d);
            this->next = nullptr;
        }
    };


    int size;
    Node* head;
public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element *x);
    void insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element x);
    void printList(void);
    void deleteNode(TO_DO_ELEMENT_WR_NS::To_Do_Element* elem);
    TO_DO_ELEMENT_WR_NS::To_Do_Element* get_task(std::string name);
    TO_DO_ELEMENT_WR_NS::To_Do_Element* get_task(int id);
};
    

#endif