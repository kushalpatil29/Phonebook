#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct contact{
    char name[30],phone[10],email[30];
    struct contact *left,*right;
};
typedef struct contact CONTACT;

CONTACT *start=NULL;

void add_contact();
//void search_contact();
//void update_contact();
//void delete_contact();
//void display();

void main()
{
    int choice;
    while(1)
    {
        printf("\nMENU\n");
        printf("1.Add Contact\n2.Search Contact\n3.Update Contact\n4.Delete Contact\n5.Display\n6.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:add_contact();
                   break;
            //case 2:search_contact();
                   //break;
            //case 3:update_contact();
                   //break;
            //case 4:delete_contact();
                   //break;
            //case 5:display();
                   //break;
            case 6:exit(0);
        }
    }
}
void add_contact()
{
    CONTACT *new_contact,*ptr;
    new_contact=(CONTACT *)malloc(sizeof(struct contact));
    new_contact->left=NULL;
    new_contact->right;
    printf("Enter Name:");
    scanf("%s",new_contact->name);
    printf("Enter Phone Number:");
    scanf("%s",new_contact->phone);
    printf("Enter Mail Id:");
    scanf("%s",new_contact->email);
    if(start==NULL){
        start=new_contact;
    }
    else{
        ptr=start;
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        ptr->right=new_contact;
        new_contact->left=ptr;
    }
    printf("\nContact Created Successfully!!\n");
}
