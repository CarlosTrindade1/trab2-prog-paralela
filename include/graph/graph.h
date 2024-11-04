#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <vector>
#include <omp.h>
#include <math.h>

using namespace std;

class Graph {
    public:
        Graph(char *file_name);
        ~Graph();
        void print();
        int count_clicks_1(int k, string type, int chunk);
        int count_clicks_2(int k, int r);

    private:
        struct Edge {
            int id;
            Edge *next;
        };

        struct Vertex {
            int id;
            Edge *edges;
        };

        struct Thread_Data {
            int thread_id;
            vector<vector<int>> clicks;
        };

        Vertex *vertices;
        int num_vertices;

        void read_graph(char *file_name, map<int, int> new_ids);
        map<int, int> rename_vertices(char *file_name);
        bool is_on_click(vector<int> click, int vertex);
        bool makes_a_click(vector<int> click, int vertex);
        bool is_neighbor(int vertex_1, int vertex_2);
        int count_clicks(vector<vector<int>> clicks, int k);
        int count_clicks_balanced(vector<vector<int>> *clicks, vector<vector<vector<int>>> *global_clicks, int k, int r);
};