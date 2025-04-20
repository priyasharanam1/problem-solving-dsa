class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for(int ans : answers){
            m[ans]++;
        }

        int total = 0;
        for(auto& it : m){
            int x = it.first;     // rabbit says there are x others like it
            int count = it.second;

            int groupSize = x + 1;
            int groups = (count + groupSize - 1) / groupSize;  // ceil division

            total += groups * groupSize;
        }

        return total;
    }
};
