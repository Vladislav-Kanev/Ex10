// Copyright 2021 by me
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <typename T>
class MyStack {
 private:
     unsigned int size;
     int top;
     T *value;

 public:
     explicit MyStack(unsigned int max_size) {
         size = max_size;
         top = 0;
         value = new T[size];
     }
     MyStack(const MyStack& to_copy) {
         size = to_copy.size;
         top = to_copy.top;
         value = new T[size];
         for (unsigned i = 0; i < top; ++i) {
             value[i] = to_copy.value[i];
         }
     }
     ~MyStack() {
         if (top != 0)
            delete value;
     }
     T get() const {
         if (top != 0)
             return value[top - 1];
     }
     T pop() {
        if (top == 0) throw - 1;
        top -= 1;
        return value[top];
     }
     void push(T element) {
         if (isFull()) throw - 1;
         value[top] = element;
         top++;
     }
     bool isFull() const {
         if (top == size)
             return true;
         else
             return false;
     }
     bool isEmpty() const {
         if (top == 0)
             return true;
         else
             return false;
     }
};



#endif  // INCLUDE_MYSTACK_H_
