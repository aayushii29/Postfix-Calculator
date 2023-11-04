#include<iostream>
#include"stack_c.h"
#include"stdexcept"

using namespace std;
Stack_C::Stack_C(){
    try{
        stk=new List();
    }
    catch(const bad_alloc& e){
        throw runtime_error("Out of Memory");
    }
}
Stack_C::~Stack_C(){
    delete stk;
}
void Stack_C::push(int data){
    stk->insert(data);
}
int Stack_C::pop(){
    if(get_size()==0){
        throw std::runtime_error("Empty Stack");
    }
    else{
        return stk->delete_tail();
    }
}
int Stack_C::get_element_from_top(int idx){
    if(idx>=get_size()){
        throw std::runtime_error("Index out of range");
    }
    else{
        Node* current=stk->get_head()->next;
        int i=0;
        int size=get_size();
        while(i!=size-idx-1){
            i++;
            current=current->next;
        }
        return current->get_value();
    }
}
int Stack_C::get_element_from_bottom(int idx){
    if(idx>=get_size()){
        throw std::runtime_error("Index out of range");
    }
    else{
        Node* current=stk->get_head()->next;
        int i=0;
        while(i!=idx){
            i++;
            current=current->next;
        }
        return current->get_value();
    }
}
void Stack_C::print_stack(bool top_or_bottom){
    if(get_size()!=0){
        if(top_or_bottom==0){
            Node* current=stk->get_head()->next;
            while(current!=stk->get_head()){
                std::cout<<current->get_value()<<std::endl;
                current=current->next;
             }
        }
        else{
            Node* current=stk->get_head()->next;
            while(current->next!=nullptr){
                current=current->next;
            }
            while(current->prev!=stk->get_head()){
                std::cout<<current->prev->get_value()<<std::endl;
                current=current->prev;
            }
        }
    }
    else{
        // do nothing
    }
    
}
int Stack_C::add(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        push(top1+top2);
        return top1+top2;
    }
}
int Stack_C::subtract(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        push(top2-top1);
        return top2-top1;
    }
}
int Stack_C::multiply(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        push(top2*top1);
        return top2*top1;
    }
}
int Stack_C::divide(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        if(top1==0){
            push(top2);
            push(top1);
            throw std::runtime_error("Divide by Zero Error");
        }
        else{
            if(top2*top1<0){
                if(top2%top1!=0){
                    push(top2/top1-1);
                    return top2/top1-1;
                }
                else{
                    push(top2/top1);
                    return top2/top1;
                }
            }
            else{
                push(top2/top1);
                return top2/top1;
            }
        }
    }
}
List* Stack_C::get_stack(){
    return stk;
} 

int Stack_C::get_size(){
    return stk->get_size();
}