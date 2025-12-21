#include<bits/stdc++.h>
using namespace std;
// Node* --> left,right,val..
vector<int> TopView(Node* root)
{
    Node* temp = root;
    queue<pair<Node*,int>> q; //** node-addr;H.D ..
    map<int,int> m; //** {H.D, NODE->VAL,..}
    if(root == NULL)
    {
        return {};
    }
    q.push({root,0});
    while( !q.empty() )
    {
        auto [curr,d] = q.front();
        q.pop();
        if( m.find(d) == m.end() ) //** no need of condition check for bottom - view ..
        {
            m[d] = curr->val;
        }
        if(curr->left != NULL)
        {
            q.push({curr->left,d-1});
        }
        if(curr->right != NULL)
        {
            q.push({curr->right,d+1});
        }
    }
    vector<int> result;
    for(auto it : m)
    {
        result.push_back(it.second);
    }
    return result;
}
//** Bottom view just we have to take most depth // last horrizantal same distances .. (( NO need of if-condition..thats it at line-18))
int main()
{

}