#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct reservation
{
    char name[25];
    int age;
    int pno;
    int tno;
    char gen;
    char st1[20], st2[20];
    char berth[20];
    struct reservation *next;
};

typedef struct reservation node;
node *head = NULL;

int count, n, tno, trno;
int a[15][4];
node *create()
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->next = NULL;
    return new;
}
void train()
{
    printf("\t\t\t\t1--->BENGALURU TO RANCHI EXPRESS\n");
    printf("\t\t\t\t2--->BENGALURU TO AGRA EXPRESS\n");
    printf("\t\t\t\t3.--->BENGALURU TO PATNA EXPRESS\n");
    printf("\t\t\t\t4--->BENGALURU TO MAHARASTRA EXPRESS\n");
    printf("\t\t\t\t5--->BENGALURU TO RAJASTHAN EXPRESS\n");
    printf("\t\t\t\t6--->BENGALURU TO SATNA EXPRESS\n");

    printf("ENTER THE TRAIN YOU WANT\n");
    scanf("%d", &trno);
}

void reserve()
{
    node *new1, *temp = head;
    int i=1;

    train();
    new1 = create();

    printf("ENTER PASSENGER DETAIL\n");
    printf("NAME:");
    scanf("%s", new1->name);
    printf("\nENTER THE GENDER: ");
    scanf("%s", &new1->gen);
    printf("\nENTER THE AGE: ");
    scanf("%d", &new1->age);
    printf("\nENTER THE PHONE NO.: ");
    scanf("%d", &new1->pno);


    if (trno == 1)
        printf("PAY Rs 1800\n");

    else if (trno == 2)
        printf("PAY Rs 2000\n");

    else if (trno == 3)
        printf("PAY Rs 2300\n");

    else if (trno == 4)
        printf("PAY Rs 1200\n");

    else if (trno == 5)
        printf("PAY Rs 1900\n");

    else if (trno == 6)
        printf("PAY Rs 1500\n");

    if (head == NULL)
    {
        head = new1;
        count = 1;
        new1->tno = count;
       

        printf("\t\t\t\t\tBOOKING SUCCESSFULL\n");
        printf("\t\t\t\t\tYOUR SEAT NO. IS %d\n", count);


        return ;
    }

    while (temp->next!=NULL)
    {

        temp = temp->next;
    }
    temp->next = new1;
    temp->tno = count++;
   // a[i]="temp->name";
   // i++;



    printf("YOUR SEAT NO. IS %d\n", count);
    if(trno == 1)
        strcpy(new1->st2, "RANCHI");

    else if (trno == 2)
        strcpy(new1->st2, "AGRA");

    else if (trno == 3)
        strcpy(new1->st2, "PATNA");

    else if (trno == 4)
        strcpy(new1->st2, "MAHARASTRA");

    else if (trno == 5)
        strcpy(new1->st2, "RAJASTHAN");

    else if (trno == 6)
        strcpy(new1->st2, "SATNA");

}
void display()
{
    node *temp = head, *prev = temp;
    int no;

    printf("enter the ticket id\n");
    scanf("%d", &no);

    if (head == NULL)
    {
        printf("seat is not reserved\n");
        return;
    }

    while (temp != NULL)
    {
        if (no == temp->tno)
            break;

        temp = temp->next;
    }
    printf("\t\t=================================================\n");
    printf("\t\t|                                               \n");
    printf("\t\t|        -----------------------------          \n");
    printf("\t\t|                TRAIN TICKET                   \n");
    printf("\t\t|        -----------------------------          \n");
    printf("\t\t|                                               \n");
    printf("\t\t|      NAME: %s                                 \n", temp->name);
    printf("\t\t|      AGE: %d                                  \n", temp->age);
    printf("\t\t|      PHONE NO.: %d                            \n", temp->pno);
    printf("\t\t|      DESTINATION: %s                           \n", temp->st2);
    printf("\t\t=================================================\n\n\n");
}
void seat()
{
    printf("SEAT MATRIX:\n");
    printf("\t           -:SEAT MATRIX:-        \n");
    printf("\t(U)    (M)        (L)    (L)    "
           "    (U)\n\n");
    printf("\t01    02        03\t04        "
           "05\n\n");
    printf("\t06    07        08\t09        "
           "10\n");
    printf("\t11    12        13\t14        "
           "15\n\n");
    printf("\t16    17        18\t19        "
           "20\n");
    printf("\t21    22        23\t24        "
           "25\n\n");
    printf("\t26    27        28\t29        "
           "30\n");
    printf("\t31    32        33\t34        "
           "35\n\n");
    printf("\t36    37        38\t39        "
           "40\n");
    printf("\t41    42        43\t44        "
           "45\n\n");
    printf("\t46    47        48\t49        "
           "50\n");
    printf("\t51    52        53\t54        "
           "55\n\n");
    printf("\t56    57        58\t59        "
           "60\n");
}

void delete ()
{
    node *p;
    node *prev;
    int t;
    if (head == NULL)
    {
        printf("No Entry to be deleted \n");
    }
    else
    {
        printf("Enter the ticket no. : ");
        scanf("%d", &t);
        p = head;
        prev = p;
        while (p != NULL)
        {
            if (p->tno == t)
            {
                prev->next = p->next;
                printf("\t\t\t the deleted ticket no . %d  and person'name : %s\n\n", p->tno, p->name);
                printf("\t\t\tYOUR MONEY WILL BE REFUNDED IN 2-3 DAYS\n");
                free(p);
                return;
            }
            prev = p;
            p = p->next;
        }
        printf("\t\t\t the ticket no. is does not exist. \n");
    }
}

void main()
{
    int ch,i,j;

   
    


    while (1)
    {
        printf("====================================== WELCOME TO RAILWAY RESERVATION SYSTEM ======================================\n\n\n");
        printf("\t\t\t\t\t[1]=> Book Tickets\n");
        printf("\n");
        printf("\t\t\t\t\t[2]=> Cancel Booking\n");
        printf("\n");
        printf("\t\t\t\t\t[3]=> seat status\n");
        printf("\n");
        printf("\t\t\t\t\t[4]=> train Status Board\n");
        printf("\n");
        printf("\t\t\t\t\t[5]=> Exit\n\n");
        printf("===============================================================================================================\n\n");
        printf("ENTER THE CHOICE\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            reserve();
            break;

        case 2:
            delete ();
            break;

        case 3:
            seat();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            break;
        }
    }
}