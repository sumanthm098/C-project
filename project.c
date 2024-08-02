#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<unistd.h>
#include<stdlib.h>
FILE *BD;
struct signup
{
    char name[30];
    long long int mno;
    char pass[10];
}s;
struct login
{
    char name[30];
    char pass[10];
}l;
struct book
{
    char name[30];
    long long int pno;
    char add[30];
    char model[30];
}b;
void S_password()
{
    char c;
    int i=0;
    while(1)
    {
        c=getch();
        if(c==13)
        {
            s.pass[i]='\0';
            break;
        }
        else if(c==8)
        {
            if(i>0)
            {
                i--;
                printf("\b\b");
            }
        }
        else if(c==9||c==32)
            continue;
        else{
            s.pass[i]=c;
            printf("*");
            i++;
        }
    }
}
void L_password()
{
    char c;
    int i=0;
   while(1)
    {
        c=getch();
        if(c==13)
        {
            l.pass[i]='\0';
            break;
        }
        else if(c==8)
        {
            if(i>0)
            {
                --i;
                printf("\b\b");
            }
        }
        else if(c==9||c==32)
            continue;
        else{
            l.pass[i]=c;
            printf("*");
            i++;
        }
    }
}
void invoice(char a[30],long long int b,char c[50],char d[30])
{
                                                system("cls");
                                                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                                                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                                                printf("\n\n\t\t\t\t\tCustomer Invoice\n\t\t\t\t\t-----------------\n\n");
                                                printf("\t\t _________________________________________________________\n");
                                                printf("\t\t|                                                         |\n");
                                                printf("\t\t|          ****** Invoice from Dream Bikes ******         |\n");
                                                printf("\t\t|_________________________________________________________|\n");
                                                printf("\t\t|                                                         |\n");
                                                printf("\t\t|   Date : %s                  Time : %s   |\n\n",__DATE__,__TIME__);
                                                printf("\t\t    Customer Name  : %s                  \n\n",a);
                                                printf("\t\t    Phone Number   : %lld                  \n\n",b);
                                                printf("\t\t    Address        : %s                    \n\n",c);
                                                printf("\t\t    Bike Model     : %s\n\n",d);
                                                printf("\t\t|   Payment Status : Paid (Rs.10,000/-)                   |\n");
                                                printf("\t\t|_________________________________________________________|\n");

                                                BD=fopen("Buyer_Details.csv","a");
                                                fprintf(BD,"%s,%lld,%s,%s,%s,%s\n",a,b,c,d,__DATE__,__TIME__);
                                                fclose(BD);

                                                printf("\n\tYou can proceed the remaining payment after receiving the bike to your address.");
}
void buyer_details()
{
                                        system("cls");
                                        printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                                        printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");
                                        printf("\n\n\t\t\t\t\t    Buyer Form\n\t\t\t\t\t    ----------");
                                        fflush(stdin);
                                        printf("\n\n\tEnter the name          : ");
                                        gets(b.name);
                                        printf("\n\tEnter the mobile number : ");
                                        scanf("%lld",&b.pno);
                                        fflush(stdin);
                                        printf("\n\tEnter the address       : ");
                                        gets(b.add);
                                        printf("\n\n\tPress any key to continue...");
                                        getch();
}
void payment()
{
    printf("\n\tPlease wait we are checking the payment\n\n");
    char loading[15]={'L','o','a','d','i','n','g','.','.','.','.','.','.'};

    for(int i=0;i<3;i++)
    {
    printf("\r             \r");
    for(int j=0;j<=12;j++)
    {
        printf("%c",loading[j]);
        usleep(190000);
    }
    }
    printf("\n\n\t***** Payment Successfull *****");
}
int main()
{
    system("color 0E");
    char t;
    int sno=0;
    char buy;
    char *name,*pass;
    FILE *sp;
    menu:
    system("cls");
    printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
    printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");
    printf("\n\n\n\n\t   Menu\n\t   ----\n");
    printf("\t1) Sign-up\n\t2) Login\n\t3) Exit");
    printf("\n\n\tChoose an option to continue :");
    scanf(" %c",&t);
    switch(t)
    {
        case '1':   system("cls");
                    printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                    printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");
                    printf("\n\n\t\tSign-up\n\t\t-------\n");
                sp=fopen("signup.csv","a");
                if(sp == NULL)
                {
                    printf("File is Null\n");
                    fprintf(sp,"Name,Pno.Number,Password");
                }
                    printf("\tEnter the name : ");
                    fflush(stdin);
                    gets(s.name);
                    printf("\n\tEnter the phone number : ");
                    scanf("%lld",&s.mno);
                    printf("\n\tEnter the password : ");
                    S_password();
                    fprintf(sp,"%s,%lld,%s,\n",s.name,s.mno,s.pass);
                    fclose(sp);
                printf("\n\n\t********** Sign-up Successfull **********\n\n");
                printf("\tPress 1 to Login.....");
                scanf(" %c",&t);
                if(t=='1')
                    goto Login;
                else
                    goto menu;
                break;
        case '2': Login:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");
                printf("\n\n\t\tLogin\n\t\t-----\n");
                printf("\n\tEnter your name      :");
                fflush(stdin);
                gets(l.name);
                printf("\tEnter your password  :");
                L_password();

                int buffer[1000];
                sp = fopen("signup.csv","r");
                if(sp == NULL)
                {
                    perror("Error opening file");
                    return 1;
                }
                while(fgets(buffer,sizeof(buffer),sp)!=NULL)
                {
                    name=strtok(buffer,",");
                    pass=strtok(NULL,",");
                    pass=strtok(NULL,",");
                    if(strcmp(name,l.name)==0 && strcmp(pass,l.pass)==0)
                       {
                           break;
                       }
                }
                fclose(sp);
                if(strcmp(name,l.name)==0 && strcmp(pass,l.pass)==0)
                {
                    goto home;
                }
                else
                {
                    printf("\n\n\tIncorrect username or password.........!\n\n\tNew User? press 1 : ");
                    scanf("%c",&t);
                    if(t=='1')
                        goto menu;
                    else
                        goto Login;
                }


                break;
        case '3': exit(1);
        default:printf("\n\tIncorrect option......! try again..\n");
                goto menu;
    }
    home:
        system("cls");
        printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
        printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");
        printf("\n\n\t***** Top Brands *****\n");
        printf("\n\t1) Royal Enfield\t4) Hero\n\t2) Kawasaki\t\t5) Honda\n\t3) BMW\t\t\t6) Suziki\n\n");
        printf("\tPlease select your Brand : ");
        scanf(" %c",&t);
        switch(t)
        {
        case '1':
                RE:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t******* Selected Royal Enfield *******");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\n\tSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': re_sp:
                            printf("\n\t***** Sport *****\n");
                            printf("\n\t1) Himalayan 450\n\t2) Scram 411\n\t3) Himalayan\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': H450:
                                    strcpy(b.model,"Himalayan 450");
                                    printf("\n\t***** Selected Himalayan 450 *****\n");
                                    printf("\n\tPrice          : 2.85 - 2.98 Lakh");
                                    printf("\n\tEngine         : 452 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 17 Liters");
                                    printf("\n\tWeight         : 196 kg");
                                    printf("\n\tTyre Type      : Tube");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(298000.0/12),(298000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                            buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);

                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': Sc411:
                                    strcpy(b.model,"Scram 411");
                                    printf("\n\t***** Selected Scram 411 *****\n");
                                    printf("\n\tPrice          : 2.06 - 2.11 Lakh");
                                    printf("\n\tEngine         : 411 cc");
                                    printf("\n\tMileage        : 35.11 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 185 kg");
                                    printf("\n\tTyre Type      : Tube");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(211000.0/12),(211000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();

                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': H411:
                                    strcpy(b.model,"Himalayan");
                                    printf("\n\t***** Selected Himalayan *****\n");
                                    printf("\n\tPrice          : 2.06 - 2.11 Lakh");
                                    printf("\n\tEngine         : 411 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 199 kg");
                                    printf("\n\tTyre Type      : Tube");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(211000.0/12),(211000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();

                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto re_sp;
                            }break;
                    case '2': re_cruz:
                            strcpy(b.model,"Classic 350");
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) Classic 350\n\t2) Hunter 350\n\t3) Meteor 350\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': c350:
                                    printf("\n\t***** Selected Classic 350 *****\n");
                                    printf("\n\tPrice          : 1.93 - 2.24 Lakh");
                                    printf("\n\tEngine         : 349 cc");
                                    printf("\n\tMileage        : 37.77 Kmpl");
                                    printf("\n\tFuel Capacity  : 13 Liters");
                                    printf("\n\tWeight         : 195 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(224000.0/12),(224000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': H350:
                                    strcpy(b.model,"Hunter 350");
                                    printf("\n\t***** Selected Hunter 350 *****\n");
                                    printf("\n\tPrice          : 1.49 - 1.74 Lakh");
                                    printf("\n\tEngine         : 349 cc");
                                    printf("\n\tMileage        : 36.2 Kmpl");
                                    printf("\n\tFuel Capacity  : 13 Liters");
                                    printf("\n\tWeight         : 181 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(174000.0/12),(174000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);

                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': M350:
                                    strcpy(b.model,"Meteor 350");
                                    printf("\n\t***** Selected Meteor 350 *****\n");
                                    printf("\n\tPrice          : 2.05 - 2.29 Lakh");
                                    printf("\n\tEngine         : 349 cc");
                                    printf("\n\tMileage        : 41.88 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 191 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(229000.0/12),(229000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto RE;
                                    else if(buy=='S'||buy=='s')
                                        goto re_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto re_cruz;
                            }
                }
                break;
        case '2':
                Ka:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t***** Selected Kawasaki *****");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\nSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': k_sp:
                            printf("\n\t***** Sports *****\n");
                            printf("\n\t1) Ninja ZX-4R\n\t2) Ninja 500\n\t3) Ninja 650\n\t4) Ninja H2 SX\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': zx:
                                    strcpy(b.model,"Ninja ZX-4R");
                                    printf("\n\t***** Selected Ninja ZX-4R *****\n");
                                    printf("\n\tPrice          : 8.49 - 9.10 Lakh");
                                    printf("\n\tEngine         : 399 cc");
                                    printf("\n\tMileage        : 23 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 189 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(910000.0/12),(910000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': n500:
                                strcpy(b.model,"Ninja 500");
                                    printf("\n\t***** Selected Ninja 500 *****\n");
                                    printf("\n\tPrice          : 5.24 Lakh");
                                    printf("\n\tEngine         : 451 cc");
                                    printf("\n\tMileage        : 23 Kmpl");
                                    printf("\n\tFuel Capacity  : 14 Liters");
                                    printf("\n\tWeight         : 171 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(524000.0/12),(524000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': n650:
                                    strcpy(b.model,"Ninja 650");
                                    printf("\n\t***** Selected Ninja 650 *****\n");
                                    printf("\n\tPrice          : 7.16 Lakh");
                                    printf("\n\tEngine         : 649 cc");
                                    printf("\n\tMileage        : 21 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 196 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(716000.0/12),(716000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': H2:
                                    strcpy(b.model,"Ninja H2 SX");
                                    printf("\n\t***** Selected Ninja H2 SX *****\n");
                                    printf("\n\tPrice          : 31.95 - 32.95 Lakh");
                                    printf("\n\tEngine         : 998 cc");
                                    printf("\n\tMileage        : 18 Kmpl");
                                    printf("\n\tFuel Capacity  : 19 Liters");
                                    printf("\n\tWeight         : 191 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(3295000.0/12),(3295000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto k_sp;
                            }break;
                    case '2': k_cruz:
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) Vulcan\n\t2) Eliminator\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': vu:
                                    strcpy(b.model,"Vulcan");
                                    printf("\n\t***** Selected Vulcan *****\n");
                                    printf("\n\tPrice          : 7.10 Lakh");
                                    printf("\n\tEngine         : 649 cc");
                                    printf("\n\tMileage        : 24.37 Kmpl");
                                    printf("\n\tFuel Capacity  : 14 Liters");
                                    printf("\n\tWeight         : 235 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(710000.0/12),(710000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': el:
                                strcpy(b.model,"Eliminator");
                                    printf("\n\t***** Selected Eliminator *****\n");
                                    printf("\n\tPrice          : 5.62 Lakh");
                                    printf("\n\tEngine         : 451 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 13 Liters");
                                    printf("\n\tWeight         : 176 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(562000.0/12),(562000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto Ka;
                                    else if(buy=='S'||buy=='s')
                                        goto k_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto k_cruz;
                            }
                }break;
        case '3':
                bmw:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t***** Selected BMW *****");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\nSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': bmw_sp:
                            printf("\n\t***** Sports *****\n");
                            printf("\n\t1) G 310 RR\n\t2) M 1000 RR\n\t3) M 1000 XR\n\t4) S 1000 R\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': g310:
                                    strcpy(b.model,"G 310 RR");
                                    printf("\n\t***** Selected G 310 RR *****\n");
                                    printf("\n\tPrice          : 3.05 Lakh");
                                    printf("\n\tEngine         : 3313 cc");
                                    printf("\n\tMileage        : 30.3 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 174 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(305000.0/12),(305000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': m1000r:
                                strcpy(b.name,"M 1000 RR");
                                    printf("\n\t***** Selected M 1000 RR *****\n");
                                    printf("\n\tPrice          : 42 - 45 Lakh");
                                    printf("\n\tEngine         : 999 cc");
                                    printf("\n\tMileage        : 15.4 Kmpl");
                                    printf("\n\tFuel Capacity  : 16.5 Liters");
                                    printf("\n\tWeight         : 192 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(4500000.0/12),(4500000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': m1000:
                                strcpy(b.model,"M 1000 XR");
                                    printf("\n\t***** Selected M 1000 XR *****\n");
                                    printf("\n\tPrice          : 45 Lakh");
                                    printf("\n\tEngine         : 999 cc");
                                    printf("\n\tMileage        : 15 Kmpl");
                                    printf("\n\tFuel Capacity  : 20 Liters");
                                    printf("\n\tWeight         : 223 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(450000.0/12),(450000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': s1000:
                                    strcpy(b.model,"S 1000 R");
                                    printf("\n\t***** Selected S 1000 R *****\n");
                                    printf("\n\tPrice          : 19 - 23.30 Lakh");
                                    printf("\n\tEngine         : 999 cc");
                                    printf("\n\tMileage        : 16.1 Kmpl");
                                    printf("\n\tFuel Capacity  : 16.5 Liters");
                                    printf("\n\tWeight         : 194 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(233000.0/12),(233000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto bmw_sp;
                            }break;
                    case '2': bmw_cruz:
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) R 12 NineT\n\t2) R 12\n\t3) R 18 Transcontinental");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': r129:
                                    strcpy(b.model,"R 12 NineT");
                                    printf("\n\t***** Selected R 12 NineT *****\n");
                                    printf("\n\tPrice          : 20.90 Lakh");
                                    printf("\n\tEngine         : 1170 cc");
                                    printf("\n\tMileage        : 18 Kmpl");
                                    printf("\n\tFuel Capacity  : 16 Liters");
                                    printf("\n\tWeight         : 220 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(209000.0/12),(209000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': r12:
                                    strcpy(b.model,"R 12");
                                    printf("\n\t***** Selected R 12 *****\n");
                                    printf("\n\tPrice          : 19.90 Lakh");
                                    printf("\n\tEngine         : 1170 cc");
                                    printf("\n\tMileage        : 18.5 Kmpl");
                                    printf("\n\tFuel Capacity  : 14 Liters");
                                    printf("\n\tWeight         : 227 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(199000.0/12),(199000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': r18:
                                    strcpy(b.model,"R 18 Transcontinental");
                                    printf("\n\t***** Selected R 18 Transcontinental *****\n");
                                    printf("\n\tPrice          : 32.50 Lakh");
                                    printf("\n\tEngine         : 1802 cc");
                                    printf("\n\tMileage        : 17.21 Kmpl");
                                    printf("\n\tFuel Capacity  : 24 Liters");
                                    printf("\n\tWeight         : 427 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(3250000.0/12),(3250000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto bmw;
                                    else if(buy=='S'||buy=='s')
                                        goto bmw_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto bmw_cruz;
                            }
                }break;
        case '4':
                hero:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t***** Selected Hero *****");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\nSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': hero_sp:
                            printf("\n\t***** Sports *****\n");
                            printf("\n\t1) XPulse 200 4V\n\t2) Xtreme 125R\n\t3) Karizma XMR\n\t4) Xtreme 160R 4V\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': xpulse:
                                    strcpy(b.model,"XPulse 200 4V");
                                    printf("\n\t***** Selected XPulse 200 4V *****\n");
                                    printf("\n\tPrice          : 1.45 - 1.53 Lakh");
                                    printf("\n\tEngine         : 199 cc");
                                    printf("\n\tMileage        : 42.28 Kmpl");
                                    printf("\n\tFuel Capacity  : 13 Liters");
                                    printf("\n\tWeight         : 161 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(153000.0/12),(153000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto hero;
                                    else if(buy=='S'||buy=='s')
                                        goto hero_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': x125R:
                                    strcpy(b.model,"Xtreme 125R");
                                    printf("\n\t***** Selected Xtreme 125R *****\n");
                                    printf("\n\tPrice          : 0.97 - 1.02 Lakh");
                                    printf("\n\tEngine         : 124 cc");
                                    printf("\n\tMileage        : 66 Kmpl");
                                    printf("\n\tFuel Capacity  : 10 Liters");
                                    printf("\n\tWeight         : 136 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(102000.0/12),(102000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto hero;
                                    else if(buy=='S'||buy=='s')
                                        goto hero_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();
                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': xmr:
                                    strcpy(b.model,"Karizma XMR");
                                    printf("\n\t***** Selected Karizma XMR *****\n");
                                    printf("\n\tPrice          : 1.79 Lakh");
                                    printf("\n\tEngine         : 210 cc");
                                    printf("\n\tMileage        : 41.55 Kmpl");
                                    printf("\n\tFuel Capacity  : 11 Liters");
                                    printf("\n\tWeight         : 163.5 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(179000.0/12),(179000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto hero;
                                    else if(buy=='S'||buy=='s')
                                        goto hero_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();
                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': x160:
                                    strcpy(b.model,"Xtreme 160R 4V");
                                    printf("\n\t***** Selected Xtreme 160R 4V *****\n");
                                    printf("\n\tPrice          : 1.29 - 1.38 Lakh");
                                    printf("\n\tEngine         : 163 cc");
                                    printf("\n\tMileage        : 48.28 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 145 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(138000.0/12),(138000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto hero;
                                    else if(buy=='S'||buy=='s')
                                        goto hero_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto hero_sp;
                            }break;
                    case '2': hero_cruz:
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) Mavrick 440\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': m440:
                                    strcpy(b.model,"Mavrick 440");
                                    printf("\n\t***** Selected Mavrick 440 *****\n");
                                    printf("\n\tPrice          : 1.99 - 2.24 Lakh");
                                    printf("\n\tEngine         : 440 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 13.5 Liters");
                                    printf("\n\tWeight         : 187 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(224000.0/12),(224000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto hero;
                                    else if(buy=='S'||buy=='s')
                                        goto hero_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto hero_cruz;
                            }
                }break;
        case '5':
                honda:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t***** Selected Honda *****");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\nSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': honda_sp:
                            printf("\n\t***** Sports *****\n");
                            printf("\n\t1) Hornet 2.0\n\t2) CB300R\n\t3) CB300F\n\t4) CRF1100L Africa Twin\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': hornet:
                                    strcpy(b.model,"Hornet 2.0");
                                    printf("\n\t***** Selected Hornet 2.0 *****\n");
                                    printf("\n\tPrice          : 1.39 - 1.40 Lakh");
                                    printf("\n\tEngine         : 184 cc");
                                    printf("\n\tMileage        : 55.77 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 142 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(140000.0/12),(140000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': cb300r:
                                    strcpy(b.model,"CB 300R");
                                    printf("\n\t***** Selected CB300R *****\n");
                                    printf("\n\tPrice          : 2.40 Lakh");
                                    printf("\n\tEngine         : 286 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 9.7 Liters");
                                    printf("\n\tWeight         : 146 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(240000.0/12),(240000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': cb300f:
                                    strcpy(b.model,"CB 300F");
                                    printf("\n\t***** Selected CB300F *****\n");
                                    printf("\n\tPrice          : 1.70 Lakh");
                                    printf("\n\tEngine         : 293 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 14.1 Liters");
                                    printf("\n\tWeight         : 153 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(170000.0/12),(170000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': crf:
                                    strcpy(b.name,"CRF110L Africa Twin");
                                    printf("\n\t***** Selected CRF1100L Africa Twin *****\n");
                                    printf("\n\tPrice          : 16.01 - 17.55 Lakh");
                                    printf("\n\tEngine         : 1082 cc");
                                    printf("\n\tMileage        : 20 Kmpl");
                                    printf("\n\tFuel Capacity  : 24.5 Liters");
                                    printf("\n\tWeight         : 249 kg");
                                    printf("\n\tTyre Type      : Tube");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(1755000.0/12),(1755000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto honda_sp;
                            }break;
                    case '2': honda_cruz:
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) Hness CB350\n\t2) CB350\n\t3) CB350RS\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': hness:
                                strcpy(b.model,"Hness CB350");
                                    printf("\n\t***** Selected Hness CB350 *****\n");
                                    printf("\n\tPrice          : 7.10 Lakh");
                                    printf("\n\tEngine         : 649 cc");
                                    printf("\n\tMileage        : 24.37 Kmpl");
                                    printf("\n\tFuel Capacity  : 14 Liters");
                                    printf("\n\tWeight         : 235 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(710000.0/12),(710000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': cb350:
                                    strcpy(b.model,"CB 350");
                                    printf("\n\t***** Selected CB350 *****\n");
                                    printf("\n\tPrice          : 2.14 - 2.17 Lakh");
                                    printf("\n\tEngine         : 348 cc");
                                    printf("\n\tMileage        : 42.17 Kmpl");
                                    printf("\n\tFuel Capacity  : 15.2 Liters");
                                    printf("\n\tWeight         : 176 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(217000.0/12),(217000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': cb350rs:
                                    strcpy(b.model,"CB 350RS");
                                    printf("\n\t***** Selected CB350RS *****\n");
                                    printf("\n\tPrice          : 2.14 - 2.19 Lakh");
                                    printf("\n\tEngine         : 348 cc");
                                    printf("\n\tMileage        : 35 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 179 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(219000.0/12),(219000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto honda;
                                    else if(buy=='S'||buy=='s')
                                        goto honda_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto k_cruz;
                            }
                }break;
        case '6':
                suzuki:
                system("cls");
                printf("\n\t\t\t\t\t\t             \\\n\t\t\t\t\t\t       \\_____/\\\n\t\t\t\t\t\t      _//   \\\\_\n\t\t\t\t\t\t     (o)     (o)");
                printf("\n\t\t\t\t*************** Welcome to Dream Bikes ***************");

                printf("\n\n\t\t\t\t***** Suzuki *****");
                printf("\n\n\t***** Categories *****\n");
                printf("\n\t1) Sports\n\t2) Cruzer\n");
                printf("\nSelect the Category : ");
                scanf(" %c",&t);
                switch(t)
                {
                    case '1': suzuki_sp:
                            printf("\n\t***** Sports *****\n");
                            printf("\n\t1) Hayabusa\n\t2) Katana\n\t3) Gixxer SF 250\n\t4) Gixxer SF 150\n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': hayabusa:
                                    strcpy(b.model,"Hayabusa");
                                    printf("\n\t***** Selected Hayabusa *****\n");
                                    printf("\n\tPrice          : 13.82 - 17.70 Lakh");
                                    printf("\n\tEngine         : 1340 cc");
                                    printf("\n\tMileage        : 17 Kmpl");
                                    printf("\n\tFuel Capacity  : 15 Liters");
                                    printf("\n\tWeight         : 266 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(1382000.0/12),(1382000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': katana:
                                    strcpy(b.model,"Katana");
                                    printf("\n\t***** Selected Katana *****\n");
                                    printf("\n\tPrice          : 13.61 Lakh");
                                    printf("\n\tEngine         : 999 cc");
                                    printf("\n\tMileage        : 23 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 217 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(1361000.0/12),(1361000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': sf250:
                                    strcpy(b.model,"Gixxer SF 250");
                                    printf("\n\t***** Selected Gixxer SF 250 *****\n");
                                    printf("\n\tPrice          : 1.95 - 2.08 Lakh");
                                    printf("\n\tEngine         : 249 cc");
                                    printf("\n\tMileage        : 38 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 161 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(208000.0/12),(208000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': sf150:
                                    strcpy(b.model,"Gixxer SF 150");
                                    printf("\n\t***** Selected Gixxer SF 150 *****\n");
                                    printf("\n\tPrice          : 1.40 - 1.48 Lakh");
                                    printf("\n\tEngine         : 155 cc");
                                    printf("\n\tMileage        : 45 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 148 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(148000.0/12),(148000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_sp;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto suzuki_sp;
                            }break;
                    case '2': suzuki_cruz:
                            printf("\n\t***** Cruser *****\n");
                            printf("\n\t1) Gixxer 150\n\t2) V-Strome SX\n\t3) Gixxer 250\n\t4) V-Strom 800 DE \n");
                            printf("\n\tPlease select your bike for more details : ");
                            scanf(" %c",&t);
                            switch(t)
                            {
                            case '1': gix150:

                                    printf("\n\t***** Selected Gixxer 150 *****\n");
                                    printf("\n\tPrice          : 1.37 - 1.43 Lakh");
                                    printf("\n\tEngine         : 155 cc");
                                    printf("\n\tMileage        : 45 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 141 kg");
                                    printf("\n\tTyre Type      : Tubeless");
                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(143000.0/12),(143000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '2': vstrom:
                                    printf("\n\t***** Selected V-Strome SX *****\n");
                                    printf("\n\tPrice          : 2.14 Lakh");
                                    printf("\n\tEngine         : 249 cc");
                                    printf("\n\tMileage        : 32 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 167 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(214000.0/12),(214000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '3': gix250:
                                    printf("\n\t***** Selected Gixxer 250 *****\n");
                                    printf("\n\tPrice          : 1.84 - 2.01 Lakh");
                                    printf("\n\tEngine         : 249 cc");
                                    printf("\n\tMileage        : 38 Kmpl");
                                    printf("\n\tFuel Capacity  : 12 Liters");
                                    printf("\n\tWeight         : 156 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(201000.0/12),(201000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();

                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            case '4': vstrom800:
                                    printf("\n\t***** Selected V-Strom 800 DE *****\n");
                                    printf("\n\tPrice          : 10.30 Lakh");
                                    printf("\n\tEngine         : 776 cc");
                                    printf("\n\tMileage        : 30 Kmpl");
                                    printf("\n\tFuel Capacity  : 20 Liters");
                                    printf("\n\tWeight         : 232 kg");
                                    printf("\n\tTyre Type      : Tubeless");

                                    printf("\n\n\tIf you want to check the EMI details press Y/y : ");
                                    scanf(" %c",&buy);
                                    if(buy=='Y'||buy=='y')
                                    {
                                        printf("\n\n\t    12 months\t\t    24 months\n\t    ---------\t\t    ---------\n\tRs.%.2f/month \tRs.%.2f/month",(1030000.0/12),(1030000.0/24));
                                    }
                                    printf("\n\n\tIf you want to book the bike press Y/y (or) press C/c to change category or press S/s for other bike : ");
                                    scanf(" %c",&buy);
                                    if(buy=='C'||buy=='c')
                                        goto suzuki;
                                    else if(buy=='S'||buy=='s')
                                        goto suzuki_cruz;
                                    else if(buy=='Y'|| buy=='y')
                                    {
                                        buyer_details();
                                            printf("\n\n\t*** To book the bike you have to pay the down payment of Rs.10,000/- ***");
                                            printf("\n\n\tAre you ready to pay ? press Y/y : ");
                                            scanf(" %c",&buy);
                                        if(buy=='Y'|| buy=='y')
                                        {
                                            printf("\n\n\n\tPay the down payment to the below Number to book your bike\n");
                                            printf("\n\t\t\tPh.no :- 9874563218\n\t\t\tName  :-Dream Bikes");

                                            printf("\n\n\tIf you pay the amount press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                            {
                                                payment();
                                                printf("\n\n\tPress any key to download the invoice.....");
                                                getch();

                                                invoice(b.name,b.pno,b.add,b.model);
                                                printf("\n\n\t if you want to search another bike press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                            else
                                            {
                                                printf("\n\n\tIf you want to select other brand press 1 : ");
                                                scanf(" %c",&t);
                                                if(t=='1')
                                                    goto home;
                                                else
                                                    printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                            }
                                        }
                                        else
                                        {
                                            printf("\n\n\tIf you want to select other brand press 1 : ");
                                            scanf(" %c",&t);
                                            if(t=='1')
                                                goto home;
                                            else
                                                printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                        }
                                    }
                                    else
                                    {
                                        printf("\n\n\tIf you want to select other brand press 1 : ");
                                        scanf(" %c",&t);
                                        if(t=='1')
                                            goto home;
                                        else
                                            printf("\n\n\n\t\t*************** Thank You Visit Again ***************");
                                    }
                                    break;
                            default:printf("\n\n\tinvalid option.....!try again...");
                                    goto suzuki_cruz;
                            }
                }
        }
        return 0;
}
