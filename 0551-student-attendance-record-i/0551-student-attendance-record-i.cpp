class Solution {
public:
    bool checkRecord(string s) {
           int ab=0;
        int late=0;
        for(int i=0; i<s.length(); i++)
        {
            if(late==3)
            {
                break;
            }
            if(s[i]=='A')
            {
                ab++;
                late=0;
            }
            else if(s[i]=='P')
            {
                late=0;
            }
            else if(s[i]=='L')
            {
                late++;
            }   
        }
       if((ab<2) && (late<3))
       {
           return true;
       }
        return false;
    }
};