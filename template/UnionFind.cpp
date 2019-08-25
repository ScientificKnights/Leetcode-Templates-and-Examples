class Unionfind{
private:
    vector<int> root;
public:
    //constructor
    Unionfind(int n){
        root=vector<int>(n+1,0);
        for(int i=0;i<n+1;i++)
            root[i]=i;
    }
    //Union
    bool Union(int u,int v){
        int root_u=findroot(u),root_v=findroot(v);
        if(root_u==root_v) return false;
        root[root_u]=root_v;
        return true;
    }
    //find root
    int findroot(int u){
        //是if不是while！！多次犯错啦。if+recursive，不需要loop
        if(u!=root[u])
            root[u]=findroot(root[u]);      //path compression
        return root[u];
    }
};
