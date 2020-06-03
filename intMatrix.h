#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <string>
#include <iostream>
#include "Auxiliaries.h"


namespace mtm {
    class intMatrix
    {
    private:
        /* data */
    public:
        intMatrix(Dimensions::Dimensions,const int init_num);
        ~intMatrix();
        intMatrix identity(Dimensions::Dimensions);
        int height(const intMatrix matrix);
        int width(const intMatrix matrix);
        int size(const intMatrix matrix);
        intMatrix transpose(const intMatrix matrix);
        intMatrix operator+(const intMatrix matrix) const;
        intMatrix operator-() const;



    };
    
    intMatrix::intMatrix(Dimensions::Dimensions, int init_num){

        }
    
    intMatrix::~intMatrix()
    {
    }
    
}


#endif //INTMATRIX_H