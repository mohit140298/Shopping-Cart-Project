#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

void login();
void welcome();

COORD c={0,0};

void gotoxy(int x,int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
	
}


int z=0;
int c1=0;
void front()
{
	 int i;

	for(i=4;i<=39;i++)
	{
	  gotoxy(40,i);
	  printf("%c",36);
	  Sleep(2);
	  gotoxy(110,i);
	  printf("%c",36);
	  Sleep(2);
        }
for(i=40;i<=110;i++)
{
  gotoxy(i,4);
  printf("%c ",36);
  Sleep(2);
  gotoxy(i,39);
  printf("%c",36);
  Sleep(2);
	  
		
	}
	
}

void small_front()
{
    	 int i;

	for(i=8;i<=26;i++)
	{
	  gotoxy(40,i);
	  printf("%c",36);
	  Sleep(1);
	  gotoxy(110,i);
	  printf("%c",36);
	  Sleep(1);
}
for(i=40;i<=110;i++)
{
  gotoxy(i,8);
  printf("%c ",36);
  Sleep(1);
  gotoxy(i,26);
  printf("%c",36);
  Sleep(1);
	  
		
	}
	
}	

struct cart
{
 int id;
 char name[20]; 
 int price;
 struct cart *next;
};

cart *top=NULL,*top1=NULL,*newnode,*temp2,*temp1,*temp,*prev;

 void print(struct cart *top)
 {
 	 int i=6;
 	temp=top;
 	 gotoxy(45,i);
   printf("ID");
   gotoxy(50,i);
   printf("Name");
   gotoxy(60,i);
   printf("Price");
 	while(temp!=NULL)
 	{
	
  	
   gotoxy(45,i+3);
   printf("%d ",temp->id);
  gotoxy(50,i+3);
   printf("%s ",temp->name);
  gotoxy(60,i+3);
  printf("%d",temp->price);
  temp=temp->next;
  i=i+3;
 }
}
 void menu()
 {
 	 gotoxy(45,8);
   printf("ID");
   gotoxy(63,8);
   printf("Name");
   gotoxy(78,8);
   printf("Price");
   gotoxy(45,12);
   printf("1");
   gotoxy(63,12);
   printf("t-shirt");
   gotoxy(78,12);
   printf("300");
   gotoxy(45,18);
   printf("2");
   gotoxy(63,18);
   printf("Watch");
   gotoxy(78,18);
   printf("1100");
   
   gotoxy(45,24);
   printf("3");
   gotoxy(63,24);
   printf("shirt");
   gotoxy(78,24);
   printf("500");
   gotoxy(45,30);
   printf("4");
   gotoxy(63,30);
   printf("Chinos");
   gotoxy(78,30);
   printf("700");
   gotoxy(45,36);
   printf("5");
   gotoxy(63,36);
   printf("jeans");
   gotoxy(78,36);
   printf("800");
   
 }
 void del(int ch)
 {
  temp=top;
  if(top==NULL)
  {
  	system("cls");
  	small_front();
  	gotoxy(45,18);
  	printf("Cart Is Empty");
  	gotoxy(45,28);
  	exit(0);
					  
					  }
					
  	

  if(top->id==ch)
  {
   top=top->next;
   free(temp);
  }
  else
  {
   while(temp->id!=ch)
   {
    prev=temp;
    temp=temp->next;
   }
    prev->next=temp->next;
    free(temp);
  }
   
 }
 int total=0;
 
 
 void buy(int x)
 {
 	 int idy;
 char l[50];
 int p;
 FILE *fp3;
 fp3=fopen("input.txt","r");
 while(1)
 {
  fscanf(fp3,"%d",&idy);
  fscanf(fp3,"%s",l);
  fscanf(fp3,"%d",&p);
  
  if(idy==x)
  { 
   newnode=(struct cart *)malloc(sizeof(struct cart));
   newnode->id=idy;
   strcpy(newnode->name,l);
   newnode->price=p;
   z=z+p;
   if(top1==NULL)
   { 
    	newnode->next=NULL;
   	top1=newnode;
    	break;
   }
   
   else
   {
    	newnode->next=top1;
    	top1=newnode;
   	break;
   
   }
   } 
    
  }
   
  
   fclose(fp3);
 }
 
 
 
 void add(int ch)
{
	int a;
	/*if(ch>5){
	
	system("cls");
	small_front();
	gotoxy(45,18);
	printf("you entered a wrong id");
	gotoxy(45,25);
	exit(0);
}*/
					  
					       	
				     
 int idy;
 char l[50];
 int p;
 FILE *fp2;
 fp2=fopen("input.txt","r");
 while(1)
 {
  fscanf(fp2,"%d",&idy);
  fscanf(fp2,"%s",l);
  fscanf(fp2,"%d",&p);
  
  if(idy==ch)
  { 
   newnode=(struct cart *)malloc(sizeof(struct cart));
   newnode->id=idy;
   strcpy(newnode->name,l);
   newnode->price=p;
   total=total+p;
   if(top==NULL)
   { 
    	newnode->next=NULL;
   	top=newnode;
    	break;
   }
   
   else
   {
    	newnode->next=top;
    	top=newnode;
   	break;
   
   }
   } 
    
  }
   
  
   fclose(fp2);
   system("cls");
   
    gotoxy(43,10);
   printf("you added:");
   gotoxy(45,15);
   printf("%d",newnode->id);
   gotoxy(55,15);
   printf("%s",newnode->name);
   gotoxy(65,15);
   printf("%d",newnode->price);
 }
 
 void choice()
 {
 	  int i;
 	 gotoxy(45,12);
         printf("1.VIEW CART");
         gotoxy(70,12);
  printf("2.VIEW ITEMS");
  gotoxy(45,20);
  printf("3.ADD ITEM");
  gotoxy(70,20);
  printf("4.DELETE ITEM");
  gotoxy(45,28);
  printf("5.MyOrders");
  gotoxy(70,28);
  printf("6.EXIT");
 }
 /*void small_choice()
 {
    	 gotoxy(13,12);
  printf("1.VIEW CART");
  gotoxy(28,12);
  printf("2.VIEW ITEMS");
  gotoxy(13,20);
  printf("3.ADD ITEM");
  gotoxy(28,20);
  printf("4.DELETE ITEM");
  gotoxy(13,28);
  printf("5.ADDED ITEMS");
  gotoxy(28,28);
  printf("6.EXIT");	
 }*/
 
 /*void small_choice_front()
 {
 	 int i;

	for(i=8;i<=26;i++)
	{
	  gotoxy(10,i);
	  printf("%c",219);
	  gotoxy(35,i);
	  printf("%c",219);
}
for(i=10;i<=35;i++)
{
  gotoxy(i,8);
  printf("%c ",219);
  gotoxy(i,26);
  printf("%c",219);
	  
		
	}
		 
 }*/
 void big_front()
 {
 		 int i;

	for(i=4;i<=50;i++)
	{
	  gotoxy(40,i);
	  printf("%c",36);
	  gotoxy(110,i);
	  printf("%c",36);
}
for(i=40;i<=110;i++)
{
  gotoxy(i,4);
  printf("%c ",36);
  gotoxy(i,50);
  printf("%c",36);
	  
		
	}
	
}
 int quantity=0;
 int v=0;






