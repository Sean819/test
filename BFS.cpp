#include <cstdio>
#include <queue>
using namespace std;

struct state{
	int len;
	int time;
	
	state(int l,int t):len(l),time(t){}
	state& operator = (const state& s){
		len = s.len;
		time = s.time;
		return *this;
	}
};

bool visit[10001];//注注注注注注注：BFS 和 DFS 一定要visit数组记录节点是否被遍历过

int main(){
	int N,K;
	while(scanf("%d %d",&N,&K) != EOF){
		queue<state> q;
		q.push(state(N,0));
		visit[N] = true;
		while(!q.empty()){
			state s = q.front();
			if(s.len == K){
				printf("%d\n",s.time);
				break;
			}
			q.pop();
			
			int l = s.len,t = s.time;
			if(l+1 > 0 && l+1 < 10001){
				q.push(state(l+1,t+1));
				visit[l+1] = true;
			}
			if(l-1 > 0 && l-1 < 10001){
				q.push(state(l-1,t+1));
				visit[l-1] = true;
			}
			if(l*2 > 0 && l*2 < 10001){
				q.push(state(l*2,t+1));
				visit[l*2] = true;
			}
		}
	}
	
	return 0; 
}
