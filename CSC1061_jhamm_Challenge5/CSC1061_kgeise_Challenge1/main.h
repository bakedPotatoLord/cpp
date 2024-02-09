#pragma once

#include <vector>
#include <stack>

struct point{
    int i;
    int j;
};

int main();
int numIslands(std::vector<std::vector<bool>> );
template<typename T>
void printMatrix(const std::vector<std::vector<T>> mx);
