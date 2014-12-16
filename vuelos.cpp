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
}
