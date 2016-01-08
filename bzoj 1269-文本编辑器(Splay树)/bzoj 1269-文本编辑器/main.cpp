//splay树的问题
/*
伸展树（Splay Tree），也是对二叉查找树的一种改进，虽然它并不能保证树一直是“平衡”的，但对于伸展树的一系列操作，我们可以证明其每一步操作的平摊复杂度都是O(log n)。所以从某种意义上说，伸展树也是一种平衡的二叉查找树。而在各种树状数据结构中，伸展树的空间要求与编程复杂度也都是很优秀的
*/
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
#define debug puts("here")//将字符数组输出到标准输出
#define rep(i,n) for(int i=0;i<n;i++)
#define foreach(i,vec) for(unsigned i=0;i<vec.size();i++)
#define pb push_back
 
int tot,root,pos;//pos是光标的位置
 
namespace Splay{
 
#define lx ch[x][0]
#define rx ch[x][1]
#define px pre[x]
 
#define ly ch[y][0]
#define ry ch[y][1]
#define py pre[y]
 
#define lz ch[z][0]
#define rz ch[z][1]
#define pz pre[z]
 
#define rt ch[root][1]
#define lrt ch[rt][0]
 
    const int X = (1<<21)+5;
 
    int ch[X][2],pre[X],sz[X],rev[X];
    char str[X];
    char qq[X];
 
    inline void dfs(int x){
        if(x){
            dfs(lx);
            cout<<lx<<" "<<rx<<" "<<x<<endl;
            dfs(rx);
        }
    }
 
    inline void update(int x){
        //cout<<lx<<" "<<rx<<" "<<sz[lx]<<" "<<sz[rx]<<" "<<sz[lx]+sz[rx]+1<<endl;
        sz[x] = sz[lx]+sz[rx]+1;
    }
 
    inline void push_down(int x){
        if(x&&rev[x]){
            swap(lx,rx);
            rev[lx] ^= 1;
            rev[rx] ^= 1;
            rev[x] = 0;
        }
    }
 
    inline void new_node(int &x,int y,char c){
        x = ++tot;
        pre[x] = y;
        rev[x] = ch[x][0] = ch[x][1] = 0;
        str[x] = c;
    }
 
    inline void build(int &x,int l,int r,int y,char *s){
        if(l>r) return;
        int mid = (l+r)>>1;
        new_node(x,y,s[mid]);
        build(lx,l,mid-1,x,s);
        build(rx,mid+1,r,x,s);
        update(x);
    }
    inline void setc(int y,int d,int x){
        ch[y][d] = x;
        pre[x] = y;
    }
 
    inline int sgn(int x){
        return ch[px][1]==x;
    }
 
    inline void _rot(int x,int d){
        int y = px;
        int z = py;
        push_down(y);
        push_down(x);
        setc(y,!d,ch[x][d]);
        if(z)   setc(z,sgn(y),x);
        pre[x] = z;
        setc(x,d,y);
        update(y);
    }
 
    inline void rot(int x){_rot(x,!sgn(x));}
    inline void zag(int x){_rot(x,0);}
    inline void zig(int x){_rot(x,1);}
 
 
    inline int splay(int x,int goal=0){
        push_down(x);
        while(px!=goal){
            int y = px;
            int z = py;
            if(z==goal){
                rot(x);
                break;
            }
            if(lz==y){
                if(ly==x)
                    zig(y),zig(x);
                else
                    zag(x),zig(x);
            }
            else{
                if(ry==x)
                    zag(y),zag(x);
                else
                    zig(x),zag(x);
            }
        }
        update(x);
        if(goal==0)
            root = x;
        return x;
    }
 
    inline int get_Kth(int x,int k){
        push_down(x);
        int tmp = sz[lx]+1;
        if(tmp==k)
            return x;
        if(k<tmp)
            return get_Kth(lx,k);
        else
            return get_Kth(rx,k-tmp);
    }
 
    inline int get_min(int x){
        push_down(x);
        while(lx){
            x = lx;
            push_down(x);
        }
        return x;
    }
 
    inline void Move(){
        int k;
        scanf("%d",&k);
        pos = k+1;//改变pos游标位置
    }
 
    inline void Insert(){
        int k;
        scanf("%d",&k);
        getchar();
        gets(qq);
        int x = get_Kth(root,pos);
        splay(x);
        x = get_min(rt);
        splay(x,root);
        build(lrt,0,k-1,rt,qq);
    }
 
    inline void Delete(){
        int k;
        scanf("%d",&k);
        int x = get_Kth(root,pos);
        splay(x);
        int y = get_Kth(root,pos+k+1);
        splay(y,root);
 
        pre[lrt] = 0;
        lrt = 0;
        update(rt);
        update(root);
    }
 
    inline void Rotate(){
        int k;
        scanf("%d",&k);
        int x = get_Kth(root,pos);
        splay(x);
        int y = get_Kth(root,pos+k+1);
        splay(y,root);
        rev[lrt] ^= 1;
    }
 
    inline void Get(){
        int x = get_Kth(root,pos);
        splay(x);
        x = get_min(rt);
        printf("%c\n",str[x]);
    }
 
    inline void Prev(){//prev和next都是改变游标的
        pos--;
    }
 
    inline void Next(){
        pos++;
    }
 
    inline void init(){
        memset(pre,0,sizeof(pre));
        memset(ch,0,sizeof(ch));
        memset(sz,0,sizeof(sz));
        memset(rev,0,sizeof(rev));
        root = tot = 0;//root初始值0
        char s[] = "@@@@@@";
        build(root,0,5,0,s);
        pos = 1;
    }
}using namespace Splay;
 
int main(){
    int ncase;
    char op[20];
    cin>>ncase;
    init();
    while(ncase--){
        scanf("%s",op);
        switch(op[0]){
            case 'M':Move();break;
            case 'I':Insert();break;
            case 'D':Delete();break;
            case 'R':Rotate();break;
            case 'G':Get();break;
            case 'P':Prev();break;
            default:Next();
        }
    }
    return 0;
}