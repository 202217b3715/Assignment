#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100
 
/*Now let's define all the required functions to create a list, inserting into the list, deleting an element from the list, search and display the list
*/
 
void create();
void insert();
void deletion();
void search();
void display();
 
int a, b[20], n, p, e, f, i, pos;
 
void main()
{
    //clrscr();
    int ch;
    char g = 'y';
    do
    {
        printf("\n Main Menu");
        printf("\n 1.Create \n 2.Insert \n 3.Delete \n 4.Search \n 5.Display \n 6.Exit \n");
        printf("\n  Enter your choice");
        scanf("%d", &ch);
 
        /*Now the below switch statement will call the appropriate operation function and perform that*/
 
        switch(ch)
        {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                deletion();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
 
            default:
                printf(" \n Enter the correct choice: ");
 
        }
        printf("\n Do you want to continue:::");
        scanf("\n%c", &g);
 
    }while(g == 'y' || g == 'Y');
 
}
 
 
 
void create()
{
    printf("\n Enter the number of nodes: ");
    scanf("%d", &n);
    //lets run the for loop for n iterations
    for(int i = 0; i<n; i++)
    {
        printf("\n Enter the element %d", i+1);
        scanf("%d", &b[i]);
    }
}
 
 
 
void deletion()
{
    printf("\n Enter the position u want to delete::");
    scanf("%d", &pos);
 
    if(pos>=n)
    {
        printf("\n Invalid Location::");
    }
    else
    {
        for(i=pos+1;i<n;i++)
        {
            b[i-1]=b[i];
        }n--;
    }
    printf("\n The Elements after deletion");
 
    for(i=0;i<n;i++)
    {
        printf("\t%d", b[i]);
    }
}
 
 
void search()
{
    printf("\n Enter the Element to be searched:");
    scanf("%d", &e);
    for(i=0;i<n;i++)
    {
        if(b[i]==e)
        {
            printf("Value is in the %d Position", i);
        }
        else
        {
            printf("Value %d is not in the list::", e);
            continue;
        }
    }
}
 
 
 
void insert()
{
    printf("\n Enter the position u need to insert::");
    scanf("%d", &pos);
    if(pos>=n)
    {
        printf("\n invalid Location::");
    }
    else
    {
        for(i=MAX-1;i>=pos-1;i--)
        {
            b[i+1]=b[i];
        }
        printf("\n Enter the element to insert::\n");
        scanf("%d",&p);
        b[pos]=p;
        n++;
    }
    printf("\n The list after insertion::\n");
    display();
}
 
 
void display()
{
    printf("\n The Elements of The list ADT are:");
    for(i=0;i<n;i++)
    {
        printf("\n\n%d", b[i]);
    }
}
