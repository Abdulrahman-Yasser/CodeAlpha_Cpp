#include "try.hpp"



int LinkedList::size = 0;


void LinkedList::insertNode(int x){
    Node* new_node = new Node(x);

    if(head == nullptr){
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->data < x && temp->next != nullptr){
        temp = temp->next;
    }
    


    if(temp == head){
        new_node->next = head;
        head = new_node;
    }else{
        new_node->next = temp->next;
        temp->next = new_node;
    }
    size++;

}

void LinkedList::printList(void){

    Node* temp = head;
    while(temp->next != nullptr){
        std::cout << temp->data << "\t";
        temp = temp->next;
    }
    std::cout << temp->data << "\t";
    std::cout << std::endl;

}

void LinkedList::deleteNode(int x){

    Node* temp_1 = head, *temp_2 = nullptr;
    int len = 0;

    if(head == nullptr){
        std::cout << "Empty list \n";
        return;
    }

    if(x >= size){
        std::cout << "Wrong position \n";
        return;
    }

    size--;

    for(int i = 0; i < x; i++){
        temp_2 = temp_1;
        temp_1 = temp_1->next;
    }
    if(x == 0){
        head = head->next;
        delete temp_1;
        return;
    }else{
        temp_2->next = temp_1->next;
        delete temp_1;
    }


}


int main(void){
    LinkedList my_node;
    my_node.insertNode(10);
    my_node.insertNode(15);
    my_node.insertNode(11);
    my_node.insertNode(9);
    my_node.insertNode(2);
    my_node.insertNode(80);
    my_node.printList();
    my_node.deleteNode(0);
    my_node.printList();
    my_node.deleteNode(0);
    my_node.printList();
    my_node.deleteNode(4);
    my_node.printList();
}