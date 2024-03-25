#include "LinkedList.hpp"
#include "../ToDo_Element_with_wrapper/to-do_Element.hpp"




void LinkedList::insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element *x){
    LinkedList::Node* new_node = new Node(x);

    if(head == nullptr){
        head = new_node;
        return;
    }

    LinkedList::Node* temp = head;
    while(temp->data->starting_after_x_min() < x->starting_after_x_min() && temp->next != nullptr){
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

void LinkedList::insertNode(TO_DO_ELEMENT_WR_NS::To_Do_Element x){
    LinkedList::Node* new_node = new Node(x);

    if(head == nullptr){
        head = new_node;
        return;
    }

    LinkedList::Node* temp = head;

    while(temp->data->starting_after_x_min() > x.starting_after_x_min() && temp->next != nullptr){

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
    LinkedList::Node* temp = head;
    while(temp->next != nullptr){
        temp->data->print_task();
        std::cout << "\n";
        temp = temp->next;
    }
    temp->data->print_task();
    std::cout << "\n";
    std::cout << std::endl;
}



void LinkedList::deleteNode(TO_DO_ELEMENT_WR_NS::To_Do_Element* elem){

    LinkedList::Node* temp_1 = head, *temp_2 = nullptr;
    int i ;
    if(head == nullptr){
        std::cout << "Empty list \n";
        return;
    }


    for(i = 0; temp_1->data != nullptr && temp_1->data != elem; i++){
        temp_2 = temp_1;
        temp_1 = temp_1->next;
    }
    i--;

    if(i == 0 && temp_1->data == elem){
        head = head->next;
        delete temp_1;
        size--;
    }else if(temp_1->data == elem){
        temp_2->next = temp_1->next;
        delete temp_1;
        size--;
    }

}


TO_DO_ELEMENT_WR_NS::To_Do_Element* LinkedList::get_task(int id){
    LinkedList::Node* temp = head;
    while(temp->next != nullptr){
        if( temp->data->is_that_you(id) ){
            return temp->data;
        }
        temp = temp->next;
    }
    if( temp->data->is_that_you(id) ){
        return temp->data;
    }
    return nullptr;
}

TO_DO_ELEMENT_WR_NS::To_Do_Element* LinkedList::get_task(std::string name){
    LinkedList::Node* temp = head;
    while(temp->next != nullptr){
        if( temp->data->is_that_you(name) ){
            return temp->data;
        }
        temp = temp->next;
    }
    if( temp->data->is_that_you(name) ){
        return temp->data;
    }
    return nullptr;
}
