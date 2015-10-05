#include<stdio.h>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<string.h>
using namespace std;
bool visited[200000];//marks if the given index has been visited or not.
queue<int> indices[10];//to store where each digit has occured.
queue<int> qq[2];
char str[200001];
int main()
{
    int l,digit,i,toggle,dist,index,x;
    scanf("%s",str);
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        digit=str[i]-'0';
        indices[digit].push(i);
    }
    toggle=0;
    qq[toggle].push(0);dist=0;
    ///i have a starting digit now..
    ///ill enqueue all indices to which i can go from here..
while(1){
    while(!qq[toggle].empty())
    {
        //ive found an index..
        index=qq[toggle].front();
        qq[toggle].pop();
        if(index==l-1)
        {
            printf("%d\n",dist);
            return 0;
        }
        //i need to enqueue all indices to which i can reach from here..
        //those indices must be unvisited.
        //first enqueue the adjacent indices..
        if((index+1)<l && !visited[index+1])
        {
            visited[index]=1;
            qq[1-toggle].push(index+1);
        }
        if((index-1)>=0 && !visited[index-1])
        {
            visited[index-1]=1;
            qq[1-toggle].push(index-1);
        }
        //now enqueue the other reachable indices..
        digit=str[index]-'0';
        while(!indices[digit].empty())
        {
            x=indices[digit].front();
            indices[digit].pop();
            if(!visited[x])
            qq[1-toggle].push(x);
        }
    }
    dist++;
    toggle=1-toggle;
}
return 0;
}
