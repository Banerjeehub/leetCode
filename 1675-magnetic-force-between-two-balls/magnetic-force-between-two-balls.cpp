class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = *max_element(position.begin(), position.end()) - *min_element(position.begin(), position.end());

        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;
            int count = 1;
            int lastPos = position[0];

            for(int i=1; i<position.size(); i++){
                if(position[i] - lastPos >= mid){
                    lastPos = position[i];
                    count++;
                }
            }

            if(count >= m){
                ans = max(ans, mid);
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};