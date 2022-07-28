#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define L_TYPE 0
#define S_TYPE 1

using namespace std;

struct BucketIdx{
    int L_head, S_head, S_tail;

};

struct TypeCnt{
    int L_cnt, S_cnt;
};

struct LMS{
    
    string str;
    int idx;

    LMS(string s, int i): str(s), idx(i){
        
    }
};

inline bool isLMS(int i, vector<bool> type)
{
    if(type[i] == L_TYPE)
        return false;
    if(type[i] == S_TYPE && i-1 >= 0 && type[i-1] == L_TYPE)
        return true;

    return false;
}

vector<int> sais(string str)
{

    str.push_back('$');
    int len = str.length();

    /* map string to value */
    map<char, int> charRank;
    for(char ch: str)
        charRank.insert(make_pair(ch, 0));

    int cnt = 0;
    for(auto& x: charRank)
    {
        x.second = cnt;
        cnt++;
    }
    
    vector<int> s;
    for(char ch: str)
        s.push_back(charRank.find(ch)->second);


    
    /* build type map */
    vector<bool> type(len);
    type[len-1] = S_TYPE;
    type[len-2] = L_TYPE;

    for(int i = len-3; i >= 0; i--)
    {
        if(s[i] < s[i+1])
            type[i] = S_TYPE;
        else if(s[i] > s[i+1])
            type[i] = L_TYPE;
        else
            type[i] = type[i+1];
    }

    /* build bucket map */
    map<char, TypeCnt> m;
    for(int i = 0; i<len; i++)
    {
        if(type[i] == L_TYPE)
            m[s[i]].L_cnt++;
        else
            m[s[i]].S_cnt++;    
    }
   
    vector<BucketIdx> bucketIdxMap(m.size());
    cnt = 0;
    int  i = 0;
    for(auto a: m)
    {
        /* [head, tail) */
        bucketIdxMap[i].L_head = cnt;
        cnt += a.second.L_cnt;

        bucketIdxMap[i].S_head = cnt;
        cnt += a.second.S_cnt;
        bucketIdxMap[i].S_tail = cnt;

        ++i;
    }

    /* build LMS strings */
    /* build LMS idx */
    vector<LMS> LMS_v;
    map<string, char> LMS_ch_map;
    bool tie = false;

    for(int i = 0; i<len; i++)
    {
        string t;
        if(isLMS(i, type))
        {

            t.push_back(s[i]+'0');

            int idx = i+1;
            while(idx<len && !isLMS(idx, type) )
            {
                t.push_back(s[idx]+'0');
                ++idx;
            }
            
            LMS_v.push_back(LMS(t, i));
            if(++LMS_ch_map[t] > 1)
                tie = true;
        }
    }
    char ch = 'a';
    for(auto& x: LMS_ch_map)
        x.second = ch++;

    
    string s2;

    for(LMS x: LMS_v)
    {
        ch = LMS_ch_map.find(x.str)->second;
        s2.push_back(ch);
    }

    /* build suffix array of s2 */
    vector<int> SA2;
    if(tie) 
        SA2 = sais(s2);
    else
    {   
        /* 建SA2有更快的方法，但這裡只簡單實作 */
        map<char, int> m;
        for(int i = 0; i < LMS_v.size(); ++i)
        {
            char rank = LMS_ch_map.find(LMS_v[i].str)->second;
            m[rank] = i;
        }
        for(auto x: m)
            SA2.push_back(x.second);
    }

    /* induced sorting */
    /* place S* into bucket */
    vector<int> SA(len, -1);
    for(int i: SA2)
    {
        int firstChar = LMS_v[i].str[0] - '0';
        SA[bucketIdxMap[firstChar].S_head++] = LMS_v[i].idx;
    }

    /* place L type into bucket */
    for(int i: SA)
    {
        if(i>0 && type[i-1] == L_TYPE)
        {
            int place = bucketIdxMap[s[i-1]].L_head++;
            SA[place] = i - 1;
        }
    }

    /* place S type into bucket */
    for(int i = SA.size()-1; i >= 0; i--)
    {
        int j = SA[i];
        if(j>0 && type[j-1] == S_TYPE)
        {
            int place = bucketIdxMap[s[j-1]].S_tail--;
            /* Because tail points to the next position of the last element, 
               it needs to be decreased */
            place--;

            SA[place] = j - 1;
        }
            
    }
    SA.erase(SA.begin());
    return SA;
}

int main(){
    string str = "immissiissippi";
    
    vector<int> SA;
    SA = sais(str);
    
    for(int i: SA)
        cout<<i<<": "<<str.substr(i)<<endl;
}