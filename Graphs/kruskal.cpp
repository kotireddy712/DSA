int FIND_UL_PARENT(vector<int>& parent, int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    return parent[node] = FIND_PARENT(parent,parent[node]); //** Helped for path-compression */
}
//** rank.resize(n+1,0);
//parent[i] = i; //intiallty .. */
//** ASSUME, BOTH "rank,parent -  VECTORS ARE GLOABLLY AVAILABLE ."star-coder LLM"." */
int Union(int u, int v)
{
    int ulp_u = FIND_UL_PARENT(parent,u);
    int ulp_v = FIND_UL_PARENT(parent,v);
    if(ulp_u == ulp_v) //** SKIP THE EDGE BETWEEN "u" and "v" for MST weight */
    {
        return; //** both nodes already in same compnents, so it will form cycle... */
    }
    min_spanning_weight = min_spanning_weight + EDGE_WEIGHT(u,v);
    if(rank[ulp_u] < rank[ulp_v])
    {
        parent[ulp_u] = ulp_v;
    }
    else if(rank[ulp_u] > rank[ulp_v])
    {
        parent[ulp_v] = ulp_u;
    }
    else //** both - equal .. */
    {
        parent[ulp_v] = ulp_u; //* attaching v to u.. so, rank of U increases by 1.
        rank[ulp_u]++;
    }
}