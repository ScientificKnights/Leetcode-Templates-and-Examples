/*
Given an array of prices [p1,p2...,pn] and a target, round each price pi to Roundi(pi) 
so that the rounded array [Round1(p1),Round2(p2)...,Roundn(pn)] sums to the given target.
Each operation Roundi(pi) could be either Floor(pi) or Ceil(pi).

Return the string "-1" if the rounded array is impossible to sum to target. 
Otherwise, return the smallest rounding error, which is defined as Σ |Roundi(pi) - (pi)| for i from 1 to n, 
as a string with three places after the decimal.

Input: prices = ["0.700","2.800","4.900"], target = 8
Output: "1.000"

Input: prices = ["1.500","2.500","3.500"], target = 10
Output: "-1"

1 <= prices.length <= 500.
Each string of prices prices[i] represents a real number which is between 0 and 1000 and has exactly 3 decimal places.
target is between 0 and 1000000.
*/

string minimizeError(vector<string>& prices, int target) {
    int n=prices.size(),sum=0,count=0;  //count可上可下的数量，不是n
    vector<double> diffs;
    for(auto i:prices){     //2.0,2.0,2.0 不能进位
        double num=stod(i);
        sum+=(int)num;
        if(num==(int)num*1.0) continue;
        count++;
        diffs.push_back(num-(int)num);
    }
    if(count+sum>=target && sum<=target){
        int nFloor=count-(target-sum);
        nth_element(diffs.begin(),diffs.begin()+nFloor,diffs.end());
        double res=0.0;
        for(int i=0;i<count;i++){
            if(i<nFloor) res+=diffs[i];
            else res+=(1.0-diffs[i]);
        }
        string ans=to_string(res);
        return ans.substr(0,ans.find('.')+4);
    }
    return "-1";
}
