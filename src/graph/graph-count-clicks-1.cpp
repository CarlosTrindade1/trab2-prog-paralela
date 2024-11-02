#include <graph.h>

int Graph::count_clicks(vector<vector<int>> clicks, int k) {
    int counter = 0;

    while (!clicks.empty()) {
        vector<int> click;
        vector<int> already_vertices;

        click = clicks.back();
        clicks.pop_back();

        if (click.size() == k) {
            counter++;
            continue;
        }

        int last_vertex = click.back();

        for (int j = 0; j < click.size(); j++) {
            int vertex = click[j];

            Edge *neighbor = vertices[vertex].edges;

            while (neighbor) {
                if (
                    makes_a_click(click, neighbor->id) &&
                    !is_on_click(click, neighbor->id) &&
                    neighbor->id > last_vertex &&
                    !is_on_click(already_vertices, neighbor->id)
                ) {
                    vector<int> new_click = click;
                    new_click.push_back(neighbor->id);
                    clicks.push_back(new_click);
                    already_vertices.push_back(neighbor->id);
                }
                neighbor = neighbor->next;
            }
        }
    }

    return counter;
}

int Graph::count_clicks_1(int k, string type) {
    int total_counter = 0;
    vector<vector<int>> clicks(num_vertices, vector<int>(1));

    for (int i = 0; i < num_vertices; i++) {
        clicks[i].pop_back();
        clicks[i].push_back(vertices[i].id);
    }

    if (type == "static") {
        #pragma omp parallel for schedule(static) reduction(+:total_counter)
        for (int i = 0; i < clicks.size(); i++) {
            vector<vector<int>> local_clicks;

            #pragma omp critical
            local_clicks.push_back(clicks[i]);

            int counter = count_clicks(local_clicks, k);

            total_counter += counter;
        }
    } else if (type == "dynamic") {
        #pragma omp parallel for schedule(dynamic) reduction(+:total_counter)
        for (int i = 0; i < clicks.size(); i++) {
            vector<vector<int>> local_clicks;

            #pragma omp critical
            local_clicks.push_back(clicks[i]);

            int counter = count_clicks(local_clicks, k);

            total_counter += counter;
        }
    } else if (type == "guided") {
        #pragma omp parallel for schedule(guided) reduction(+:total_counter)
        for (int i = 0; i < clicks.size(); i++) {
            vector<vector<int>> local_clicks;

            #pragma omp critical
            local_clicks.push_back(clicks[i]);

            int counter = count_clicks(local_clicks, k);

            total_counter += counter;
        }
    }

    return total_counter;
}