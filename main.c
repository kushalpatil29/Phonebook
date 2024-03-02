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

CONTACT *search_id(){
       system("cls");
       char id[250];
       printf("Enter the Mail id to be searched:\n");
       scanf("%s",id);
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (strcmp(ptr->email,id)!=0)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("No matches found\n");
              }
              else{
                    printf("Contact Details:\n");
                    printf("------------------------------------------------------\n");
                    printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                    printf("------------------------------------------------------\n");                     
              //       printf("%s",ptr->name);
              //       printf("%lld",ptr->ph);
              //       printf("%s",ptr->email);
              printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              }
       }
       return start; 
}
       
CONTACT *search_name(){
       system("cls");
       char name[100];
       printf("Enter the Name to be searched:\n");
       scanf("%s",name);
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (strcmp(ptr->name,name)!=0)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("No matches found\n");
              }
              else{
                    printf("Contact Details:\n");
                    printf("------------------------------------------------------\n");
                    printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                    printf("------------------------------------------------------\n");  
              //       printf("%s",ptr->name);
              //       printf("%lld",ptr->ph);
              //       printf("%s",ptr->email);
              printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              }  
       }
       return start;
}

CONTACT *search_phno(){
       system("cls");
       long long int num;
       printf("Enter the phone number to be searched:\n");
       scanf("%lld",num);
       CONTACT *ptr;
       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (ptr->ph!=num)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("No matches found\n");
              }
              else{
                    printf("Contact Details:\n");
                    printf("------------------------------------------------------\n");
                    printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                    printf("------------------------------------------------------\n"); 
              //       printf("%s",ptr->name);
              //       printf("%lld",ptr->ph);
              //       printf("%s",ptr->email);
                    printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              }  
       }
       return start;
}

CONTACT *search_contact(){
       system("cls");
       printf("How would you like to search\n");
       printf("1.Name\n2.Phone no.\n3.Email id\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch(ch){
              case 1:search_name();
                     break;
              case 2:search_phno();
                     break; 
              case 3:search_id();
                     break;
       }         
       return start;
}

CONTACT *update_id(){
       system("cls");
       char crr_id[150],id[250];
       printf("Enter the Mail id to be updated\n");
       scanf("%s",crr_id);
       printf("Enter the new mail id\n");
       scanf("%s",id);
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

CONTACT *update_name(){
       system("cls");
       char name[100],crr_name[100];
       printf("Enter the Name to be updated:\n");
       scanf("%s",crr_name);
       printf("Enter the new Name:\n");
       scanf("%s",name);
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

CONTACT *update_phno(){
       system("cls");
       long long int num,crr_num;
       printf("Enter the phone number to be updated:\n");
       scanf("%lld",&crr_num);
       // if(len(crr_num)!=10){
       //        printf("Enter a valid phone number\n");
       //        break;
       // }
       printf("Enter the new phone number\n");
       scanf("%lld",&num);
       CONTACT *ptr;

       if(start==NULL){
              printf("Phone book is empty\n");
              return start;
       }
       else{
              ptr=start;
              while((ptr!=NULL) && (ptr->ph!=crr_num)){
                     ptr=ptr->rl;
              }
              if(ptr==NULL){
                     printf("Please check the phone number once\n");
              }
              else{
                     ptr->ph=num;
                     printf("%s Phone number have been updated to %lld\n",ptr->name,ptr->ph);
              }  
       }
       return start;
}

CONTACT *update_contact(){
       system("cls");
       printf("What would you like to update\n");
       printf("1.Name\n2.Phone no.\n3.Email id\n4.Exit\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch(ch){
              case 1:update_name();
                     break;
              case 2:
                     update_phno();
                     break; 
              case 3:
                     update_id();
                     break;
       }         
       return start;
}

CONTACT *delete_name(){
       system("cls");
       char keyname[100];
       printf("Enter the Name to be deleted:\n");
       scanf("%s",keyname);
       CONTACT *ptr,*temp;
       if (start == NULL){
              printf("Phonebook is Empty\n");
              return start;
       }
       else if(start->name == keyname )
       {
                  ptr=start;
                  start = start->rl;
                  printf("Item Deleted: %s\n", ptr->name); 
                  free(ptr);
       } 
       else 
       {
             ptr=start;
             while((ptr!= NULL)&&(ptr->name != keyname))
             {
                  temp=ptr;
                  ptr= ptr->rl;
              }
              if(ptr == NULL)  // Searched till end of phonebook
                      printf("Invalid Contact Name\n");
              else
              {
                  temp->rl = ptr->rl;
                  if(ptr->rl != NULL)
                  {
                     (ptr->rl)->ll = temp;
                  }
                  printf("Item deleted:  %s\n",ptr->name);   
                  free(ptr);
              }
       }
       return start;   

}

CONTACT *delete_phno(){
       system("cls");
       long long int num;
       printf("Enter the phone number to be deleted:\n");
       scanf("%lld",&num);
       CONTACT *ptr,*temp;
       if (start == NULL){
              printf("Phonebook is Empty\n");
              return start;
       }
       else if(start->ph == num )
       {
                  ptr=start;
                  start = start->rl;
                  printf("Item Deleted: %lld\n", ptr->ph); 
                  free(ptr);
       } 
       else 
       {
             ptr=start;
             while((ptr!= NULL)&&(ptr->ph != num ))
             {
                  temp=ptr;
                  ptr= ptr->rl;
              }
              if(ptr == NULL)  // Searched till end of phonebook
                      printf("Invalid Contact Name\n");
              else
              {
                  temp->rl = ptr->rl;
                  if(ptr->rl != NULL)
                  {
                     (ptr->rl)->ll = temp;
                  }
                  printf("Item deleted:  %lld\n",ptr->ph);   
                  free(ptr);
              }
       }
       return start;   

}
       
CONTACT *delete_contact(){
       system("cls");
       printf("What would you like to delete\n");
       printf("1.Name\n2.Phone no.\n3.Exit\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d",&ch);
       switch(ch){
              case 1:delete_name();
                     break;
              case 2:
                     delete_phno();
                     break; 
              case 3:
                     exit(0);
       }         
       return start;
}


/*
 * Function to display all contacts stored in the phone book.
 * If the phone book is empty, it prints a message indicating so.
 * If there are contacts, it prints each contact's name, phone number, and email.
 */
void display_contacts() {
    system("cls"); // Clear the screen
    if (start == NULL) {
        printf("Phone book is empty\n");
        return;
    }
    printf("Contacts in the phone book:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email"); // Header for contact details
    printf("----------------------------------------------------------------------------------------\n");
    CONTACT *ptr = start;
    while (ptr != NULL) {
        printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email); // Print each contact's details
        ptr = ptr->rl; // Move to the next contact
    }
    printf("----------------------------------------------------------------------------------------\n");
}


int main()
{
    int choice;
    system("cls");
    while(1)
    {
       printf("\nMENU\n");
       printf("----------------------------------------------------------------------------------------");
       printf("\n1.Add Contact\n2.Search Contact\n3.Update Contact\n4.Delete Contact\n5.Display\n6.Exit\n");
       printf("----------------------------------------------------------------------------------------\n");
       printf("Enter Your Choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1: start = add_contact();
              break;
      case 2:start = search_contact();
             break;
       case 3:start = update_contact();
              break;
//      case 4:start = delete_contact();
//             break;
      case 5:display_contacts();
             break;
       case 6:printf("Exited from the program\n");
              exit(0);
       default:printf("Enter a valid choice\n");
               break;
       }
    }
    return 0;
}
