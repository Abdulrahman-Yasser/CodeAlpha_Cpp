#include <iostream>




class LinkedList{
private:

    class Node{
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = nullptr;
        }
        Node(int d){
            this->data = d;
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
    void insertNode(int x);
    void printList(void);
    void deleteNode(int x);
};
    