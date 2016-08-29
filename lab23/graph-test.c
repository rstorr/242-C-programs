#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void){
	graph g;
	int size, u, v;
	scanf("%d", &size);
	g = graph_new(size);
	while(scanf("%d %d", &u, &v) == 2){
		graph_add_edge(g,u,v);
	}

	graph_dfs(g);
	graph_print(g);
        graph_free(g);
	return EXIT_SUCCESS;
}
