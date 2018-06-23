#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAX_NAME_LEN = 100;
const int MAX_ASCII = 100;
const int MAX_N = 5;
const int MAX_R = 10;
const int MAX_C = 10;
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

int dir[MAX_ASCII];
int fx[MAX_ASCII];
bool maze[MAX_R][MAX_C][MAX_N][MAX_N];
int dis[MAX_R][MAX_C][MAX_N];

struct node
{
    int r,c,d;
    node *p;
    node(int x = 0,int y = 0,int z = 0,node *w = NULL) : r(x),c(y),d(z),p(w) {}
}start,goal,inter;

node* walk(node *u,int turn)
{
    node *p = new node;
    p->p = u;
    p->d = u->d;
    if (turn == 1)
        p->d = (p->d + 3) % 4;
    if (turn == 2)
        p->d = (p->d + 1) % 4;
    p->r = u->r + dr[p->d];
    p->c = u->c + dc[p->d];
    return p;
}

void print(node *v)
{
    vector<node*> nodes;
    node *pn = v;
    while (pn)
    {
        nodes.push_back(pn);
        pn = pn->p;   
    }
    int cnt = 0;
    for (int i = nodes.size() - 1; i >= 0; --i)
    {
        if (cnt == 10)
        {
            printf("\n");
            cnt = 0;
        }
        if (!cnt)
            printf(" ");
        printf(" (%d,%d)",nodes[i]->r,nodes[i]->c);
        ++cnt;
    }
    printf("\n");
}

void bfs()
{
    node *start2 = walk(&start,0);
    memset(dis,-1,sizeof(dis));
    dis[start2->r][start2->c][start2->d] = 1;
    queue<node*> q;
    q.push(start2);
    node *u,*v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (u->r == goal.r && u->c == goal.c)
        {
            print(u);
            return;
        }
        for (int i = 0; i != 3; ++i)
            if (maze[u->r][u->c][u->d][i])
            {
                v= walk(u,i);
                if (v->r < 1 || v->r > 9 || v->c < 1 || v->c > 9)
                    continue;
                if (dis[v->r][v->c][v->d] > 0)
                    continue;
                dis[v->r][v->c][v->d] = dis[u->r][u->c][u->d] + 1;
                q.push(v);
            }
    }
    puts("  No Solution Possible");
    return;
}

int main()
{
    dir['N'] = 0;
    dir['E'] = 1;
    dir['S'] = 2;
    dir['W'] = 3;
    fx['F'] = 0;
    fx['L'] = 1;
    fx['R'] = 2;
    char name[MAX_NAME_LEN];
    while (scanf("%[^\n]%*c",name) == 1 && strcmp(name,"END")) 
    {
        printf("%s\n",name);
        memset(maze,0,sizeof(maze));
        char sd;
        scanf("%d%d%*c%c%d%d",&start.r,&start.c,&sd,&goal.r,&goal.c);
        start.d = dir[sd];
        char str[MAX_N];
        while (scanf("%d",&inter.r) == 1 && inter.r)
        {
            scanf("%d",&inter.c);
            while (scanf("%s",str) == 1 && str[0] != '*')
            {
                for (int i = 1; i < strlen(str); ++i)
                    maze[inter.r][inter.c][dir[str[0]]][fx[str[i]]] = true;
            }
        }
        getchar();
        bfs();
    }
    return 0;
}
