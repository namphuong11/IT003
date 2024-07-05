#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

// Hàm nhập ma trận từ tập tin
void readMatrixFromFile(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int& cols) {
    ifstream inputFile("data.txt");
    if (inputFile.is_open()) {
        inputFile >> rows >> cols;  // Đọc số hàng và số cột của ma trận từ tập tin
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                inputFile >> matrix[i][j];  // Đọc từng phần tử của ma trận từ tập tin
            }
        }
        inputFile.close();
    } else {
        cout << "Khong the mo file." << endl;
    }
}

// Hàm xuất ma trận vào tập tin
void writeMatrixToFile(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    ofstream outputFile("data.txt");
    if (outputFile.is_open()) {
        outputFile << rows << " " << cols << endl;  // Ghi số hàng và số cột của ma trận vào tập tin
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                outputFile << matrix[i][j] << " ";  // Ghi từng phần tử của ma trận vào tập tin
            }
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cout << "Khong the mo file." << endl;
    }
}

// Hàm tìm phần tử Min, Max trong ma trận
void findMinMax(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int& minVal, int& maxVal) {
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
}

// Hàm sắp xếp ma trận theo thứ tự zigzag
void sortMatrixZigZag(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int size = rows * cols;
    int temp;

    for (int k = 0; k < size - 1; k++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i + j) % 2 == 0 && (i * cols + j) < (rows * cols - 1)) {
                    if (matrix[i][j] > matrix[i + 1][j + 1]) {
                        temp = matrix[i][j];
                        matrix[i][j] = matrix[i + 1][j + 1];
                        matrix[i + 1][j + 1] = temp;
                    }
                }
            }
        }
    }
}

// Hàm sắp xếp ma trận theo thứ tự trộn ốc xoáy vào trong
void sortMatrixSpiral(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int topRow = 0, bottomRow = rows - 1;
    int leftCol = 0, rightCol = cols - 1;

    while (topRow <= bottomRow && leftCol <= rightCol) {
        // In hàng từ trái sang phải
        for (int i = leftCol; i <= rightCol; i++) {
            cout << matrix[topRow][i] << " ";
        }
        topRow++;

        // In cột từ trên xuống dưới
        for (int i = topRow; i <= bottomRow; i++) {
            cout << matrix[i][rightCol] << " ";
        }
        rightCol--;

        // In hàng từ phải sang trái
        if (topRow <= bottomRow) {
            for (int i = rightCol; i >= leftCol; i--) {
                cout << matrix[bottomRow][i] << " ";
            }
            bottomRow--;
        }

        // In cột từ dưới lên trên
        if (leftCol <= rightCol) {
            for (int i = bottomRow; i >= topRow; i--) {
                cout << matrix[i][leftCol] << " ";
            }
            leftCol++;
        }
    }
}

// Hàm thêm một dòng v vào cuối ma trận
void addRow(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int cols, int v) {
    for (int j = 0; j < cols; j++) {
        matrix[rows][j] = v;
    }
    rows++;
}

// Hàm xóa dòng thứ k khỏi ma trận
void deleteRow(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int cols, int k) {
    if (k >= 0 && k < rows) {
        for (int i = k; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = matrix[i + 1][j];
            }
        }
        rows--;
    }
}

// Hàm tìm vị trí của phần tử vừa là phần tử lớn nhất trên dòng và nhỏ nhất trên cột
void findMaxOnRowMinOnCol(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int v, int& rowIdx, int& colIdx) {
    rowIdx = -1;
    colIdx = -1;
    int maxOnRow = INT_MIN;
    int minOnCol = INT_MAX;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxOnRow) {
                maxOnRow = matrix[i][j];
                rowIdx = i;
            }
            if (matrix[i][j] < minOnCol) {
                minOnCol = matrix[i][j];
                colIdx = j;
            }
        }
    }

    if (rowIdx != -1 && colIdx != -1 && maxOnRow != v && minOnCol != v) {
        rowIdx = -1;
        colIdx = -1;
    }
}

// Hàm tính tổng hai ma trận
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int rows, int cols, int sumMatrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Hàm tính tích hai ma trận
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], int rows1, int cols1, const int matrix2[MAX_SIZE][MAX_SIZE], int cols2, int resultMatrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Hàm tính tổng theo mỗi dòng của ma trận
void sumRows(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int rowSum[MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
        }
    }
}

