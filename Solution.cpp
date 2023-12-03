
#include <vector>
using namespace std;

class Solution {
    
public:
    vector<int> getSumAbsoluteDifferences(const vector<int>& input) const {
        const size_t totalElements = input.size();

        //alternatively: accumulate(input.begin(), input.end(), 0) => not supporting parallel implementation
        //               reduce(input.begin(), input.end(), 0) => supporting parallel implementation
        int sumAllElements = 0;
        for (const auto& value : input) {
            sumAllElements += value;
        }

        vector<int> sumAbsoluteDifferences(totalElements);
        int sumPreceedingElements = 0;

        for (size_t i = 0; i < totalElements; ++i) {
            int numberOfPreceedingElements = i;
            int numberOfFollowingElements = totalElements - 1 - i;

            int sumFollowingElements = sumAllElements - sumPreceedingElements - input[i];

            int preceedingValuesDifferences = (input[i] * numberOfPreceedingElements) - sumPreceedingElements;
            int followingValuesDifferences = sumFollowingElements - (input[i] * numberOfFollowingElements);

            sumAbsoluteDifferences[i] = preceedingValuesDifferences + followingValuesDifferences;

            sumPreceedingElements += input[i];
        }

        return sumAbsoluteDifferences;
    }
};
