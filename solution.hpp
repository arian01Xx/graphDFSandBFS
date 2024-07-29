#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>

class Solution{
public:
	int dfs(std::vector<std::vector<int>>& val, std::vector<bool>& visited, int from){
		auto change=0;
		visited[from]=true;
		for(auto to: val[from]){
			if(!visited[std::abs(to)]){
				change += dfs(val, visited, std::abs(to)) + (to > 0);
			}
		}
		return change;
	}
	int minReorder(int n, std::vector<std::vector<int>>& connections){
		std::vector<std::vector<int>> al(n);
		for(auto &c: connections){
			al[c[0]].push_back(c[1]);
			al[c[1]].push_back(-c[0]);
		}
		return dfs(al, std::vector<bool>(n) = {}, 0);
	}
};

#endif // SOLUTION_HPP