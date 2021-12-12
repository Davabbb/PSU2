//https://contest.yandex.ru/contest/30914/run-report/59097692/

#include <iostream>
#include <vector>
#include <string>
#include <map>

void msd_sort(std::vector<std::string>* data, int index, std::vector<int>* data_help) {
    std::map <char, std::vector<int>> count;
    for (int s : *data_help) {
        if ((*data)[s].size() > index) {
            count[(*data)[s][index]].push_back(s);
        } else {
            std::cout << (*data)[s] << std::endl;
        }
    }
    for (auto& i : count) {
        msd_sort(data, index + 1, &i.second);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::string> data;
    for(std::string s; std::cin >> s; data.push_back(s));
    std::vector<int> data_help;
    data_help.reserve(data.size());
    for (int i = 0; i < data.size(); i++) data_help.push_back(i);
    msd_sort(&data, 0, &data_help);
    return 0;
}
