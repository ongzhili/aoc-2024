#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>
using namespace std;


void part1() {

    string xmas = "XMAS";
    vector<vector<int>> directions = {
        {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}, {-1, -1}
    };
    int r;
    int c;

    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;
    
    vector<vector<char>> matrix;

    ifstream data;
    data.open(filename);
    string line;

    function <bool(int, int, int, int, int)> backtrack = [&](int curr, int i, int j, int di, int dj) {
        if (curr == xmas.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= r || j >= c || matrix[i][j] != xmas[curr]) {
            return false;
        }


        char temp = matrix[i][j];
        matrix[i][j] = ' ';
        bool ans = backtrack(curr + 1, i + di, j + dj, di, dj);
        matrix[i][j] = temp;
        return ans;
    };

    while (getline(data, line)) {
        vector<char> currLine;
        for (auto ch : line) {
            currLine.push_back(ch);
        }
        matrix.push_back(currLine);
    }
    
    r = matrix.size();
    c = matrix[0].size();

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for(const vector<int>& d : directions) {
                if (backtrack(0, i, j, d[0], d[1])) {
                    answer += 1;
                }
            }
        }
    }

    cout << answer;

}

void part2() {

    string xmas = "XMAS";
    int r;
    int c;

    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;
    
    vector<vector<char>> matrix;

    ifstream data;
    data.open(filename);
    string line;

    function <bool(int, int)> xmasfinder = [&](int i, int j) {
        return (
            ((matrix[i + 1][j + 1] == 'M' && matrix[i - 1][j - 1] == 'S') || (matrix[i + 1][j + 1] == 'S' && matrix[i - 1][j - 1] == 'M'))
            && ((matrix[i - 1][j + 1] == 'M' && matrix[i + 1][j - 1] == 'S') || (matrix[i - 1][j + 1] == 'S' && matrix[i + 1][j - 1] == 'M'))
        );
    };

    while (getline(data, line)) {
        vector<char> currLine;
        for (auto ch : line) {
            currLine.push_back(ch);
        }
        matrix.push_back(currLine);
    }
    
    r = matrix.size();
    c = matrix[0].size();

    for (int i = 1; i < r - 1; ++i) {
        for (int j = 1; j < c - 1; ++j) {
            if (matrix[i][j] == 'A') {
                if (xmasfinder(i,j)) {
                    answer += 1;
                }
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