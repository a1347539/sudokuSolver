// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Board {
    int width;
    int sections;
    int sectionWidth;
    vector<vector<int>> data;
    
    Board(int width, int sections, vector<vector<int>> b) : 
    width(width), sections(sections), sectionWidth(width/sections), data(b) {
    }
    
    void print() {
        int offsetX = 0;
        int offsetY = 0;
        for (int i = 0; i < width+sections-1; ++i) {
            if (i == 4 || i == 9 || i == 14) {
                ++offsetY;
            } 
            offsetX = 0;
            for (int j = 0; j < width+sections-1; ++j) {
                if (j == 4 || j == 9 || j == 14) {
                    cout << "|";
                    ++offsetX;
                    continue;
                }
                if (i == 4 || i == 9 || i == 14) {
                    cout << "-----";
                    continue;
                }
                if (floor(data[i-offsetY][j-offsetX] / 10) > 0) {
                    cout << " " << data[i-offsetY][j-offsetX] << "  ";
                } else {
                    cout << "  " << data[i-offsetY][j-offsetX] << "  ";
                }
            }
            cout << endl;
        }
    }
};


bool isValid(Board& b, int& x, int& y, int& data) {
    // printf("checking: x: %d, y: %d, data: %d\n", x, y, data); 
    int xx = x;
    int yy = y;
    int ddata = data;
    for (int i = 0; i < b.width; ++i) {
        if (b.data[y][i] == data || b.data[i][x] == data) return false; 
    }
    int cxSection = floor(x/b.sectionWidth);
    int cySection = floor(y/b.sectionWidth);
    int sX = cxSection*b.sectionWidth;
    int sY = cySection*b.sectionWidth;
    for (int i = sY; i < sY+b.sectionWidth; ++i) {
        for (int j = sX; j < sX+b.sectionWidth; ++j) {
            if (b.data[i][j] == data) return false;
        }
    }
    return true;
}

bool isComplete(Board& b) {
    for (int i = 0; i < b.width; ++i) {
        for (int j = 0; j < b.width; ++j) {
            if (b.data[i][j] == -1) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(Board& b) {
    if (isComplete(b)) return true;
    
    for (int i = 0; i < b.width; ++i) {
        for (int j = 0; j < b.width; ++j) {
            if (b.data[i][j] != -1) continue;
            for (int tdata = 0; tdata < b.width; ++tdata) {
                if (isValid(b, j, i, tdata)) {
                    b.data[i][j] = tdata;
                    cout << endl;
                    if (sudoku(b)) return true;
                    b.data[i][j] = -1;
                }
            }
            return false;
        }
    }
    return false;
}

int main() {
    // Write C++ code here
    
    Board b(16, 4, { 
                    {15,13,-1,-1,-1,-1,-1,-1,14,-1,-1,-1,-1,-1,-1,-1},
                    {-1,12,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,8,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,5,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,3,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
                   });
    
/*    Board b(9, 3, { {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1, 3,-1,-1, 4,-1, 5,-1,-1},
                    {-1,-1,-1,-1,-1,-1, 6,-1,-1},
                    {-1,-1,-1,-1,-1,-1, 7,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1},
                    {-1,-1,-1,-1,-1,-1,-1,-1,-1} });*/

/*    Board b(4, 2, { {-1,-1,-1,-1 },
                    {-1,-1,-1,-1 },
                    {-1,-1,-1,-1 },
                    {-1,-1,-1,-1 } });*/
                                
    sudoku(b);
    
    b.print();
    
    std::cout << "done";

    return 0;
}
