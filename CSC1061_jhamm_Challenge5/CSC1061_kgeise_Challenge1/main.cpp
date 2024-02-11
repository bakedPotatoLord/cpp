#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include "main.h"

using namespace std;

int main()
{

    vector<vector<vector<bool>>> tests{
        {
            {0,0,1,1,0,1,0},
            {1,0,1,0,0,1,0},
            {1,0,0,0,0,0,0},
            {0,0,1,0,1,0,1}    
        },
        {
            {1,1},
            {1,1}
        },
        {
            {1,0},
            {0,1}
        },
        {
            {1,0,0,0,1},
            {0,0,0,0,0},
            {0,0,1,0,0},
            {0,0,0,0,0},
            {1,0,0,0,1}
        },
        {
            {0}
        },
        {
            {1}
        },
        {
            {0,1,1,1,0,1,0,1,0,0,1,1}
        }
    };

    vector<int> answers = { 6,1,2,5,0,1,4};

    assert(tests.size() == answers.size()); // make sure tests are set up correctly

   for(int i  = 0 ; i<tests.size();i++){
    printMatrix(tests[i]);
    auto answer = numIslands(tests[i]);
    cout << "algorithm answer: " << answer << endl;
    cout << "answer "  << ((answers[i] == answer)? "correct👍": "incorrect👎") << endl <<endl;
    assert(answers[i] == answer);
   }

    return 0;
};

int numIslands(vector<vector<bool>> mx){
    int islands = 0;
    //find height and length
    const int height = mx.size();
    const int length = mx[0].size();
    
    for(int i =0; i< height;i++){
        for(int j = 0 ; j<length;j++){ //iterating over all possible points of the matrix
            if(mx[i][j]){ // if looking at island for first time
                islands++;
            
                stack<point*> island ; //create stack for visiting the island
                
                island.push(new point{i,j}); // push first point for starting

                while(!island.empty()){ //for all ajacent island points
                    point p = *island.top(); //derefrence and pop the top of the stack
                    island.pop();

                    if(mx[p.i][p.j]){ //if looking at island
                        mx[p.i][p.j] = 0; //set it to 0
                        for (auto v : getTouching(p,height,length)){
                            island.push(v); // push touching elements
                        }
                    }
                }
            }
        }
    }
    return islands;
};




vector<point*> getTouching(const point p,int height,int width){
    vector<point*> points;
    if(p.i >0) points.push_back(new point{p.i-1,p.j});
    if(p.i < height-1) points.push_back(new point{p.i+1,p.j});

    if(p.j >0) points.push_back(new point{p.i,p.j-1});
    if(p.j < width-1) points.push_back(new point{p.i,p.j+1});

    return points;
}

template<typename T>
void printMatrix(vector<vector<T>> mx){
    for(const vector<bool>& vec :mx){
       
        for(const bool& b : vec){
            cout << b << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

