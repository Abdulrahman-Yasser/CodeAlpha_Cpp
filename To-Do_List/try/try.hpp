#include <iostream>

class Node{
    private:
        int element;
        Node *next;
        static int size;
    public:
        Node(int e){
            this->element = e;
            this->next = nullptr;
            Node::size = 1;
        }
        Node(){
        }

        void push(int element)
        {
            Node* new_node= new Node();
            new_node->element = element;
            Node* ptr = this;
            Node* prev_ptr = nullptr;
            
            while(ptr != nullptr && (ptr->element < element) ){
                prev_ptr = ptr;
                ptr = ptr->next;
            }

            if(prev_ptr != nullptr){
                prev_ptr->next = new_node;
            }else{
                this = new_node;
            }
            new_node->next = ptr;
            this->size++;
        }
        int pop(void){
            Node* new_node = this;
            int i = new_node->element;
            this = this->next;
            this->size--;
            free(new_node);
            return i;
        }
        int pop(int position){
            if(position > this->size){
                return 0;
            }
            int i = 0;
            Node* prev_ptr, *ptr = this;
            for(int i = 0; i < this->size; i++){
                prev_ptr = ptr;
                ptr = ptr->next;
            }
            prev_ptr->next = ptr->next;
            i = ptr->element;
            this->size--;
            free(ptr);
            return i;
        }
};
    
int main(){
    Node my_node(5);
    my_node.push(10);
    my_node.push(15);
    my_node.push(11);
    my_node.push(9);
    my_node.push(80);
    std::cout << my_node.pop() << std::endl;
    std::cout << my_node.pop() << std::endl;
    std::cout << my_node.pop() << std::endl;
    std::cout << my_node.pop() << std::endl;
    std::cout << my_node.pop() << std::endl;
}