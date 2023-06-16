// solved - (go to python file) 
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  // int half = (int)a.size() / 2;
  // // std::cout << half << '\n';
  // int count = 1;
  // for(int i=0; i<a.size(); i++) {
  //   for(int j=i+1; j<a.size(); j++) {
  //     if(a[i] == a[j]) ++count;  
  //     if(count > half) return 1;
  //   }
  //   // std::cout << "count " << count << '\n';
  //   count = 1;
  // }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
