#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <string>
#include <iostream>
#include "Auxiliaries.h"


namespace mtm {
    class intMatrix
    {
    private:
        int** matrix;
        Dimensions dimensions;
    public:
        intMatrix(Dimensions dims,int init_num = 0);
        intMatrix(const intMatrix& intmatrix);
        ~intMatrix();
        intMatrix& operator=(const intMatrix& intmatrix);


        intMatrix& identity(Dimensions dims);
        int height(const intMatrix matrix);
        int width(const intMatrix matrix);
        int size(const intMatrix matrix);
        intMatrix transpose(const intMatrix matrix);
        intMatrix operator+(const intMatrix matrix) const;
        intMatrix operator-() const;
        intMatrix operator-(const intMatrix matrix) const;
        intMatrix operator+(const int x) const;
        intMatrix operator+=(const int x) const;
        std::ostream& operator<<(std::ostream& os) const;
        intMatrix operator()(const int col, const int row) const;
        intMatrix& operator()(const int col, const int row);
        bool operator<(intMatrix matrix);
        bool operator>(intMatrix matrix);
        bool operator>=(intMatrix matrix);
        bool operator<=(intMatrix matrix);
        bool operator==(intMatrix matrix);
        bool operator!=(intMatrix matrix);
        class iterator
        {
        private:
            int i;
        public:
            iterator();
            ~iterator();
            iterator begin(const intMatrix matrix) const;
            iterator end(const intMatrix matrix) const;
            iterator operator++() const;
            iterator operator*(intMatrix matrix) const;

        };




    };
    bool all(const intMatrix matrix);
    bool any(const intMatrix matrix);
//TODO symmetric


#endif //INTMATRIX_H
