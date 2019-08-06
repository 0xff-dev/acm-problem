#include <iostream>

namespace my_list {
template<class T>
    struct _node {
        T val;
        _node* _next;
    };

template<class T>
    class list{
    private:
        _node<T>* head;
        int size;
    public:
        list(T val); // ok
        list(_node<T>* node); // ok
        list(list<T>* _list); // ok
        ~list(); // ok
        int len();
        _node<T>* head_val();
        void display();
        void add(T val);
        //void sort(); //对链表排序, T类型需要实现比较
        void del(int index);  // 删除节点
    };

template<class T>
    list<T>::list(T val) {
        this->head = new _node<T>();
        this->head->val = val;
        this->size = 1;
    }
template<class T>
    list<T>::list(_node<T>* node) {
        if(node == nullptr) {
            throw "can not use nullptr as head";
        }
        this->head = node;
        this->size = 1;
    }
template<class T>
    list<T>::list(list<T>* _list) {
        if(_list->len() == 0) {
            throw "empty list can not use.";
        }
        _node<T>* walker = _list->head_val();
        this->head = new _node<T>();
        this->head->val = walker->val;
        _node<T>* tail = this->head;
        this->size ++;
        walker = walker->_next;
        for(; walker!=nullptr; walker=walker->_next) {
            _node<T>* node = new _node<T>();
            node->_next = nullptr, node->val = walker->val;
            tail->_next = node;
            tail = node;
            this->size++;
        }
    }
template <class T>
    list<T>::~list() {
        for(_node<T>** cur = &this->head; *cur != nullptr;) {
            _node<T>* entry = *cur;
            *cur = entry->_next;
            delete entry;
        }
    }

template<class T>
    int list<T>::len() {
        return this->size;
    }
template <class T>
    _node<T>* list<T>::head_val() {
        return this->head;
    }
template<class T>
    void list<T>::display() {
        _node<T>* walker = this->head;
        while(walker != nullptr) {
            std::cout << walker->val << " ";
            walker = walker->_next;
        }
        std::cout << std::endl;
    }
template <class T>
    void list<T>::add(T val) {
        _node<T>* tail = this->head;
        for(; tail->_next != nullptr; tail = tail->_next){}
        _node<T>* node = new _node<T>();
        node->val = val;
        tail->_next = node;
        this->size++;
    }

template <class T>
    void list<T>::del(int index) {
        if(this->size == 0 || index > this->size) {
            throw "out of range";
        }
        int now = 1;
        for(_node<T>** cur = &this->head; *cur != nullptr; now++){
            _node<T>* entry = *cur;
            if(now == index){
                *cur = entry->_next;
                delete entry;
            } else {
                cur = &(entry->_next);
            }
        }
        this->size--;
    }
}

int main()
{
    my_list::list<int>* _list = new my_list::list<int>(5);
    _list->display();
    my_list::list<int>* tmp_list = new my_list::list<int>(_list);
    tmp_list->display();
    for(int i=0; i<4; i++) {
        tmp_list->add(i);
    }
    tmp_list->display();
    tmp_list->del(2);
    tmp_list->display();
    return 0;
}

