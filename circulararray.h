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
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

// IMPLEMENTACIONES


template <class T>
void CircularArray<T>::push_front(T data)
{
  if(is_empty())
  {
    array[front]=data;
  }

  else if(is_full())
  {
    T *new_array = new T [capacity+10];
    for(int i = front; i < rear; i++)
    {
      new_array[i+1] = array[i];
    }
    new_array[front] = data;
    array = new_array;
  }
  else
  {
    for(int i=rear; i > front; i--)
    {
      array[i+1] = array[i];
    }
    array[front]=data;
  }
}

template <class T>
void CircularArray<T>::push_back(T data)
{
  if(is_empty())
  {
    array[back] = data;
  }
  else if(is_full())
  {
    T *new_array = new T[capacity+10];
    for(int i = front; i < rear; i++)
    {
      array[i] = new_array[i];
    }
    new_array[back+1] = data;
    array = new_array;
  }
  else{
    array[back+1] = data;
  }
}

template <class T>
void CircularArray<T>::pop_front(T data)
{
  if(is_empty())
  {
    cout << "error"; << endl;
  }
  else if
  {
     T *new_array = new T [capacity];
     for(int i = front; i < rear; i++)
     {
       array[i+1] = new_array[i];
     }
     array = new_array;
  }

}

template <class T>
void CircularArray<T>::pop_back(T data)
{
  if(is_empty())
  {
    array[back] = data;
  }
  else if(is_full())
  {
    T *new_array = new T [capacity+10];
    new_array[back+1] = data;
    array = new_array;
  }
  else
  {
    array[back+1] = data;
  }
}


template <class T>
bool CircularArray<T>::is_full()
{
  return (back+1) % capacity == front;
}

template <class T>
bool CircularArray<T>::is_empty()
{
  if(front == rear)
  {
    return true;
  } 
  else
  {
    return false;
  }

}


// SIN TERMINAR 
template <class T>
int CircularArray<T>::size()
{
  int count = 0;
  if(front == rear)
  {
    return 0;
  }
  else
  {
    for(int i = front; i < rear; i++){
      count++;
    }
    return count;
  }
}


// DEFAULTS

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
    for (int i = 0; i < size(); i++)
    {
        result += std::to_string((*this)[i]) + sep;
    }
    return result;    
}
