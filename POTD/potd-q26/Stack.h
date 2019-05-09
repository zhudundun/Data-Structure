#pragma once

// #include <cstddef>
//
// class Stack {
// private:
//   struct node{
//     int val;
//     node* next;
//   };
//   node* head;
// public:
//   Stack();
// ~Stack();
//   int size() const;
//   bool isEmpty() const;
//   void push(int value);
//   int pop();
// };

#include<iostream>
#include<vector>
#include<cstddef>

class Stack{
public:
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
  Stack();
private:
  std::vector<int> vec_;
};
