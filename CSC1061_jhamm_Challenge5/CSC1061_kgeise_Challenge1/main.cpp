
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "main.h"

using namespace std;

int main()
{
    testAlgorithm();
    return 0;
};

// Function to count the number of islands time complexity is O(n*m) where n and m are height and length;
int numIslands(vector<vector<bool>> mx)
{
    int islands = 0;
    // Find height and length of the matrix
    const int height = mx.size();
    const int length = mx[0].size();

    // Iterate through each point in the matrix
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < length; j++)
        {
            // If the current point is part of an island
            if (mx[i][j])
            {
                islands++; // Increment the island count

                stack<point *> island;        // Create stack for visiting the island
                island.push(new point{i, j}); // Push the first point for starting

                // Traverse the island
                while (!island.empty())
                {
                    point p = *island.top(); // Dereference and pop the top of the stack
                    island.pop();

                    if (mx[p.i][p.j])
                    {                     // If the current point is part of the island
                        mx[p.i][p.j] = 0; // Mark it as visited
                        // Add adjacent points to the stack
                        for (auto v : getTouching(p, height, length))
                        {
                            island.push(v);
                        }
                    }
                }
            }
        }
    }
    return islands;
};

//function to test my island counting algorithm
void testAlgorithm(){
    // Define test cases
    vector<vector<vector<bool>>> tests{
        {{0, 0, 1, 1, 0, 1, 0},
         {1, 0, 1, 0, 0, 1, 0},
         {1, 0, 0, 0, 0, 0, 0},
         {0, 0, 1, 0, 1, 0, 1}},
        {{1, 1},
         {1, 1}},
        {{1, 0},
         {0, 1}},
        {{1, 0, 0, 0, 1},
         {0, 0, 0, 0, 0},
         {0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0},
         {1, 0, 0, 0, 1}},
        {{0}},
        {{1}},
        {{0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1}}};

    // Define expected answers
    vector<int> answers = {6, 1, 2, 5, 0, 1, 4};

    // Ensure the size of tests and answers match
    assert(tests.size() == answers.size());

    // Iterate over test cases
    for (int i = 0; i < tests.size(); i++)
    {
        // Print the matrix for the current test case
        printMatrix(tests[i]);
        // Get the number of islands using the algorithm
        auto answer = numIslands(tests[i]);
        // Print the algorithm's answer
        cout << "algorithm answer: " << answer << endl;
        // Check if the answer matches the expected answer
        cout << "answer " << ((answers[i] == answer) ? "correct" : "incorrect") << endl
             << endl;
        // Assert the correctness of the answer
        assert(answers[i] == answer);
    }
}

// Function to get adjacent points
vector<point *> getTouching(const point p, int height, int width)
{
    //create point vector
    vector<point *> points;
    // Add adjacent points to the vector
    if (p.i > 0) 
        points.push_back(new point{p.i - 1, p.j});
    if (p.i < height - 1)
        points.push_back(new point{p.i + 1, p.j});
    if (p.j > 0)
        points.push_back(new point{p.i, p.j - 1});
    if (p.j < width - 1)
        points.push_back(new point{p.i, p.j + 1});
    return points;
}

// Template function to print the matrix
template <typename T>
void printMatrix(vector<vector<T>> mx)
{
    for (const vector<bool> &vec : mx) 
    { //for each row
        for (const bool &b : vec)
        { //for each value
            cout << b << ' '; //print the value
        }
        cout << endl; 
    }
    cout << endl;
}
