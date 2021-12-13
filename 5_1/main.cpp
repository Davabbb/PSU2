//https://contest.yandex.ru/contest/30914/run-report/61024788/

#include <iostream>
#include <vector>
#include <string>
#include <map>

void msd_sort(std::vector<std::string>& data, int index, std::vector<int>& data_help,
              std::vector<std::string>& new_data) {
    std::map <char, std::vector<int>> count;
    for (int s : data_help) {
        if (data[s].size() > index) {
            count[data[s][index]].push_back(s);
        } else {
            new_data.push_back(data[s]);
        }
    }
    for (auto& i : count) {
        if (i.second.size() != 1) {
            msd_sort(data, index + 1, i.second, new_data);
        } else {
            new_data.push_back(data[i.second[0]]);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<int> data_help;
    std::vector<std::string> new_data;
    std::vector<std::string> data;
    for(std::string s; std::cin >> s; data.push_back(s));
    data_help.reserve(data.size());
    for (int i = 0; i < data.size(); i++) data_help.push_back(i);
    msd_sort(data, 0, data_help, new_data);
    for (auto & i : new_data) {
        std::cout << i << std::endl;
    }
    return 0;
}