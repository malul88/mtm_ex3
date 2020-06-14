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

        intMatrix(int init_num );

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

        intMatrix& operator+=(const int x);

        intMatrix operator+(const int x) const;

        friend std::ostream& operator<<(std::ostream &os, const intMatrix &matrix1) {
            int squared_dims = matrix1.intMatrix::size();
            int* mat_to_array = new int[squared_dims]; //TODO template and check where is the implementation
            int rows = matrix1.dimensions.getRow();
            int cols = matrix1.dimensions.getCol();
            int counter = 0;
            for (int i = 0; i <rows; ++i) {
                for (int j = 0; j <cols; ++j) {
                    mat_to_array[counter++] =  matrix1.matrix[i][j];
                }
            }

            return os << printMatrix(mat_to_array,matrix1.dimensions) << std::endl;
        }

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
            Dimensions dims;
            int index;
            int** matrix;
        public:
            iterator(Dimensions dims, int i, int** matrix);

            ~iterator() = default;

            iterator(const iterator &it) ;

            iterator& operator=(const iterator& x);

            int& operator*() const;

            iterator operator++();

            iterator operator++(int);

            bool operator==(const iterator& x) const;

            bool operator!=(const iterator& x) const;

        };
        class const_iterator {
        private:
            Dimensions dims;
            int index;
            int** matrix;
        public:
            const_iterator(Dimensions dims, int i, int** matrix);

            ~const_iterator() = default;

            const_iterator(const const_iterator& it);

            const_iterator& operator=(const const_iterator& x);

            const int operator*() const;

            const_iterator operator++();

            const_iterator operator++(int);

            bool operator==(const const_iterator& x) const;

            bool operator!=(const const_iterator& x) const;

        };
        iterator begin();

        iterator end();

        const_iterator begin() const;

        const_iterator end() const;


    };
    intMatrix operator+(intMatrix x,const intMatrix& matrix1);


//    std::ostream& operator<<(std::ostream &os, intMatrix &matrix1){
//        int squared_dims = matrix1.intMatrix::size();
//        int* mat_to_array = new int[squared_dims];
//        for (int i = 0; i <matrix1.height() ; ++i) {
//            for (int j = 0; j <matrix1.width() ; ++j) {
//                mat_to_array[i+j] = matrix1(i, j);
//            }
//        }
//        return os << printMatrix(mat_to_array,matrix1.dimensions) << std::endl;
//    }

    bool any(const intMatrix matrix);
//TODO symmetric



}

#endif //INTMATRIX_H

