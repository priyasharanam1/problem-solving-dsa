class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                a = i;
            if (s[i] == 'b')
                b = i;
            if (s[i] == 'c')
                c = i;
            if(a!=-1 && b!=-1 && c!=-1){
                int mini = min(a,min(b,c));
                cnt += (mini+1);
            }    
        }
        return cnt;
    }
};