int main()
{
	
	int q[10];
	 int w;
	 int h;
	 int a;
	 int c=0;
	 int i;
	 int p=0;
	 //small_front();
	 while(v<1){
	 
	 gotoxy(45,22);
	 printf("loading.....");
	 for(i=0;i<10;i++){
	  gotoxy(58,22);
	  printf("%d %%",p);
	  Beep(700,500);
	  p=p+10;}
	  
	  system("cls");
        	
	 login();}
    system("cls");	 
   front();
   choice();
  gotoxy(45,34);
  printf("enter your choice");
  scanf("%d",&w);
  system("cls");
  /*while(1)
  {
     small_choice_front();
     small_choice();
     gotoxy(14,34);
  printf("enter your choice");
  scanf("%d",&w);*/
  
  switch(w)
  {
   case 1:
   	
   if(top==NULL)
   {
   	small_front();
   gotoxy(60,16);
   printf("Sorry,no items in cart");
   gotoxy(45,22);
   printf("1.main menu:- ");
   scanf("%d",&a);
   system("cls");
   if(a==1)
   {
   	main();
   }
   else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
   gotoxy(30,1);}
   else
   {
      front();
      print(top);
      gotoxy(45,32);
      printf("Cart Total:");
      gotoxy(57,32);
      printf("%d",total);
      gotoxy(65,32);
      printf("Total Quantity :");
      gotoxy(82,32);
      printf("%d",quantity);
      gotoxy(45,34);
   printf("1.main menu:- ");
   scanf("%d",&a);
   system("cls");
   if(a==1)
   {
   	main();
   }
   else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
   gotoxy(30,1);
  }
   
   break;

   case 2:
   	big_front();
        menu();
        gotoxy(45,39);
        printf("1.buy now");
        gotoxy(45,42);
        printf("2.add to cart");
        gotoxy(45,45);
        printf("3.main menu");
        gotoxy(45,48);
        printf("enter your choice");
        scanf("%d",&a);
        system("cls");
        switch(a)
        {
        	case 1:
        	small_front();
		gotoxy(45,15);
		printf("1.enter the id of product:-");
		gotoxy(45,20);
		printf("2.main menu");
		gotoxy(45,25);
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			system("cls");
			small_front();
			gotoxy(45,15);
			printf("enter id here:");
			gotoxy(58,15);
			scanf("%d",&a);
			buy(a);
			
			/*gotoxy(45,17);
			printf("enter the no of pieces of product:");
			gotoxy(80,17);
			scanf("%d",&q[z]);
			z++;*/
			switch(a)
			{
				case 1:
				system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for tshirt has been placed");
				gotoxy(45,18);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
                               break;
                               
                               case 2:
                               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("watch is a nice choice ");
				gotoxy(70,15);
				printf("order has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,23);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
                               break;
                     
                             case 3:
                             	system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for shirt has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
				break;
					
		               case 4:
		               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for chinos has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
		               	break;
		               	
		               	case 5:
		               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("you choose a nice jeans");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
			       break;
			       
			       default:
			       	system("cls");
			       	small_front();
			       	gotoxy(45,22);
			       	printf("1. main menu");
			       	scanf("%d",&a);
			       	if(a==1){
				       
			       	system("cls");
			       	main();}
			       	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
			       	break;
			       	
		             }
		             gotoxy(30,1);
		       break;
		       
		       case 2:
		       	system("cls");
		       main();
		       break;
		       default:
		       	system("cls");
		       	small_front();
		       	gotoxy(45,20);
		       	printf("you entered a invalid number");
		       	gotoxy(42,24);
		       	printf("1.go back");
		       	gotoxy(55,24);
		       	printf("2.main menu");
		       	scanf("%d",&a);
		       	system("cls");
		       	switch(a)
		       	{
		       		case 1:
		       			
		       		small_front();
		gotoxy(45,15);
		printf("1.enter the id of product:-");
		gotoxy(45,20);
		printf("2.main menu");
		gotoxy(45,25);
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			system("cls");
			small_front();
			gotoxy(45,15);
			printf("enter here:");
			gotoxy(58,15);
			scanf("%d",&a);
			switch(a)
			{
				case 1:
				system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for tshirt has been placed");
				gotoxy(45,18);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
                               break;
                               
                               case 2:
                               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("watch is a nice choice ");
				gotoxy(70,15);
				printf("order has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,23);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
                               break;
                     
                             case 3:
                             	system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for shirt has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
				break;
					
		               case 4:
		               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("order for chinos has been placed");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
		               	break;
		               	
		               	case 5:
		               	system("cls");
				small_front();
				gotoxy(45,15);
				printf("you choose a nice jeans");
				gotoxy(45,20);
				printf("thank you");
				gotoxy(45,22);
				printf("1.main menu");
				scanf("%d",&a);
				system("cls");
				if(a==1)
                                {
   	                            main();
                                }
                                else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
                               gotoxy(30,1);
			       break;
			       
			       default:
			       	system("cls");
			       	small_front();
			       	gotoxy(45,22);
			       	printf("1. main menu");
			       	scanf("%d",&a);
			       	if(a==1){
				       
			       	system("cls");
			       	main();}
			       	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
			       	break;
		             }
		     
		             break;
		             
		             case 2:
		             	system("cls");
		             main();
		             break;
		             
		             default:
		             system("cls");
		             	small_front();
		             	gotoxy(45,22);
		             	printf("1.main menu");
		             	scanf("%d",&a);
		             	if(a==1){
				     
		             	system("cls");
		             	main();}
		             	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
		             	break;
			}
		}
			       break;
		               
			          	
	               }
   gotoxy(30,1);
   break;
                                 case 2:
                                 	do{
					 
			       system("cls");
			        front();
                                menu();
                                
				c++;
                            gotoxy(25,3);
                            if(c>1)
                            printf("you entered a wrong id please re-enter:");
                            else{
			    
     printf("Enter the id of the product u wish to add to cart");}
     
                        scanf("%d",&h);
                }while(h>5);
                         add(h);
                         quantity++;
                        	gotoxy(45,22);
		             	printf("1.main menu");
		             	scanf("%d",&a);
		             	if(a==1){
				     
		             	system("cls");
		             	main();}
		             	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
		     break;
		     case 3:
		     	system("cls");
		     	main();
		     	break;
		     	
		     	default:
		     	system("cls");
		     	small_front();
		     	gotoxy(45,16);
		     	printf("invalid entry");
		     	gotoxy(45,22);
		     	printf("1 Main Menu");
		     	scanf("%d",&a);
			     break;	
		     gotoxy(30,1);
}
gotoxy(30,1);
break;

   case 3:
   front();
   menu();
   gotoxy(25,3);
   printf("Enter the id of the product u wish to add to cart");
   scanf("%d",&h);
   add(h);
   quantity++;
   gotoxy(45,22);
		             	printf("1.main menu");
		             	scanf("%d",&a);
		             	if(a==1){
				     
		             	system("cls");
		             	main();}
		             	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
   
   gotoxy(30,1);
   break;

   case 4:
    small_front();
    gotoxy(45,12);
   printf("Enter the id of the product u wish to delete");
   scanf("%d",&h);
   del(h);
   system("cls");
   small_front();
   gotoxy(45,20);
   printf("1.main menu");
		             	scanf("%d",&a);
		             	if(a==1){
				     
		             	system("cls");
		             	main();}
		             	else{
		             	        system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("invlid entry");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
					  
					  }
					       	
				     }
   
   break;

   case 5:
   front();
   print(top1);	
   /*gotoxy(70,6);
   printf("quantity");
   c=9;
   for(i=0;i<z;i++){
   	
   gotoxy(70,c);
   c=c+3;
   printf("%d",q[i]);}*/
    gotoxy(45,32);
      printf("Your Total:");
      gotoxy(57,32);
      printf("%d",z);
      gotoxy(57,34);
      printf("1. Main Menu");
       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	  system("cls");
                                        small_front();
                                        gotoxy(45,15);
                                        printf("last chance");
                                        gotoxy(45,20);
                                       printf("1.main menu");
		             	       scanf("%d",&a);
		                       	if(a==1){
					       
		                  	system("cls");
		             	          main();}
					  else{
					  	
					  	system("cls");
					  	small_front();
					  	gotoxy(45,18);
					  	printf("you failed");
					  	gotoxy(45,28);
					  	exit(0);
					  }
				}
   gotoxy(30,40);
   break;
   
   case 6:
   exit(0);
   break;
   default:
   	main();
   	
   	break;
  }
 





	return 0;
}


