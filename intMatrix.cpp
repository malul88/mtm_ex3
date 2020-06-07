#include "intMatrix.h"
#include "Auxiliaries.h"

using namespace mtm;

// matrix constructor
intMatrix::intMatrix(Dimensions dims, int init_num) : dimensions(dims), matrix(nullptr) { //todo check initialize list
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = init_num;
        }
    }
}

// matrix copy constructor
intMatrix::intMatrix(const intMatrix &intmatrix) : dimensions(intmatrix.dimensions), matrix(nullptr) {
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int *[col];
    for (int i = 0; i < col; i++) {
        matrix[i] = new int[row];
    }
    for (int i = 0; i < col; i++) { // todo check index
        for (int j = 0; j < row; j++) {
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
}

// matrix destructor
intMatrix::~intMatrix() {
    int col = this->dimensions.getCol();
    for (int i = 0; i < col; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


// assigment operator
intMatrix &intMatrix::operator=(const intMatrix &intmatrix) {
    if (this == &intmatrix) {
        return *this;
    }
    int row = intmatrix.dimensions.getRow();
    int col = intmatrix.dimensions.getCol();
    for (int i = 0; i < col; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    matrix = new int *[col];
    for (int i = 0; i < col; i++) {
        matrix[i] = new int[row];
    }
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
    return *this;
}

// Create an identity matrix with the required dimension
intMatrix intMatrix::identity(int dim) {
    Dimensions squared_dims(dim, dim);
    intMatrix result(squared_dims, 0);
    for (int i = 0; i < dim; ++i) {
        result.matrix[i][i] = 1;
    }
    return result;
}

int intMatrix::height() {
    int result = dimensions.getRow();
    return result;
}

int intMatrix::width() {
    int result = dimensions.getCol();
    return result;
}

int intMatrix::size() {
    int result = this->height() * this->width();
    return result;
}

intMatrix intMatrix::transpose() {
    Dimensions transposed_dimensions(this->dimensions.getCol(), this->dimensions.getRow());  // in purpose in order to make transposed matrix
    intMatrix transposed(transposed_dimensions);
    for (int i = 0; i < dimensions.getCol(); ++i) {
        for (int j = 0; j < dimensions.getRow(); ++j) {
            transposed.matrix[i][j] = this->matrix[j][i];
        }
    }
    return transposed;
}

intMatrix intMatrix::operator+(const intMatrix &matrix1) const {
    intMatrix result(matrix1.dimensions);
    for (int i = 0; i < result.dimensions.getCol(); ++i) {
        for (int j = 0; j < result.dimensions.getRow(); ++j) {
            result.matrix[i][j] = this->matrix[i][j] + matrix1.matrix[i][j];
        }
    }
    return result;
}

intMatrix intMatrix::operator-() const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <this->dimensions.getCol() ; ++i) {
        for (int j = 0; j <this->dimensions.getCol() ; ++j) {
            result.matrix[i][j] = -this->matrix[i][j];
        }
    }
    for (int i = 0; i <this->dimensions.getCol() ; ++i) {
        delete [] this->matrix[i];
    }
    delete [] this->matrix;
    return result;
}

intMatrix intMatrix::operator-(const intMatrix matrix1) const {
    intMatrix temp = -matrix1;
    intMatrix result(matrix1.dimensions);
    result = this->operator+(temp);
    return result;
}

intMatrix& intMatrix::operator+=(const int x) {
    for (int i = 0; i <this->dimensions.getCol() ; ++i) {
        for (int j = 0; j <this->dimensions.getRow() ; ++j) {
            this->matrix[i][j] += x;
        }
    }
    return *this;
}

intMatrix intMatrix::operator+(const int x) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <result.dimensions.getCol() ; ++i) {
        for (int j = 0; j <result.dimensions.getRow() ; ++j) {
            result.matrix[i][j] = this->matrix[i][j] + x;
        }
    }
    return result;
}

const int intMatrix::operator()(const int col, const int row) const{
    const int result = this->matrix[col][row];
    return result;
}

int& intMatrix::operator()(const int col, const int row){
    return this->matrix[col][row];
}

