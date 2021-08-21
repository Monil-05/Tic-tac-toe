#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
int checkwin();
void board();
struct node 
{
    char list[2];                        
    struct node *nextptr;           
}*head;

void createNodeList(int n);    

int main()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("Welcome to TIC - TAC - TOE Game\nPlease Enter the number of your choice to place your mark");
  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	FILE *fptr;
    fptr = fopen("D:\\result.txt","w");
    if(fptr == NULL)
    {
       printf("Error!");   
       exit(1);             
    }
    int n=9, list[9],j=0;
    createNodeList(n);
    int player = 1, i, choice;
    char mark;
    do
    {
    	board();
        player = (player % 2==1) ? 1 : 2;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
        printf("Player %d turn : ", player);
  		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        scanf("%d", &choice);
        Beep(500,500);
        mark = (player == 1) ? 'X' : 'O' ;
        struct node *tmp;
        tmp = head;
    	while(tmp != NULL)
   		{
   			int s=0;
   			if(choice<1 || choice>9){
        		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
   				printf("Invalid Move!!!");
  				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
   				player--;
   				break;
			   }
			for(int f=0;f<j+1;f++){
				if(choice==list[f]){
        			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
					printf("Invalid Move!!!");
  					SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
					player--;
					s+=1;
					break;
				}
			}
			if(s>0){
				break;
			}
       		if(tmp->list[0]==choice){
				tmp->list[1]=mark;
				list[j]=choice;
				fprintf(fptr,"Player %d move = ",player);
    			fprintf(fptr,"%d\n",choice);
				j++;
				break;	
			}
			else{
				tmp=tmp->nextptr;
			}
		}
		i=checkwin();
		player++;
	}
	while(i==-1);
	board();
	if (i == 1){
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
        printf("\a==>Player %d has won!!!!!\n", --player);
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    	fprintf(fptr,"\n=>Winner = Player %d !!!!!",player);
    }
    else{
    	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE);
    	printf("==>\aGame draw!!!!!");
    	fprintf(fptr,"\n=>Game Draw !!!!!");
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
    fclose(fptr);
    Beep(1000,1000);
}
void createNodeList(int n)
{
    struct node *fnNode, *tmp;
    char list[2];
	int i;
    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL) 
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        list[0]=1;
        list[1]='1';
        head->list[0] = list[0]; 
		head->list[1] = list[1];     
        head->nextptr = NULL; 
        tmp = head;
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                list[0]=i;
 				list[1]='0' + i;
                fnNode->list[0] = list[0];
				fnNode->list[1] = list[1];
                fnNode->nextptr = NULL; 
 
                tmp->nextptr = fnNode;
                tmp = tmp->nextptr; 
            }
        }
    }
}
int checkwin()
{
	struct node *tmp;
    tmp = head;
    char x;
   	x=tmp->list[1];
   	tmp=tmp->nextptr;
	if(tmp->list[1]==x)
	{
		tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	} 
	tmp=head;
	while(tmp->list[0]!=5){
		tmp=tmp->nextptr;
	}
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	tmp=tmp->nextptr;
	x=tmp->list[1];
	tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	tmp=tmp->nextptr;tmp=tmp->nextptr;
	x=tmp->list[1];
	tmp=tmp->nextptr;tmp=tmp->nextptr;
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	while(tmp->list[0]!=6)
	{
		tmp=tmp->nextptr;
	}
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	tmp=tmp->nextptr;tmp=tmp->nextptr;tmp=tmp->nextptr;
	x=tmp->list[1];
	tmp=tmp->nextptr;
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	while(tmp->list[0]!=7){
		tmp=tmp->nextptr;
	}
	x=tmp->list[1];
	tmp=tmp->nextptr;
	if(tmp->list[1]==x){
		tmp=tmp->nextptr;
		if(tmp->list[1]==x){
			return 1;
		}
	}
	tmp=head;
	int c=0;
	for(int j=1;j<10;j++){
		if(tmp->list[1]!=('0' + j)){
			c+=1;
		}
		tmp=tmp->nextptr;
	}
	if(c==9){
		return 0;
	}
	return -1;
}

void board()
{
	struct node *tmp;
    tmp = head;
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("\n\n\tTic Tac Toe\n\n");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
  	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    printf("     |     |     \n");
    printf("  %c  |  ", tmp->list[1]);tmp=tmp->nextptr;printf("%c  |",tmp->list[1]);tmp=tmp->nextptr;printf("  %c\n",tmp->list[1]);tmp=tmp->nextptr;
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  ", tmp->list[1]);tmp=tmp->nextptr;printf("%c  |",tmp->list[1]);tmp=tmp->nextptr;printf("  %c\n",tmp->list[1]);tmp=tmp->nextptr;
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  ", tmp->list[1]);tmp=tmp->nextptr;printf("%c  |",tmp->list[1]);tmp=tmp->nextptr;printf("  %c\n",tmp->list[1]);tmp=tmp->nextptr;
    printf("     |     |     \n\n");
}
