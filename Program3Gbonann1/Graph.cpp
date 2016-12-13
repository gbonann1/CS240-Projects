#include "Graph.h"
#include <queue>
#include <list>

using namespace std;

Graph::Graph(ifstream& in){
	char thing[200];
	int counter = 0;
	while(in.getline(thing, 200, '\n')){
		Edge *newEdge = new Edge();
		string line(thing);
		int firstSpaceIndex = line.find(' ');
		int secondSpaceIndex = line.find(' ', firstSpaceIndex+1);
		int thirdSpaceIndex = line.find(' ', secondSpaceIndex+1); 
		int fourthSpaceIndex = line.find(' ', thirdSpaceIndex+1);
		int end = line.find('\n', fourthSpaceIndex+1);
		string cityOne = line.substr(0,firstSpaceIndex);
		string cityTwo = line.substr(firstSpaceIndex+1,secondSpaceIndex - firstSpaceIndex - 1);
		string departureTime = line.substr(secondSpaceIndex+1, thirdSpaceIndex - secondSpaceIndex -1);
		string arrivalTime = line.substr(thirdSpaceIndex+1, fourthSpaceIndex - thirdSpaceIndex -1);
		string price = line.substr(fourthSpaceIndex+2, end - fourthSpaceIndex -2);
		int intPrice = atoi(price.c_str());
		newEdge->arrivalTime = Time(arrivalTime);
		newEdge->departureTime = Time(departureTime);
		newEdge->city = cityTwo;
		newEdge->price = intPrice;
		bool newCityOne = true;
		//bool newCityTwo = true;
		for(int i=0; i<cityNames.size(); i++){
			if(cityOne == cityNames[i].city) {newCityOne = false;}
			//if(cityTwo == cityNames.city[i]) {newCityTwo = false;}
		}
		if(newCityOne){
			Node add;
			add.city = cityOne;
			cityNames.push_back(add);
			counter++;
		}
		cityNames[counter-1].flights.push_back(newEdge);
		//cout << thing << "  " << firstSpaceIndex << "  " << secondSpaceIndex << endl;
	}
	
}
void Graph::print(){
	for(int j=0; j<cityNames.size(); j++){
		for (int k = 0; k<cityNames[j].flights.size(); k++){
			cout << cityNames[j].city;
			cout << " to ";
			Edge* blah = cityNames[j].flights[k];
			cout << blah->city;
			cout << " ";
			cout << blah->departureTime;
			cout << " ";
			cout << blah->arrivalTime;
			cout << " $";
			cout << blah->price << endl;
		}
	}
}

