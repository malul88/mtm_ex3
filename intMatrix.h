#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <string>
#include <iostream>
#include "Auxiliaries.h"

namespace mtm {

    class IntMatrix {
    private:
        int **matrix;
        Dimensions dimensions;
    public:
        IntMatrix(Dimensions dims, int init_num = 0);

        IntMatrix(int init_num );

        IntMatrix(const IntMatrix &matrix1);

        ~IntMatrix();

        IntMatrix &operator=(const IntMatrix &matrix1);

        static IntMatrix Identity(int dim); //todo static??

        int height() const;

        int width() const;

        int size() const;

        IntMatrix transpose() const;

        //IntMatrix operator+(const IntMatrix &matrix1) const;

        IntMatrix operator-() const;

        IntMatrix operator-(const IntMatrix matrix) const;

        IntMatrix& operator+=(const int x);

        //IntMatrix operator+(const int x) const;

        friend std::ostream& operator<<(std::ostream &os, const IntMatrix &matrix1) {
            int squared_dims = matrix1.IntMatrix::size();
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

        IntMatrix operator<(int n) const;

        IntMatrix operator>(int n) const;

        IntMatrix operator<=(int n) const;

        IntMatrix operator>=(int n) const;

        IntMatrix operator==(int n) const;

        IntMatrix operator!=(int n) const;


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
    IntMatrix operator+(const IntMatrix& matrix1 , const IntMatrix& matrix2);
    bool any(const IntMatrix& matrix);
    bool all(const IntMatrix& matrix); //TODO put the declaration in the header file

//    std::ostream& operator<<(std::ostream &os, IntMatrix &matrix1){
//        int squared_dims = matrix1.IntMatrix::size();
//        int* mat_to_array = new int[squared_dims];
//        for (int i = 0; i <matrix1.height() ; ++i) {
//            for (int j = 0; j <matrix1.width() ; ++j) {
//                mat_to_array[i+j] = matrix1(i, j);
//            }
//        }
//        return os << printMatrix(mat_to_array,matrix1.dimensions) << std::endl;
//    }


}

#endif //INTMATRIX_H
