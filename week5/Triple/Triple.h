#include <iostream>
#include <stdexcept>
#include "Assistance.h"

template<typename ElemType>
class Triple {
public:
    int row,col;
    ElemType value;
    Triple() = default;
    Triple(int r, int c, ElemType v = 0) : row(r), col(c), value(v) {}
};
template<typename ElemType>
class TriSparseMatrix {
protected:
    Triple<ElemType> *triElems;
    int maxSize,rows,cols;
public:
    int num;
    explicit TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE);
    TriSparseMatrix<ElemType> &operator+(const TriSparseMatrix<ElemType> &other);
    Status SetElem(int r, int c, const ElemType &v);
    void Display() const;
    void DisplayMatrix() const;
};

template<typename ElemType>
TriSparseMatrix<ElemType> &TriSparseMatrix<ElemType>::operator+(const TriSparseMatrix<ElemType> &other) {
    TriSparseMatrix<ElemType> temp(rows, cols);
    int iRep = 0;
    int jRep = 0;
    int iTmp;

    cout<<"default success"<<endl;
    //判定两个矩阵维数是否一致
    if (rows != other.rows || cols != other.cols) throw std::logic_error("维数错误");
    while (iRep < num && jRep < other.num) {
        cout<<"1roule   "<<"iRep:"<<iRep<<"  jRep:"<<jRep<<"  iTmp:"<<iTmp<<endl;
        if (triElems[iRep].row == other.triElems[jRep].row) {
            if (triElems[iRep].col == other.triElems[jRep].col) {
                iTmp = triElems[iRep].value + other.triElems[jRep].value;
                if (iTmp != 0) {
                    temp.triElems[temp.num].row = triElems[iRep].row;
                    temp.triElems[temp.num].col = triElems[iRep].col;
                    temp.triElems[temp.num].value = iTmp;
                    temp.num++;
                }
                iRep++;
                jRep++;
                TriSparseMatrix<int> myTri = temp;
                myTri.DisplayMatrix();
            } else if (triElems[iRep].col > other.triElems[jRep].col) {
                temp.triElems[temp.num].row = other.triElems[jRep].row;
                temp.triElems[temp.num].col = other.triElems[jRep].col;
                temp.triElems[temp.num].value = other.triElems[jRep].value;
                temp.num++;
                jRep++;
                TriSparseMatrix<int> myTri = temp;
                myTri.DisplayMatrix();

            } else if (triElems[iRep].col < other.triElems[jRep].col) {
                temp.triElems[temp.num].row = triElems[iRep].row;
                temp.triElems[temp.num].col = triElems[iRep].col;
                temp.triElems[temp.num].value = triElems[iRep].value;
                temp.num++;
                iRep++;
                TriSparseMatrix<int> myTri = temp;
                myTri.DisplayMatrix();

            }
        } else if (triElems[iRep].row > other.triElems[jRep].row) {
            temp.triElems[temp.num].row = other.triElems[jRep].row;
            temp.triElems[temp.num].col = other.triElems[jRep].col;
            temp.triElems[temp.num].value = other.triElems[jRep].value;
            temp.num++;
            jRep++;
            TriSparseMatrix<int> myTri = temp;
            myTri.DisplayMatrix();

        } else if (triElems[iRep].row < other.triElems[jRep].row) {
            temp.triElems[temp.num].row = triElems[iRep].row;
            temp.triElems[temp.num].col = triElems[iRep].col;
            temp.triElems[temp.num].value = triElems[iRep].value;
            temp.num++;
            iRep++;
            TriSparseMatrix<int> myTri = temp;
            myTri.DisplayMatrix();

        }
    }

    cout<<"1roule fini"<<endl;
    while (iRep < num) {
        cout<<"2roule   "<<"iRep:"<<iRep<<"  jRep:"<<jRep<<"  iTmp:"<<iTmp<<endl;
        temp.triElems[temp.num].row = triElems[iRep].row;
        temp.triElems[temp.num].col = triElems[iRep].col;
        temp.triElems[temp.num].value = triElems[iRep].value;
        temp.num++;
        iRep++;
        TriSparseMatrix<int> myTri = temp;
        myTri.DisplayMatrix();
    }

    while (jRep < num) {
        cout<<"3roule   "<<"iRep:"<<iRep<<"  jRep:"<<jRep<<"  iTmp:"<<iTmp<<endl;

        temp.triElems[temp.num].row = other.triElems[jRep].row;
        temp.triElems[temp.num].col = other.triElems[jRep].col;
        temp.triElems[temp.num].value = other.triElems[jRep].value;
        temp.num++;
        jRep++;
        TriSparseMatrix<int> myTri = temp;
        myTri.DisplayMatrix();
    }

    cout<<"fini"<<endl;
    //return temp;
}

template<typename ElemType>
Status TriSparseMatrix<ElemType>::SetElem(int r, int c, const ElemType &v) {
    if (r > rows || c > cols)
        return FAIL;
    else {
        triElems[num].row = r;
        triElems[num].col = c;
        triElems[num].value = v;
        num++;
        return SUCCESS;
    }
}
//稀疏矩阵构造器
template<typename ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int rs, int cs, int size) {
    maxSize = size;
    triElems = new Triple<ElemType>[maxSize];
    rows = rs;
    cols = cs;
    num = 0;
}

template<typename ElemType>
void TriSparseMatrix<ElemType>::Display() const {
    for (unsigned int i = 0; i < num; i++) {
        std::cout << triElems[i].value << ", ";
    }
}

template<typename ElemType>
void TriSparseMatrix<ElemType>::DisplayMatrix() const {
    // 必须规则set才可使用

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            bool flag = true;
            for (unsigned int count = 0; count < num; count++)
                if (i == triElems[count].row && j == triElems[count].col) {
                    printf("%3d", triElems[count].value);
                    flag = false;
                }
            if (flag) printf("%3d", 0);
        }
        std::cout << std::endl;
    }
}
