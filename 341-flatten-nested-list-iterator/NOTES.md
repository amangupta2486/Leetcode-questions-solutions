```
class NestedIterator {
private:
stack<NestedInteger> nodes;
public:
NestedIterator(vector<NestedInteger> &nestedList) {
int size = nestedList.size();
for(int i = size - 1; i >= 0; --i) {
nodes.push(nestedList[i]);
}
}
​
int next() {
int result = nodes.top().getInteger();
nodes.pop();
return result;
}
​
bool hasNext() {
while(!nodes.empty()) {
NestedInteger curr = nodes.top();
if(curr.isInteger()) {
return true;
}
nodes.pop();
vector<NestedInteger>& adjs = curr.getList();
int size = adjs.size();
for(int i = size - 1; i >= 0; --i) {
nodes.push(adjs[i]);
}
}
return false;
}
};
The same idea as a DFS, the only tricky part probably is you have to find a value node to claim there is next. And to do that, you have to look through all the nodes in the worst case in the entire graph. So you just keep going until you find a value node; if you can't, there is no next.
```