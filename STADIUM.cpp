#include<bits/stdc++.h>
#define start second
#define end first
using namespace std;
pair<int, int> event[100001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&event[i].start, &event[i].end);
        event[i].end+=event[i].start;
        //second is start time...
        //first is end time..
    }
    sort(event, event+n);
    //sorted acc to ending time..
    int ans=0,prev=-1;
    for(int i=0;i<n;i++)
    {
        if(event[i].start>prev)
        {
            prev=event[i].end;
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
