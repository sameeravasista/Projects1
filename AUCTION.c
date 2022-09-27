//-------------AUCTION---------------//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define stack_size 25 //max number of stacks

int usern;//number of bidders
int bidding[stack_size][stack_size]; //stacks used to conduct bidding
int nxt_player=0;//used change stacks for different players
int top[stack_size];//used as the top of stack for differnt player stacks
int tbids[stack_size];//calculating total bids for a player
int roundbid=3;//to check bids in a round
int front=0;//front of the queue
int rear=0;//rear of the queue
int play=0;//to move to next player after bidding is complete
int turn=0;//to give the turn to the next player
int currbid;//handles the current bid of the player



char players[10][10];//list of players being auctioned
int bprice[10];//base price of the players
char bidq[3][10];//queue used for bidding process order
char temp[1][20];//used to change order
int choice;

//---------------------FUNCTIONS-------------------------//

void auction();
void choice1(int a);
void change();

//---------------structure-to-store-details--------------//

struct user
{
    char bidder[4][20];//names of bidders
    int purse[4];//bidders purse
    int sprice[10];//selling price of the players
    char solduser[2][10];//bidders and the players bought by them
}player;

//---------------------PLAYER NAMES---------------------//

char players[10][10]={
    "B. Kumar",
    "M.S.Dhoni",
    "V. Kohli",
    "R.Sharma",
    "H.Pandya",
    "Y.Chahal",
    "R.Jadeja",
    "K.L.Rahul",
    "K. Yadav",
    "S . Iyer"
};

//------------intializing base price--------------------//

int bprice[10]={ 200, 200, 200, 200, 200, 200, 200, 200, 200, 200,};

//--------------------AUCTION---------------------------//

void auction()
{
    printf("ENTER 1 to bid and 0 to not\n");
    while(play!=10)
    {
        printf("PLAYER No.%d going into the auction is:\n%s\t%d",play+1,players[play],bprice[play]);
        while(roundbid>1)
        {
            roundbid=0;
            printf("%s--->",player.bidder[turn]);
            scanf("%d",&choice);
            choice1(choice);
            printf("%s--->",player.bidder[turn]);
            scanf("%d",&choice);
            choice1(choice);
            printf("%s--->",player.bidder[turn]);
            scanf("%d",&choice);
            choice1(choice);
        }

    }
}

//-----------------------PROCESSING BID---------------------//

void choice1(int a)
{
    if(a==1)
    {
        tbids[play]++;
        printf("--bid-->");
        scanf("%d",&currbid);
        if(currbid<bidding[play][top[play]] || currbid<bprice[play])
        {
            printf("WRONG BID NEXT PLAYER");
            turn++;
            change();
        }
        else
        {
            top[play]++;
            bidding[play][top[play]]=currbid;
            turn++;roundbid++;
            change();
        }
    }
    if(a==0)
    {
        printf("--pass-->");
        turn++;
        change();
    }
    else
    {
        printf("WRONG CHOICE NEXT PLAYER");
        turn++;
        change();
    }
}

//-----------------------CHANGE ORDER OF QUEUE--------------------------//

void change()
{
    strcpy(temp[1],bidq[front]);
    for(int i=front;i>0;i--)
    {
        strcpy(bidq[i],bidq[i-1]);
    }
    strcpy(bidq[rear],temp[1]);
}









//---------------------------MAIN FUNCTION---------------------------//

int main()
{
    printf("WELCOME TO THE AUCTION.1.0\n");
    printf("ENTER THE NUMBER OF USERS:");
    scanf("%d",&usern);
    printf("Enter BIDDER names\n");
    for(int i=0;i<usern;i++)//taking names of bidders
    {
        scanf("%s",player.bidder[i]);
    }
    for(int i=0;i<usern;i++)//
    {
        player.purse[i]=10000;
    }
    for(int i=0;i<usern;i++)//adding names of bidders to order queue
    {
        strcpy(bidq[i],player.bidder[i]);
        front++;
    }
    for(int i=0;i<stack_size;i++)
    {
        top[i]=-1;
        tbids[i]=0;
    }
    printf("THE PLAYERS LIST:\n");
    printf("PLAYER\t\tBASE_PRICE(LAKH)\n");
    for(int i=0;i<10;i++)
    {
        printf("%s\t%d\n",players+i,bprice[i]);
    }
    printf("THE AUCTION BEGINS......\n");
    printf("THE BIDDERS and their PURSE is:\n");
    for(int i=0;i<usern;i++)
    {
        scanf("%s\t%d\n",bidq[i],player.purse[i]);
    }
    auction();

    return 0;    
}