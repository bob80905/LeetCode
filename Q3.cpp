class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int start = 0;
        int size = 0;
        unordered_map<char, int> h;
        for(unsigned int index = 0; index < s.size(); index++){
            size+=1;
            char c = (char) s[index];
            unordered_map<char, int>::iterator i = h.find(c);
            if(i == h.end()){
                h.insert(make_pair(c,index));
            }
            else{
                int first_instance = i->second;
                for(int j = start; j < first_instance+1; j++){                    
                    h.erase(s[j]);
                    start+=1;
                }
                size = index - start + 1;  //indexing
                h.insert(make_pair(c,index));
                
            }
            
            ret = max(ret, size);
            
        }
        return ret;
    }
};
