
#include "../to-do_class/to-do.hpp"

namespace LinkedList_NS{


class Node{
    private:
        TO_DO_ELEMENT::To_Do_Element* element;
        Node *next;
    public:
        Node(TO_DO_ELEMENT::To_Do_Element* e):{
            this->element = e;
            this->next = nullptr;
        }

        void push(TO_DO_ELEMENT::To_Do_Element* element)
        {
            Node* new_node = new Node;
            new_node->element = element;
            Node* ptr = this;
            Node* prev_ptr = nullptr;
            
            while(ptr != nullptr && (ptr->element->ending_time < element->ending_time) ){
                prev_ptr = ptr;
                ptr = ptr->next;
            }

            if(prev_ptr != nullptr){
                prev_ptr->next = new_node;
            }else{
                this = new_node;
            }
            new_node->next = ptr;
        }
        TO_DO_ELEMENT::To_Do_Element pop(void);
        TO_DO_ELEMENT::To_Do_Element pop(int position);
};
    

}