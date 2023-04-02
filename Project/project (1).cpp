#include<bits/stdc++.h>
using namespace std;
void create( );

void add_Records();
void insertAtBegin();
void insertAtEnd();
void insertAnyPosition();

void traverse_records();
void count_Records();
void search_linear();

void delete_Record();
void deleteAtBegin();
void deleteAtEnd();
void deleteAnyPosition();
void delete_By_ID();

void sort_selection();
void swap_INT(long int *,long int *);
void swap_String(char *, char *);
void swap_Float(float *x, float *y);

void decorationhomeWindow();
void decoration_on_all_students();
void decoration_on_searching_record();

//i have taken class
class node
{
    public: // class member we can used whole the program for doing public
    long int ID;
    char name[30];
    char dpt[10];
    char section[20];
    float CGPA;
    char phone[12];
     node *next;
};
//globally i have declared
node *head,*temp,*tail;

int main()
{
    system("color 0a"); //this is for consol color.
    int choice=1;
    while(choice!=0)
    {
// i am using decoration for welcome window
    decorationhomeWindow();
        cout<<(" 1. Create Records\n");
        cout<<(" 2. Add Records\n");
        cout<<(" 3. Display All Records\n");
        cout<<(" 4. Number of Records\n");
        cout<<(" 5. Search Record\n");
        cout<<(" 6. Delete Record\n");
        cout<<(" 7. Sort Records\n");
        cout<<(" 0. Exit\n");
        cout<<("\nChoose Your Option\n");
        cin>>choice;
        switch(choice)
        {
        case 1:
            create( );
            break;
        case 2:
            add_Records();
            break;
        case 3:
            traverse_records();
            break;
        case 4:
            count_Records();
            break;
        case 5:
            search_linear();
            break;
        case 6:
            delete_Record();
            break;
        case 7:
            sort_selection();
            break;

        case 0:
            exit(0);
            break;
        default:
            cout<<("\nWrong option: ");
        }
    }
}

// create records
void create( )
{
    system("cls");
    node *newnode;
    head=0;
    int i,choice;
    cout<<("\nHow Many records want to Create? ");
    cin>>choice;

    for(i=1; i<=choice; i++)
    {
        newnode = new node();

        cout<<("Enter ID: ");
         cin>>newnode->ID;
         fflush(stdin);

        cout<<("Enter Name : ");
        cin.get(newnode->name, 100);

        cout<<("Enter Depertment : ");
        cin>>newnode->dpt;

        cout<<("Enter Section : ");
        cin>>newnode->section;

        cout<<("Enter CGPA : ");
        cin>>newnode->CGPA;

        cout<<("Enter Contact Number : ");
        cin>>newnode->phone;

        newnode->next = 0;
        if(head==0)
        {
            head = tail = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            tail=tail->next;
        }
        system("cls");
    }
    cout<<("\nRecord Created Successfully\n")<<endl;
}


// add records
void add_Records()
{
    int pos;
    cout<<("\nWhich Position Want to Add?\n1. Add Begin\n2. Add End\n3. Add Any Position\n")<<endl;
   cin>>pos;
    if(pos==1)
        insertAtBegin();
    else if(pos==2)
        insertAtEnd();
    else if(pos==3)
        insertAnyPosition();
    else
        cout<<("\nWrong Option\n")<<endl;
}

//insert record at beggining
void insertAtBegin()
{
    system("cls");
     node *newnode;
    newnode = new node();
    cout<<("Enter ID: ");
         cin>>newnode->ID;
         fflush(stdin);

        cout<<("Enter Name : ");
        cin.get(newnode->name, 100);

        cout<<("Enter Depertment : ");
        cin>>newnode->dpt;

        cout<<("Enter Section : ");
        cin>>newnode->section;

        cout<<("Enter CGPA : ");
        cin>>newnode->CGPA;

        cout<<("Enter Contact Number : ");
        cin>>newnode->phone;

    newnode->next=head;
    head=newnode;
    system("cls");
    cout<<("\nRecord Added Successfully\n");

}

//insert record end of the list
void insertAtEnd()
{
    system("cls");
    node *newnode;
    newnode = new node();

    cout<<("Enter ID: ");
         cin>>newnode->ID;
         fflush(stdin);

        cout<<("Enter Name : ");
        cin.get(newnode->name, 100);

        cout<<("Enter Depertment : ");
        cin>>newnode->dpt;

        cout<<("Enter Section : ");
        cin>>newnode->section;

        cout<<("Enter CGPA : ");
        cin>>newnode->CGPA;

        cout<<("Enter Contact Number : ");
        cin>>newnode->phone;

    newnode->next=0;
    tail->next = newnode;
    system("cls");
    cout<<("\nRecord Added Successfully\n");
}

//insert record any position in the list
void insertAnyPosition()
{
    system("cls");
    int pos;
    cout<<("Enter position to Add: ");
    cin>>pos;
    if(pos<0)
    {
        cout<<("Invalid position\n");
    }
    else
    {
        node *newnode;
        newnode = new node();

       cout<<("Enter ID: ");
         cin>>newnode->ID;
         fflush(stdin);

        cout<<("Enter Name : ");
        cin.get(newnode->name, 100);

        cout<<("Enter Depertment : ");
        cin>>newnode->dpt;

        cout<<("Enter Section : ");
        cin>>newnode->section;

        cout<<("Enter CGPA : ");
        cin>>newnode->CGPA;

        cout<<("Enter Contact Number : ");
        cin>>newnode->phone;

        newnode->next=0;
        temp = head;
        int i=1;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next = newnode;
    }
    system("cls");
    cout<<("\nRecord Added Succssfully\n");
}


//display all records
void traverse_records()
{
    system("cls");

    if(head==0)
    {
        cout<<("There are no Records!\n");
    }
    else
    {
// call the decoration function
        decoration_on_all_students();
        temp = head;
        while(temp!=NULL)
        {
            cout << " "<<temp->ID << " \t"
                 << temp->name << "\t"
                 << temp->dpt << "\t\t"
                 << temp->section << "\t   "
                 << temp->CGPA << "\t   "
                 << temp->phone << endl;
            temp = temp->next;
        }

        cout<<("\n");
    }
}

//count all records
void count_Records()
{
    system("cls");
    temp = head;
    int count_all_records=0;
    while(temp!=NULL)
    {
        count_all_records++;
        temp = temp->next;
    }
    cout<<"\nTotal Number of Records:"<<count_all_records<<endl;
}

// searching specific record by id
void search_linear()
{
    system("cls");
    int id,flag=0;
    cout<<("\nEnter ID to Search: ");
   cin>>id;
    temp = head;
    while(temp!=NULL)
    {
        if(id==temp->ID)
        {
        decoration_on_searching_record();
            flag=1;
          cout << " "<<temp->ID << " \t"
                 << temp->name << "\t"
                 << temp->dpt << "\t\t"
                 << temp->section << "\t   "
                 << temp->CGPA << "\t   "
                 << temp->phone << endl;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
        cout<<("\nRecord Not Found!\n");
       // printf("\n\n\n");
}

// delete function
void delete_Record()
{
    int choice;
    cout<<("\n1. Delete Beginning of Records\n2. Delete At End of Records\n3. Delete Any Position Of Records");
    cout<<("\n4. Delete By ID\n\nChoose Your Option\n");
   cin>>choice;
    if(choice==1)
        deleteAtBegin();
    else if(choice==2)
        deleteAtEnd();
    else if(choice==3)
        deleteAnyPosition();
    else if(choice==4)
        delete_By_ID();
    else
        cout<<("\nWrong Option!\n")<<endl;
}

// delete record at beggining of the records.
void deleteAtBegin()
{
    system("cls");
    if(head==0)
        cout<<("\nThere is No Record!\n")<<endl;
    else
    {
        temp = head;
        head = head->next;
        free(temp); // free the deleted node
        cout<<("Record Deleted Successfully\n");
    }
}

// delete record end of the records.
void deleteAtEnd()
{
    system("cls");
    if(head==0)
    {
        cout<<("\nThere is No Record!\n");
    }
    else
    {
        node *preNode;
        temp = head;
        while(temp->next!=0)
        {
            preNode = temp;
            temp = temp->next;
        }
        preNode->next=0;
        free(temp); //here free the deleted node
        cout<<("\nRecord Deleted Successfully\n");
    }
}

// delete record any position of the records
void deleteAnyPosition()
{
    system("cls");
    if(head==0)
    {
        cout<<("\nThere is No Record!\n");
    }
    else
    {
        int pos;
        cout<<("Enter position To Delete");
        cin>>pos;
        int i=1;
        temp = head;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        free(temp); //here done free deleted node
        cout<<("\nRecord Deleted Successfully\n");
    }
}

// delete record by student id
void delete_By_ID()
{
    system("cls");
    if(head==0)
    {
        cout<<("\nThere is No Record!\n");
    }
    else
    {
        int id,flag=0;
        cout<<("\nInput ID To Delete :\n ");
       cin>>id;
        if(id==head->ID)
        {
            deleteAtBegin();
        }
        else
        {
            node *preNode;
            temp = head;
            while(temp!=NULL)
            {
                preNode = temp;
                temp=temp->next;
                if(id==temp->ID)
                {
                    flag=1;
                    preNode->next = temp->next;
                    cout<<("\nRecord Deleted Successfully\n");
                    break;
                }
            }
        }
        if(flag==0)
            cout<<("\nRecord Not Found!\n");
    }
}

// sorting the records according to id
void sort_selection()
{
    system("cls");
    node *curNode,*nextNode;
    curNode = head;
    while(curNode!=0)
    {
        nextNode = curNode->next;

        while(nextNode!=0)
        {
            if(curNode->ID>nextNode->ID)
            {
                swap_INT(&curNode->ID, &nextNode->ID);
                swap_String(curNode->name, nextNode->name);
                swap_String(curNode->dpt, nextNode->dpt);
                swap_String(curNode->section, nextNode->section);
                swap_Float(&curNode->CGPA, &nextNode->CGPA);
                swap_String(curNode->phone, nextNode->phone);
            }
            nextNode = nextNode->next;
        }
        curNode = curNode->next;
    }
    cout<<("\nRecord is Now Sorted\n");
}

// this function swap only long integer data type.
void swap_INT(long int *a,long int *b)
{
    int temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}

//this function swap only float data type.
void swap_Float(float *x, float *y)
{
    float temp;
    temp  = *x;
    *x = *y;
    *y = temp;
}

//this function swap string
void swap_String(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}


// this is the welcome screen for this projects
void decorationhomeWindow()
{
    cout<<("\n");
    cout<<("\n\t\t\t\t  **-**-**-**-**-**-** -**-**-**-**-**-**-**-**-**-**-**-**");
    cout<<("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    cout<<("\n\t\t\t\t        =                  WELCOME                  =");
    cout<<("\n\t\t\t\t        =                    TO                     =");
    cout<<("\n\t\t\t\t        =               STUDENT RECORD              =");
    cout<<("\n\t\t\t\t        =                 MANAGEMENT                =");
    cout<<("\n\t\t\t\t        =                   SYSTEM                  =");
    cout<<("\n\t\t\t\t        =      GREEN UNIVERSITY OF BANGLADESH       =");
    cout<<("\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    cout<<("\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
}

// decoration will show when list all records function is called
void decoration_on_all_students()
{
    cout<<("\n********************** LIST OF ALL STUDENTS RECORDS ************************\n");
    cout<<("\n     ID\t\tName\t\tDepartment     Section\t  CGPA\t   Phone No.\n");
    cout<<("-----------------------------------------------------------------------------\n");
}

// decoration will show when searching  function is called
void decoration_on_searching_record()
{
    cout<<("\n********************** SEARCHING  STUDENTS RECORD ************************\n");
    cout<<("\n     ID\t\tName\t\tDepartment     Section\t  CGPA\t   Phone No.\n");
    cout<<("-----------------------------------------------------------------------------\n");
}

