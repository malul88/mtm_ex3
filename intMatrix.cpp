#include "intMatrix.h"
#include "Auxiliaries.h"
using namespace mtm;

// matrix constructor
intMatrix::intMatrix(Dimensions dims,int init_num) : dimensions(dims) , matrix(nullptr) { //todo check initialize list
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            matrix[i][j] = init_num;
        }
    }
}

// matrix copy constructor
intMatrix::intMatrix(const intMatrix& intmatrix) : dimensions(intmatrix.dimensions) , matrix(nullptr){
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    for (int i = 0; i < row; i++) { // todo check index
        for (int j = 0; j < col; j++){
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
}

// matrix destructor
intMatrix::~intMatrix() {
    int row = this->dimensions.getRow();
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


// operator =
intMatrix& intMatrix::operator=(const intMatrix& intmatrix) {
    if (this == &intmatrix){
        return *this;
    }
    int row = intmatrix.dimensions.getRow();
    int col = intmatrix.dimensions.getCol();
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
    return *this;
}
