//
//  Polynomial.hpp
//  18124681
//
//  Created by 张厚泽 on 2020/12/18.
//


#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <iostream>
#include <list>
#include <math.h>


template<typename Type>
class NodeSingle{
    
private:
    Type num;
    NodeSingle* nextNode;
    
public:
    NodeSingle(Type num,NodeSingle* node):num(num),nextNode(node){};
    Type getNum();
    NodeSingle* getNodeNext();
    void setNodeNext(NodeSingle*);
    
};

template<typename Type>
class SingleListCircule{
    
private:
    NodeSingle<Type>* nodeFirst;
    
public:
    void addNode(Type);
    SingleListCircule();
    SingleListCircule(std::list<Type>);
    NodeSingle<Type>* getNodeFirst() const;
    
};

class Polynomial{
private:
    class Nomial{
    private:
        int exp;
        double coef;
    public:
        Nomial()=default;
        Nomial(int exp,double coef):exp(exp),coef(coef){}
        int getExp() const {return this->exp;}
        double getCoef() const {return this->coef;}
        Nomial operator+(const Nomial&);
        bool operator<(const Nomial&);
        bool operator==(const Nomial&);
    };
    SingleListCircule<Nomial> polynominal;
    
public:
    Polynomial(std::list<Nomial>);
    Polynomial operator+(const Polynomial&);
    double Calc(double);
    
};


template<typename Type>
Type NodeSingle<Type>::getNum(){
    return this->num;
}

template<typename Type>
NodeSingle<Type>* NodeSingle<Type>::getNodeNext(){
    return this->nextNode;
}

template<typename Type>
void NodeSingle<Type>::setNodeNext(NodeSingle<Type> * ptr){
    this->nextNode=ptr;
}

template<typename Type>
SingleListCircule<Type>::SingleListCircule(){
    this->nodeFirst=new NodeSingle<Type>(Type(),nullptr);
    this->nodeFirst->setNodeNext(this->nodeFirst);
}

template<typename Type>
SingleListCircule<Type>::SingleListCircule(std::list<Type> il):SingleListCircule<Type>(){
    for(auto a:il){
        this->addNode(a);
    }
}

template<typename Type>
void SingleListCircule<Type>::addNode(Type num){
    if(this->nodeFirst==this->nodeFirst->getNodeNext()){
        this->nodeFirst->setNodeNext(new NodeSingle<Type>(num,this->nodeFirst));
        return;
    }else{
        NodeSingle<Type>* ptrnode=this->nodeFirst;
        do{
            if(ptrnode->getNodeNext()->getNum()<num){
                ptrnode->setNodeNext(new NodeSingle<Type>(num,ptrnode->getNodeNext()));
                return;
            }
            ptrnode=ptrnode->getNodeNext();
        }while(ptrnode->getNodeNext()!=this->nodeFirst);
        ptrnode->setNodeNext(new NodeSingle<Type>(num,this->nodeFirst));
        return;
    }
}

template<typename Type>
NodeSingle<Type>* SingleListCircule<Type>::getNodeFirst() const{
    return this->nodeFirst;
}



#endif /* Polynomial_hpp */
