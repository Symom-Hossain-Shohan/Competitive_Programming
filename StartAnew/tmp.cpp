#include <iostream>
#include <vector>

using namespace std;

long long count_adjacent_pairs(const vector<int>& dimensions) {
    int n = dimensions.size();
    long long total_pairs = 0;

    for (int d = 0; d < n; ++d) {
        if (dimensions[d] > 1) {
            long long prod = 1;
            for (int i = 0; i < n; ++i) {
                if (i != d) {
                    prod *= dimensions[i];
                }
            }
            total_pairs += (dimensions[d] - 1) * prod;
        }
    }

    return total_pairs;
}

int main() {
    int n;
    cin >> n;  // Number of dimensions

    vector<int> dimensions(n);
    for (int i = 0; i < n; ++i) {
        cin >> dimensions[i];  // Input dimension sizes
    }

    cout << count_adjacent_pairs(dimensions) << endl;
    return 0;
}
