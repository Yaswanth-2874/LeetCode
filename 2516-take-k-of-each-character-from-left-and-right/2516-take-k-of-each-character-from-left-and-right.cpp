// Not my code, debugging other's code
class Solution {
public:
bool helper(int m,int k,vector<vector<int>>&pref,vector<vector<int>>&suff){
     if(k==0)return  true;
     int n=pref.size();

      for(int i=0;i<m;i++){
        vector<int>& tmp1=pref[i];
        int idx=n-(m-i-1);

        vector<int>tmp2(3,0);
        if(idx<n &&idx>=0 )tmp2=suff[idx];
        
        bool flg2=true;
        for(int j=0;j<3;j++)if(tmp1[j]+tmp2[j]<k)flg2=false;
        if(flg2)return true;

    }
     bool flg=true;
     for(int i=0;i<3;i++){
       int idx=n-m;
       if(idx<0 || idx>=n)return false;
       if(suff[n-m][i]<k)flg=false;
     } 
     
     if(flg)return true;
     return false;
}

    int takeCharacters(string str, int k) {
        vector<vector<int>>freqPref(str.length(),vector<int>(3,0));
        vector<vector<int>>freqSuff(str.length(),vector<int>(3,0));
        
        vector<int>freq(3,0);
        vector<int>freq2(3,0);

        for(int i=0;i<str.length();i++){
            freq[str[i]-'a']++;
            freqPref[i]=freq;
            int idx=str.length()-1-i;
            freq2[str[idx]-'a']++;
            freqSuff[idx] = freq2;
        }

        int s=0;
        int e=str.length();
        int ans=-1;
        while(s<=e){
              int m=s+(e-s)/2;
              if(helper(m,k,freqPref,freqSuff)){
                ans=m;
                e=m-1;
              }
              else{
                s=m+1;
              }
        }
        return ans;
    }
};