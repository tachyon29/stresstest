#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll bruteForceSolution(const vector<ll>& data) {
    ll counteven=0;
    for(auto x:data)
    if(x%2==0) counteven++;
    return counteven;
}

ll optimizedSolution(const vector<ll>& data) {
   ll counteven=0;
    for(auto x:data)
    if(x%2==0 && x>0) counteven++;
    return counteven;
}

vector<ll> generateTestCase(ll maxSize,ll maxValue) {
    ll size = rand() % maxSize + 1;
    vector<ll> data(size);
    for (ll i = 0; i < size; i++) {
        data[i] = rand() % maxValue;
    }
    return data;
}

int main() {
    srand(time(0));
    ll testCaseCount = 100;
    ll maxSize = 10;
    ll maxValue = 10;

    for (ll i = 0; i < testCaseCount; i++) {
        vector<ll> testCase = generateTestCase(maxSize, maxValue);
        ll resultBruteForce = bruteForceSolution(testCase);
        ll resultOptimized = optimizedSolution(testCase);

        if (resultBruteForce != resultOptimized) {
            cout << "Failing test case found!" << endl;
            cout << "Input: ";
            for (ll num : testCase) cout << num << " ";
            cout << endl;
            cout << "Correct code result: " << resultBruteForce << endl;
            cout << "Wrong code result: " << resultOptimized << endl;
            return 0;
        }
    }

    cout << "No failing test case found!" << endl;
    return 0;
}