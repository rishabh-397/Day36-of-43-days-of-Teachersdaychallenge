#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int k1, k2;
    queue<int> q1, q2;
    
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int card;
        cin >> card;
        q1.push(card);
    }
    
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int card;
        cin >> card;
        q2.push(card);
    }
    
    set<pair<vector<int>, vector<int>>> seen;
    int fights = 0;
    
    while (!q1.empty() && !q2.empty()) {
        fights++;
        
        int card1 = q1.front(); q1.pop();
        int card2 = q2.front(); q2.pop();
        
        if (card1 > card2) {
            q1.push(card2);
            q1.push(card1);
        } else {
            q2.push(card1);
            q2.push(card2);
        }
        
        // Convert queues to vectors for state comparison
        vector<int> state1, state2;
        queue<int> temp1 = q1, temp2 = q2;
        
        while (!temp1.empty()) {
            state1.push_back(temp1.front());
            temp1.pop();
        }
        while (!temp2.empty()) {
            state2.push_back(temp2.front());
            temp2.pop();
        }
        
        pair<vector<int>, vector<int>> state = {state1, state2};
        if (seen.find(state) != seen.end()) {
            cout << -1 << endl;
            return 0;
        }
        seen.insert(state);
        
        if (fights > 1000000) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    int winner = q1.empty() ? 2 : 1;
    cout << fights << " " << winner << endl;
    
    return 0;
}
