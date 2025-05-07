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
List<T1>::List() : _head(nullptr), _tail(nullptr), listSize(0)
{
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    while(!empty())
    {
        pop_front();
    }
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
    return listSize;
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    Node<T1> *new_node = new Node<T1>();
    new_node->setData(data);
    new_node->setNext(_head);
    new_node->setPrev(nullptr);

   if(_head == nullptr)
   {
      _tail = new_node;
   }
   else
   {
      _head->setPrev(new_node);
   }
   _head = new_node;

   listSize++;
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    if(_head == nullptr)
    {
        cout<<"The list is empty. "<<endl;
        return 0;
    }
    else
    {
       return _head->getData();
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    if(_head == nullptr)
    {
        cout<<"The list is empty"<<endl;
        return 0;
    }
    
    Node<T1> *cNode = _head;
    T1 data = cNode->getData();
    
    _head = _head->getNext();
    
    if(_head == nullptr) {
        // List becomes empty
        _tail = nullptr;
    }
    else {
        _head->setPrev(nullptr);
    }
    
    delete cNode;
    listSize--;
    return data;
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    Node<T1>* new_node = new Node<T1>();
    new_node->setData(data);
    new_node->setNext(nullptr);
    new_node->setPrev(_tail);

    if(_head == nullptr)
    {
        // List is empty, set both head and tail to the new node
        _head = new_node;
        _tail = new_node;
    }
    else
    {
        _tail->setNext(new_node);
        _tail = new_node;
    }

    listSize++;
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if(_head == NULL)
   {
       cout<<"The list is empty. "<<endl;
       return 0;
   }
    else
    {
        return _tail->getData();
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if(_head == nullptr)
    {
        cout<<"The list is empty. "<<endl;
        return 0;
    }
    
    Node<T1> *cNode = _tail;
    T1 data = cNode->getData();
    
    _tail = _tail->getPrev();
    
    if(_tail == nullptr) {
        // List becomes empty
        _head = nullptr;
    }
    else {
        _tail->setNext(nullptr);
    }
    
    delete cNode;
    listSize--;
    return data;
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1>* current = list._head;
    while (current) {
        os << current->getData() << " ";
        current = current->getNext();
    }
    return os;
}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    if (listSize != rhs.listSize) return false;
    Node<T1>* left = _head;
    Node<T1>* right = rhs._head;
    while (left && right)
    {
        if (left->getData() != right->getData()) return false;
        left = left->getNext();
        right = right->getNext();
    }
    return left == nullptr && right == nullptr;
}
