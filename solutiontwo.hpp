#ifndef SOLUTIONTWO_HPP
#define SOLUTIONTWO_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>

class SolutionTwo {
public:
    int nearestExit(std::vector<std::vector<char>>& maze, std::vector<int>& entrance){
        int min_path=INT_MAX;
        std::deque<std::vector<int>> go_to_lab;
        go_to_lab.push_back({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+'; //i=entrance[0] and j=entrance[1]
        int size=maze.size()-1; //tamaño de las filas menos 1
        int size1=maze[0].size()-1; //tamaño de las columnas menos 1
        while(!go_to_lab.empty()){
            auto el=go_to_lab.front();
            if(el[0] == 0 || el[0] == size || el[1] == 0 || el[1] == size1){
                if(el[0] != entrance[0] || el[1] != entrance[1]){
                    return std::min(min_path, el[2]);
                }
            }
            if(el[0] + 1 <= size && maze[el[0] + 1][el[1]]=='.'){
                maze[el[0]+1][el[1]]='+';
                go_to_lab.push_back({el[0] + 1, el[1], el[2] + 1});
            }
            if(el[0]-1>=0 && maze[el[0]-1][el[1]]=='.'){
                maze[el[0]-1][el[1]]='+';
                go_to_lab.push_back({el[0]-1, el[1], el[2]+1});
            }
            if(el[1]+1<=size1 && maze[el[0]][el[1]+1]=='.'){
                maze[el[0]][el[1]+1]='+';
                go_to_lab.push_back({el[0], el[1]+1, el[2]+1});
            }
            if(el[1]-1 >= 0 && maze[el[0]][el[1]-1]=='.'){
                maze[el[0]][el[1]-1]='+';
                go_to_lab.push_back({el[0], el[1]-1, el[2]+1});
            }
            go_to_lab.pop_front();
        }
        return min_path=INT_MAX ? -1 : min_path;
    }
 /*
Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
Output: 1
 */
};

#endif // SOLUTIONTWO_HPP