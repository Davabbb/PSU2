//https://contest.yandex.ru/contest/30914/run-report/57871078/

#include <iostream>

struct Point {
    int Coord;
    bool IsBegin;
};

void heapify(Point *data, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l].Coord > data[largest].Coord) {
        largest = l;
    }

    if (r < n && data[r].Coord > data[largest].Coord) {
        largest = r;
    }

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

void sort(Point *data, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(data, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    Point* points = new Point[n * 2];

    for (int i = 0; i < n * 2; i++) {
        Point point{};
        std::cin >> point.Coord;

        if (i % 2 == 0) {
            point.IsBegin = true;
        } else {
            point.IsBegin = false;
        }

        points[i] = point;
    }

    sort(reinterpret_cast<Point*>(points), n * 2);

    int s = 0;
    int count = 0;

    for (int i = 0; i < n * 2; i++) {
        if (points[i].IsBegin) {
            if (count == 1) {
                s += points[i].Coord - points[i - 1].Coord;
            }
            count += 1;
        } else {
            if (count == 1) {
                s += points[i].Coord - points[i - 1].Coord;
            }
            count -= 1;
        }
    }

    std::cout << s;

    return 0;
}
