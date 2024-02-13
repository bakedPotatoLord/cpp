#pragma once

#include <vector>

struct point{
    int i;
    int j;
};

int main();
int numIslands(std::vector<std::vector<bool>> );
void testAlgorithm();
std::vector<point*> getTouching(const point p, const int height, const int length);
template<typename T>
void printMatrix(const std::vector<std::vector<T>> mx);
