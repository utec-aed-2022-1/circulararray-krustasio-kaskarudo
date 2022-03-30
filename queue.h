#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    public:
    
    template<typename T>
    void enqueue(T data){
        if(is_full()){
            resize();
        }
        int rear = next(rear);
        array[rear] = data;
    }
    
    template<typename T>
    void dequeue(T data){
        if(is_empty()) throw("is empty");
        front = next(front);
    }  
};  
  
