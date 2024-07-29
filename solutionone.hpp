#ifndef SOLUTIONONE_HPP
#define SOLUTIONONE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>

class SolutionOne{
public:
	void dfs(std::string node, std::string& dest, std::unordered_map<std::string, std::unordered_map<std::string, double>>& gr, std::unordered_set<std::string>& vis, double& ans, double temp){
		if(vis.find(node) != vis.end()) return;
		vis.insert(node);
		if(node==dest){
			ans=temp;
			return;
		}
		for(auto ne: gr[node]){
			dfs(ne.first, dest, gr, vis, ans, temp*ne.second);
		}
	}
	std::unordered_map<std::string, std::unordered_map<std::string, double>> buildGraph(const std::vector<std::vector<std::string>>& equations, const std::vector<double>& values){
		std::unordered_map<std::string, std::unordered_map<std::string, double>> gr;
		for(int i=0; i<equations.size(); i++){
			std::string dividend=equations[i][0];
			std::string divisor=equations[i][1];
			double value=values[i];

			gr[dividend][divisor]=value;
			gr[divisor][dividend]=1.0/value;
		}
		return gr;
	}
	std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries){
		std::unordered_map<std::string, std::unordered_map<std::string, double>> gr=buildGraph(equations, values);
		std::vector<double> finalAns;
		for(auto query: queries){
			std::string dividend=query[0];
			std::string divisor=query[1];
			if(gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()){
				finalAns.push_back(-1.0);
			}else{
				std::unordered_set<std::string> vis;
				double ans = -1, temp=1.0;
				dfs(dividend, divisor, gr, vis, ans, temp);
				finalAns.push_back(ans);
			}
		}
		return finalAns;
	}
/*
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
*/
};

#endif // SOLUTIONONE_HPP