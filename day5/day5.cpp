#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;
    char delimiter = '|';
    
    // Key = number, Value = Elements that must be after it
    map<int, set<int>> rules;

    // Rules
    while (getline(data, line)) {
        if (line == "") {
            break;
        }
        istringstream stream(line);
        string token;
        vector<int> rule;
        while (getline(stream, token, delimiter)) {
            rule.push_back(stoi(token));
        }
        rules[rule[0]].insert(rule[1]);
    }
    // To print out the dict
    // for (const auto &[k, v]: rules) {
    //     cout << endl << k << ": ";
    //     for (const auto r : v) {
    //         cout << r << ", ";
    //     }
    // }

    // Updates
    while (getline(data, line)) {
        // cout << line << endl;
        istringstream stream(line);
        string token;
        vector<int> rule;
        while (getline(stream, token, ',')) {
            // cout << stoi(token);
            rule.push_back(stoi(token));
        }

        set<int> seen = {};
        bool valid = true;
        for (auto r : rule) {
            for (auto s : seen) {
                if (rules[r].find(s) != rules[r].end()) {
                    valid = false;
                    break;
                }
            }
            seen.insert(r);
        }
        if (valid == true) {
            auto mid = rule[rule.size() / 2];
            // for (auto r: rule) {
            //     cout << r << ",";
            // }
            // cout << mid << endl;
            answer += mid;
        }
    }

    cout << answer;

}

void part2() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;
    char delimiter = '|';
    
    // Key = number, Value = Elements that must be after it
    map<int, set<int>> rules;

    // Rules
    while (getline(data, line)) {
        if (line == "") {
            break;
        }
        istringstream stream(line);
        string token;
        vector<int> rule;
        while (getline(stream, token, delimiter)) {
            rule.push_back(stoi(token));
        }
        rules[rule[0]].insert(rule[1]);
    }
    // To print out the dict
    // for (const auto &[k, v]: rules) {
    //     cout << endl << k << ": ";
    //     for (const auto r : v) {
    //         cout << r << ", ";
    //     }
    // }

    // Updates
    while (getline(data, line)) {
        // cout << line << endl;
        istringstream stream(line);
        string token;
        vector<int> nums;
        while (getline(stream, token, ',')) {
            // cout << stoi(token);
            nums.push_back(stoi(token));
        }

        bool change = true;
        bool found = false;

        while (change == true) {
            int i = 0;
            bool swapped = false;
            set<int> seen;
            while (i < nums.size()) {
                for (auto s: seen) {
                    if (rules[nums[i]].find(s) != rules[nums[i]].end()) {
                        // cout << "FOUND!" << endl;
                        found = true;
                        swapped = true;
                        int temp = nums[i];
                        auto idx = find(nums.begin(), nums.end(), s);
                        // cout << *idx << endl;
                        nums[i] = *idx;
                        *idx = temp;
                        swapped = true;
                        break;
                    }
                }
                seen.insert(nums[i]);
                i++;
            }
            if (swapped == false) {
                change = false;
            }
        }

        if (found == true) {
            auto mid = nums[nums.size() / 2];
            // for (auto r: nums) {
            //     cout << r << ",";
            // }
            // cout << mid << endl;
            answer += mid;
        }

    }

    cout << answer;

}

int main() {
    part1();
    cout << "\n";
    part2();
}