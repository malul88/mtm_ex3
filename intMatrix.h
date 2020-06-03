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
        intMatrix(Dimensions dims,int init_num);
        ~intMatrix();
        intMatrix identity(Dimensions dims);
        int height(const intMatrix matrix);
        int width(const intMatrix matrix);
        int size(const intMatrix matrix);
        intMatrix transpose(const intMatrix matrix);
        intMatrix operator+(const intMatrix matrix) const;
        intMatrix operator-() const;



    };
    
    intMatrix::intMatrix(Dimensions dims, int init_num){

        }



}


#endif //INTMATRIX_H