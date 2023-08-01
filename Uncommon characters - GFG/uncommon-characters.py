#User function Template for python3

class Solution:
  def UncommonChars(self,A, B):
        #code here
        s = ''.join(sorted((set(A) ^ set(B))))
        if s:
            return s
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        A = input()
        B = input()
        ob = Solution()
        print(ob.UncommonChars(A, B))

# } Driver Code Ends