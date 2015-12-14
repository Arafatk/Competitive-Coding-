#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
// with bitcount be careful with data types

struct flow_graph{
    int MAX_V,E,s,t,head,tail,h;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;h=MAX_E;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[2*MAX_E], q = new int[2*MAX_E], dist = new int[2*MAX_E], now = new int[2*MAX_E];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
    }
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
	
	bool bfs(){
		fill(dist,dist+MAX_V,-1);
		head = tail = 0;
		
		q[tail] = t; ++tail;
		dist[t] = 0;
		
		while(head<tail){
			int v = q[head]; ++head;
			
			for(int e = last[v];e!=-1;e = next[e]){
				if(cap[e^1]>0 && dist[to[e]]==-1){
					q[tail] = to[e]; ++tail;
					dist[to[e]] = dist[v]+1;
				}
			}
		}
	//forall(i,0,MAX_V)cout << dist[i] <<" ";cout <<"\n";
		
		return dist[s]!=-1;
	}
	
	int dfs(int v, int f){
		if(v==t) return f;
		
		for(int &e = now[v];e!=-1;e = next[e]){
			if(cap[e]>0 && dist[to[e]]==dist[v]-1){
				int ret = dfs(to[e],min(f,cap[e]));
				
				if(ret>0){
					cap[e] -= ret;
					cap[e^1] += ret;
					return ret;
				}
			}
		}
		
		return 0;
	}
	
	long long max_flow(int source, int sink){
		s = source; t = sink;
		long long f = 0;
		int x;
		
		while(bfs()){
			for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
			while(true){
				x = dfs(s,INT_MAX);
				if(x==0) break;
				f += x;
			}
		}
		
		return f;
	}
	void print()
	{
		for (int i = 0; i < 2*h; ++i)
	{
//		printf("%d %d %d %d %d \n",i,to[i],cap[i],next[i],last[i]);
	}
	}
}G;

int main(){
	int V,E,u,v,c;
	scanf("%d %d",&V,&E);
	
	G = flow_graph(V,E);
	
	for(int i = 0;i<E;++i){
		scanf("%d %d %d",&u,&v,&c);
		G.add_edge(u-1,v-1,c,c);
	}
	G.print();
	
	printf("%lld\n",G.max_flow(0,V-1));
	
	return 0;
}
/*
Sample Input 1
6 8
1 2 3
1 4 7
2 4 1
2 3 1
3 6 5
4 6 3
5 4 3
6 5 2

*/