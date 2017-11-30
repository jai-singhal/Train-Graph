#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <list>
#include "graph.h"
#include "graph.cpp"
#include "printMenu.cpp"
using namespace std;

struct scheduleItem{
	int departureStationId;
	int arrivalStationId;
	string departureTime;
	string arrivalTime;
};

struct station {
	int id;
	string name;
};


bool isDirectRoute(Graph* G, int src, int dest){
		Node* temp = G->arr[src].head;
		while(temp != NULL){
				if(temp->station_id == dest)
					return true;
				temp = temp->next;
		}
		return false;
}

bool isPathRoute(Graph* G, int src, int dest){
		int *bfs = graphBFS(G, src);
		for(int i = 0; i < sizeof(bfs); i++){
				if(bfs[i] == dest)
						return true;
		}
		return false;
}

int main(){
		station stations[1000];
		scheduleItem schedule[1000];
		int i, j, k = 0, scheduleLength = 0, counter = 0, counterOfCase4, a, option, input;
		bool found;
		string nameOfStation, b, input_str;
		// read text files and put there data in arrays or any other datastructure
	  ifstream infile("stations.dat");

		while (infile >> a >> b){
			stations[a].id = a;
			stations[a].name = b;
		}

		Graph* G;
		G  = createGraph(10);
		// read text files and put there data in arrays or any other datastructure
		ifstream infile2("trains.dat");
		int departureId, arrivalId;
		string departureTime, arrivalTime;

		while (infile2 >> departureId >> arrivalId >> departureTime >> arrivalTime){
				schedule[scheduleLength].departureStationId = departureId;
				schedule[scheduleLength].arrivalStationId = arrivalId;
				schedule[scheduleLength].departureTime = departureTime;
				schedule[scheduleLength].arrivalTime = arrivalTime;
				scheduleLength++;
				stringstream departure(departureTime);
		 		int x = 0, y = 0;
		 		departure >> x;
				stringstream arrival(arrivalTime);
		 		arrival >> y;
				addEdge( G, departureId, arrivalId, y-x);
		}


		printGraphAdjLIst(G);

		 graphBFS(G, 1);
		 //isPathRoute(G, 2, 6);
		 printMenu();


		printf("Enter option: ");
		scanf("%d", &option);


		switch(option){
			case 1:
			printf("Full Schedule\n");
			for (j = 0; j < scheduleLength; j++)
				cout << "Departure from " << stations[schedule[j].departureStationId].name << " going to " << stations[schedule[j].arrivalStationId].name<< " departing at " << schedule[j].departureTime << " and arriving at " <<schedule[j].arrivalTime << endl;
			break;

			case 2:
					int stationId;
					printf("Enter station id: ");
					scanf("%d", &stationId);
					cout<<"Schedule of "<<stations[stationId].name<< endl;
					// check the schedule
					for (j = 0; j < scheduleLength; j++){
						if(schedule[j].departureStationId == stationId)
							cout<<"Departure to "<<stations[schedule[j].arrivalStationId].name<<" at " << schedule[j].departureTime <<" arriving at "<< schedule[j].arrivalTime<<endl;
						else 	if(schedule[j].arrivalStationId == stationId)
							cout<<"Arrival from "<<stations[schedule[j].departureStationId].name<<" at "<<schedule[j].arrivalTime<< endl;
					}
					break;

			case 3:
					j = 0;
					found = false;
					cout << "Enter station name: ";
					cin >> input_str;
					while (!found && j < 1000){
						if (stations[j].name == input_str){
							cout << "Id: " << stations[j].id;
							found = true;
						}
						j++;
					}
					if (!found)
						cout << "No station found";
					break;

			case 4:
					cout<<"Enter station id: ";
					cin >> input;
					cout<< stations[input].name<< endl;
					break;

			case 5:
			break;

			case 6:
			break;

			case 7:
			break;

			case 8:
			break;

			case 9:
			break;




		}


//		getch();

		return 0;
}
