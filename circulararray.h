#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;



public:
    CircularArray();
    CircularArray(int _capacity);

    void display(){
      if(is_empty()){
        return;
        } else{
      for(int i = front; i<=back;i++){
        cout<<array[i]<<endl;
        }
      }
    }

    virtual ~CircularArray();

    void push_front(T data){
     T *new_array = new T [capacity+1];
        for(int i = front; i <= back; i++)
        {
            new_array[i+1] = array[i];
        }
        new_array[front] = data;
        this->back++;
        this->capacity++;
      array = new_array;
      }

    void resize(){
      int *temp = new T[this->capacity * 2];
      for (int i = 0; i < this->capacity; i++){
        temp[i] = this->array[(i+1) % this->capacity];
        }
      delete[] this->array;
      this->array = temp;
      this->back = this->capacity - 1;
      this->front = 0;
      this->capacity = this->capacity * 2;
    }

    void push_back(T data){
      if (is_full()){
        resize();
      }
      if (is_empty() == false){
        this->back = next(this->back);
      } else {
        this->front = this->back = 0;
        }
      this->array[this->back] = data;
    }

    void insert(T data, int pos){
      if (is_full()){
        resize();
    }
      
    if (is_empty() == false){
      int i = next(this->back);
      this->back = next(this->back);
      while (i != ((pos % size()) + this->front)){
        this->array[i] = this->array[prev(i)];
        cout << endl << this->array[i] <<endl;
        i = prev(i);
      }
      this->array[((pos % size()) + this->front)] = data;
      }
    }

    T pop_front(){
      if (is_empty() == false){
        if (this->front == this->back){
          T frnt = this->array[this->front];
          this->front = this->back = -1;
          return frnt;
      } else {
          T frnt = this->array[this->front];
          this->front = next(this->front);
          return frnt;
      }
      } else {
          return;
        }
    }
    

    T pop_back(){
      if (is_empty() == false){
        if (this->front == this->back){
          T bck = this->array[this->back];
          this->front = this->back = -1;
          return bck;
        } else{
            T bck = this->array[this->back];
            this->back = prev(this->back);
            return bck;
          }
            } else {
                return;
      }
    }
    

    bool is_full(){
      if (back == capacity){
      return true;
      }
      else{
        return false;
      }
    }

    bool is_empty(){
      return ((this->back == -1) && (this->front == -1));
    }

    int size(){
      if (is_empty() == false){
        int sz = 0;
        if (this->front > this->back){
            sz = this->capacity - this->front + this->back+ 1;
        } else{
          sz = this->back - this->front + 1;
          } return sz;
      } else {
        return 0;
      }
    }
    
  void clear(){
    delete []array;
    this->array = new T[0];
    this->capacity = 0;
    this->rear = 0;
    this->front = 0;
    array  = new T[0];
    }

    T& operator[](int index){
      return array[(this->front + index) % this->capacity];
    }
    
    
    void sort();
    bool is_sorted();
    void reverse(){
      for (int low = 0, high = size()-1; low < high; low++, high--){
        swap(this->array[low], this->array[high]);
        }
    }

    string to_string(string sep=" ");

private:
    int next(int index);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = front-1; i < back; i++){
      cout<<i<< endl;
      result += std::to_string((*this)[i]) + sep;

    }
    return result;    
}
