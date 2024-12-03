#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

bool safe(vector<int> currentFloor) {
    bool increasing;
    for (int i = 1; i < currentFloor.size(); i++) {

        // Looks at the difference between i and i-1. If it is not within [1,3], return false immediately
        int diff = currentFloor[i] - currentFloor[i-1];
        if (!(abs(diff) > 0 && abs(diff) <= 3)) {
            return false;
        }

        // Checks if the array should be gradually inc or dec
        if (i == 1) {
            increasing = diff > 0 ? true : false;
        }

        // Checks if the array is gradually increasing or decreasing (magnitude doesnt matter here)
        if (increasing) {
            if (diff < 0)
                return false;
        } else {
            if (diff > 0)
                return false;
        }
    }
    return true;
}

bool safe2(vector<int> currentFloor) {
    if (safe(currentFloor)) {
        return true;
    }
    else {
        for (int i = 0; i < currentFloor.size(); i++) {
            vector<int> temp(currentFloor);
            temp.erase(temp.begin() + i);
            if (safe(temp)) {
                return true;
            }
        }
        return false;
    }
    return false;
}

void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    while (getline(data, line)) {
        stringstream ln(line);
        int number;
        vector<int> currentFloor;
        while ( ln >> number )
            currentFloor.push_back( number );
        if (safe(currentFloor))
            answer += 1;
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

    while (getline(data, line)) {
        stringstream ln(line);
        int number;
        vector<int> currentFloor;
        while ( ln >> number )
            currentFloor.push_back( number );
        if (safe2(currentFloor))
            answer += 1;
    } 

    cout << answer;
}

int main() {
    part1();
    cout << "\n";
    part2();
}