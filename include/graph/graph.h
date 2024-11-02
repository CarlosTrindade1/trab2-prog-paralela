#include <iostream>
#include <fstream>
#include <map>
#include <cstring>
#include <pthread.h>

using namespace std;

class Graph {
    public:
        Graph(char *file_name);
        ~Graph();

    private:
        pthread_mutex_t mtx;

        struct Edge {
            int id;
            Edge *next;
        };

        struct Vertex {
            int id;
            Edge *edges;
        };

        Vertex *vertices;
        int num_vertices;

        void read_graph(char *file_name, map<int, int> new_ids);
        map<int, int> rename_vertices(char *file_name);
        void print();
};