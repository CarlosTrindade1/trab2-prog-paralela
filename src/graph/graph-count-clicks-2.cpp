#include <graph.h>

int Graph::count_clicks_2(int k) {
    int total_counter = 0;
    vector<vector<int>> clicks(num_vertices, vector<int>(1));

    for (int i = 0; i < num_vertices; i++) {
        clicks[i].pop_back();
        clicks[i].push_back(vertices[i].id);
    }

    for (int i = 0; i < clicks.size(); i++) {
        
    }
}