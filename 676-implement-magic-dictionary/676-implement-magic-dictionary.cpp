class MagicDictionary {
public:
    unordered_set<string>st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) 
    {
        for(auto i:dictionary)
            st.insert(i);
    }
    
    bool search(string s) 
    {
    for(int i=0;i<s.size();i++)
    {
        for(int j='a';j<='z';j++)
        {
            if(s[i]==j)continue;
            char temp=s[i];
            s[i]=j;
            if(st.find(s)!=st.end())
                return true;
            s[i]=temp;
        }
    }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */