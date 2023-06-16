#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int count = 0, current = 0;
    while(tank < dist) { // While the destination cannot be reached with current fuel
        if(current > stops.size() || stops[current] > tank) return -1; // Cannot reach the destination nor the next gas station
        while((current < stops.size()-1) && (stops[current+1] <= tank)) {
            current ++;
            count ++; // Stop to refill
            tank = stops[current] + tank; // Fill up the tank 
            current ++;
        }
    }
    return count;
}

int main() {
    int d = 0; // distance between two cities (dist)
    cin >> d;
    int m = 0; // car's milage (tank)
    cin >> m;
    int n = 0; // number of gas stations in the way (stops)
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i); // distances of the gas station from the starting point

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
