class Solution {
public:
double findMedianSortedArrays(vector<int>&nums1, vector<int >&nums2) {
vector<int> ans ; 
for(auto i : nums1){
ans.push_back(i); //first pushing all the values of first vector
}
for(auto i : nums2){
ans.push_back(i); //pushing values of second vector
}
sort(ans.begin(),ans.end()); //then using sort function
int a=ans.size();
if((ans.size())%2!=0){
return ans[a/2]; // if size is odd
}
else{
return (ans[(a/2)-1]+ans[a/2])/2.0 ; // if size is even
}
}
//tc=O(m+nlog(m+n))
//sc=O(m+n)
//not the best optimal solution but more like a brute force and esay understanding sol
};