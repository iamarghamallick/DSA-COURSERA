#include <iostream>
#include <vector>
#include <iomanip>
using std::vector;

void sort(double costs[], int size) {
  for(int i=0; i<size-1; i++) {
    for(int j=0; j<size-1-i; j++) {
      if(costs[j] < costs[j+1]) {
        double temp = costs[j];
        costs[j] = costs[j+1];
        costs[j+1] = temp;
      }
    }
  }
}

void display(double v[], int size) {
  for(int i=0; i<size; i++) {
    std::cout << v[i] << " " << std::endl;
  }
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  int size = values.size();
  double value = 0.0;
  double A[size];
  double a;
  // write your code here

  for(int i=0; i<size-1; i++) {
    for(int j=0; j<size-1-i; j++) {
      if((double)values[j]/(double)weights[j] < (double)values[j+1]/(double)weights[j+1]) {
        int temp1 = values[j]; int temp2 = weights[j];
        values[j] = values[j+1]; weights[j] = weights[j+1];
        values[j+1] = temp1; weights[j+1] = temp2;
      }
    }
  }
  
  double costs[size];
  for(int i=0; i<values.size(); i++) {
    costs[i] = (double)values[i] / (double)weights[i];
    // std::cout << costs[i];
  }
  // display(costs, size);
  // sort(costs, size);
  // display(costs, size);
  for(int i=0; i<size; i++) {
    if(capacity == 0) return value;
    else {
      a = weights[i] > capacity ? capacity : weights[i];
      value = value + a*costs[i];
      weights[i] = weights[i] - a;
      A[i] = A[i] + a;
      capacity = capacity - a;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << std::setprecision(4) << std::fixed;
  std::cout << optimal_value << std::endl;
  return 0;
}
