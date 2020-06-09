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
    for (int i = 0; i < col; i++) {
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

// return the number of row in the matrix
int intMatrix::height() const {
    int result = dimensions.getRow();
    return result;
}

//return the number of columns in the matrix
int intMatrix::width() const {
    int result = dimensions.getCol();
    return result;
}

//return the number of elements in the matrix
int intMatrix::size() const {
    int result = (this->height()) * (this->width());
    return result;
}

//Create transposed matrix
intMatrix intMatrix::transpose() const {
    Dimensions transposed_dimensions(this->dimensions.getCol(), this->dimensions.getRow());// in purpose in order to make transposed matrix
    intMatrix transposed(transposed_dimensions);
    for (int i = 0; i < transposed.dimensions.getCol(); ++i) {
        for (int j = 0; j < transposed.dimensions.getRow(); ++j) {
            transposed.matrix[i][j] = this->matrix[j][i];
        }
    }
    return transposed;
}

// Binary operator add matrix to other matrix and return the new summed matrix
intMatrix intMatrix::operator+(const intMatrix &matrix1) const {
    intMatrix result(matrix1.dimensions);
    for (int i = 0; i < result.dimensions.getCol(); ++i) {
        for (int j = 0; j < result.dimensions.getRow(); ++j) {
            result.matrix[i][j] = this->matrix[i][j] + matrix1.matrix[i][j];
        }
    }
    return result;
}
// Unary operator return the matrix where each element multiplied by -1
intMatrix intMatrix::operator-() const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <this->dimensions.getCol() ; ++i) {
        for (int j = 0; j <this->dimensions.getCol() ; ++j) {
            result.matrix[i][j] = -this->matrix[i][j];
        }
    }
    return result;
}

// Binary operator. return new matrix equals to mat1 - mat2
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

const int intMatrix::operator()(const int row, const int col) const{
    const int result = this->matrix[row][col];
    return result;
}

int& intMatrix::operator()(const int row, const int col){
    return this->matrix[row][col];
}

intMatrix intMatrix::operator<(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] < n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

intMatrix intMatrix::operator>(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] > n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

intMatrix intMatrix::operator<=(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] <= n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

intMatrix intMatrix::operator>=(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] >= n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

intMatrix intMatrix::operator==(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] == n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}
intMatrix intMatrix::operator!=(int n) const {
    intMatrix result(this->dimensions);
    for (int i = 0; i <dimensions.getCol() ; ++i) {
        for (int j = 0; j <dimensions.getRow() ; ++j) {
            if (this->matrix[i][j] != n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}
bool all(const intMatrix matrix); //TODO put the declaration in the header file

bool all(intMatrix matrix) {
    bool check = true;
    for (int i = 0; i <matrix.width(); ++i) {
        for (int j = 0; j <matrix.height() ; ++j) {
            if (matrix(i, j) == 0){
                check = false;
            }
        }
    }
    return check;
}

bool any(intMatrix matrix) {
    return !all(matrix); //the compiler cant tell the difference between declaration and implementation
}

int* intMatrix::iterator::begin(intMatrix matrix1) {
    dims = matrix1.dimensions;
    this->i = matrix1(0, 0);
    return &i;
}

int* intMatrix::iterator::end(intMatrix matrix1){
    int * result = &matrix1(matrix1.height() -1 ,matrix1.width());
    return result;
}


int main(){
    Dimensions dim4_4(4,4);
    intMatrix matrix1(dim4_4,3);
    intMatrix matrix2(dim4_4,5);
    intMatrix matrix3 = matrix1 + matrix2;
    intMatrix matrix5(dim4_4);
    matrix5 = -matrix3;

    return 0;
}
