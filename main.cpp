#include <graph.h>

using namespace std;

int main(int argc, char* argv[]) {
    if (!argv[1]) {
        printf("filename was not provided\n");
        return 1;
    }

    if (!argv[2]) {
        printf("size of click was not provided\n");
        return 1;
    }

    if (!argv[3]) {
        printf("number of algorithm was not provided\n");
        return 1;
    }

    char* file_name_graph = argv[1];
    int size_of_click = atoi(argv[2]);
    int algorithm = atoi(argv[3]);

    Graph *graph = new Graph(file_name_graph);

    return 0;
}