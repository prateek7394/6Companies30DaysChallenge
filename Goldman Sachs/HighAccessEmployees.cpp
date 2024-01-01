// Problem: https://leetcode.com/problems/high-access-employees/description/

#include<bits/stdc++.h>
using namespace std;

// ---------------------- My approach ---------------------------
vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    int n = access_times.size();
        sort(access_times.begin(), access_times.end());
        unordered_set<string>st;
        for(int i=2; i<n; i++){
            string currName = access_times[i][0];
            int currTime = stoi(access_times[i][1]);

            string prevName = access_times[i-2][0];
            int prevTime = stoi(access_times[i-2][1]);

            if(currName==prevName && currTime-prevTime<=99){
                st.insert(currName);
            }
        }
        vector<string>ans(st.begin(), st.end());
        return ans;
}


// --------------------- Approach 2 -------------------------------
vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        int n = access_times.size();
        
        unordered_map<string, vector<int>> mp;
        for(auto &it: access_times){
            string name = it[0];
            int time = stoi(it[1]);
            mp[name].push_back(time);
        }

        for(auto &it: mp){
            sort(it.second.begin(), it.second.end());
        }

        vector<string>ans;

        for(auto &it : mp){
            string name = it.first;
            vector<int> times = it.second;

            for(int i=2; i<times.size(); i++){
                if(times[i]-times[i-2]<=99){
                    ans.push_back(name);
                    break;
                }
            }
        }

        return ans;
    }

int main()
{
    return 0;
}