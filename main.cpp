#include <algorithm>
#include "solution.hpp"
#include "solutionone.hpp"
#include "solutiontwo.hpp"
#include "solutionfour.hpp"

int main(){
    
    Solution solution;
    int n=6;
    std::vector<std::vector<int>> idk={{0,1},{1,3},{2,3},{4,0},{4,5}};
    int mainy=solution.minReorder(n,idk);
    std::cout<<"ANSWER MAIN= ";
    std::cout<<mainy<<std::endl;

    SolutionOne solution1;
    std::vector<std::vector<std::string>> equations={{"a","b"},{"b","c"}};
    std::vector<double> values={2.0,3.0};
    std::vector<std::vector<std::string>> queries={{"a","b"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    std::vector<double> output=solution1.calcEquation(equations,values,queries);
    for(int i=0; i<output.size(); i++){
        std::cout<<"ANSWER ONE= ";
        std::cout<<output[i]<<std::endl;
    }

    SolutionTwo solution2;
    std::vector<std::vector<char>> maze={{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    std::vector<int> entrance={1,2};
    int out=solution2.nearestExit(maze,entrance);
    std::cout<<"ANSWER TWO= ";
    std::cout<<out<<std::endl;

    SolutionFour solution4;
    std::vector<std::vector<int>> fouU={{2,1,1},{1,1,0},{0,1,1}};
    int outt=solution4.orangesRotting(fouU);
    std::cout<<"ANSWER THREE= ";
    std::cout<<outt<<std::endl;

	return 0;
}
