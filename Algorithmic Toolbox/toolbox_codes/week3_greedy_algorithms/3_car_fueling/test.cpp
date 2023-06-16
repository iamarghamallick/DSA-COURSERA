// // CPP program for finding the total
// // number of stops for refilling to
// // reach destination of N km
// #include <iostream>
// using namespace std;

// // Function that returns the total number of
// // refills made to reach the destination of N km
// int countRefill(int N, int K, int M, int compulsory[])
// {
// 	int count = 0;
// 	int i = 0;
// 	int distCovered = 0;

// 	// While we complete the whole journey.
// 	while (distCovered < N) {
// 		// If must visited petrol pump lie
// 		// between distCovered and distCovered+K.
// 		if (i < M && compulsory[i] <= (distCovered + K)) {
// 			// make last mustVisited as distCovered
// 			distCovered = compulsory[i];

// 			// increment the index of compulsory visited.
// 			i++;
// 		}

// 		// if no such must visited pump is
// 		// there then increment distCovered by K.
// 		else
// 			distCovered += K;

// 		// Counting the number of refill.
// 		if (distCovered < N)
// 			count++;
// 	}

// 	return count;
// }

// // Driver Code
// int main()
// {
// 	int N = 950;
// 	int K = 400;
// 	int M = 4;
// 	// compulsory petrol pumps to refill at
// 	int compulsory[] = { 200, 375, 550, 750 };

// 	// function call that returns the answer to the problem
// 	cout << countRefill(N, K, M, compulsory) << endl;
// 	return 0;
// }


 #include <iostream>
#include <vector>

using namespace std; 

//Function that returns the total number of refills made to reach the destination of N km

int MinRefills( int n, int milesAway, vector<int> Stops, int fulltank) { 
    int numRefills = 0;
    int currentRefill = 0;
    int lastRefill = 0;
    
    if ((Stops[currentRefill] + fulltank) >= milesAway) {
        return numRefills;
    }

    while (currentRefill <= n) {
        lastRefill = currentRefill; 
        while ((currentRefill <= n) && ((Stops[currentRefill + 1] - Stops[lastRefill]) <= fulltank)) {
            currentRefill = currentRefill + 1;
            cout << currentRefill << Stops[currentRefill] << "\t"; //printing to check 
        }
        if (currentRefill == lastRefill) {
            //cout << "-1";
            return -2;
        }
        if (currentRefill <= n) {
            //cout << numRefills;
            numRefills = numRefills + 1;
        }
        if ((Stops[currentRefill] + fulltank) >= milesAway) {
            cout << "Not bullshit" << Stops[currentRefill + 1];
            return numRefills++;
        }
    }
    return numRefills; 
}

int main() {
    int milesAway, fulltank, n, stopValue; 
    vector<int> Stops;
    cin >> milesAway;
    cin >> fulltank; 
    cin >> n; 
    Stops.push_back(0);
    if (n == 4) {
        int stop1, stop2, stop3, stop4;
        cin >> stop1 >> stop2 >> stop3 >> stop4;
        Stops.push_back(stop1);
        Stops.push_back(stop2);
        Stops.push_back(stop3);
        Stops.push_back(stop4); 
    }
    else { 
       for ( int i = 0; i < n; i++) {
         cin >> stopValue; 
         Stops.push_back(stopValue);
         //cout << Stops.size();
       }
    }
    cout << MinRefills(n, milesAway, Stops, fulltank);
    return 0;
}