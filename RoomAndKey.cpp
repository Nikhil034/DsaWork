#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    queue<int> q;
    unordered_set<int> keys;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int room = q.front();
        q.pop();

        for (int key : rooms[room]) {
            if (!visited[key]) {
                visited[key] = true;
                q.push(key);
            }
        }
    }

    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> rooms = {{1}, {2}, {3}, {}};
    bool result = canVisitAllRooms(rooms);
    cout << (result ? "Can visit all rooms" : "Cannot visit all rooms") << endl;

    return 0;
}
