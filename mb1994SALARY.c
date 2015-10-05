long long int total=0;
long long int thru=0;
#include<stdio.h>
#include<stdlib.h>
#define white 0
#define black 1
#include<ctype.h>
#define gc getchar_unlocked
inline int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
struct linked_rooms
{
	long long int adjacent_room;
	struct linked_rooms* next_adjacent_room;
};
typedef struct linked_rooms linked_rooms;
struct room
{
	long long int open;
	long long int color;
	linked_rooms *head;
	linked_rooms* tail;
};
typedef struct room room;
inline int dfs(room* r, int i);
void main_DFS(room *r, int n);
inline void add_neighbour(room *r1,int r2)
{
	linked_rooms  *head=r1->head,*temp,*thead;
		temp=(linked_rooms*)malloc(sizeof(linked_rooms));
		temp->adjacent_room=r2;
		temp->next_adjacent_room=NULL;
		r1->tail->next_adjacent_room=temp;
		r1->tail=temp;
}
int main()
{
	int n,m,i,p1,p2,ans2,x1;
	//scanf("%lld%lld",&n,&m);
	n=read_int();
	m=read_int();
	room rooms[n+1];
	//status statusRooms[n+1];
	for(i=1;i<n+1;i++)
	{
		//scanf("%lld",&rooms[i].open);
		rooms[i].open=read_int();
		rooms[i].head=NULL;
		rooms[i].color=white;
		/*statusRooms[i].parent=i;
		statusRooms[i].open=rooms[i].open;
		statusRooms[i].visited=0;*/
	}
	while(m--)
	{
		//scanf("%lld%lld",&p1,&p2);
		p1=read_int();p2=read_int();
		if(!rooms[p1].head)
		{
		rooms[p1].head=(linked_rooms*)malloc(sizeof(linked_rooms));
		rooms[p1].head->adjacent_room=p2;
		rooms[p1].head->next_adjacent_room=NULL;
		rooms[p1].tail=rooms[p1].head;
		}
		else add_neighbour(&rooms[p1],p2);		//while adding i will also check if both are open.
		if(!rooms[p2].head)
		{
		rooms[p2].head=(linked_rooms*)malloc(sizeof(linked_rooms));
		rooms[p2].head->adjacent_room=p1;
		rooms[p2].head->next_adjacent_room=NULL;
		rooms[p2].tail=rooms[p2].head;
		}
		else
		add_neighbour(&rooms[p2],p1);
	}
		main_DFS(rooms, n);
		printf("%lld %lld\n",total,thru);
		return 0;
}
void main_DFS(room *r, int n)
{
	int i;
	long long int count=0;
	for(i=1;i<=n;i++)
	{
		if(r[i].open==1&&r[i].color==white)
		{
			//r[i].drot=r[i].open +
			count=dfs(r,i);
			if(count==1)thru--;
			total+=count*(count-1)/2;
		}
	}
}
inline int dfs(room* r, int i)
{
	int next;int count=0;
	linked_rooms *head;
	r[i].color=black;
	count+=r[i].open;
	head=r[i].head;
	while(head!=NULL)
	{
		next=head->adjacent_room;
		if(r[next].color==white)
			count+=dfs(r,next);
		head=head->next_adjacent_room;
	}
	if(count>0)thru++;
	return count;
}
