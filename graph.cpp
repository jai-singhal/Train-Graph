using namespace std;

Graph* createGraph(int total_vertex){
		Graph* G = new Graph;
		G->total_station = total_vertex;
		G->arr = new NodeList[total_vertex];
		for(int i = 0; i < total_vertex; i++)
				G->arr[i].head = NULL;
		return G;
}

Node* createNode(int station_id, int wt){
		Node* newNode = new Node;
	//	newNode->station_name = station_name;
		newNode->weight = wt;
		newNode->station_id = station_id;
		newNode->next = NULL;
		return newNode;
}

void addEdge(Graph*G, int src, int dest, int wt){
		Node* newNode = createNode(dest, wt);
		newNode->next = G->arr[src].head;
		G->arr[src].head = newNode;
}

void printGraphAdjLIst(Graph* G){
	int k = 0;
	Node* temp;
	while(k < 10){
		temp = G->arr[k].head;
		cout << k << " --> ";
		while(temp != NULL){
				cout << temp->station_id << " ";
				temp = temp->next;
		}
		cout << endl;
		k++;
	}
}

int* graphBFS(Graph* G, int start){
		list<int> q;
		int* bfs = new int[G->total_station];
		int k = 0;
		bool visited[G->total_station];
		for(int i = 0; i < G->total_station; i++)
				visited[i] = false;

		q.push_back(start);
		while(! q.empty()){
				int val = q.front();
				q.pop_front();
				if(! visited[val])
						bfs[k++] = val;
				Node* temp = G->arr[val].head;
				while(temp != NULL){
						if(! visited[temp->station_id]){
							q.push_back(temp->station_id);
						}
						temp = temp->next;
				}
				visited[val] = true;
		}

		return bfs;
}
