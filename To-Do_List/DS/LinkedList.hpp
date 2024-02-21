#include <iostream>
#include "../ToDo_Element/to-do_Element.hpp"



class LinkedList{
private:

    class Node{
    public:
        TO_DO_ELEMENT::To_Do_Element data;
        Node* next;

        Node(){
            next = nullptr;
        }
        Node(TO_DO_ELEMENT::To_Do_Element d){
            this->data = TO_DO_ELEMENT::To_Do_Element(d);
            this->next = nullptr;
        }
    };


    static int size;
    Node* head;
public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void insertNode(TO_DO_ELEMENT::To_Do_Element x);
    void printList(void);
    void deleteNode(int x);
};
    