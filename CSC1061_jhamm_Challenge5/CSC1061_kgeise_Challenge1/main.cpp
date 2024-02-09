#include <iostream>
#include <vector>
#include <stack>
#include "main.h"

using namespace std;



int main()
{

    vector<vector<bool>> vec{
        {0,0,1,1,0,1,0},
        {1,0,1,0,0,1,0},
        {1,0,0,0,0,0,0},
        {0,0,1,0,1,0,1}
    };
    //calculate number of islands
    cout << numIslands(vec);

    return 0;
};

int numIslands(vector<vector<bool>> mx){

    
    
    cout << "matrix:" <<endl;
    printMatrix(mx);

    cout << "visited: " << endl;
    printMatrix(visited);

    int numIslands = 0;

    while(!possibleStack.empty()){
        auto top = possibleStack.top();
        possibleStack.pop();
        int i = top->i;
        int j = top->j;



        if(visited[i][j]){
            //don't do anything
        }else{
            visited[i][j] = 1;


            if(mx[i][j]){
                //if there is an island
                

                auto touching = getTouching(point(i,j))

                while()

            }
        }
    }

    cout << "visited: " << endl;
    printMatrix(visited);
    

    return 0;
};




vector<point*> getTouching(const point p,int height,int width){
    vector<point*> points;
    if(p.i >0) points.push_back(new point{p.i-1,p.j});
    if(p.i < height-1) points.push_back(new point{p.i+1,p.j});

    (p.j >0) points.push_back(new point{p.i,p.j-1});
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

