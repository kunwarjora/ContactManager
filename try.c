// Status:- Linked list concept used.
// can used as a roll no. manager
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct profile
{
    char number[16];
    char name[20];
    struct profile *next;
} name;

void display(name *start);
name *insert_at_begin(name *start, char data[], char nam[]);
name *insert_at_end(name *start, char data[], char nam[]);
name *create_contact();
int searching(name *start, char nam[]);
name *delete (name *start, char nam[]);
name *rename_contact(name *start, char old[20], char new[20]);
void display_par(name *start, char nam[]);
void export(name *start);
name *import(name *start);
name *c_number(name *start, int pos, char nn[]);

int main()
{
    int choose, start, temp;
    int ptr = -1;
    char numb[20];
    char nam[20], nnam[20];
    char nnumb[20];
    name *p = NULL;

    while (1)
    {
        printf("****Choose any of the following****\n");
        printf("1. New Contact\n");
        printf("2. delete Contact\n");
        printf("3. rename Contact\n");
        printf("4. Display a particular contact\n");
        printf("5. Display all contact\n");
        printf("6. Searching of a contact\n");
        printf("7. Export contact list in csv format\n");
        printf("8. Import Contact\n");
        printf("9. Change Number\n");
        printf("10. Exit\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Enter the name: ");
            // scanf("%s",nam);
            fflush(stdin);
            gets(nam);
            printf("Enter number: ");
            // scanf("%s",numb);
            fflush(stdin);
            gets(numb);
            // p=insert_at_begin(p,numb,nam);
            p = insert_at_end(p, numb, nam);
            // printf("%s",p->name);//________---> it is working
            break;
        case 2:
            printf("Enter the name to be deleted: ");
            // scanf("%s",nam);
            fflush(stdin);
            gets(nam);
            p = delete (p, nam);
            break;
        case 3:
            printf("Enter old name to be Renamed: ");
            // scanf("%s",nam);
            fflush(stdin);
            gets(nam);
            printf("Enter new name : ");
            // scanf("%s",nnam);
            fflush(stdin);
            gets(nnam);
            p = rename_contact(p, nam, nnam);
            break;
        case 4:
            printf("Enter name whose details you want: ");
            fflush(stdin);
            // scanf("%s",nam);
            gets(nam);
            display_par(p, nam);
            break;
        case 5:
            display(p);
            break;
        case 6:
            printf("Enter contact name to be searched : ");
            fflush(stdin);
            // scanf("%s",nam);
            gets(nam);
            temp = searching(p, nam);
            if (temp == -2)
            {
                printf("\t**Contact NOT found**\n");
            }
            else
                printf("The entered name is at position %d\n", temp);
            break;
        case 7:
            export(p);
            break;
        case 8:
            p = import(p);
            break;
        case 9:
            printf("Enter contact name to be Changed : ");
            // scanf("%s",nam);
            fflush(stdin);
            gets(nam);
            temp = searching(p, nam);
            if (temp == -2)
            {
                printf("\t**Contact NOT found**\n");
            }
            else
            {
                fflush(stdin);
                printf("Enter new number: ");
                gets(nnumb);
                p = c_number(p, temp, nnumb);
            }
            break;
        case 10:
            exit(0);
        default:
            printf("\tEnter a Valid Input \n");
            break;
        }
    }

    return 0;
}
name *create_contact()
{
    name *l;
    // printf("xyz\n");
    l = (name *)malloc(sizeof(name));
    // if (l==NULL)
    // {
    //     printf("Node not created\n");
    //     return l;
    // }
    // else{
    //     printf("Node created\n");
    return l;
    // }
}
void display(name *start)
{
    if (start == NULL)
    {
        printf("\n*****The list is empty*****\n\n");
    }
    else
    {

        while (start->next != NULL)
        {
            printf("%s -- %s\n", start->name, start->number);
            start = start->next;
        }
        printf("%s -- %s\n", start->name, start->number);
    }
    return;
}

