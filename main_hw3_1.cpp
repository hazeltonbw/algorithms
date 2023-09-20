#include <iostream>
#include <vector>
using namespace std;

/*
 * Title: main_hw3_1.cpp
 * Abstract: Shorten consecutive numbers in an array
 * Name: Brandon Hazelton
 * Date: 09-18-2023
 */

void die() {
  cout << "BAD INPUT!\n";
  exit(EXIT_FAILURE);
}

int main()
{
  int N = 0;
  cin >> N;
  if (!cin) die(); 
  vector<int> vec;
  for (int i = 0; i < N; i++) {
    int x = 0;
    cin >> x;
    vec.push_back(x);
  }
  sort(vec.begin(), vec.end());

  bool cons = false;
  for (int i = 0; i < vec.size() - 1; i++) {
    if (vec[i] == (vec[i+1] - 1)) {
      if (!cons) {
        cout << vec[i] << "-";
        cons = !cons;
      }
      continue;
    }
    else {
      cons = false;
      cout << vec[i] << " ";
    }
  }
  cout << vec[vec.size()-1] << endl;

  return 0;
}
