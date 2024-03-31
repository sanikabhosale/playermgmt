#include<stdio.h>
#include<string.h>
int ctr=0;   //maintain the track the player in array
typedef struct Player{
	int jno;
	char name[30];
	int N_matches;
	int N_runs;
	int N_wicket;
}Player;
void hardcode(Player*);
void storeData(Player*,int);
void displayData(Player*);
void searchPlayer(Player*);
int searchPlayerByJno(Player*,int);
int searchPlayerByName(Player*);
void deletePlayer(Player*);
void updatePlayer(Player*);
int updateMatch(Player*);
int updateWicket(Player*);
int updateRuns(Player*);
void sortPlayer(Player*);
void sortByMatche(Player*);
void sortByRuns(Player*);
void sortByWicket(Player*);
void displayData1(Player*,int);
void topsort(Player* p);
void topMatche(Player*,int);
void topRuns(Player*,int);
void topWicket(Player*,int);
void main()
{
	Player p[20];
	int ch;	
	hardcode(p);
	do{
		printf("***MAIN MENU****");
		printf("\n1.add player data\n2.display player information\n3.search player");
		printf("\n4.delete player data");
		printf("\n5.update player data");
		printf("\n6.sort player data");
		printf("\n7.top player data");
		printf("\n0 exit:");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				storeData(p,20);
				break;
			case 2:
				displayData(p);
				break;
			case 3:
				searchPlayer(p);
				break;
			case 4:
				deletePlayer(p);
				break;
			case 5:
				updatePlayer(p);
				break;
			case 6:
				sortPlayer(p);
				break;
			case 7:
				topsort(p);
				
				break;
		}
	}while(ch!=0);
		
}
void hardcode(Player* p) //esay to check function working 
{   
    char name[30]="kunal";
	p[0].jno=1;
	strcpy(p[0].name,name);
	p[0].N_matches=5;
	p[0].N_runs=200;
	p[0].N_wicket=20;
	ctr++;
	char name1[25]="ram";
	p[1].jno=2;
	strcpy(p[1].name,name1);
	p[1].N_matches=7;
	p[1].N_runs=500;
	p[1].N_wicket=4;
    ctr++;
    char name3[25]="DS";
	p[2].jno=3;
	strcpy(p[2].name,name3);
	p[2].N_matches=5;
	p[2].N_runs=400;
	p[2].N_wicket=0;
    ctr++;
    char name4[25]="MS";
	p[3].jno=4;
	strcpy(p[3].name,name4);
	p[3].N_matches=7;
	p[3].N_runs=1500;
	p[3].N_wicket=8;
    ctr++;
}
void storeData(Player* p,int size)
{
	if(ctr<=size)
	{
		printf("enter player jersey no:");
		scanf("%d",&p[ctr].jno);
		printf("Enter Player Name:");
		scanf("%s",p[ctr].name);
		printf("Enter No.matches:");
		scanf("%d",&p[ctr].N_matches);
		printf("Enter No.runs:");
		scanf("%d",&p[ctr].N_runs);
		printf("Enter No.Wickets:");
		scanf("%d",&p[ctr].N_wicket);
		ctr++;
	}
	else
		printf("array is full");

}
void displayData(Player* p)
{
	int i;
    printf("---------------------------------------------------------------------------\n");
	printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
    printf("---------------------------------------------------------------------------\n");
	for(i=0;i<ctr;i++)
	{
	printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[i].jno,p[i].name,p[i].N_matches,p[i].N_runs,p[i].N_wicket);
	
    }
}
void searchPlayer(Player* p)//two way of searching 
{
	int search;
	int sj,sn,s;
	
	do{
		printf("\n-1.search by jersey No\n-2.search by Name\n-3.Main Menu\n");
		scanf("%d",&search);
		switch(search)
		{
			case 1:
				printf("enter search player no=");
	            scanf("%d",&s);
				sj=searchPlayerByJno(p,s);
				if(sj==-1)
				{
				 	printf("player not faund\n");
				}
				else
				{
				   printf("---------------------------------------------------------------------------\n");
	               printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
                   printf("---------------------------------------------------------------------------\n");
		           printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[sj].jno,p[sj].name,p[sj].N_matches,p[sj].N_runs,p[sj].N_wicket);
			    }
				break;
			case 2:
				sn=searchPlayerByName(p);
				if(sn==-1)
				{
				 	printf("player not faund\n");
				}
				else
				{
				   printf("---------------------------------------------------------------------------\n");
	               printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
                   printf("---------------------------------------------------------------------------\n");
		           printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[sn].jno,p[sn].name,p[sn].N_matches,p[sn].N_runs,p[sn].N_wicket);
			    }
				break;
			default:
				printf("Envalid choice");
		

		}
		
	}while(search!=3);
	
}
int searchPlayerByJno(Player* p,int s)
{
	//int s;
   // printf("enter search player no=");
	//scanf("%d",&s);
	int i=0,f=0;
	for(i=0;i<ctr;i++)
	{
		if(p[i].jno==s)
		{
			return i;
		}			
	}
	return -1;
	
}
int searchPlayerByName(Player* p)
{
	int i=0;
	char n[20];
	printf("enter search player name=");
	scanf("%s",&n);
	for(i=0;i<ctr;i++)
	{
		if(strcmp(p[i].name,n)==0)
		{
		 return i;		
		}
	}
	return -1;
	
}
void  deletePlayer(Player* p)
{
	int i,n,f=0;
	printf("enter delete player jersey no:");
	scanf("%d",&n);
	for(i=0;i<ctr;i++)
	{
		if(p[i].jno==n)
		{    
		    f=1;
			p[i]=p[i+1];
			printf("player deleted successfully..\n");
	    }
	    else if(f==1)
	    {
	    	p[i]=p[i+1];
	    	
		}
	} 
	ctr=ctr-1; 
	if(f==0)
	{
		printf("player not faund\n");
	} 
	displayData(p);   
}
void updatePlayer(Player* p)
{
	int update;
	int um,ur,uw;
	
	do{
		printf("\n-1.upadate matches\n-2.update runs\n-3.update wickets\n-4.Main Menu\n");
		scanf("%d",&update);
		switch(update)
		{
			case 1:
				um=updateMatch(p);
				if(um==-1)
					printf("player not faund\n");
				else
				{
					printf("updated successfully...\n");
		            printf("---------------------------------------------------------------------------\n");
	                printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
                    printf("---------------------------------------------------------------------------\n");
		            printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[um].jno,p[um].name,p[um].N_matches,p[um].N_runs,p[um].N_wicket);
				}
				break;
			case 2:
				ur=updateRuns(p);
				if(ur==-1)
					printf("player not faund\n");
				else
				{
					printf("updated successfully...\n");
		            printf("---------------------------------------------------------------------------\n");
	                printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
                    printf("---------------------------------------------------------------------------\n");
		            printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[ur].jno,p[ur].name,p[ur].N_matches,p[ur].N_runs,p[ur].N_wicket);
				}
				break;
			case 3:
				uw=updateWicket(p);
				if(um==-1)
					printf("player not faund\n");
				else
				{
					printf("updated successfully...\n");
		            printf("---------------------------------------------------------------------------\n");
	                printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
                    printf("---------------------------------------------------------------------------\n");
		            printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[uw].jno,p[uw].name,p[uw].N_matches,p[uw].N_runs,p[uw].N_wicket);
				}
				break;
			default:
				printf("Envalid choice");
		

		}
		
	}while(update!=4);
	
}
int updateMatch(Player* p)
{
	int i,jn,mt,f=0;
	printf("enter player jersey no you want update:");
	scanf("%d",&jn);
	for(i=0;i<ctr;i++)
	{
		if(p[i].jno==jn)
		{
		  f=1;
		 printf("enter updated matches:");
	     scanf("%d",&mt);
		 p[i].N_matches=p[i].N_matches+mt;
		 return i;	
		}			
	}
	if(f==0)
		return -1;
	 	
}
int updateRuns(Player* p)
{
	int i,n,rn,f=0;
	printf("enter player jersey no you want update:");
	scanf("%d",&n);
	for(i=0;i<ctr;i++)
	{
		if(p[i].jno==n)
		{
			f=1;
		printf("enter updated runs:");
		scanf("%d",&rn);
		 p[i].N_runs=p[i].N_runs+rn;
		 return i;	 	
		}			
	}
	if(f==0)
	{
	  return -1;	
	}  
	
}
int updateWicket(Player* p)
{
	int i,n,w,f=0;
	printf("enter player jersey no you want update:");
	scanf("%d",&n);
	for(i=0;i<ctr;i++)
	{
		if(p[i].jno==n)
		{
		 f=1;
		 printf("enter updated Wicket:");
		 scanf("%d",&w);
		 p[i].N_wicket=p[i].N_wicket+w;
			return i;			
		}			
	}
	if(f==0)
	{
		return -1;
	}  
	
}
void sortPlayer(Player* p)
{
	int sort;
	do{
		printf("\n-1.sort by matches\n-2.sort by runs\n-3.sort by wickets\n-4.Main Menu\n");
		scanf("%d",&sort);
		switch(sort)
		{
			case 1:
				sortByMatche(p);
				break;
			case 2:
				sortByRuns(p);
				break;
			case 3:
				sortByWicket(p);
				break;

		}
		
	}while(sort!=4);
}
void sortByMatche(Player* p)
{
	Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	
	int i,j;
	for(i=0;i<ctr;i++)
	{

		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_matches)<(p1[j].N_matches))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
			 
			}
		}
		
	}
	displayData(p1);
	
}
void sortByRuns(Player* p)
{	
	Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	int i,j;
	for(i=0;i<ctr;i++)
	{
		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_runs)<(p1[j].N_runs))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
				
			}
		}
    }
		
	displayData(p1);
	
}
void sortByWicket(Player* p)
	
