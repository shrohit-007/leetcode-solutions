class Solution {
public:
    int calculate(string s) {
        stack<string>st;
        int n=s.length();
        int res=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                string tm="";
                if(s[i]!='(')
                {
                    st.push(s[i]+tm);
                    //cout<<s[i]<<endl;
                }
                else
                {
                    int cal=0;
                    string tmp="";
                    int f=-1;
                    while(!st.empty() and st.top()!=")")
                    {
                        if(st.top()!="+" and st.top()!="-")
                        {
                            tmp+=st.top();
                            st.pop();
                        }
                        else
                        {
                            if(f==-1)
                            {
                                if(tmp!="")
                                {
                                    cal+=stoi(tmp);
                                }
                                if(st.top()=="+")
                                {
                                    f=1;
                                    st.pop();
                                }
                                else
                                {
                                    f=0;
                                    st.pop();
                                }
                                tmp="";
                                    continue;
                            }
                            if(f==1)
                            {
                                cal+=stoi(tmp);
                            }
                            else if(f==0)
                            {
                                cal-=stoi(tmp);
                            }
                            if(st.top()=="+")
                            {
                                f=1;
                                st.pop();
                            }
                            else
                            {
                                f=0;
                                st.pop();
                            }
                            tmp="";
                        }
                    }
                    if(f)
                    cal+=stoi(tmp);
                    else
                        cal-=stoi(tmp);
                    st.pop();
                    st.push(to_string(cal));
                } 
            }
        }
        int ans=0;
        string tmp="";
        int f=-1;
        while(!st.empty())
        {
            if(st.top()!="+" and st.top()!="-")
            {
                tmp+=st.top();
                st.pop();
            }
            else
            {
                if(f==-1)
                {
                    if(tmp!="")
                    ans+=stoi(tmp);
                    if(st.top()=="+")
                        f=1;
                    else
                        f=0;
                    st.pop();tmp="";continue;
                }
                if(f)ans+=stoi(tmp);
                else if(f==0) ans-=stoi(tmp);
                if(st.top()=="+")f=1;
                else f=0;
                st.pop();tmp="";
            }
        }
        if(f)ans+=stoi(tmp);
        else if(f==0)ans-=stoi(tmp);
        return ans;
    }
};
