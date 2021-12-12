//https://contest.yandex.ru/contest/30914/run-report/59022659/

#include <iostream>
#include <vector>

void merge(std::vector <int>& data, int left, int mid, int right) {
    int len1 = mid - left + 1;
    int len2 = right - mid;
    std::vector <int> left_data(len1);
    std::vector <int> right_data(len2);
    for (int i = 0; i < len1; i++) left_data[i] = data[left + i];
    for (int i = 0; i < len2; i++) right_data[i] = data[mid + i + 1];
    int index1 = 0, index2 = 0;
    int index_arr = left;

    while (index1 < len1 && index2 < len2) {
        if (left_data[index1] <= right_data[index2]) {
            data[index_arr] = left_data[index1];
            index1++;
        } else {
            data[index_arr] = right_data[index2];
            index2++;
        }
        index_arr++;
    }
    while (index1 < len1) {
        data[index_arr] = left_data[index1];
        index1++;
        index_arr++;
    }
    while (index2 < len2) {
        data[index_arr] = right_data[index2];
        index2++;
        index_arr++;
    }
}

void merge_sort(std::vector <int>& data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector <int> data;

    if (n <= k * 2) {
        int elem;
        for (int i = 0; i < n; i++) {
            std::cin >> elem;
            data.push_back(elem);
        }
        merge_sort(data, 0, n - 1);
        for (int i = 0; i < n; i++) {
            std::cout << data[i] << " ";
        }
    } else {
        int elem;
        for (int i = 0; i < k; i++) {
            std::cin >> elem;
            data.push_back(elem);
        }
        int count = k;
        while (count != n) {
            for (int i = 0; i < k && count != n; i++) {
                std::cin >> elem;
                data.push_back(elem);
                count++;
            }
            merge_sort(data, 0, data.size() - 1);
            for (int i = 0; i < k; i++) {
                std::cout << data[i] << " ";
            }
            for (int i = 0; i < data.size() - k; i++) {
                data[i] = data[i + k];
            }
            data.resize(data.size() - k);
        }
        for (int i : data) {
            std::cout << i << " ";
        }
    }
     return 0;
}
