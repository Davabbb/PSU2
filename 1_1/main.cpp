//https://contest.yandex.ru/contest/30914/run-report/57576366/

#include <iostream>

bool operator_ (int *data1, int *data2) {
    if (data1[0] < data2[0] && data1[1] < data2[1] && data1[2] < data2[2]) {
        return false;
    } else if (data1[0] < data2[0] && data1[1] < data2[2] && data1[2] < data2[1]) {
        return false;
    } else if (data1[0] < data2[1] && data1[1] < data2[0] && data1[2] < data2[2]) {
        return false;
    } else if (data1[0] < data2[1] && data1[1] < data2[2] && data1[2] < data2[1]) {
        return false;
    } else if (data1[0] < data2[2] && data1[1] < data2[1] && data1[2] < data2[0]) {
        return false;
    } else if (data1[0] < data2[2] && data1[1] < data2[0] && data1[2] < data2[1]) {
        return false;
    } else {
        return true;
    }
}

void sort(int **data, int n) {
    int *temp;
    int item;
    for (int i = 1; i < n; i++) {
        temp = data[i];
        item = i - 1;
        while (item >= 0 && operator_(data[item], temp)) {
            data[item + 1] = data[item];
            data[item] = temp;
            item--;
        }
    }
}

int main() {
    int n = 0;

    std::cin >> n;
    int **data = new int* [n];
    for (int i = 0; i < n; i++) {
        data[i] = new int [4];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> data[i][j];
        }
        data[i][3] = i;
    }

    sort(data, n);

    for (int i = 0; i < n; i++) {
        std::cout << data[i][3] << " ";
    }

    for (int i = 0; i < n; i++) {
        delete [] data[i];
    }
    delete [] data;

    return 0;
}
