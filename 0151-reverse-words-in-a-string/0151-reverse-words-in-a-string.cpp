class Solution {
public:
    vector<string>v;
    string reverseWords(string s) {
    int n = s.length();
    string ans="";
    int space=0;
    for(int i=n-1;i>=0;i--){
        if(s[i] != ' '){
           space = 0;
           ans+=s[i];
        }
        else{
            space++;
            if(space <= 1){
                reverse(ans.begin(), ans.end());
                if(ans!=""){
                    v.push_back(ans);
                }
            }
            ans="";
        }
    }

    ans="";
    for(int i=0;i<n;i++){
        if(s[i]!=' '){
            ans+=s[i];
        }
        else
        break;
    }
    v.push_back(ans);

    s="";
    for(auto it : v){
        for(auto i : it){
            s+=i;
        }
       s+=' ';
    }
    int pos=0;
    for(int i=s.length()-1;i>=0;i--){
       if(s[i]==' ')
       pos++;
       else
       break;
    }
    s.erase(s.end()-pos,s.end());
    return s;
    }
};