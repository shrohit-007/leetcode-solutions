class Solution {
public:

    bool isValidSerialization(string preorder) {
        if(preorder.empty())return false;
        preorder+=',';
        int sz=preorder.size();
        int capacity=1;// we can have this much nodes uptill this point
        for(int i=0;i<sz;i++)
        {
            if(preorder[i]!=',')continue;
            capacity--;
            if(capacity<0)return false;
            if(preorder[i-1]!='#')capacity+=2;
        }
        return capacity==0;
    }
};
