#include<bits/stdc++.h>
using namespace std;

class Segment {
    public:
        void update(int ind, vector<int>& arr, vector<int>& seg, vector<int>& lazy, int low, int high, int l, int r, int val) {
            if (lazy[ind] != 0) {
                seg[ind] += (high-low+1)*lazy[ind];
                if (low != high) {
                    lazy[2 * ind + 1] += lazy[ind];
                    lazy[2 * ind + 2] += lazy[ind];
                }
                lazy[ind] = 0;
            }
            if (low > high || low > r || high < l)
                return;
            if (low >= l && high <= r) {
                seg[ind] += (high-low+1)*val;
                if (low != high) {
                    lazy[2 * ind + 1] += val;
                    lazy[2 * ind + 2] += val;
                }
                return;
            }
            int mid = (low + high) / 2;
            update(2 * ind + 1, arr, seg, lazy, low, mid, l, r, val);
            update(2 * ind + 2, arr, seg, lazy, mid + 1, high, l, r, val);
            seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
        }

        int query(int ind, vector<int>& seg, vector<int>& lazy, int low, int high, int l, int r) {
            if (low > high || low > r || high < l)
                return 0;
            if (lazy[ind] != 0) {
                seg[ind] += (high-low+1)*lazy[ind];
                if (low != high) {
                    lazy[2 * ind + 1] += lazy[ind];
                    lazy[2 * ind + 2] += lazy[ind];
                }
                lazy[ind] = 0;
            }
            if (low >= l && high <= r)
                return seg[ind];
            int mid = (low + high) / 2;
            int left = query(2 * ind + 1, seg, lazy, low, mid, l, r);
            int right = query(2 * ind + 2, seg, lazy, mid + 1, high, l, r);
            return (left + right);
        }

        void build(int ind, vector<int>& arr, int low, int high, vector<int>& seg) {
            if (low == high) {
                seg[ind] = arr[low];
                return;
            }
            int mid = (low + high) / 2;
            build(2 * ind + 1, arr, low, mid, seg);
            build(2 * ind + 2, arr, mid + 1, high, seg);
            seg[ind] = (seg[2 * ind + 1] + seg[2 * ind + 2]);
        }

        vector<int> solve(vector<int>& arr) {
            int n = arr.size();
            vector<int> seg(4 * n, 0);
            build(0, arr, 0, n - 1, seg);
            return seg;
        }
};

int main() {
    Segment sg;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> seg = sg.solve(arr);
    vector<int> lazy(4 * n, 0);

    // Example usage:
    // Update range [1, 3] with value 5
    for(auto it:seg)cout<<it<<" ";
    cout<<endl;
    sg.update(0, arr, seg, lazy, 0, n - 1, 1, 3, 5);
    // Query range [1, 3]
    for(auto it:seg)cout<<it<<" ";
    cout<<endl;
    int result = sg.query(0, seg, lazy, 0, n - 1, 1, 3);
    cout << "Query result: " << result << endl;

    return 0;
}