{

    Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	int i,j;
	for(i=0;i<ctr;i++)
	{
		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_wicket)<(p1[j].N_wicket))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
			 
			}
		}	
	}
	displayData(p1);	
}

//top 3
void topsort(Player* p)
{
	int sort;
	int top;
	do{
		printf("\n-1.top in matches\n-2.Top in runs\n-3.top in wickets\n-4.Main Menu\n");
		scanf("%d",&sort);
		switch(sort)
		{
			case 1:
				printf("enter top count");
				scanf("%d",&top);
				topMatche(p,top);
				break;
			case 2:
				printf("enter top count");
				scanf("%d",&top);
				topRuns(p,top);
				break;
			case 3:
				printf("enter top count");
				scanf("%d",&top);
				topWicket(p,top);
				break;

		}
		
	}while(sort!=4);
}
void topMatche(Player* p,int top)
{
  Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	
	int i,j;
	for(i=0;i<ctr;i++)
	{

		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_matches)<(p1[j].N_matches))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
			 
			}
		}
			
	}
	displayData1(p1,top);
	
}
void topRuns(Player* p,int top)
{
    Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	int i,j;
	for(i=0;i<ctr;i++)
	{
		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_runs)<(p1[j].N_runs))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
				
			}
		}
		
	}
	displayData1(p1,top);
	
}
void topWicket(Player* p,int top)
{
    Player p1[ctr];
	int k;
	for(k=0;k<ctr;k++)
	{
		p1[k]=p[k];
	}
	int i,j;
	for(i=0;i<ctr;i++)
	{
		Player temp;
		for(j=i+1;j<ctr;j++)
		{
			if((p1[i].N_wicket)<(p1[j].N_wicket))
			{
				temp=p1[i];
				p1[i]=p1[j];
				p1[j]=temp;
			}
		}
		
	}
	displayData1(p1,top);	
}
void displayData1(Player* p,int top)
{
	int i;
    printf("---------------------------------------------------------------------------\n");
	printf("jersey No|      Player Name     |No.matches     |No.runs        |No.Wickets|\n");
    printf("---------------------------------------------------------------------------\n");
	for(i=0;i<top;i++)
		printf("%-9d|%-9s\t\t|%-5d\t\t|%-5d%\t\t|%-5d\n",p[i].jno,p[i].name,p[i].N_matches,p[i].N_runs,p[i].N_wicket);	
}

