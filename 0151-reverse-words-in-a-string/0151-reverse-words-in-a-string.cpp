class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(j!=0 and s[j-1]!=' '){
                    s[j++] = ' ';
                }
            }else{
                s[j++] = s[i];
            }
        }
        if(s[j-1]==' '){
            s.resize(j-1);
        }else{
            s.resize(j);
        }
        
        j = 0;
        int i = 0;
        for(;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
        }
        reverse(s.begin()+j,s.begin()+i);
        return s;
    }
};