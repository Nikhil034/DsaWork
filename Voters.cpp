#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// Custom comparison function to rank teams based on votes
bool compareTeams(const std::pair<std::string, int> &team1, const std::pair<std::string, int> &team2) {
    // Compare by the number of votes (in descending order)
    if (team1.second != team2.second) {
        return team1.second > team2.second;
    } else {
        // If votes are the same, compare lexicographically by team name
        return team1.first < team2.first;
    }
}

std::vector<std::string> rankTeams(std::map<std::string, int> &votes) {
    // Convert the map to a vector of pairs for sorting
    std::vector<std::pair<std::string, int>> teamsVector(votes.begin(), votes.end());
    
    // Sort the teams based on the custom comparison function
    std::sort(teamsVector.begin(), teamsVector.end(), compareTeams);
    
    // Extract the team names in the sorted order
    std::vector<std::string> rankedTeams;
    for (const auto &team : teamsVector) {
        rankedTeams.push_back(team.first);
    }
    
    return rankedTeams;
}

int main() {
    std::map<std::string, int> votes;
    votes["TeamA"] = 10;
    votes["TeamB"] = 5;
    votes["TeamC"] = 15;
    votes["TeamD"] = 8;

    std::vector<std::string> rankedTeams = rankTeams(votes);

    // Display the ranked teams
    for (const std::string &team : rankedTeams) {
        std::cout << team << std::endl;
    }

    return 0;
}
