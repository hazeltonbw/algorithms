#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Title: main_hw3_2.cpp
 * Abstract: Find the shortest path from the starting edge, 
 * visiting every other city once and then back to the starting edge.
 * Name: Brandon Hazelton
 * Date: 09-18-2023
*/

class TSP {
	vector<vector<unsigned int>> adj_matrix = {};
	vector<unsigned int> cities_to_visit;
	vector<unsigned int> optimal_path;
	size_t starting_edge = 0;
	size_t min_cost = INT_MAX;

public:
	TSP(size_t num_verts, size_t num_edges) {
		adj_matrix = vector<vector<unsigned int>>(num_verts, vector<unsigned int>(num_verts, 0));
		init_adj_matrix(num_edges);
		init_path(num_verts);
		find_optimal_path(cities_to_visit, cities_to_visit.size());
		print_optimal_path();
	}

	void print_optimal_path() {
		if (optimal_path.size() == 0) {
			cout << "Path:" << endl;
			cout << "Cost:-1" << endl;
			return;
		}
		cout << "Path:" << starting_edge << "->";
		for (size_t i = 0; i < optimal_path.size(); i++) {
			cout << optimal_path[i] << "->";	
		}
		cout << starting_edge << endl;
		cout << "Cost:" << min_cost << endl;
	}

	void init_path(size_t num_verts) {
		cin >> starting_edge;
		for (size_t i = 0; i < num_verts; i++) {
			if (i != starting_edge)  {
				cities_to_visit.push_back(i);
			}
		}
	}

	void init_adj_matrix(size_t num_edges) {
		for (size_t i = 0; i < num_edges; i++) {
			size_t vert1 = 0, vert2 = 0;
			unsigned int cost = 0;
			cin >> vert1 >> vert2 >> cost;
			adj_matrix[vert1][vert2] = cost;
		}
	}

	void print_adj_matrix() {
		// Print header
		cout << "\t";
		for (size_t i = 0; i < adj_matrix.size(); i++)
			cout << i << "\t";
		cout << endl;
		for (size_t i = 0; i < adj_matrix.size(); i++) {
			cout << i << "\t";
			for (size_t j = 0; j < adj_matrix[i].size(); j++) {
				cout << adj_matrix[i][j] << "\t";
			}
			cout << endl;
		}
	}

	void display(vector<unsigned int> &a, int n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	unsigned int calculate_path(vector<unsigned int> &path) {
		unsigned int cost = adj_matrix[starting_edge][path[0]];
		size_t i;
		unsigned int current_cost = 0;
		for (i = 0; i < path.size() - 1; i++) {
			current_cost = adj_matrix[path[i]][path[i+1]];
			if (cost == 0 || current_cost == 0) {
				return INT_MAX;
			}
			cost += current_cost;
		}
		current_cost = adj_matrix[path[i]][starting_edge]; 
		if (current_cost == 0) return INT_MAX;
		cost += current_cost;
		return cost;
	}

	void find_optimal_path(vector<unsigned int> &a, int n) {
		sort(a.begin(), a.begin() + n);

		do {
			unsigned int current_cost = calculate_path(a);
			if (current_cost < min_cost) {
				min_cost = current_cost;	
				optimal_path = a;
			}
		} while (next_permutation(a.begin(), a.begin() + n));
	}
};

int main() {
	size_t num_verts = 0;
	size_t num_edges = 0;
	cin >> num_verts;
	cin >> num_edges;

	TSP tsp = TSP(num_verts, num_edges);
}
