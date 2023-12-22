#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> inDegree(numCourses, 0);

    // Construct the graph and count in-degrees of each node
    for (const auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        inDegree[pre[0]]++;
    }

    queue<int> q;

    // Add nodes with in-degree 0 to the queue
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int coursesTaken = 0;

    // Process courses
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        coursesTaken++;

        // Decrement in-degrees of connected nodes and add to queue if in-degree becomes 0
        for (int neighbor : graph[course]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return coursesTaken == numCourses;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    bool canFinishAll = canFinish(numCourses, prerequisites);

    if (canFinishAll) {
        cout << "You can finish all courses!" << endl;
    } else {
        cout << "You cannot finish all courses." << endl;
    }

    return 0;
}
