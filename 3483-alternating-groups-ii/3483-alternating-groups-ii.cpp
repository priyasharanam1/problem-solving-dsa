class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int lastColor=colors[0];
        int altColorsCnt=1;
        int altGroupCnt=0;
        
        //append first k-1 elemnets of colors to colors for circular array behavior
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        for(int i=1;i<colors.size();i++){
            if(colors[i]!=lastColor) altColorsCnt++;
            else altColorsCnt=1;

            if(altColorsCnt>=k) altGroupCnt++;
            lastColor=colors[i];
        }
        return altGroupCnt;
    }
};