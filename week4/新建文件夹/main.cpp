//
//  main.cpp
//  18124681
//
//  Created by 张厚泽 on 2020/12/18.
//

#include "CirculationQueueArray.hpp"
#include "Polynomial.hpp"

void tryCirculationQueueArray();
void tryPolynomial();
int main(int argc, const char * argv[]) {
    tryCirculationQueueArray();
    tryPolynomial();
}

void tryPolynomial(){
    int x=1;
    Polynomial p1({{1,2},{2,3}});
    Polynomial p2({{2,3}});
    Polynomial p=p1+p2;
    std::cout<<p1.Calc(x)<<std::endl;
    std::cout<<p2.Calc(x)<<std::endl;
    std::cout<<p.Calc(x)<<std::endl;
}

void tryCirculationQueueArray(){
    CirculationQueueArray<int> c;
    c.addNum(1);
    c.addNum(2);
    c.addNum(3);
    c.addNum(4);
    c.addNum(5);
    std::cout<<c.getNum()<<std::endl;
    c.addNum(6);
    std::cout<<c.getNum()<<std::endl;
    std::cout<<c.getNum()<<std::endl;
    std::cout<<c.getNum()<<std::endl;
    std::cout<<c.getNum()<<std::endl;
    std::cout<<c.getNum()<<std::endl;
}
