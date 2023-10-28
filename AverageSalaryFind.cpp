#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double averageSalary(vector<int>& salary) {
    int maxSalary = *max_element(salary.begin(), salary.end());
    int minSalary = *min_element(salary.begin(), salary.end());
    double sum = 0;
    int count = 0;

    for (int s : salary) {
        if (s != maxSalary && s != minSalary) {
            sum += s;
            count++;
        }
    }

    return sum / count;
}

int main() {
    vector<int> salary = {6000, 5000, 4000, 3000, 2000, 1000};
    double result = averageSalary(salary);
    cout << "Average salary (excluding min and max): " << result << endl;
    return 0;
}
