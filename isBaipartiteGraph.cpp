void dfs(int vertex) {
    for (auto neighbor: graph[vertex])
        if (!color[neighbor]) {
            color[neighbor] = 3 — color[vertex];
            dfs(neighbor);
        } else if (color[neighbor] + color[vertex] != 3)
            isBipartite = 0;
}
