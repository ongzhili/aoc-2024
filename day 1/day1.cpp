#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <cmath>
#include <unordered_map>
using namespace std;

bool comp(int a, int b) {
    return a >= b;
}


// Part 1
void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    
    ifstream data;
    data.open(filename);

    vector<int> l1;
    vector<int> l2;

    string line;

    int answer = 0;
    
    while (getline(data, line)) {
        int n1;
        int n2;
        istringstream currentLine(line);
        currentLine >> n1;
        currentLine >> n2;
        l1.push_back(n1);
        l2.push_back(n2);
    }

    sort(l1.begin(), l1.end(), comp);
    sort(l2.begin(), l2.end(), comp);
    for (int i = 0; i < l1.size(); i++) {
        answer += abs(l1[i] - l2[i]);
    }


    cout << answer;
    return;
}

// Part 2
void part2() {
    int answer = 0;
    string filename = "input.txt";
    // string filename = "test.txt";
    
    ifstream data;
    string line;
    data.open(filename);

    unordered_map<int, int> counts;

    vector<int> l1;

    while (getline(data, line)) {
        int n1;
        int n2;
        istringstream currentLine(line);
        currentLine >> n1;
        currentLine >> n2;

        l1.push_back(n1);
        if (counts.find(n2) == counts.end())
            counts[n2] = 1;
        else
            counts[n2] += 1;
    }

    for (int n1: l1) {
        if (counts.find(n1) != counts.end())
            answer += n1 * counts[n1];
    }

    cout << answer;
    return;
}

int main() {
    part1();
    cout << "\n";
    part2();
}