//
//  CirculationQueueArray.hpp
//  18124681
//
//  Created by 张厚泽 on 2020/12/18.
//



#ifndef CirculationQueueArray_hpp
#define CirculationQueueArray_hpp

#include <iostream>
#include <array>

template<typename Type>
class CirculationQueueArray{
private:
    size_t front=0;
    size_t length=0;
    const static size_t nbMAX;
    std::array<Type, nbMAX> arr;
    
public:
    CirculationQueueArray()=default;
    bool isFull();
    bool isEmpty();
    bool addNum(Type);
    Type getNum();
    
};

template<typename Type>
const size_t CirculationQueueArray<Type>::nbMAX=5;

template<typename Type>
bool CirculationQueueArray<Type>::isFull(){
    if(this->length==this->nbMAX){
        return true;
    }else{
        return false;
    }
}

template<typename Type>
bool CirculationQueueArray<Type>::isEmpty(){
    return this->length==0;
}
    
template<typename Type>
bool CirculationQueueArray<Type>::addNum(Type num){
    if(this->isFull()){
        std::cerr<<"FULL QUEUE"<<std::endl;
    }else{
        arr[(front+(length++))%nbMAX]=num;
    }
    return true;
}

template<typename Type>
Type CirculationQueueArray<Type>::getNum(){
    if(this->isEmpty()){
        std::cerr<<"EMPTY QUEUE"<<std::endl;
    }else{
        length--;
        front%=nbMAX;
        return arr[front++];
    }
    return true;
}
    
    
#endif /* CirculationQueueArray_hpp */