void welcome()
{     
         int d;
	small_front();
	gotoxy(59,10);
	printf("Welcome");
	Sleep(1000);
	gotoxy(55,12);
	printf("To  The Shopping Cart");
	Sleep(1000);
	gotoxy(55,15);
	printf("Project Made By");
	Sleep(1000);
	gotoxy(55,17);
	printf("Mohit,Saurav");
	Sleep(1000);
	gotoxy(55,19);
	printf("Mithun,Deepak");
	Sleep(1000);
	gotoxy(45,23);
	printf("1.Main Menu");
	Sleep(2000);
	gotoxy(59,23);
	printf("2.Exit");
	gotoxy(69,23);
	scanf("%d",&d);
	switch(d)
	{
		case 1:
		system("cls");
		v++;
		main();
		break;
		
		case 2:
		system("cls");
		exit(0);
		break;
			
		default:
		system("cls");
		gotoxy(42,9);
		printf("invalid entry");
		welcome();
		break;	
	}
	
	
}

void login()
{
	int id;
	int psd;
	//small_front();
	gotoxy(55,8);
	printf("LOGIN");
	gotoxy(50,12);
	printf("enter the user Id:-");
	scanf("%d",&id);
	gotoxy(50,14);
	printf("enter the password:-");

	scanf("%d",&psd);
	if(id==12345 && psd==12345)
	{
		system("cls");
		//small_front();
		
		welcome();
		gotoxy(30,10);
		
	}
	else
	{
		system("cls");
		gotoxy(45,10);
		printf("invalid credentials");
		login();
		gotoxy(30,38);
	}
	getch();
}
