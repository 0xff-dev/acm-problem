#include <iostream>

namespace my_stack {
template <class T>
class stack {
private:
    T* store;
    int size;
    int cap;
public:
    stack(int size);
    ~stack();
    void push(T item);
    int Cap();
    T top();
    T pop();
};

template<class T>
stack<T>::stack(int _cap) {
    if(_cap == 0) {
        _cap = 5;
    }
    this->cap = _cap;
    this->size = -1;
    this->store = new T[this->cap];
}

template<class T>
stack<T>::~stack() {
    delete []this->store;
}

template<class T>
int stack<T>::Cap() {
    return this->cap;
}

template<class T>
void stack<T>::push(T item) {
    if(this->size == this->cap-1) {
        this->cap *= 2;
        T* tmp_store = new T[this->cap];
        for(int index=0; index<=this->size; index++){
            tmp_store[index] = this->store[index];
        }
        delete []this->store;
        this->store = tmp_store;
    }
    this->size++;
    this->store[this->size] = item;
}

template<class T>
T stack<T>::top(){
    if(this->size == -1){
        throw "empty stack can not use function top";
    }
    return this->store[this->size];
}

template<class T>
T stack<T>::pop() {
    if(this->size == -1){
        throw "empty stack can not use function pop";
    }
    T top_item = this->top();
    this->size --;
    return top_item;
}
};
int main()
{
    my_stack::stack<int> _stack(6);
    for( int i=0; i<100; i++ ){
        _stack.push(i);
    }
    std::cout << "cap: " << _stack.Cap() << std::endl;
    for( int cnt=0; cnt<60; cnt++ ){
        std::cout << "top: " << _stack.pop() << std::endl;
    }
    return 0;
}

