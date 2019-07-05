/*
Given a chemical formula (given as a string), return the count of each atom.
An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. 
If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. 
For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), 
followed by its count (if that count is more than 1), followed by the second name (in sorted order), 
followed by its count (if that count is more than 1), and so on.

Example 1:
formula = "H2O"
Output: "H2O"

Example 2:
formula = "Mg(OH)2"
Output: "H2MgO2"

Example 3:
formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"

Note:
All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.
*/
class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        vector<map<string,int>> data(1);
        for(int i=0;i<n;){
            if(formula[i]=='(') {
                i++;
                data.push_back(map<string,int>());
            }
            else if(formula[i]==')'){
                i++;
                string temp;
                while(i<n && isdigit(formula[i])){
                    temp+=formula[i++];
                }
                int count=(temp=="")?1:stoi(temp);
                
                map<string,int> todelete=data.back();
                data.pop_back();
                for(auto i:todelete){
                    data.back()[i.first]+=(count*i.second);
                }
            }
            else{
                string temp1,temp2;
                temp1+=formula[i++];
                while(i<n && formula[i]!='(' && formula[i]!=')' && !(formula[i]>='A' && formula[i]<='Z')){
                    if(isalpha(formula[i])) temp1+=formula[i];
                    else temp2+=formula[i];
                    i++;
                }
                data.back()[temp1]+=((temp2=="")?1:stoi(temp2));
            }
        }
        string res;
        for(auto i:data[0])
            res+=i.first,res+= (i.second==1)?"":to_string(i.second);
        return res;
                                     
    }
};
