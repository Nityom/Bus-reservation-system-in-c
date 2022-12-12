#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
   char name[50];
   int bus_num;
   int num_of_seats;
}pd;

void reservation();
void viewdetails();
void printticket(char name[],int,int,float);
void specificbus(int);
float charge(int,int);

int main()
{
    system("cls");
printf("\t\t|            BUS TICKET RESERVATION SYSTEM      |\n");
printf("\t\t|                         By NITYOM TIKHE       |\n");
printf("\t\t|                         LIC.MH12345678        |\n");
printf("\t\t-------------------------------------------------\n");
printf("\t\t--------------press any key to continue----------\n");
printf("\t\t-------------------------------------------------\n");
getch();
system("cls");
int menu_choice,choice_return;
start:
system("cls");
printf("\n=====================================\n");
printf("       BUS RESERVATION SYSTEM");
printf("\n=====================================\n");
printf("\n1>> Reseve A Ticket");
printf("\n -------------------------");
printf("\n2>> View All Available Bus");
printf("\n -------------------------");
printf("\n3>> Exit");
printf("\n -------------------------");
printf("\n\n-->");
scanf("%d",&menu_choice);
switch (menu_choice)
{
case 1:
    reservation();
    break;
    case 2: 
    viewdetails();
    printf("\n\nPress any key to go to Main Menu...");
    getch();
    break;
    case 3:
    return 0;
default:
printf("\nInvlid option");
}
goto start;
return 0; 
}

void viewdetails()
{
    system("cls");
    printf("\nBUS.No\tBUS Name\t\tDestinations\t\tfare\t\tTime\n");
    printf("\n533101\tBus A\t\t\tPune to Wardha\t\tRs.1500\t\t7pm");
    printf("\n533102\tBus B\t\t\tWardha to GandhiNagar\tRS.2500\t\t6pm");
    printf("\n533103\tBus C\t\t\tBhadravati to Pune\tRs.1600\t\t8pm");
    printf("\n533104\tBus D\t\t\tMumbai to Pune\t\tRs.1200\t\t5pm");
    printf("\n533105\tBus E\t\t\tLadakh to Pune\t\tRs.8000\t\t9pm");
}
void reservation()
{
    char confirm;
    int i=0;
    float charges;
    pd passdetails;
    FILE *fp;
    fp=fopen("seats_reserved.txt","a");
    system("cls");
     
     printf("\nEnter Your Name :> ");
    fflush(stdin);
    gets(passdetails.name);

     printf("\nEnterNumber of seats:> ");
     scanf("%d",&passdetails.num_of_seats);
      printf("\n\n>>Press enter To View Availabel Bus<< ");
      getch();
      system("cls");
      viewdetails();
      printf("\n\nEnter Bus Number:> ");
      start1:
      scanf("%d",&passdetails.bus_num);
      if (passdetails.bus_num>=533101 && passdetails.bus_num<=533105)
      {
       charges = charge(passdetails.bus_num,passdetails.num_of_seats);
       printticket(passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
       }
      else{
        printf("\nInvalid Bus Number! Enter Again -->");
        goto start1;
      }
     
      printf("\n\nConfirm Ticket (y/n) :>");
      start:
      scanf("%c",&confirm);
      if (confirm == 'y')
      {
        fprintf(fp,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.bus_num,charges);
        printf("==================");
        printf("\n Resevation successful\n");
        printf("==================");
        printf("\nPress any key to go back to Main Menu");
        }
        else{
            if(confirm=='n'){
                printf("\nReservation not done!\n Press any key to go back to main menu!");
              }
             else{
                printf("\n.");
                goto start;
             }   
        }
        fclose(fp);
        getch();
}
   float charge(int bus_num,int num_of_seats)
{
    if(bus_num == 533101)
    {
        return(1500.0*num_of_seats);
    }
    if(bus_num == 5433102)
    {
        return (2500.0*num_of_seats);
        }

      if(bus_num == 5433103)
      {
        return(1600.0*num_of_seats);

      }
      if(bus_num == 533104)
      {
        return(1200.0*num_of_seats);

      }
      if(bus_num == 533105)
      {
        return(8000.0*num_of_seats);
      }
}   
  void printticket(char name[],int num_of_seats,int bus_num,float charges)
  {
    system("cls");
    	printf("-------------------\n");
    printf("\tTICKET\n");
    	printf("-------------------\n\n");
    printf("Name:\t\t\t%s",name);
    printf("\nNumber Of Seats :\t%d",num_of_seats);
    printf("\nBus Number:\t\t%d",bus_num);
    specificbus(bus_num);
    printf("\nCharges:\t\t%.2f",charges);
  } 
   
   void specificbus(int bus_num)
   {
    if (bus_num==533101)
	{
		printf("\nBus:\t\t\tBUS A");
		printf("\nDestination:\t\tPune to Wardha");
		printf("\nDeparture:\t\t7pm ");
	}
	if (bus_num==533102)
	{
		printf("\nBus:\t\t\tBUS B");
		printf("\nDestination:\t\tWardha to GandhiNagar");
		printf("\nDeparture:\t\t6pm");
	}
	if (bus_num==533103)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\tBhadravati to Pune");
		printf("\nDeparture:\t\t8pm");
	}
	if (bus_num==533104)
	{
		printf("\nBus:\t\t\tBUS D");
		printf("\nDestination:\t\tMumbai to Pune");
		printf("\nDeparture:\t\t5pm ");
	}
	if (bus_num==533105)
	{
		printf("\nBus:\t\t\tBUS C");
		printf("\nDestination:\t\tLadakh to Pune");
		printf("\nDeparture:\t\t9pm");
	}
   }
       

    