// Hàm tính tổng theo mỗi cột của ma trận
void sumCols(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int colSum[MAX_SIZE]) {
    for (int j = 0; j < cols; j++) {
        colSum[j] = 0;
        for (int i = 0; i < rows; i++) {
            colSum[j] += matrix[i][j];
        }
    }
}

// Hàm xóa một dòng trên ma trận
void deleteMatrixRow(int matrix[MAX_SIZE][MAX_SIZE], int& rows, int cols, int rowIdx) {
    if (rowIdx >= 0 && rowIdx < rows) {
        for (int i = rowIdx; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = matrix[i + 1][j];
            }
        }
        rows--;
    }
}

// Hàm xóa một cột trên ma trận
void deleteMatrixColumn(int matrix[MAX_SIZE][MAX_SIZE], int rows, int& cols, int colIdx) {
    if (colIdx >= 0 && colIdx < cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = colIdx; j < cols - 1; j++) {
                matrix[i][j] = matrix[i][j + 1];
            }
        }
        cols--;
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // Đọc ma trận từ tập tin
    readMatrixFromFile(matrix, rows, cols);

    // Thực hiện các thao tác trên ma trận

    // a) Tìm phần tử Min, Max trong mảng 2 chiều.
    int minVal, maxVal;
    findMinMax(matrix, rows, cols, minVal, maxVal);
    cout << "Min: " << minVal << endl;
    cout << "Max: " << maxVal << endl;

    // b) Sắp xếp theo thứ tự zigzag.
    sortMatrixZigZag(matrix, rows, cols);

    // c) Sắp xếp theo thứ tự trộn ốc xoáy vào trong
    sortMatrixSpiral(matrix, rows, cols);

    // d) Thêm một dòng v vào ma trận ở cuối ma trận
    int v = 5; // Giá trị dòng mới
    addRow(matrix, rows, cols, v);

    // e) Xóa dòng thứ k khỏi ma trận
    int k = 2; // Số dòng cần xóa
    deleteRow(matrix, rows, cols, k);

    // f) Tìm vị trí của phần tử vừa là phần tử lớn nhất trên dòng của nó đồng thời nhỏ nhất trên cột của nó.
    int vRowIdx, vColIdx;
    findMaxOnRowMinOnCol(matrix, rows, cols, v, vRowIdx, vColIdx);
    cout << "Vi tri phan tu " << v << " la phan tu lon nhat tren dong va nho nhat tren cot: (" << vRowIdx << ", " << vColIdx << ")" << endl;

    // g) Tính tổng, tích 2 ma trận
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int sumMatrix[MAX_SIZE][MAX_SIZE];
    int productMatrix[MAX_SIZE][MAX_SIZE];

    // Đọc ma trận 1 từ tập tin
    readMatrixFromFile(matrix1, rows, cols);

    // Đọc ma trận 2 từ tập tin
    readMatrixFromFile(matrix2, rows, cols);

    // Tính tổng hai ma trận
    addMatrices(matrix1, matrix2, rows, cols, sumMatrix);

    // Tính tích hai ma trận
    multiplyMatrices(matrix1, rows, cols, matrix2, cols, productMatrix);

    // h) Tính tổng theo mỗi dòng và cột của ma trận.
    int rowSum[MAX_SIZE];
    int colSum[MAX_SIZE];

    // Tính tổng theo mỗi dòng của ma trận
    sumRows(matrix, rows, cols, rowSum);

    // Tính tổng theo mỗi cột của ma trận
    sumCols(matrix, rows, cols, colSum);

    // i) Xóa một dòng trên mảng 2 chiều vừa nhập.
    int rowIdxToDelete = 3;
    deleteMatrixRow(matrix, rows, cols, rowIdxToDelete);

    // j) Xóa một cột trên mảng 2 chiều vừa nhập trong C++
    int colIdxToDelete = 2;
    deleteMatrixColumn(matrix, rows, cols, colIdxToDelete);

    // Xuất ma trận vào tập tin
    writeMatrixToFile(matrix, rows, cols);

    return 0;
}

