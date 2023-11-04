#include<iostream>
#include "stack_b.h"
#include"stdexcept"
using namespace std;
Stack_B::Stack_B(){
    capacity=1024;
    size=0;
    stk= new(nothrow) int[1024];
    if(stk==NULL){
        throw runtime_error("Out of Memory");
    }
}
void Stack_B::push(int data){
    if(size>=capacity){
        capacity=capacity*2;
        int* temp= stk;
        stk = new(nothrow) int[capacity];
        if(stk==NULL){
        throw runtime_error("Out of Memory");
    }
        for(int i=0;i<size;i++){
            stk[i]=temp[i];
        }
        delete[] temp;
        stk[size]=data;
        size++;
    }
    else{
        stk[size]=data;
        size++;
    }
}
int Stack_B::pop(){
    if(size<capacity/4 && capacity/2>=1024){
        capacity=capacity/2;
        int *temp= stk;
        stk = new(nothrow) int[capacity];
        if(stk==NULL){
        throw runtime_error("Out of Memory");
        }
        for(int i=0;i<size;i++){
            stk[i]=temp[i];
        }
        delete[] temp;
        size--;
        return stk[size];
    }
    else if(size>0){
        size--;
        return stk[size];
    }
    else{
        throw runtime_error("Empty Stack");
    }
}
int Stack_B::get_element_from_top(int idx){
    if(idx<size && idx>=0){
        return stk[size-idx-1];
    }
    else{
        throw runtime_error("Index out of range");
    }
}
int Stack_B::get_element_from_bottom(int idx){
    if(idx<size && idx>=0){
        return stk[idx];
    }
    else{
        throw runtime_error("Index out of range");
    }
}
void Stack_B::print_stack(bool top_or_bottom){
    if(size!=0){
        if(top_or_bottom==1){
            for(int i=size-1;i>=0;i--){
                cout<<stk[i]<<endl;
            }
        }
        else{
            for(int i=0;i<size;i++){
                cout<<stk[i]<<endl;
            }
        }
    }
}
int Stack_B::add(){
    if(get_size()<2){
        throw runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        push(top1+top2);
        return top1+top2;
    }
}
int Stack_B::subtract(){
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
int Stack_B::multiply(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        push(top1*top2);
        return top1*top2;
    }
}
int Stack_B::divide(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=pop();
        int top2=pop();
        if(top1==0){
            throw std::runtime_error("Divide by Zero Error");
        }
        else{
            if(top2*top1<0){
                if(top2%top1!=0){
                    push((top2/top1)-1);
                    return (top2/top1)-1;
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
int* Stack_B::get_stack(){
    return stk;
}
int Stack_B::get_size(){
    return size;
}
Stack_B::~Stack_B(){
    delete[] stk;
}