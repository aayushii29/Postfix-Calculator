#include<iostream>
#include"list.h"
using namespace std;
List::List(){
    size=0;
    sentinel_head=new Node(true);
    sentinel_tail=new Node(true);
    sentinel_head->next=sentinel_tail;
    sentinel_tail->prev=sentinel_head;
 }
void List::insert(int v){
    Node* newNode;
    newNode=new Node(v,sentinel_tail,sentinel_tail->prev);
    sentinel_tail->prev->next=newNode;
    sentinel_tail->prev=newNode;
    size++;
}
int List::delete_tail(){
        int temp=sentinel_tail->prev->get_value();
        Node* newTail=sentinel_tail->prev;
        newTail->prev->next=sentinel_tail;
        sentinel_tail->prev=newTail->prev;
        delete newTail;
        size--;
        return temp;
}
int List::get_size(){
    return size;
}
Node* List::get_head(){
    return sentinel_head;
}
List::~List(){
    Node* current=sentinel_head->next;
    while(current->next!=nullptr){
        Node* temp=current;
        current=current->next;
        delete temp;
    }
    delete current;
    delete sentinel_head;
    delete sentinel_tail;
}