#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <string>
#include <ostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Time.h"
#include "Date.h"

using namespace std;

typedef struct{
	Time departureTime;
	Time arrivalTime;
	Date date;
	int price;
	string city;
}Edge;

typedef struct{
	string city;
	bool visited = false;
	int index = -1;
	vector<Edge*> flights; //adjacency list
}Node;

class Graph{
	public:
		Graph(ifstream& in);
		void j();
		void f();
		void c();
		void s();
		void print();
		~Graph();	
	
	private:
		vector<Node> cityNames;
};

#endif
