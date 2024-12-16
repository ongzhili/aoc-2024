#include <fstream>
#include <vector>
#include <iostream>
#include <array>
#include <tuple>
#include <set>

using namespace std;

array<int, 2> turn(int r, int c) {
    array<int, 2> newdir;
    // -1 0, 0 1, 1 0, 0 -1
    if (r == -1 && c == 0) {
        newdir[0] = 0;
        newdir[1] = 1;
        return newdir;
    }

    if (r == 0 && c == 1) {
        newdir[0] = 1;
        newdir[1] = 0;
        return newdir;
    }

    if (r == 1 && c == 0) {
        newdir[0] = 0;
        newdir[1] = -1;
        return newdir;
    }

    if (r == 0 && c == -1) {
        newdir[0] = -1;
        newdir[1] = 0;
        return newdir;
    }
}

void part1() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    vector<vector<char>> grid;
    int row = 0;
    int col = 0;

    int startRow;
    int startCol;

    int dirRow = -1;
    int dirCol = 0;

    while (getline(data, line)) {
        col = 0;
        vector<char> curr;
        for (char c: line) {
            curr.push_back(c);
            if (c == '^') {
                startRow = row;
                startCol = col;
            }
            col++;
        }
        grid.push_back(curr);
        row++;
    }

    int r = grid.size();
    int c = grid[0].size();

    // for (const vector<char> v : grid) {
    //     for (const char c: v) {
    //         cout << c << " ";
    //     }
    //     cout << endl;
    // }

    while (true) {
        if (grid[startRow][startCol] != 'X') {
            answer += 1;
            grid[startRow][startCol] = 'X';
        }

        // Left the mapped zone
        if (startRow + dirRow < 0 || startRow + dirRow >= r || startCol + dirCol < 0 || startCol + dirCol >= c) {
            cout << answer;
            return;
        }

        // Run into wall (#)
        if (grid[startRow + dirRow][startCol + dirCol] == '#') {
            array<int, 2> newDirs;
            newDirs = turn(dirRow, dirCol);
            dirRow = newDirs[0];
            dirCol = newDirs[1];
        }

        if (startRow + dirRow < 0 || startRow + dirRow >= r || startCol + dirCol < 0 || startCol + dirCol >= c) {
            cout << answer;
            return;
        }
        startRow += dirRow;
        startCol += dirCol;
    }

    
}

bool check(vector<vector<char>> grid, int startRow, int startCol, int dirRow, int dirCol) {
    int r = grid.size();
    int c = grid[0].size();

    set<tuple<int, int, int ,int>> seen;

    while (true) {
        tuple<int, int, int ,int> curr = make_tuple(startRow, startCol, dirRow, dirCol);
        if (seen.find(curr) != seen.end()) {
            return true;
        } else {
            seen.insert(curr);
        }

        // Left the mapped zone
        if (startRow + dirRow < 0 || startRow + dirRow >= r || startCol + dirCol < 0 || startCol + dirCol >= c) {
            return false;
        }

        // Run into wall (#)
        if (grid[startRow + dirRow][startCol + dirCol] == '#') {
            array<int, 2> newDirs;
            newDirs = turn(dirRow, dirCol);
            dirRow = newDirs[0];
            dirCol = newDirs[1];
        } else {
            startRow += dirRow;
            startCol += dirCol;
        }

    }
}

void part2() {
    string filename = "input.txt";
    // string filename = "test.txt";
    int answer = 0;

    ifstream data;
    data.open(filename);
    string line;

    vector<vector<char>> grid;
    int row = 0;
    int col = 0;

    int startRow;
    int startCol;

    int dirRow = -1;
    int dirCol = 0;

    while (getline(data, line)) {
        col = 0;
        vector<char> curr;
        for (char c: line) {
            curr.push_back(c);
            if (c == '^') {
                startRow = row;
                startCol = col;
            }
            col++;
        }
        grid.push_back(curr);
        row++;
    }

    int r = grid.size();
    int c = grid[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] != '^' && grid[i][j] != '#') {
                grid[i][j] = '#';
                cout << "Checking (" << i << "," << j << ")" << endl;
                if (check(grid, startRow, startCol, dirRow, dirCol)) {
                    answer += 1;
                }
                grid[i][j] = '.';
            }
        }
    }

    cout << answer << endl;
}

int main() {
    part1();
    cout << "\n";
    part2();
}