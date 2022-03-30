#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
    public:
    template<typename T>
    void push(T data){
        push_front(data);
    }

    template<typename T>
    int pop(T data){
        pop_front(data);
    }
};
