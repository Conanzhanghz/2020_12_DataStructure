//
//  Polynomial.cpp
//  18124681
//
//  Created by 张厚泽 on 2020/12/18.
//

#include "Polynomial.hpp"
Polynomial::Nomial Polynomial::Nomial::operator+(const Nomial & othernomial){
    if(this->exp==othernomial.getExp()){
        return Nomial(exp,this->coef+othernomial.getCoef());
    }else{
        throw std::exception();
    }
}

bool Polynomial::Nomial::operator<(const Nomial& othernominal){
    return this->exp<othernominal.getExp();
}

bool Polynomial::Nomial::operator==(const Nomial& othernominal){
    return this->exp==othernominal.getExp();
}

Polynomial::Polynomial(std::list<Nomial> nomials){
    this->polynominal=SingleListCircule<Nomial>(nomials);
}

Polynomial Polynomial::operator+(const Polynomial& otherpolynomial){
    std::list<Nomial> li;
    NodeSingle<Nomial>* ptr1=this->polynominal.getNodeFirst()->getNodeNext();
    NodeSingle<Nomial>* ptr2=otherpolynomial.polynominal.getNodeFirst()->getNodeNext();
    while(ptr1!=this->polynominal.getNodeFirst()||ptr2!=otherpolynomial.polynominal.getNodeFirst()){
        if(ptr1==this->polynominal.getNodeFirst()){
            li.push_back(ptr2->getNum());
            ptr2=ptr2->getNodeNext();
        }else if (ptr2==otherpolynomial.polynominal.getNodeFirst()){
            li.push_back(ptr1->getNum());
            ptr1=ptr1->getNodeNext();
        }else{
            if(ptr1->getNum()==ptr2->getNum()){
                li.push_back(Nomial(ptr1->getNum()+ptr2->getNum()));
                ptr1=ptr1->getNodeNext();
                ptr2=ptr2->getNodeNext();
            }else if(ptr1->getNum()<ptr2->getNum()){
                li.push_back(ptr2->getNum());
                ptr2=ptr2->getNodeNext();
            }else{
                li.push_back(ptr1->getNum());
                ptr1=ptr1->getNodeNext();
            }
        }
    }
    return Polynomial(li);
}

double Polynomial::Calc(double x){
    NodeSingle<Nomial>* ptr=this->polynominal.getNodeFirst()->getNodeNext();
    double sum=0;
    while(ptr!=this->polynominal.getNodeFirst()){
        sum+=ptr->getNum().getCoef()*pow(x,ptr->getNum().getExp());
        ptr=ptr->getNodeNext();
    }
    return sum;
}
