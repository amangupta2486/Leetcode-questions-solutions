```
Using bfs to solve this problem.
​
Every node can have 2^n state because of mask and total number of nodes are n, therefore in worst case we will push n * 2^n states in queue and pop them.
now for every state we will try to check it neighbors and see if we can push them.
A node can have O(n) neighbors.
hence:
​
TC : O(n * n * 2^n)
SC: O(n)
​
Checkout my github repo for solution of other leetcode problem - https://github.com/winnerfool/Leetcode-Solution
​
class Solution {
public:
int shortestPathLength(vector<vector<int>>& graph) {
int i,n=graph.size(),j,ans=0;
queue<vector<int>>q;
set<pair<int,int>>s;
//starting bfs from every node and mask is used to check state of all visited node
for(i=0;i<n;i++)
{
vector<int>v(3,0);
int mask=(1<<i);
int node=i;
int cost=0;
v[0]=cost;
v[1]=node;
v[2]=mask;
q.push(v);