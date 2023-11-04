#include<iostream>
#include"stack_a.h"
#include"stdexcept"
using namespace std;
Stack_A::Stack_A() {
    size = 0;
}
void Stack_A::push(int data){
    if(size<1024){
        stk[size]=data;
        size++;
    }
    else{
        throw runtime_error("Stack Full");
    }
}
int Stack_A::pop(){
    if(size>0){
        int temp;
        temp=stk[size-1];
        size--;
        return temp;
    }
    else{
        throw runtime_error("Empty Stack");
    }
}
int Stack_A::get_element_from_top(int idx){
    if(idx>=0 && idx<size){
        return stk[size-idx-1];
    }
    else{
        throw runtime_error("Index out of range");
    }
}
int Stack_A::get_element_from_bottom(int idx){
    if(idx>=0 && idx<size){
        return stk[idx];
    }
    else{
        throw runtime_error("Index out of range");
    }
}
void Stack_A::print_stack(bool top_or_bottom){
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
    else{
        // do nothing
    }
    
}
int Stack_A::add(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=stk[size-1];
        int top2=stk[size-2];
        pop();
        pop();
        push(top1+top2);
        return top1+top2;
    }
}
int Stack_A::subtract(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=stk[size-1];
        int top2=stk[size-2];
        pop();
        pop();
        push(top2-top1);
        return top2-top1;
    }
}
int Stack_A::multiply(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=stk[size-1];
        int top2=stk[size-2];
        pop();
        pop();
        push(top1*top2);
        return top1*top2;
    }
}
int Stack_A::divide(){
    if(get_size()<2){
        throw std::runtime_error("Not Enough Arguments");
    }
    else{
        int top1=stk[size-1];
        int top2=stk[size-2];
        if(top1==0){
            throw std::runtime_error("Divide by Zero Error");
        }
        else{
            pop();
            pop();
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
int* Stack_A::get_stack(){
    return stk;
}
int Stack_A::get_size(){
    return size;
}