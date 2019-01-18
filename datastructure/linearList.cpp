#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class illgalParamterValue {
    public:
        illgalParamterValue():
            msg("Illgal paramter value"){}
        illgalParamterValue(std::string message){
            msg = message;
        }
        void output() {
            std::cout << msg << std::endl;
        }
    private:
        std::string msg;
};

template<class T>
class linearList {
    public:
        virtual ~linearList(){};
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual T& get(int itemIndex) const = 0;
        virtual int indexOf(const T& item) const = 0;
        virtual void erase(int itemIndex) = 0;
        virtual void insert(int index, const T& item) = 0;
        virtual void output(ostream& os) const = 0;
};

template<class T>
class arrayList : public linearList<T> {
    public:
        arrayList(int capacity=10);
        arrayList(const arrayList<T>&);
        ~arrayList() {delete []element;}

        bool empty() const { return listSize == 0;}
        int size() const { return listSize;}
        T& get(int index) const; // 检查越界问题
        int indexOf(const T& ele) const;
        void erase(int index);
        void insert(int index, const T& ele);
        void output(ostream &os) const;
        //friend ostream& operator<<(ostream& out, const arrayList<T>& list);
        int capacity() const { return arrayLength;}
    private:
        void checkIndex(int index) const;
        void resize();
        T* element;
        int arrayLength; // 容量
        int listSize; // 数组的长度
};

template<class T>
arrayList<T>::arrayList(int capacity) {
    if (capacity<1){
        ostringstream os;
        os << "Initial capacity = " << capacity << " Must be > 0";
        throw illgalParamterValue(os.str());
    }
    arrayLength = capacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& list) {
    arrayLength = list.arrayLength;
    listSize = list.listSize;
    delete []element;
    element = new T[arrayLength];
    copy(list.element, list.element+list.listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int index) const {
    if (index < 0 || index >= listSize){
        ostringstream os;
        os << "index=" << index << " size=" << listSize;
        throw illgalParamterValue(os.str());
    }
}

template<class T>
void arrayList<T>::resize() {
    arrayLength *= 2;
    T* ele = new T[arrayLength];
    copy(element, element+listSize, ele);
    delete []element;
    element = ele;
}
template<class T>
T& arrayList<T>::get(int index) const {
    checkIndex(index);
    return element[index];
}

template<class T>
int arrayList<T>::indexOf(const T& ele) const {
    int tmpIndex = (int)(find(element, element+listSize, ele)-element);
    if (tmpIndex == listSize) {
        return -1;
    }
    return tmpIndex;
}

//  删除某个index元素, 后面的数据填充
template<class T>
void arrayList<T>::erase(int index) {
    checkIndex(index);
    copy(element+index+1, element+listSize, element+index);
    element[--listSize].~T();
}

template<class T>
void arrayList<T>::insert(int index, const T& ele) {
    if(index<0 || index>listSize){
        ostringstream os;
        os << "index=" << index << " size=" << listSize;
        throw illgalParamterValue(os.str());
    }
    if (listSize == arrayLength){
        resize();
    }
    // 从哪里开始移动, 最后的位置在哪里.
    copy_backward(element+index, element+listSize, element+listSize+1);
    element[index] = ele;
    listSize ++;
}

template<class T>
void arrayList<T>::output(ostream& os) const {
    copy(element, element+listSize, ostream_iterator<T>(cout, " "));
}

// template<class T>
// ostream& operator<<(ostream& out, const arrayList<T>& list) {
//     list.output(out);
//     return out;
// }

int main() {
    arrayList<int> *list = new arrayList<int>();
    for( int i=0; i<5; i++){
        list->insert(i, i);
    }
    list->output(cout);
}
