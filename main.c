#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<malloc.h>
struct contact{
       char name[30],email[30];
       long long int ph;
       struct contact *rl;
       struct contact *ll;
};
typedef struct contact CONTACT;

CONTACT *start=NULL;

CONTACT *add_contact()
{
    CONTACT *new_contact,*ptr;
    new_contact=(CONTACT *)malloc(sizeof(struct contact));
    new_contact->ll=NULL;
    new_contact->rl;
    printf("Enter Name:");
    scanf("%s",new_contact->name);
    printf("Enter Phone Number:");
    scanf("%lld",&new_contact->ph);
    printf("Enter Mail Id:");
    scanf("%s",new_contact->email);
    if(start==NULL){
        start=new_contact;
    }
    else{
        ptr=start;
        while(ptr->rl!=NULL)
        {
            ptr=ptr->rl;
        }
        ptr->rl=new_contact;
        new_contact->ll=ptr;
    }
    printf("\nContact Created Successfully!!\n");
    return start;
}

// CONTACT *search_contact();
CONTACT *update_id(char crr_id[],char id[]){
       system("cls");
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (strcmp(ptr->email,crr_id)!=0)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("Please check the email id once\n");
              }
              else{
                     if(id[0]!='\0'){
                            strcpy(ptr->email, id);
                            printf("Name updated to %s sucessfully\n",ptr->email);
                     }
              }  
       }
       return start;
}

CONTACT *update_name(char crr_name[],char name[]){
       system("cls");
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (strcmp(ptr->name,crr_name)!=0)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("Please check the name once\n");
              }
              else{
                     if(name[0]!='\0'){
                            strcpy(ptr->name, name);
                            printf("Name updated to %s sucessfully\n",ptr->name);
                     }
              }  
       }
       return start;
}

CONTACT *update_phno(long long int crr_number,long long int number){
       system("cls");
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (ptr->ph!=crr_number)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("Please check the phone number once\n");
              }
              else{
                     ptr->ph=number;
                     printf("%s Phone number have been updated to %lld\n",ptr->name,ptr->ph);
              }  
       }
       return start;
}

CONTACT *update_contact(){
       system("cls");
       printf("What would you like to update\n");
       printf("1.Name\n2.Phone no.\n3.Email id\n");
       int ch;
       while(1){
              printf("Enter your choice\n");
              scanf("%d",&ch);
              switch(ch){
                     case 1:char name[100],crr_name[100];
                            printf("Enter the Name to be updated:\n");
                            gets(crr_name);
                            printf("Enter the new Name:\n");
                            gets(name);
                            update_name(crr_name,name);
                            break;
                     case 2:long long int num,crr_num;
                            printf("Enter the phone number to be updated:\n");
                            scanf("%lld",&crr_num);
                            printf("Enter the new phone number\n");
                            scanf("%lld",&num);
                            update_phno(crr_num,num);
                            break; 
                     case 3:char crr_id[250],id[250];
                            printf("Enter the Mail id to be updated\n");
                            gets(crr_id);
                            printf("Enter the new mail id\n");
                            gets(id);
                            update_id(crr_id,id);
                            break;
              }
       }         
       return start;
}

// CONTACT *delete_contact();
// void display();

int main()
{
    int choice;
    printf("\nMENU\n");
    printf("----------------------------------------------------------------------------------------");
    printf("1.Add Contact\n2.Search Contact\n3.Update Contact\n4.Delete Contact\n5.Display\n6.Exit\n");
    printf("----------------------------------------------------------------------------------------\n");
    while(1)
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: start = add_contact();
                   break;
       //      case 2:start = search_contact();
       //             break;
            case 3:start = update_contact();
                   break;
       //      case 4:start = delete_contact();
       //             break;
       //      case 5:display();
       //             break;
            case 6:printf("Exited from the program\n");
                   exit(0);
        }
    }
    return 0;
}