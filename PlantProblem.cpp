#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int P[100005];
queue<int> q;
int day[100005];
int pre[100005];
int nex[100005];
bool done[100005];

int main(){
	int N;
	scanf("%d", &N);
	rep(i,0,N){
		scanf("%d", P+i);
	}
	P[N]=-1;
	rrep(i,N,1){
		pre[i]=i-1;
		nex[i]=i+1;
		if(P[i] > P[i-1]){
			day[i]=1;
			q.push(i);
		}
	}
	int ans=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(done[cur])
			continue;
		done[cur]=1;
		ans=day[cur];
		pre[nex[cur]]=pre[cur];
		nex[pre[cur]]=nex[cur];
		if(P[nex[cur]] > P[pre[cur]]){
			day[nex[cur]]=day[cur]+1;
			q.push(nex[cur]);
		}
	}
	printf("%d", ans);
}