#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

struct Graph{
	int V;
	list<int> *adj;
};

struct Graph* createGraph(int V){
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;
	graph->adj = new list<int>[V];
}

void addEdge(struct Graph* graph, int u, int v){
	graph->adj[u].push_back(v);
}

void printGraph(struct Graph* graph){
	for(int i = 0; i<graph->V ; i++){
		for (list<int>::iterator j = graph->adj[i].begin(); j != graph->adj[i].end(); j++){
			printf("%d->",*j);
		} 
		printf("\n");
	}
}

void BFS(struct Graph* graph,int s){
	int visited[graph->V];
	for(int i = 0; i<graph->V;i++)
		visited[i] = 0;
		
	list<int> queue;
	
	visited[s] = 1;
	queue.push_back(s);
	
	list<int>::iterator i;
	
	while(!queue.empty()){
		s = queue.front();
		printf("%d-->",s);
		queue.pop_front();
		
		for(i = graph->adj[s].begin(); i!= graph->adj[s].end(); i++){
			if(!visited[*i]){
				queue.push_back(*i);
				visited[*i] = 1;
			}
		}
	}
}
int main(){
	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1); 
    addEdge(graph,0, 2); 
    addEdge(graph,1, 2); 
    addEdge(graph,2, 0); 
    addEdge(graph,2, 3); 
    addEdge(graph,3, 3);
	printGraph(graph); 
	printf("\n");
	BFS(graph,2);
}
