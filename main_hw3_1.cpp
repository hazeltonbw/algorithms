/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw3_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw3_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, Name, and Date.
/*
 * Title: main_hw3_1.cpp
 * Abstract: 
 * Name: 
 * Date:
 */

/*
   1. Write a C++ program (or Java program) for hw3_1 that reads the number of input values from a user.
   Then, read the input values from the user. After that, your program should display them in the ascending
   order. When you display the numbers, you have to use a short representation if there are consecutive
   numbers. For example, if there are three numbers such as 51, 52, and 53 in the input values, you have to
   display them 51–53 to save space. For the assignment, you can assume that the input values are positive
   integers and unique (= No duplications in the input numbers).
   Input format: This is a sample input from a user.
   6
   51
   27
   53
   77
   52
   75
   */

#include <iostream>
#include <vector>
using namespace std;


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


