#include <iostream>
#include <vector>
using namespace std;

/*
 * Title: main_hw3_1.cpp
 * Abstract: Depth First Search of Integers 
 * using an implicit stack and a mark array
 * to note the path taken
 * Name: Brandon Hazelton 
 * Date: 09-19-2023
*/

class Graph {
	vector<size_t> mark;
	vector<vector<size_t>> adj_list;
	size_t count = 1;
	
public:
	Graph(size_t num_verts, size_t num_edges) {
		const int INITIAL_VALUE = 0;
		mark = vector<size_t>(num_verts, INITIAL_VALUE);
		adj_list = vector<vector<size_t>> (num_verts, vector<size_t>(num_verts));
		init_adj_list(num_edges);

		const size_t STARTING_VERT = 0;
		dfs(STARTING_VERT);
		print_mark_list();
	}

	void init_adj_list(size_t num_edges) {
		for (size_t i = 0; i < num_edges; i++) {
			size_t vert1 = 0;
			size_t vert2 = 0;
			cin >> vert1; cin >> vert2;
			adj_list[vert1][vert2] = vert2;
		}
	}

	void dfs(size_t vert) {
		mark[vert] = count++;
		
		for (size_t i = 0; i < adj_list[vert].size(); i++) {
			const size_t adj_vert = adj_list[vert][i];
			if (adj_vert != 0) {
				if (mark[i] == 0) {
					dfs(adj_vert);
				}
			}
		}
	}

	void print_mark_list() const{
		for (size_t i = 0; i < mark.size(); i++) {
			cout << "Mark[" << i << "]:" << mark[i] << endl;
		}
	}

	void print_adj_list() const {
		cout << "\t";
		for (size_t i = 0; i < adj_list.size(); i++) {
			cout << i << "\t";
		}
		cout << endl;
		for (size_t i = 0; i < adj_list.size(); i++) {
			cout << i << "\t";
			for (size_t j = 0; j < adj_list[i].size(); j++) {
				cout << adj_list[i][j] << "\t";
			}	
			cout << endl;
		}
	}
};

int main() {
	size_t num_verts = 0;
	cin >> num_verts;
	size_t num_edges = 0;
	cin >> num_edges;

	Graph graph = Graph(num_verts,num_edges);
}
