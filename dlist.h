#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++() {
            this->current = this->current->next;
            return *this;
        };
        DListIterator<T> operator--() {
            this->current = this->current->prev;
            return *this;
        };
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
              
    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            Node<T>* newNode = new Node<T>(data);
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void push_back(T data) {
            Node<T>* newNode = new Node<T>(data);
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }
             
        void pop_front() {
            Node<T>* Tmp = head;
            head = head->next;
            delete Tmp;
            head->prev = nullptr;
        }
             
        void pop_back() {
            Node<T>* tmp = tail;
            tail = tail->prev;
            delete tmp;
            tail->next = nullptr;
        }

        iterator begin() {
            return iterator(head);
        }

        iterator end() {
            return iterator(nullptr);
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif