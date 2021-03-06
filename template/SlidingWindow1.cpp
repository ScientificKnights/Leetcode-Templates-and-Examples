    int length_sub_k_different_nums(vector<int>& tree) {  //914
        unordered_map<int,int> m; // key, count
        int start=0;
        int res=-1;
        for(int i=0;i<tree.size();i++){
            //更新start位置
            if(m.size()==k && m.count(tree[i])==0)
                while(m.size()==k){
                    if(--m[tree[start]]==0)
                        m.erase(tree[start]);
                    start++;
                }
            //更新hash map
            m[tree[i]]++;
            //更新result
            res=max(res,i-start+1);
        }
        return res;
    }
