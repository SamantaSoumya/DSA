#include<bits/stdc++.h>
using namespace std;

class Segment{
    public:
        void update(int ind,vector<int>&arr,vector<int>&seg,int low,int high,int i,int val){
            if(low==i && high==i){
                seg[ind]=val;
                return;
            }
            int mid=(low+high)/2;
            if(i<=mid)update(2*ind+1,arr,seg,low,mid,i,val);
            else update(2*ind+2,arr,seg,mid+1,high,i,val);
            seg[ind]= min(seg[2*ind+1],seg[2*ind+2]);
        }
        int query(int ind,vector<int>&seg,int low,int high,int lr,int hr){
            if(hr<low || lr>high)return INT_MAX;
            if(low>=lr && high<=hr)return seg[ind];
            int mid=(low+high)/2;
            int left=query(2*ind+1,seg,low,mid,lr,hr);
            int right=query(2*ind+2,seg,mid+1,high,lr,hr);
            return min(left,right);
        }
        void build(int ind,vector<int>&arr,int low,int high,vector<int>&seg){
            if(low==high){
                seg[ind]=arr[low];
                return;
            }
            int mid=(low+high)/2;
            build(2*ind+1,arr,low,mid,seg);
            build(2*ind+2,arr,mid+1,high,seg);
            seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
        }
        vector<int> solve(vector<int>&arr){
            int n=arr.size();
            vector<int>seg(4*n);
            build(0,arr,0,n-1,seg);
        }
};
int main(){
    Segment sg;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sg.solve(arr);
}