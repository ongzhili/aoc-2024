#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
using namespace std;

void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    regex pattern(R"(mul\((\d+),(\d+)\))");

    while (getline(data, line)) {
        auto matches = sregex_iterator(line.begin(), line.end(), pattern);
        auto matches_end = sregex_iterator();
        for (sregex_iterator k = matches; k != matches_end; k++) {
            smatch match = *k;
            answer +=  (stoi(match.str(1)) * stoi(match.str(2)));
        }
    }
    cout << answer;
}

void part2() {
    string filename = "input.txt";
    // string filename = "test2.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    bool toAdd = true;

    regex pattern(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");

    while (getline(data, line)) {
        auto matches = sregex_iterator(line.begin(), line.end(), pattern);
        auto matches_end = sregex_iterator();
        for (sregex_iterator k = matches; k != matches_end; k++) {
            smatch match = *k;

            if(match.str() == "do()")
                toAdd = true;
            else if (match.str() == "don't()")
                toAdd = false;
            else {
                if (toAdd == true)
                    answer += (stoi(match.str(1)) * stoi(match.str(2)));
            }
        }
    }
    cout << answer;
}

int main() {
    part1();
    cout << "\n";
    part2();
}