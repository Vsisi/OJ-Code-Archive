#include<bits/stdc++.h>
using namespace std;
class Matrix{
public:
    Matrix(int row, int col):row(row), col(col) {
        mat = new int*[row];
        for(int i = 0; i < row; i++) {
            mat[i] = new int[col];
        }
    }
    ~Matrix() {
        for(int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    Matrix(const Matrix& rhs):row(rhs.row), col(rhs.col) {
        mat = new int*[row];
        for(int i = 0; i < row; i++) {
            mat[i] = new int[col];
            for(int j = 0; j < col; j++) {
                mat[i][j] = rhs.get(i, j);
            }
        }
    }
    int get(int i, int j) const {
        return mat[i][j];
    }
    void set(int i, int j, int val) {
        mat[i][j] = val;
    }
    Matrix operator*(const Matrix& rhs) const {
        if(this->col != rhs.row) {
            return *this;
        }
        Matrix res(this->row, rhs.col);
        int sum = 0;
        for(int i = 0; i < this->row; i++) {
            for(int j = 0; j < rhs.col; j++) {
                sum = 0;
                for(int k = 0; k < this->col; k++) {
                    sum += this->get(i, k) * rhs.get(k, j);
                }
                res.set(i, j, sum);
            }
        }
        return res;
    }
    Matrix transpose() const {
        Matrix res(this->col, this->row);
        for(int i = 0; i < this->col; i++) {
            for(int j = 0; j < this->row; j++) {
                res.set(i, j, this->get(j, i));
            }
        }
        return res;
    }
    int getRow() {
        return row;
    }
    int getCol() {
        return col;
    }
private:
    int row, col;
    int** mat;
};
int main() {
    int x1, y1, x2, y2;
    int tmp;
    cin >> x1 >> y1;
    Matrix a(x1, y1);
    for(int i = 0; i < x1; i++) {
        for(int j = 0; j < y1; j++) {
            cin >> tmp;
            a.set(i, j, tmp);
        }
    }
    cin >> x2 >> y2;
    Matrix b(x2, y2);
    for(int i = 0; i < x2; i++) {
        for(int j = 0; j < y2; j++) {
            cin >> tmp;
            b.set(i, j, tmp);
        }
    }
    Matrix c = (a*b).transpose();
    for(int i = 0; i < c.getRow(); i++) {
        for(int j = 0; j < c.getCol(); j++) {
            cout << setw(5) << c.get(i, j);
        }
        cout << endl;
    }
    return 0;
}
