#pragma once
#include <iostream>
#include <vector>
// #include <cstddef>
//
// class Queue {
// private: struct node{
//   int val;
//   node* next;};
//   node* head;
//   node* tail;
//     public:
//       Queue();
//       ~Queue();
//         int size() const;
//         bool isEmpty() const;
//         void enqueue(int value);
//         int dequeue();
// };


//
// template<typename T>
// class Queue{
// private:
//  std::vector<T> elem;
// public:
//     Queue();
//     int size() const {
//         return elem.size();
//     }
//     bool empty() const {
//         return elem.empty();
//     }
//     void enqueue(T t);
//     T dequeue();
//     T peek();
//     typename std::vector <T>::iterator begin() {
//          return elem.begin();
//      }
//      typename std::vector <T>::iterator end() {
//        return elem.end();
//    }
//
// };

class Queue{
private:
 std::vector<int> elem;
public:
    Queue();
    int size() const {
        return elem.size();
    }
    bool empty() const {
        return elem.empty();
    }
    void enqueue(int t);
    int dequeue();
    int peek();
    std::vector <int>::iterator begin() {
         return elem.begin();
     }
 std::vector <int>::iterator end() {
       return elem.end();
   }

};
