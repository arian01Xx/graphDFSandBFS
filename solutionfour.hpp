#ifndef SOLUTIONFOUR_HPP
#define SOLUTIONFOUR_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>

class SolutionFour {
public:
    int time = 0;
    std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(std::queue<std::pair<std::pair<int, int>, int>>& q, std::vector<std::vector<int>>& visited,
             std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = std::max(t, time);
            q.pop();

            visited[row][col] = 2;

            for (auto dir : directions) {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1 &&
                    visited[nrow][ncol] != 2) {
                    visited[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    grid[nrow][ncol] = 2;
                }
            }
        }
    }

    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
        std::queue<std::pair<std::pair<int, int>, int>> q;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 2) {
                    q.push({{row, col}, 0});
                }
            }
        }

        bfs(q, visited, grid);

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (grid[row][col] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
/*
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
*/
};

#endif // SOLUTIONFOUR_HPP