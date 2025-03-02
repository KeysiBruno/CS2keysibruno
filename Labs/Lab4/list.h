#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List() : _head(head), _tail(tail), listSize(_listSize)
{
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    return (_head==nullptr)?true:false;
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    int counter = 0;
    Node<T1> *_random;
    _random = _head;
    
    if (_random != nullptr) continue;
    while(_random->_next != nullptr)
    {
        counter++;
    }
    return counter;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    _head->getData() = data;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    T1 List<T1> *cList = nullptr;
     cList = _head;

    if(_head == nullptr)
    {
        cout<<"The list is empty"<<endl;
        return 0;
    }
    else
    {
       return cList->push_front();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    T1 List<T1> *cList = nullptr;
    cList = _head;

   if(_head == nullptr)
   {
       cout<<"The list is empty"<<endl;
       return 0;
   }
   else
   {
      return cList->push_front();
      delete _head ->_data;
      _head = _head->_next;
   }
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1> *newHead = nullptr;
    newHead = _head;

    do
    {
       _tail = newHead;
       newHead = newHead->_next;

    }  while(newHead != nullptr);
    
   _tail->_data = data;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(_head == nullptr)
   {
       cout<<"The list is empty"<<endl;
       return 0;
   }

    Node<T1> *cNode = nullptr;
    cNode = _head;
     
    cList->push_back();

    return
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
}