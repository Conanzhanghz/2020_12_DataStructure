#include <iostream>
#include "Triple.h"

int main() {
        TriSparseMatrix<int> myTri1(4, 4);
        myTri1.SetElem(0,1,4);
        myTri1.SetElem(2,2,4);
        myTri1.DisplayMatrix();
        std::cout << std::endl;
        TriSparseMatrix<int> myTri2(4, 4);
        myTri2.SetElem(0,1,4);
        myTri2.SetElem(3,3,4);
        myTri1.DisplayMatrix();
        std::cout << std::endl;
        TriSparseMatrix<int> myTri = myTri1+myTri2;
        //����������ֱ����whileѭ�����

    return 0;
}
