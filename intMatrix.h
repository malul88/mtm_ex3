#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <string>
#include <iostream>
#include "Auxiliaries.h"


namespace mtm {

    class intMatrix {
    private:
        int **matrix;
        Dimensions dimensions;
    public:
        intMatrix(Dimensions dims, int init_num = 0);

        intMatrix(const intMatrix &matrix1);

        ~intMatrix();

        intMatrix &operator=(const intMatrix &matrix1);

        intMatrix identity(int dim);

        int height() const;

        int width() const;

        int size() const;

        intMatrix transpose() const;

        intMatrix operator+(const intMatrix &matrix1) const;

        intMatrix operator-() const;

        intMatrix operator-(const intMatrix matrix) const;

        intMatrix &operator+=(const int x);

        intMatrix operator+(const int x) const;

        friend std::ostream &operator<<(std::ostream &os, intMatrix &matrix1);

        const int operator()(const int col, const int row) const;

        int &operator()(const int col, const int row);

        intMatrix operator<(int n) const;

        intMatrix operator>(int n) const;

        intMatrix operator<=(int n) const;

        intMatrix operator>=(int n) const;

        intMatrix operator==(int n) const;

        intMatrix operator!=(int n) const;

        class iterator {
        private:
            int& i;
            Dimensions dims;
        public:
            iterator();

            ~iterator();

            iterator(const iterator& x);

            iterator operator=(const iterator& x);

            int* begin(intMatrix matrix);

            int* end(intMatrix matrix);

            int operator*(intMatrix matrix) const;

            iterator operator++();

            iterator operator++(int);

            iterator operator==(const iterator& x) const;

            iterator operator!=(const iterator& x) const;

        };
        class const_iterator {
        private:
            int i;
        public:
            const_iterator();

            ~const_iterator();

            const_iterator(const const_iterator& x);

            const_iterator operator=(const const_iterator& x);

            const_iterator begin(const intMatrix matrix) const;

            const_iterator end(const intMatrix matrix) const;

            const_iterator operator*(intMatrix matrix) const;

            const_iterator operator++();

            const_iterator operator++(int);

            const_iterator operator==(const const_iterator& x) const;

            const_iterator operator!=(const const_iterator& x) const;

        };


    };

    bool any(const intMatrix matrix);
//TODO symmetric


//    std::ostream& operator<<(std::ostream& os,intMatrix& matrix1){
//        int squared_dims = matrix1.intMatrix::size();
//        int* mat_to_array = new int[squared_dims];
//        for (int i = 0; i <matrix1.dimensions.getRow() ; ++i) {
//            for (int j = 0; j <matrix1.dimensions.getCol() ; ++j) {
//                mat_to_array[i+j] = matrix1.matrix[i][j];
//            }
//        }
//        return os << printMatrix(mat_to_array,matrix1.dimensions) << std::endl;
//    }
}
#endif //INTMATRIX_H

