class Solution {
public:
    bool cmp(string& s1, string& s2){
        if(s1.size()!=s2.size()+1) return false;
            int a =0;
            int b=0;
            while(a!=s1.size()){
                if(b<s2.size() && s1[a]==s2[b]){
                    a++;
                    b++;
                }
                else a++;
            }return b==s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.length() < b.length();
        });
        int n =words.size();
        vector<int> dp(n,1);
        int maxi =1;
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(cmp(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }maxi=max(dp[i],maxi);
        }return maxi;
    }
};