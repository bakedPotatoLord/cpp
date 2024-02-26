// CSC1061_jhamm_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "main.h"

using namespace std;

int main()
{
    //ideas
    // 
    // blackjack game
    // terminal tetris
    // snake
    // terminal dinosaur game
    // 
    // 
    //




    vector<vector<bool>> mx{
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},

    };

    printMatrix(mx);
}

template<typename T>
void printMatrix(vector<vector<T>> mx) {
    for (auto line : mx) {
        for (auto val : line) {
            cout << val;
        }
        cout << endl;
    }
}

