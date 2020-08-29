#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node * next;


    Node() = default;
    Node(T data, Node * next = NULL) : data(data),next(next) {}
    Node * insertAsSuc(T value)
    {
        Node * node = New Node;
        node -> data = value;
        node -> next = this -> next;
        this -> next = node;
        return node;
    }
};

template<typename T,typename...Args>
class List{
    private:
        Node * front;
        Node * suc;
        Node * pos;
        unsigned int __size;

    public:
        List() ;
        List(T value,Args...args){
            Node * cur = front -> insertAsSuc(value);
        }
        unsigned int size() { return __size;}
        bool empty() { return _size > 0; }
        
        
};
