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
        intMatrix(const intMatrix& matrix1);
        ~intMatrix();
        intMatrix& operator=(const intMatrix& matrix1);
        intMatrix identity(int dim);
        int height() const ;
        int width() const ;
        int size() const ;
        intMatrix transpose() const ;
        intMatrix operator+(const intMatrix& matrix1) const;
        intMatrix operator-() const;
        intMatrix operator-(const intMatrix matrix) const;
        intMatrix& operator+=(const int x);
        intMatrix operator+(const int x) const;
        friend std::ostream& operator<<(std::ostream& os,intMatrix& matrix1);
        const int operator()(const int col, const int row) const;
        int& operator()(const int col, const int row);
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
    std::ostream& operator<<(std::ostream& os,intMatrix& matrix1){
        int squared_dims = matrix1.intMatrix::size();
        int* mat_to_array = new int[squared_dims];
        for (int i = 0; i <matrix1.dimensions.getRow() ; ++i) {
            for (int j = 0; j <matrix1.dimensions.getCol() ; ++j) {
                mat_to_array[i+j] = matrix1.matrix[i][j];
            }
        }
        return os << printMatrix(mat_to_array,matrix1.dimensions) << std::endl;
    }
}
#endif //INTMATRIX_H
