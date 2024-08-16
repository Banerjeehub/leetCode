class Solution {
public:
std::set<int> getPrimeFactors(int num) {
    std::set<int> primeFactors;
    
    // Check for the number of 2s that divide num
    while (num % 2 == 0) {
        primeFactors.insert(2);
        num /= 2;
    }
    
    // num must be odd at this point, check for odd factors
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        while (num % i == 0) {
            primeFactors.insert(i);
            num /= i;
        }
    }
    
    // This condition is to check if num is a prime number greater than 2
    if (num > 2) {
        primeFactors.insert(num);
    }
    
    return primeFactors;
}

int distinctPrimeFactors(std::vector<int>& nums) {
    std::set<int> uniquePrimes;
    
    for (int num : nums) {
        std::set<int> primeFactors = getPrimeFactors(num);
        uniquePrimes.insert(primeFactors.begin(), primeFactors.end());
    }
    
    return uniquePrimes.size(); // The number of distinct prime factors
}
};