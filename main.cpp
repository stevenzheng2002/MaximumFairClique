#include "Graph.h"
#include "Utility.h"
#include "Timer.h"
using namespace std;

int main(int argc, char *argv[]){
    if(argc < 4){
        puts("Usage:");
        puts("./main [graph_file_path] [attribute_file_path] threshold delta\n");
        return 0;
    }
    // printf("Graph=%s attribute=%s threshold=%s delta=%s\n", argv[1], argv[2], argv[3], argv[4]);
    Timer tt;
    Graph* graph = new Graph();
    // 读入图
    graph -> ReadGraph(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    // graph -> check();
    graph -> Colorful_Degree_Reduction();
    graph -> Enhanced_Colorful_Degree_Reduction();
    graph -> reColor();         // 重新染色
    // graph -> printGraph();
    graph -> Colorful_Support_Reduction();
    graph -> Enhanced_Colorful_Support_Reduction();
    graph -> Node_Contraction();        // 缩图
    graph -> reColor();                 // 重新染色
    int ub = graph -> Find_MRFC_Heuristic();     // 启发式算法找MRFC
    printf("upper bound of the MRFC is %d\n", ub);

    printf("tot time: %s (microseconds)\n", Utility::integer_to_string(tt.elapsed()).c_str());
    return 0;
}