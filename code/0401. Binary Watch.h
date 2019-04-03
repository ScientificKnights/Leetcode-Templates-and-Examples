/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
Each LED represents a zero or one, with the least significant bit on the right.

For example, the above binary watch reads "3:25".
Given a non-negative integer n which represents the number of LEDs that are currently on, 
return all possible times the watch could represent.

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/

class Solution {
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
    }
};
