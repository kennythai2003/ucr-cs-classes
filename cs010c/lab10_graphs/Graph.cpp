#include "Graph.h"

Graph::Graph(ifstream &ifs) {
	int nodes = 0;
	int edges = 0;
	int weight = 0;
	string name = "";
	string adjName = "";
	
	ifs >> nodes;
	ifs >> edges;
	
	ifs.ignore();
	
	for (int i = 0; i < nodes; i++) {
		Vertex newVertex;
		string temp = "";
		getline(ifs, temp);

		newVertex.label = temp;
		vertices.push_back(newVertex); //adds the name to our vector
		//does this for the amount of names in txt file
	}
	
	while (ifs >> name) {
		//takes in name
		int ind = 0;
		int adjInd = 0;
		
		ifs >> adjName; //takes in neighbor
		ifs >> weight; //takes in the weight
		
		for (unsigned int i = 0; i < vertices.size(); i++) {
			if (name == vertices.at(i).label) {
				ind = i;
			}
			if (adjName == vertices.at(i).label) {
				adjInd = i;
			}
		}
		
		vertices.at(ind).neighbors.push_back(make_pair(adjInd, weight));
	}
}

Graph::~Graph() {
	vertices.clear();
}


void Graph::bfs() {
	//based off other code
	vertices.at(0).distance = 0;
	
	queue<Vertex*> vertexQueue;
	vertexQueue.push(&vertices.at(0));
	
	while (!vertexQueue.empty()) {
		Vertex* frontVertex = vertexQueue.front();
		vertexQueue.pop();
		frontVertex->color = "GRAY";
		
		for (auto i = frontVertex->neighbors.begin(); i != frontVertex->neighbors.end(); i++) {
			if (vertices.at(i->first).color == "WHITE") {
				vertices.at(i->first).prev = frontVertex;
				vertices.at(i->first).distance = 0;
				vertices.at(i->first).color = "GRAY";
				vertices.at(i->first).distance += vertices.at(i->first).prev->distance + 1;
				vertexQueue.push(&vertices.at(i->first));
			}
		}
		
		frontVertex->color = "BLACK";
	}
}
// input2
// Micky_Mouse[label = "Micky_Mouse, 0"]
// Micky_Mouse -> Parah_Salin
// Micky_Mouse -> Kim_Jong_Il
// Parah_Salin[label = "Parah_Salin, 1"]
// Parah_Salin -> Joe_the_Plumber
// Joe_the_Plumber[label = "Joe_the_Plumber, 2"]
// Joe_the_Plumber -> Wille_E_Coyote
// Wille_E_Coyote[label = "Wille_E_Coyote, 3"]
// Wille_E_Coyote -> Tilla_Tequila
// Tilla_Tequila[label = "Tilla_Tequila, 4"]
// Kim_Jong_Il[label = "Kim_Jong_Il, 1"]
// Kim_Jong_Il -> Scoobie_Doo
// Scoobie_Doo[label = "Scoobie_Doo, 2"]
// Scoobie_Doo -> Hugo_Chavez
// Hugo_Chavez[label = "Hugo_Chavez, 3"]
