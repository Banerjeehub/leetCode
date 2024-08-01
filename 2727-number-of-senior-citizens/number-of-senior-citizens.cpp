#include <vector>
#include <string>

class Solution {
public:
    int countSeniors(std::vector<std::string>& details) {
        int count = 0;

        for (const auto& detail : details) {
            // Extract the age part from the string (characters at index 11 and 12, 0-indexed)
            int age = std::stoi(detail.substr(11, 2));

            // Check if the age is greater than 60
            if (age > 60) {
                count++;
            }
        }

        return count;
    }
};