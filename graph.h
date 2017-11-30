using namespace std;

struct Node{
		int station_id;
		string station_name;
		int weight;
		Node* next;
};

struct NodeList{
		Node* head;
};

struct Graph{
		int total_station;
		NodeList* arr;
};
