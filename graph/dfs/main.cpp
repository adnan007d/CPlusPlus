#include <iostream>
#include <unordered_map>
#include <vector>

void dfs(const std::unordered_map<int, std::vector<int>> &graph,
         std::vector<bool> &visited, int node) {

  if (visited[node]) {
    return;
  }

  visited[node] = true;
  for (const auto &_node : graph.find(node)->second) {
    dfs(graph, visited, _node);
  }
}

int main() {

  const int n = 10;

  const std::unordered_map<int, std::vector<int>> graph{{
      {0, {1, 2, 3}},
      {1, {0, 4, 5}},
      {2, {0, 6, 7}},
      {3, {0, 8, 9}},
      {4, {1}},
      {5, {1}},
      {6, {2}},
      {7, {2}},
      {8, {3}},
      {9, {3}},
  }};

  std::vector<bool> visited(n, false);
  const int start_node = 0;

  dfs(graph, visited, start_node);
  for (const auto &[node, edges] : graph) {
    std::cout << node << " is visited " << visited[node] << '\n';
  }
}
