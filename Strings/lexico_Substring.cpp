#include<bits/stdc++.h>
using namespace std;
const int maxlen=90000+5;
const int maxnode=200000+5;
const int SIGMA_SIZE=26;
struct Node
{
    Node *fail,*ch[SIGMA_SIZE];
    int Max,Size;
    Node() {Max=Size=0;fail=0;memset(ch,0,sizeof ch);}
}mem[maxnode],*root,*last;
struct SuffixAutomaton
{
    int size;
    inline int idx(char c) {return c-'a';}
    inline void init() {size=0;root=last=&mem[0];}
    int C[maxnode],ord[maxnode];
    inline void cal(Node* now)
    {
        now->Size=1; // actually root->Size=0;(init)
        for(int c=0;c<SIGMA_SIZE;c++) if(now->ch[c]) 
        {
            if(now->ch[c]->Size==0) cal(now->ch[c]);
            now->Size+=now->ch[c]->Size;
        }
    }
    inline void add(char c)
    {
        c=idx(c);
        Node *p=last;
        Node *np=&mem[++size];np->Max=p->Max+1;
        while(p && !p->ch[c]) p->ch[c]=np,p=p->fail;
        if(!p)  np->fail=root;
        else
        {
            Node *q=p->ch[c];
            if(q->Max==p->Max+1) np->fail=q;
            else
            {
                Node* nq=&mem[++size];nq->Max=p->Max+1;
                memcpy(nq->ch,q->ch,sizeof(q->ch));
                nq->fail=q->fail;
                q->fail=np->fail=nq;
                while(p && p->ch[c]==q) p->ch[c]=nq,p=p->fail;
            }
        }
        last=np;
    }
    inline void solve(int k)
    {
        char ans[maxlen];
        int p=0;
        Node* now=root;
        for(;;)
        {
            for(int c=0;c<SIGMA_SIZE;c++) if(now->ch[c])
            {
                if(k<=now->ch[c]->Size) {now=now->ch[c];ans[p++]=c+'a';break;}
                else k-=now->ch[c]->Size;
            }
            k--;
            if(k==0) break;
        }
        ans[p]='\0';
        printf("%s\n",ans);
    }
}SAM;
char s[maxlen];
int main()
{
    SAM.init();
    scanf("%s",s);
    int n=strlen(s),x,Q;
    for(int i=0;i<n;i++) SAM.add(s[i]);
    SAM.cal(root);
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&x);
        SAM.solve(x);
    }
}
