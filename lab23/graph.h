#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>

typedef struct graphrec *graph;
typedef struct vertexrec *vertex;
typedef enum {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;
extern graph graph_new(int size);
extern void graph_free(graph g);
extern void graph_print(graph g);
extern void graph_dfs(graph g);
extern void visit(graph g, int v);
extern void graph_add_edge(graph g, int u, int v);

#endif
