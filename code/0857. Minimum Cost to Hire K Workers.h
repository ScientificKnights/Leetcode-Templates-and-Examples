/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, 
we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 

Note:
1 <= K <= N <= 10000, where N = quality.length = wage.length
1 <= quality[i] <= 10000
1 <= wage[i] <= 10000
Answers within 10^-5 of the correct answer will be considered correct.
*/

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    //先ratio排序出小的，再一个个加入，去除q大的 NlogN
    //按照ratio，wage/quality排序
    //将前K个加入max，heap，这里面可能有quality太大，导致最后wage大的
    //从k开始，一个一个加入heap，update total quality，update ratio, ratio 变大，但是total quality变小
    int n=wage.size();
    vector<pair<double,int>> ratio;
    for(int i=0;i<n;i++)
        ratio.push_back({1.0*wage[i]/quality[i],quality[i]});
    sort(ratio.begin(),ratio.end());
    int tot_quality=0;

    priority_queue<int> q;
    for(int i=0;i<K;i++){
        tot_quality+=ratio[i].second;
        q.push(ratio[i].second);
    }
    double res=ratio[K-1].first*tot_quality;

    for(int i=K;i<n;i++){
        q.push(ratio[i].second);
        tot_quality+=ratio[i].second;
        tot_quality-=q.top();
        q.pop();
        res=min(res,ratio[i].first*tot_quality);
    }
    return res;
}
