#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void deleteElement(int arr[], int& size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Giảm kích thước mảng sau khi xóa phần tử
}

void insertElement(int arr[], int& size, int value, int position) {
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = value;
    size++; // Tăng kích thước mảng sau khi chèn phần tử
}

void printMaxElements(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::cout << "Cac phan tu co gia tri lon nhat: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == max) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

void printMinElements(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    std::cout << "Cac phan tu co gia tri nho nhat: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == min) {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl;
}

int countPositiveElements(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int countNegativeElements(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int findMaxPositiveElement(int arr[], int size) {
    int maxPositive = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxPositive) {
            maxPositive = arr[i];
        }
    }
    return maxPositive;
}

int findMaxNegativeElement(int arr[], int size) {
    int maxNegative = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < maxNegative) {
            maxNegative = arr[i];
        }
    }
    return maxNegative;
}

bool searchElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

int countOccurrences(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(0));
    std::ofstream file("Data.txt");
    int a[10000];

    for (int i = 0; i < 10000; i++) {
        a[i] = rand();
        file << a[i] << '\n';
        std::cout << a[i];
        std::cout <<std::endl;
    }


    // b) Xoá 1 phần tử có giá trị X trong mảng
    std::cout << "Nhap gia tri can xoa: ";
    int X;
    std::cin >> X;

    int size = 10000;
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (a[i] == X) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        deleteElement(a, size, index);
        std::cout << "Da xoa phan tu co gia tri " << X << " khoi mang.\n";
    } else {
        std::cout << "Khong tim thay phan tu co gia tri " << X << " trong mang.\n";
    }

    // c) Chèn một phần tử X vào vị trí cho trước trong dãy hiện hành
    std::cout << "Nhap gia tri can chen: ";
    int Y;
    std::cin >> Y;
    std::cout << "Nhap vi tri can chen: ";
    int position;
    std::cin >> position;

    if (position >= 0 && position <= size) {
        insertElement(a, size, Y, position);
        std::cout << "Da chen phan tu " << Y << " vao vi tri " << position << " trong mang.\n";
    } else {
        std::cout << "Vi tri chen khong hop le.\n";
    }

    // d) Liệt kê những phần tử mang giá trị lớn nhất trong mảng
    printMaxElements(a, size);

    // e) Liệt kê những phần tử mang giá trị nhỏ nhất trong mảng
    printMinElements(a, size);

    // f) Đếm số phần tử có giá trị âm/dương trong mảng
    int countPositive = countPositiveElements(a, size);
    int countNegative = countNegativeElements(a, size);
    std::cout << "So phan tu co gia tri duong: " << countPositive << std::endl;
    std::cout << "So phan tu co gia tri am: " << countNegative << std::endl;

    // g) Cho biết giá trị âm/dương lớn nhất trong mảng
    int maxPositive = findMaxPositiveElement(a, size);
    int maxNegative = findMaxNegativeElement(a, size);
    std::cout << "Gia tri duong lon nhat: " << maxPositive << std::endl;
    std::cout << "Gia tri am lon nhat: " << maxNegative << std::endl;

    // h) Tìm một phần tử có khoá bằng X có hay không trong mảng
    std::cout << "Nhap gia tri can tim: ";
    int Z;
    std::cin >> Z;

    bool found = searchElement(a, size, Z);
    if (found) {
        std::cout << "Phan tu co gia tri " << Z << " ton tai trong mang.\n";
    } else {
        std::cout << "Phan tu co gia tri " << Z << " khong ton tai trong mang.\n";
    }

    // i) Đếm số phần tử có giá trị bằng X trong mảng
    int count = countOccurrences(a, size, Z);
    if (count > 0) {
        std::cout << "So phan tu co gia tri " << Z << " trong mang: " << count << std::endl;
    } else {
        std::cout << "Khong co phan tu co gia tri " << Z << " trong mang.\n";
    }

    return 0;
}

