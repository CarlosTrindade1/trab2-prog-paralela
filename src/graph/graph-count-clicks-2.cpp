#include <graph.h>

int Graph::count_clicks_balanced(vector<vector<int>> *clicks, vector<vector<vector<int>>> *global_clicks, int k, int r) {
    int counter = 0;

    while (clicks->size()) {
        vector<int> click;
        vector<int> already_vertices;

        #pragma omp critical
        {
            click = clicks->back();
            clicks->pop_back();
        }

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

                    #pragma omp critical
                    clicks->push_back(new_click);

                    already_vertices.push_back(neighbor->id);
                }
                neighbor = neighbor->next;
            }
        }

        if (!clicks->size()) {
            int max = 0;
            int thread_id;

            #pragma omp critical
            {
                for (int i = 0; i < omp_get_max_threads(); i++) {
                    if (global_clicks[i].size() > max) {
                        max = global_clicks[i].size();
                        thread_id = i;
                    }
                }

                if (max > 0) {
                    int length = r > max ? max - 1 : r;

                    for (int i = 0; i < length; i++) {
                        clicks->push_back(global_clicks[thread_id][i].back());
                        global_clicks[thread_id][i].pop_back();
                    }
                }
            }
        }
    }

    return counter;
}

int Graph::count_clicks_2(int k, int r) {
    int total_counter = 0;

    vector<vector<int>> clicks(num_vertices, vector<int>(1));

    for (int i = 0; i < num_vertices; i++) {
        clicks[i].pop_back();
        clicks[i].push_back(vertices[i].id);
    }

    vector<vector<vector<int>>> global_clicks;

    for (int i = 0; i < omp_get_max_threads(); i++) {
        global_clicks.push_back(vector<vector<int>>());
    }

    #pragma omp parallel for schedule(static) reduction(+:total_counter)
    for (int i = 0; i < clicks.size(); i++) {
        int thread_id = omp_get_thread_num();

        #pragma omp critical
        global_clicks[thread_id].push_back(clicks[i]);

        int counter = count_clicks_balanced(&global_clicks[thread_id], &global_clicks, k, r);

        total_counter += counter;
    }

    return total_counter;
}