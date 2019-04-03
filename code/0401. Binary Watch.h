class Solution {
public:
    vector<string> readBinaryWatch(int num) {   //BF
        vector<string> res;
        for(int i=0;i<12;i++)
            for(int j=0;j<60;j++){
                if(bitset<10>(i<<6|j).count()==num)
                    res.push_back(to_string(i)+":"+((j<10)?"0":"")+to_string(j));
            }
        return res;
    }
    /*
//backtrack
private:
    void add(vector<string> &res, vector<int> &path,int k){
        int min=path[4],hr=path[0];
        for(int i=0;i<3;i++){
            hr=hr<<1;
            hr+=path[i+1];
        }
        for(int i=0;i<5;i++){
            min=min<<1;
            min+=path[i+5];
        }
        if(min>=0 && min<60 && hr >=0 && hr<12){
            string h=to_string(hr);
            string m=to_string(min);
            res.push_back(h+":"+((m.size()==1)?"0":"")+m);
        }
        return;
    }
    void backtrack(vector<string> &res, vector<int> &path, int k, int num){
        if(k<0) return;
        if(path.size()==10 && k==0)
            add(res,path,k);
        else if((10-path.size())>=k){
            path.push_back(0);
            backtrack(res,path,k,num);
            path[path.size()-1]=1;
            backtrack(res,path,k-1,num);
            path.pop_back();
        }
        return;
    }
public:
    vector<string> readBinaryWatch(int num) {   
        vector<string> res;
        vector<int> path;
        backtrack(res,path,num,num);
        return res;
    }*/
};
