//https://contest.yandex.ru/contest/30914/run-report/58306528/

#include <iostream>
#include <random>
#include <vector>

int Partition(std::vector<int>& data, int l, int r) {
    std::random_device a;
    std::mt19937 generator(a());
    std::uniform_int_distribution<int> uniform_dist(l, r - 1);
    int pivot = uniform_dist(generator);
    std::swap(data[pivot], data[r - 1]);

    int i = l, j = l;
    bool f = false;

    while (j != r - 1) {
        if (not f) {
            if (data[r - 1] > data[j]) {
                j++;
                i++;
            } else {
                f = true;
                j++;
            }
        } else {
            if (data[r - 1] > data[j]) {
                std::swap(data[i], data[j]);
                i++;
                j++;
            } else {
                j++;
            }
        }
    }

    std::swap(data[i], data[r - 1]);
    return i;
}

double KStat(std::vector<int>& data, int n, int find) {
    int l = 0, r = n;

    while (true) {
        int pivot_pos = Partition(data, l, r);
        if (pivot_pos == find) {

//            for (int i = 0; i < n; i++) {
//                std::cout << data[i] << " ";
//            }
//            std::cout << data[find] << " ";

            return data[find];
        }
        if (pivot_pos < find) {
            l = pivot_pos + 1;
        } else {
            r = pivot_pos;
        }
    }
}

int main() {
    int n, find;
    std::cin >> n >> find;

    std::vector<int> data;
    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        data.push_back(elem);
    }

    std::cout << KStat(data, n, find);
    return 0;
}