// name *insert_at_begin(name *start, int data, char nam[]){
//     name *new=create_contact();
//     new->number=data;
//     strcpy(new->name,nam);
//     if (start==NULL)
//     {
//         new->next=NULL;
//     }
//     else
//     {new->next=start;}
//     start=new;
//     return start;
// }

name *insert_at_end(name *start, char data[], char nam[])
{
    name *new = create_contact();
    name *temp;
    // new->number=data;
    strcpy(new->number, data);
    strcpy(new->name, nam);
    new->next = NULL;
    if (start == NULL)
    {
        start = new;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
    return start;
}
name *delete (name *start, char nam[])
{
    name *temp = start;
    name *hold;
    int a;
    char key[16];
    int count = 0;
    if (start == NULL)
    {
        printf("***The list is empty!!!***\n");
        return start;
    }
    a = searching(start, nam);
    if (a == 0)
    {
        start = temp->next;
        // key=temp->number;
        strcpy(key, temp->number);
        printf("Key deleted is : %s\n", key);
        free(temp);
        return start;
    }
    while (count < a - 1)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("***Position is greater than the number of nodes***\n");
            return start;
        }
        count++;
    }
    hold = temp->next->next;
    // key=temp->next->number;
    strcpy(key, temp->next->number);
    free(temp->next);
    temp->next = hold;
    printf("Key deleted is : %s\n", key);
    return start;
}
int searching(name *start, char nam[])
{
    name *temp = start;
    int pos = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->name, nam) == 0)
        {
            // printf("The data is found at %d \n",pos);
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -2;
}

name *rename_contact(name *start, char old[20], char new[20])
{
    name *temp = start;
    char f;
    // strcpy(f,temp->name);
    if (start == NULL)
    {
        printf("***The list is empty!!!***\n");
        return start;
    }
    while (strcmp(temp->name, old) != 0)
    {
        temp = temp->next;
    }
    strcpy(temp->name, new);
    return start;
}
void display_par(name *start, char nam[])
{
    if (start == NULL)
    {
        printf("***The list is empty!!!***\n");
        return;
    }
    while (strcmp(start->name, nam) != 0)
    {
        start = start->next;
    }
    printf("%s -- %s\n", start->name, start->number);
}
void export(name *start)
{
    time_t tm;
    time(&tm);
    FILE *ptr, *ptr2;
    ptr = fopen("contact_info.csv", "w");
    fprintf(ptr, "Given Name, Phone 1 - Value\n");
    fclose(ptr);
    ptr = fopen("contact_info.csv", "a");
    ptr2 = fopen("logs.txt", "a");
    // fprintf(ptr,"\n\t\t%s",ctime(&tm));
    fprintf(ptr2, "\n\t\t%s", ctime(&tm));
    while (start != NULL)
    {
        fprintf(ptr, "%s, %s\n", start->name, start->number);
        fprintf(ptr2, "%s ----> %s\n", start->name, start->number);
        start = start->next;
    }
    fclose(ptr);
    fclose(ptr2);
    printf("\tExported Successfully\n");
}
name *import(name *start)
{
    FILE *ptr;
    name *temp;
    char ch;
    char name[20], name2[20];
    char nub[16], nub2[16];
    ptr = fopen("contact_info.csv", "r");
    for (int i = 0; i < 1; i++)
    {
        while (1)
        {
            ch = fgetc(ptr);
            if (ch == '\n')
            {
                break;
            }
        }
    }
    while (1)
    {
        // ch=getc(ptr);
        // ptr=ptr-1;
        if (ch == EOF)
        {
            break;
            // return start;
        }
        else
        {
            fscanf(ptr, "%[^,]", &name); // problem in getting K U Jora
            // fgets(name,16,ptr);
            fscanf(ptr, ", %s\n", &nub);
            start = insert_at_end(start, nub, name);
            // printf("%s ----> %d\n",start->name,start->number);
            ch = getc(ptr);
            // ptr--;
            fseek(ptr, -1, SEEK_CUR);
        }
    }

    printf("\tImported Successfully\n");
    fclose(ptr);
    return start;
}
name *c_number(name *start, int pos, char nn[])
{
    name *temp = start;
    int i = 0;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    strcpy(temp->number, nn);
    return start;
}