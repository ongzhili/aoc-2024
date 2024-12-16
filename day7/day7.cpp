#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

bool recursion(vector<long int> operands, long int target, long int curr, int idx) {
    if (curr == target && idx == operands.size()) {
        return true;
    }
    if (curr > target) {
        return false;
    }
    if (idx >= operands.size()) {
        return false;
    }
    return recursion(operands, target, curr + operands[idx], idx + 1) || 
            recursion(operands, target, curr * operands[idx], idx + 1);
}

long int concatenate(long int a, long int b) {
    int tens = log10(b);
    return (10 * a * pow(10, tens)) + b;
}

bool recursion2(vector<long int> operands, long int target, long int curr, int idx) {
    if (curr == target && idx == operands.size()) {
        return true;
    }
    if (curr > target) {
        return false;
    }
    if (idx >= operands.size()) {
        return false;
    }
    return recursion2(operands, target, curr + operands[idx], idx + 1) || 
            recursion2(operands, target, curr * operands[idx], idx + 1) ||
            recursion2(operands, target, concatenate(curr, operands[idx]), idx + 1);
}

void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    long int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    while (getline(data, line)) {
        long int desired = stol(line.substr(0, line.find(": ")));
        string leftover = line.substr(line.find(": ") + 2, line.length() - 1);
        
        vector<long int> operands;
        stringstream ss(leftover);
        string t;

        while (getline(ss, t, ' ')) {
            operands.push_back(stol(t));
        }

        if (recursion(operands, desired, operands[0], 1) == true) {
            answer += desired;
        }
    }
    cout << answer;
}

void part2() {
    string filename = "input.txt";
    // string filename = "test.txt";
    long int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    while (getline(data, line)) {
        long int desired = stol(line.substr(0, line.find(": ")));
        string leftover = line.substr(line.find(": ") + 2, line.length() - 1);
        
        vector<long int> operands;
        stringstream ss(leftover);
        string t;

        while (getline(ss, t, ' ')) {
            operands.push_back(stol(t));
        }

        if (recursion2(operands, desired, operands[0], 1) == true) {
            answer += desired;
        }
    }
    cout << answer;
}

int main() {
    part1();
    cout << "\n";
    part2();
}