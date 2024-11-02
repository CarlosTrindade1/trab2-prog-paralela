#include <graph.h>
#include <chrono>

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
    string type;

    Graph *graph = new Graph(file_name_graph);

    chrono::high_resolution_clock::time_point start, end;

    switch (algorithm) {
        case 1:
            if (!argv[4]) {
                printf("Tipo de paralelismo não foi informado\n");
                return 1;
            }

            type = argv[4];

            start = chrono::high_resolution_clock::now();
            cout << graph->count_clicks_1(size_of_click, type) << endl;
            end = chrono::high_resolution_clock::now();
            break;

        case 2:
            printf("Algoritmo 2\n");

            break;

        default:
            printf("Algoritmo não encontrado\n");
            return 1;
    }

    printf("Execution time of the %d algorithm: ", algorithm);
    cout << chrono::duration_cast<chrono::duration<double>>(end - start).count() << " s" << endl;

    return 0;
}