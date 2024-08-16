class Solution {
public:
    int f(int pos, int n, vector<int>&visited)
    {
        if(pos > n) return 1;
        int count = 0;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i] && (i % pos == 0 || pos % i == 0))
            {
                visited[i] = true;
                count += f(pos+1, n, visited);
                visited[i] = false;
            }
        }

        return count;
    }
    int countArrangement(int n) {
        
        vector<int>visited(n+1, 0);
        return f(1, n, visited);
    }
};