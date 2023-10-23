#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> domainCounts;

    for (const string& cpdomain : cpdomains) {
        istringstream iss(cpdomain);
        int count;
        string domain;
        iss >> count >> domain;

        for (int i = domain.size() - 1; i >= 0; i--) {
            if (domain[i] == '.') {
                string subdomain = domain.substr(i + 1);
                domainCounts[subdomain] += count;
            }
        }
        domainCounts[domain] += count;
    }

    vector<string> result;
    for (const auto& entry : domainCounts) {
        result.push_back(to_string(entry.second) + " " + entry.first);
    }

    return result;
}

int main() {
    vector<string> cpdomains = {"9001 discuss.leetcode.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> result = subdomainVisits(cpdomains);

    for (const string& res : result) {
        cout << res << endl;
    }

    return 0;
}