void Graph::f(){
	string sourceCity;
	string destinationCity;
	cout << "Enter a Source city: ";
	cin >> sourceCity;
	cout << "Enter a Destination city: ";
	cin >> destinationCity;
	Node aNode;
	Node theNode;
	int distance = 0;
	int nodeIndex = -2;
	int n = cityNames.size();
	vector<int> distLabel(n, -1),
		predLabel(n);
	//breadth first search labeling nodes with indices
	queue<Node> shortestPath;
	for (int i = 0; i < cityNames.size(); i++){
		if (cityNames[i].city == sourceCity){
			Node sourceNode = cityNames[i];
			cityNames[i].visited = true;
			shortestPath.push(sourceNode);
		}
	}
	//find destinationNode
	/**for (int i = 0; i < cityNames.size(); i++){
		if (cityNames[i].city == destinationCity){
			Node destinationNode = cityNames[i];
		}
	}**/
	while (!shortestPath.empty()){
		Node node;
		node = shortestPath.front();
		shortestPath.pop();
		//loop through adjacent vertices
		for (int i = 0; i < node.flights.size(); i++){ //what if it has several edges to same node
			string cityName = node.flights[i]->city;
			//loop through graph to access node with the same name
			for (int j = 0; j < cityNames.size(); j++){
				if (cityNames[j].city == cityName && !cityNames[j].visited){
					//cout << cityNames[j].city << endl; 
					cityNames[j].visited = true;
					cityNames[j].index = j;
					Node newNode = cityNames[j];
					shortestPath.push(newNode);
				}
			}
			
		}
	}
	//end of breadth first search
	Node node;
	queue<Node> nodeQueue;
	for (int i = 0; i < cityNames.size(); i++){
		if (cityNames[i].city == sourceCity){
			Node sourceNode = cityNames[i];
			distLabel[sourceNode.index] = 0;
			nodeQueue.push(sourceNode);
		}
	}
	
	
	for (int i = 0; i < cityNames.size(); i++){
		if (cityNames[i].city == destinationCity){
			Node destinationNode = cityNames[i];
			while (distLabel[destinationNode.index] < 0 && !nodeQueue.empty()){
				node = nodeQueue.front();
				nodeQueue.pop();
				if (distLabel[node.index] > distance)
					distance++;
				for (int k = 0; k < node.flights.size(); k++){
					if (k != 0){
						string oldCity = node.flights[k-1]->city;
						string newCity = node.flights[k]->city;
						if (oldCity != newCity){
							for (int p = 0; p < cityNames.size(); p++){
								if (cityNames[p].city == newCity){
									theNode = cityNames[p];
								}
							}
							if (distLabel[theNode.index] < 0) {
								distLabel[theNode.index] = distance + 1;
								predLabel[theNode.index] = node.index;
								nodeQueue.push(theNode);
							}
						}
					}
					else
					{
						string newCity = node.flights[k]->city;
						for (int w = 0; w < cityNames.size(); w++){
							if (cityNames[w].city == newCity){
								theNode = cityNames[w];
							}
						}
						if (distLabel[theNode.index] < 0) {
							distLabel[theNode.index] = distance + 1;
							predLabel[theNode.index] = node.index;
							nodeQueue.push(theNode);
						}
					}
					
						/**
						for (int w = 0; w < cityNames.size(); w++){
							if (cityNames[w].index = k){
								Node newNode = cityNames[w];
								nodeQueue.push(newNode);
							}		
						}
						**/
				}
				//check all values of distLabel. might be a problem there
				for (int n = 0; n < distLabel.size(); n++){
					//cout << distLabel[n] << endl;
				}
				distance++;
				aNode = destinationNode;
			}
		}
	}
	
	/**
	
	**/
	vector<Node> path(distance +1);
	if (distLabel[aNode.index] == 0)
		cout << "Not reachable from start" << endl;
	else
	{
		path[distance] = aNode;
		cout << "You can reach your destination in a minimum of:";
		cout << distance;
		cout << " hops" << endl;
		for (int i = 0; i < cityNames.size(); i++){
			if (cityNames[i].city == sourceCity){
				Node sourceNode = cityNames[i];
				path[0] = sourceNode;
			}
		}
		for (int k = distance - 1; k > 0; k--) {
			nodeIndex = predLabel[path[k+1].index];
			for (int q = 0; q < cityNames.size(); q++){
				if (cityNames[q].index == nodeIndex){
					path[k] = cityNames[q];
					//cout << cityNames[q].city << endl;
				}
			}
		}
		//cout << sourceCity << endl;
		for (int k = 0; k < path.size() - 1; k++){
			cout << path[k].city;
			cout << " -> ";
		}
		
		cout << path[path.size() -1].city << endl;
		
		for (int k = 0; k < path.size(); k++) {
			if (k < path.size() - 1){
				cout << path[k].city;
				cout << " ";
				cout << path[k+1].city;
				cout << " ";
			}
			for (int q = 0; q < path[k].flights.size(); q++){
				if (k != path.size() - 1){
					if (path[k].flights[q]->city == path[k+1].city){
						cout << path[k].flights[q]->departureTime;
						cout << " ";
						cout << path[k].flights[q]->arrivalTime;
						cout << " $";
						cout << path[k].flights[q]->price;
						cout << " " << endl;
						break;
					}
				}	
			}
		}
		

	}
	
	for (int i = 0; i < cityNames.size(); i++){
		cityNames[i].visited = false;
		cityNames[i].index = -1;
	}
}

Graph::~Graph() {
 for (int j = 0; j<cityNames.size(); j++) {

  for (int i = 0; i<cityNames[j].flights.size(); i++) {
  delete cityNames[j].flights[i];
  }
 }  
}
