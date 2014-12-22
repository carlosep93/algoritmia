#include <iostream>
#include <vector>
using namespace std;

struct Vuelo{
	int orig;
	int dest;
	int hsalida;
	int hllegada;
};

int main() {
	vector<Vuelo> vuelos;
	int n;
	while (cin >> n) {
		Vuelo v;
		v.orig = n;
		cin >> v.dest;
		cin >> v.hsalida;
		cin >> v.hllegada;
		vuelos.push_back(v);	
	}
	int size = (2*vuelos.size())+2;
	vector <vector <int> > M (size, vector<int>(size,0));

	//aristas hacia s y t
	for (int i=1; i<size-1;++i) {
		if (i%2 == 0)
			M[i][size-1] = 1;
		else 
			M[0][i] = 1;
	}

	//aristas entre vuelos compatibles
	for (int i=2;i<size-1; i = i+2) {
		for (int j=1; j<size-1; j= j+2) {
			if (j != i-1) {
				Vuelo v = vuelos[(i/2)-1];
				Vuelo w = vuelos[j/2];
				if (v.dest == w.orig and w.hsalida - v.hllegada >= 15)
					M[i][j] = 1;
			}	
		}
		M[i-1][i] = 1; //Arista entre u y v de cada viaje;
	}

	for (int i=0; i<size;++i) {
		for (int j=0; j<size; ++j) {
			cout << M[i][j]<<" ";
		}
		cout <<endl;
	}
}
