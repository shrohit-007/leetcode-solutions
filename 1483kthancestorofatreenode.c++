class TreeAncestor {
public:
    vector<vector<int>> par;
    
    TreeAncestor(int n, vector<int>& parent) {
        int L = ceil(log2(n));
        par.assign(n, vector<int>(L + 1, 0));
        for (int i = 0; i < n; i++)
            par[i][0] = parent[i];
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= L; j++)
                par[i][j] = par[i][j - 1] == -1 ? -1 : par[par[i][j - 1]][j - 1]; 
    }                                                                             //equal to the parent that is 2^(j-1) levels above
                                                                                  //the parent that is 2^(j-1) levels above current node
    int getKthAncestor(int node, int k) {
        while (k) { //Iterate over enabled bits in k
            int p = __builtin_ctz(k); //Get position of least significant bit in k
            if ((node = par[node][p]) == -1) return -1;
            k -= (1 << p); //Subtract least significant bit          
        }
        return node;
    }
};
