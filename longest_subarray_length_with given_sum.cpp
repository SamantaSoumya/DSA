
#include <bits/stdc++.h>
using namespace std;
int lenOfLongestSubarr(vector<int> &arr, int k)
{
    int maxLen = 0;
    int n = arr.size();
    unordered_map<long long, int> mp;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            maxLen = max(maxLen, i - mp[rem]);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return maxLen;
}
int main()
{
    vector<int> arr;
    int k;
    int ans = lenOfLongestSubarr(arr, k);
}
