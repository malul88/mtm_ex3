#include "intMatrix.h"
#include "Auxiliaries.h"

using namespace mtm;

/// matrix constructor
IntMatrix::IntMatrix(Dimensions dims, int init_num) : dimensions(dims), matrix(nullptr) { //todo check initialize list
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int*[row];
    if (row)
    {
        matrix[0] = new int[row * col];
        for (int i = 1; i < row; ++i)
            matrix[i] = matrix[0] + i * col;
    }
//    matrix = new int *[col];
//    for (int i = 0; i < col; i++) {
//        matrix[i] = new int[row];
//    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = init_num;
        }
    }
}

/// matrix cast constructor (int to IntMatrix)
IntMatrix::IntMatrix(int init_num) : dimensions(1, 1), matrix(nullptr) {
    int row = 1;
    int col = 1;
    matrix = new int *[row];
    matrix[0] = new int[row * col];
    for (int i = 1; i < row; ++i)
        matrix[i] = matrix[0] + i * col;
//    matrix = new int *[col];
//    for (int i = 0; i < col; i++) {
//        matrix[i] = new int[row];
//    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = init_num;
        }
    }
}

/// matrix copy constructor
IntMatrix::IntMatrix(const IntMatrix &intmatrix) : dimensions(intmatrix.dimensions), matrix(nullptr) {
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    matrix = new int*[row];
    if (row)
    {
        matrix[0] = new int[row * col];
        for (int i = 1; i < row; ++i)
            matrix[i] = matrix[0] + i * col;
    }
//    matrix = new int *[col];
//    for (int i = 0; i < col; i++) {
//        matrix[i] = new int[row];
//    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
}

/// matrix destructor
IntMatrix::~IntMatrix() {
    int row = this->dimensions.getRow();
    if (row) delete [] matrix[0];
    delete [] matrix;
//    for (int i = 0; i < col; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
}


/// assigment operator
IntMatrix &IntMatrix::operator=(const IntMatrix &intmatrix) {
    if (this == &intmatrix) {
        return *this;
    }
    int row = intmatrix.dimensions.getRow();
    int col = intmatrix.dimensions.getCol();
    if (row) delete [] matrix[0];
    delete [] matrix;
    matrix = new int *[row];
    matrix[0] = new int[row * col];
    for (int i = 1; i < row; ++i)
        matrix[i] = matrix[0] + i * col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = intmatrix.matrix[i][j];
        }
    }
    this->dimensions = intmatrix.dimensions;
    return *this;
}

// Create an Identity matrix with the required dimension
IntMatrix IntMatrix::Identity(int dim) {
    Dimensions squared_dims(dim, dim);
    IntMatrix result(squared_dims, 0);
    for (int i = 0; i < dim; ++i) {
        result.matrix[i][i] = 1;
    }
    return result;
}

// return the number of row in the matrix
int IntMatrix::height() const {
    int result = dimensions.getRow();
    return result;
}

//return the number of columns in the matrix
int IntMatrix::width() const {
    int result = dimensions.getCol();
    return result;
}

/// return the number of elements in the matrix
int IntMatrix::size() const {
    int result = (this->height()) * (this->width());
    return result;
}

/// Create transposed matrix
IntMatrix IntMatrix::transpose() const {
    Dimensions transposed_dimensions(this->dimensions.getCol(), this->dimensions.getRow());// in purpose in order to make transposed matrix
    IntMatrix transposed(transposed_dimensions);
    int col = transposed.dimensions.getCol();
    int row = transposed.dimensions.getRow();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            transposed.matrix[i][j] = this->matrix[j][i];
        }
    }
    return transposed;
}

//// Binary operator add matrix to other matrix and return the new summed matrix
//IntMatrix IntMatrix::operator+(const IntMatrix &matrix1) const { todo dlt
//    IntMatrix result(matrix1.dimensions);
//    for (int i = 0; i < result.dimensions.getCol(); ++i) {
//        for (int j = 0; j < result.dimensions.getRow(); ++j) {
//            result.matrix[i][j] = this->matrix[i][j] + matrix1.matrix[i][j];
//        }
//    }
//    return result;
//}

/// Unary operator return the matrix where each element multiplied by -1
IntMatrix IntMatrix::operator-() const {
    IntMatrix result(this->dimensions);
    int col = this->dimensions.getCol();
    int row = this->dimensions.getRow();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result.matrix[i][j] = -this->matrix[i][j];
        }
    }
    return result;
}

/// Binary operator. return new matrix equals to mat1 - mat2
IntMatrix IntMatrix::operator-(const IntMatrix matrix1) const { // todo check
    IntMatrix temp = -matrix1;
    IntMatrix result = *this + temp;
    return result;
}

IntMatrix& IntMatrix::operator+=(const int x) {
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            this->matrix[i][j] += x;
        }
    }
    return *this;
}

//IntMatrix IntMatrix::operator+(const int x) const { todo dlt
//    IntMatrix result(this->dimensions);
//    for (int i = 0; i <result.dimensions.getCol() ; ++i) {
//        for (int j = 0; j <result.dimensions.getRow() ; ++j) {
//            result.matrix[i][j] = this->matrix[i][j] + x;
//        }
//    }
//    return result;
//}

const int IntMatrix::operator()(const int row, const int col) const{
    const int result = this->matrix[row][col];
    return result;
}

int& IntMatrix::operator()(const int row, const int col){
    return this->matrix[row][col];
}

IntMatrix IntMatrix::operator<(int n) const {
    IntMatrix result(this->dimensions);
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] < n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

