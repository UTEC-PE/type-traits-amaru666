#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

template <class T>
class SListIterator : public Iterator<T> {
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++() {
            if(this->current && this->current->next!= nullptr) this->current = this->current->next;
            return SListIterator<T>(this->current);
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T; //Integer or Float
        typedef typename Tr::Operation Operation; //Less or Greater
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            while(*pointer && cmp(search,(*pointer)->data)){
                if((*pointer)->data == search) return true;
                pointer = &((*pointer)->next);
            }
            return false;
        }
             
        bool insert(T data) {
            Node<T> **pointer = &head;
            if(!find(data,pointer)){

                Node<T> * new_node = new Node<T>(data);
                new_node->next = *pointer;
                (*pointer) = new_node;
                std::cout<<"insert "<<data<<std::endl;
                return true;
            }
            return false;
        }
             
     /*   bool remove(T item) {
            // TODO
        }*/
             
        iterator begin() {
            return iterator(this->head);
        }
             
        iterator end() {
            return iterator(nullptr);
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif