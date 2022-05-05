#include<iostream>
#include<string.h>
using namespace std;
class node
{
public:
    char name[30];
    int pcode;
    int ccode;
    long long int mno;
    int key;
    node *next;
};
int count=0;
int keyarray[100]= {-1};
node *head=NULL;

void menu();
void display(node *head,char dname[],int k);
void modify(node *head,char mname[],int k);
void insert(node *&head);

void upper_string(char str[])
{
    for(int i=0 ; str[i]!='\0' ; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

void insert(node *&head)
{
    node *temp=head;
    int x,y;
    if(head==NULL)
    {
        cin.ignore();
        node *temp2=new node;
        cout<<"\n                 ENTER NAME : ";
        cin.getline(temp2->name,30);
        upper_string(temp2->name);
        cout<<"\n                 ENTER PIN CODE : ";
        cin>>temp2->pcode;
        cout<<"\n                 ENTER COUNTRY CODE : ";
        cin>>temp2->ccode;
        cout<<"\n                 ENTER MOBILE NUMBER : ";
        cin>>temp2->mno;
        cout<<endl;
        int sum=0;
        for(int i=0; i<strlen(temp2->name); i++)
        {
            sum=sum+int(temp2->name[i]);
        }
        x=sum%100;
        temp2->key=x;
        keyarray[count++]=x;
        cout<<"\n                 YOUR PASSWORD KEY : "<<temp2->key;
        head=temp2;
        temp2->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *temp3=new node;
        cin.ignore();
        cout<<"\n                 ENTER NAME : ";
        cin.getline(temp3->name,30);
        upper_string(temp3->name);
        cout<<"\n                 ENTER PIN CODE : ";
        cin>>temp3->pcode;
        cout<<"\n                 ENTER COUNTRY CODE : ";
        cin>>temp3->ccode;
        cout<<"\n                 ENTER MOBILE NUMBER : ";
        cin>>temp3->mno;
        int sum=0;
        for(int i=0; i<strlen(temp3->name); i++)
        {
            sum=sum+int(temp3->name[i]);
        }
        y=sum%100;
        temp3->key=y;
        for(int i=0; keyarray[i]!=-1; i++)
        {
            if(y==keyarray[i])
            {
                y++;
                i=0;
            }
        }
        temp3->key=y;
        keyarray[count++]=y;
        cout<<"\n\n                 YOUR PASSWORD KEY : "<<temp3->key<<endl<<endl;
        temp->next=temp3;
        temp3->next=NULL;

    }

    cout<<"\n\n                 DATA SAVED SUCCESFULLY \n\n\n";
    cout<<"                 * NOTE: REMEMBER YOUR PASSWORD KEY TO ACCESS DATA IN FUTURE *\n\n";

    system("pause");
    system("CLS");
    menu();
}



void deletion(node *&head, char dname[], int k)
{
    node *temp = head;
    upper_string(dname);
    if (temp == head && (strcmp(temp->name, dname) == 0 && temp->key == k))
    {
        head = temp->next;
        cout<<"\n\n--------------> DELETE SUCCESSFULLY <---------------\n\n";

        system("pause");
        system("CLS");
        menu();
    }
    else
    {
        while (temp->next != NULL && (temp->next->key != k && strcmp(temp->next->name, dname) == -1))
        {
            temp = temp->next;
        }

        if (temp->next->key == k && strcmp(temp->next->name, dname) == 0)
        {

            temp->next = temp->next->next;

            cout<<"\n\n--------------> DELETE SUCCESSFULLY <---------------\n\n";
        }
        else if(temp->next->key != k)
            cout<<"\n WRONG ENTRY\n";

        else if (temp->next == NULL)
            cout<<"\n NO ENTRY FOUND\n";


        system("pause");
        system("CLS");
        menu();
    }


}


void modify(node *head,char mname[],int k)
{
    int choice,flag=0;
    upper_string(mname);
    system("CLS");
    node *temp=head;

    while(temp!=NULL)
    {

        if(strcmp(temp->name,mname)==0 && temp->key==k)
        {
            flag=1;
            cout<<"\n                 ENTER FIELD TO BE UPDATED\n";
            cout<<"\n                 1.NAME";
            cout<<"\n                 2.PIN CODE";
            cout<<"\n                 3.COUNTRY CODE";
            cout<<"\n                 4.MOBILE NUMBER\n";
            cout<<"                 ";
            cin>>choice;
rerun:

            switch(choice)
            {
            case 1:
            {
                string s;
                cout<<"\n                 ENTER UPDATED NAME :";
                cin.ignore();
                cin.getline(temp->name,30);
                upper_string(temp->name);
                break;
            }
            case 2:
            {

                cout<<"\n                 ENTER UPDATED PIN CODE :";
                cin>>temp->pcode;
                break;
            }
            case 3:
            {

                cout<<"\n                 ENTER UPDATED COUNTRY CODE :";
                cin>>temp->ccode;
                break;
            }
            case 4:
            {
                cout<<"\n                 ENTER UPDATED MOBILE NUMBER :";
                cin>>temp->mno;
                cout<<endl;
                break;
            }
            case 5:
                break;
            default:
            {
                cout<<"\n                 WRONG CHOICE\n";
                cout<<"\n                 ENTER CORRECT CHOICE";
                cin>>choice;

                goto rerun;

            }
            }
        }
        temp=temp->next;
    }

    if(flag==0)
    {
        system("CLS");
        cout<<"\n                 NO RECORD FOUND\n\n";
    }
    else
    {
        system("CLS");
        cout<<"\n                 RECORD UPDATED\n\n";
    }

    system("pause");
    system("CLS");
    menu();


}




void menu()
{
    int choice,k;
    cout<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n                                                                                              ||PHONE BOOK DIRECTORY ||\n\n";
    cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    cout<<endl;
    cout<<endl;

    cout<<"\n                 1.ENTER RECORDS\n";
    cout<<"\n                 2.SHOW RECORDS\n";
    cout<<"\n                 3.MODIFY\n";
    cout<<"\n                 4.DELETE RECORD\n";
    cout<<"\n                 5.EXIT\n\n";


    cout<<"\n                 ENTER CHOICE : ";
    cin>>choice;
rerun:
    switch(choice)
    {
    case 1:
    {
        insert(head);
        break;
    }
    case 2:
    {
        cin.ignore();
        cout<<"\n                 ENTER NAME TO BE SEARCHED : ";
        char s[30];
        cin.getline(s,30);
        upper_string(s);
        cout<<"\n                 ENTER YOUR PASSWORD KEY : ";
        cin>>k;
        display(head,s,k);
        break;
    }
    case 3:
    {
        cin.ignore();

        cout<<"\n                 ENTER NAME WHOSE RECORD IS TO BE MODIFIED : ";
        char s[30];
        cin.getline(s,30);
        upper_string(s);
        cout<<"\n                 ENTER YOUR PASSWORD KEY : ";
        cin>>k;
        modify(head,s,k);
        break;
    }
    case 4:
    {
        cin.ignore();
        cout<<"\n                 ENTER NAME WHOSE RECORD IS TO BE DELETED : ";
        char s[30];
        cin.getline(s,30);
        upper_string(s);
        cout<<"\n                 ENTER YOUR PASSWORD KEY : ";
        int k;
        cin>>k;
        deletion(head,s,k);
    }

    case 5:
    {
        break;
    }
    default:
    {
        cout<<"\n                 ENTER CORRECT CHOICE : ";

        cin>>choice;
        goto rerun;
    }

    }
}

void display(node *head,char dname[],int k)
{
    upper_string(dname);
    int flag=0;
    system("CLS");
    node *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,dname)==0 && temp->key==k)
        {
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout<<"\n                                                                                              NAME : "<<temp->name;
            cout<<endl;
            cout<<"\n                                                                                              PIN CODE : "<<temp->pcode;
            cout<<endl;
            cout<<"\n                                                                                              COUNTRY CODE : +"<<temp->ccode;
            cout<<endl;
            cout<<"\n                                                                                              MOBILE NUMBER : ";
            cout<<temp->mno;
            cout<<endl;
            cout<<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            temp=temp->next;
            flag=1;
        }
        else
        {
            temp=temp->next;

        }
    }


    if(flag==0)
        cout<<"                                                                                              NO ENTRY FOUND";
    system("pause");
    system("CLS");
    menu();
}
int main()
{
    menu();

}