IntMatrix IntMatrix::operator>(int n) const {
    IntMatrix result(this->dimensions);
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] > n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

IntMatrix IntMatrix::operator<=(int n) const {
    IntMatrix result(this->dimensions);
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] <= n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

IntMatrix IntMatrix::operator>=(int n) const {
    IntMatrix result(this->dimensions);
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] >= n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

IntMatrix IntMatrix::operator==(int n) const {
    IntMatrix result(this->dimensions);
    int row = dimensions.getRow();
    int col = dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] == n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}
IntMatrix IntMatrix::operator!=(int n) const {
    IntMatrix result(this->dimensions);
    int row = this->dimensions.getRow();
    int col = this->dimensions.getCol();
    for (int i = 0; i < row ; ++i) {
        for (int j = 0; j < col ; ++j) {
            if (this->matrix[i][j] != n){
                result.matrix[i][j] = 1;
            }
        }
    }
    return result;
}

bool mtm::all(const IntMatrix& matrix) {
    bool check = true;
    for (int i = 0; i <matrix.height(); ++i) {
        for (int j = 0; j <matrix.width() ; ++j) {
            if (matrix(i, j) == 0){
                check = false;
            }
        }
    }
    return check;
}

bool mtm::any(const IntMatrix& matrix) {
    for (int i = 0; i <matrix.height(); ++i) {
        for (int j = 0; j <matrix.width() ; ++j) {
            if (matrix(i, j) != 0){
                return true;
            }
        }
    }
    return false; //the compiler cant tell the difference between declaration and implementation
}


IntMatrix::iterator IntMatrix::begin() {
    iterator it(dimensions,0, this->matrix);
    return it;
}

IntMatrix::iterator IntMatrix::end(){
    iterator it(dimensions,dimensions.getCol()*dimensions.getRow(), this->matrix);
    return it;
}


IntMatrix::iterator::iterator(Dimensions dims, int i, int** matrix) : dims(dims), index(i), matrix(matrix) {
}

IntMatrix::iterator::iterator(const iterator &it): dims(it.dims), index(it.index), matrix(it.matrix){
}

IntMatrix::iterator& IntMatrix::iterator::operator=(const IntMatrix::iterator &it) {
    if (this == &it){
        return *this;
    }
    dims = it.dims;
    matrix = it.matrix;
    index = it.index;
    return *this;
}

int &IntMatrix::iterator::operator*() const {
    int column = index % dims.getCol();
    int row = index / dims.getCol();
    return matrix[row][column];
}

IntMatrix::iterator IntMatrix::iterator::operator++() {
    index++;
    return *this;
}


IntMatrix::iterator IntMatrix::iterator::operator++(int) {
    iterator it = *this;
    this->index++;
    return it;
}

bool IntMatrix::iterator::operator!=(const IntMatrix::iterator &it) const {
    bool b = ((dims != it.dims) || (index != it.index) || (matrix != it.matrix));
    return b;
}

bool IntMatrix::iterator::operator==(const IntMatrix::iterator &it) const {
    return !operator!=(it);
}

IntMatrix::const_iterator::const_iterator(Dimensions dims, int i, int** matrix) : dims(dims), index(i), matrix(matrix) {
}


IntMatrix::const_iterator::const_iterator(const const_iterator &it): dims(it.dims), index(it.index), matrix(it.matrix){
}

IntMatrix::const_iterator& IntMatrix::const_iterator::operator=(const IntMatrix::const_iterator &it) {
    if (this == &it){
        return *this;
    }
    dims = it.dims;
    matrix = it.matrix;
    index = it.index;
    return *this;
}

const int IntMatrix::const_iterator::operator*() const {
    int column = index % dims.getCol();
    int row = index / dims.getCol();
    return matrix[row][column];
}

IntMatrix::const_iterator IntMatrix::const_iterator::operator++() {
    index++;
    return *this;
}


IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int) {
    const_iterator it = *this;
    this->index++;
    return it;
}

bool IntMatrix::const_iterator::operator!=(const IntMatrix::const_iterator &it) const {
    bool b = ((dims != it.dims) || (index != it.index) || (matrix != it.matrix));
    return b;
}

bool IntMatrix::const_iterator::operator==(const IntMatrix::const_iterator &it) const {
    return !operator!=(it);
}

IntMatrix::const_iterator IntMatrix::begin() const {
    const_iterator it(dimensions,0, this->matrix);
    return it;
}

IntMatrix::const_iterator IntMatrix::end() const {
    const_iterator it(dimensions,dimensions.getCol()*dimensions.getRow(), this->matrix);
    return it;
}

IntMatrix mtm::operator+(const IntMatrix& matrix1, const IntMatrix& matrix2){
    if (matrix1.size() == 1){
        IntMatrix new_mat = matrix2;
        int num = matrix1(0,0);
        for (int i = 0; i < matrix2.height(); ++i) {
            for (int j = 0; j < matrix2.width(); ++j) {
                new_mat(i,j) += num;
            }
        }
        return new_mat;
    }
    else if (matrix2.size() == 1){
        IntMatrix new_mat = matrix1;
        int num = matrix2(0,0);
        for (int i = 0; i < matrix1.height(); ++i) {
            for (int j = 0; j < matrix1.width(); ++j) {
                new_mat(i,j) += num;
            }
        }
        return new_mat;
    } else{
        IntMatrix new_mat = matrix1;
        for (int i = 0; i < matrix1.height(); ++i) {
            for (int j = 0; j < matrix1.width(); ++j) {
                new_mat(i,j) += matrix2(i,j);
            }
        }
        return new_mat;
    }
}


