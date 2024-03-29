#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>
struct contact
{
       char name[30], email[30];
       long long int ph;
       struct contact *rl;
       struct contact *ll;
};
typedef struct contact CONTACT;

CONTACT *start = NULL;

CONTACT *add_contact()
{
       CONTACT *new_contact, *ptr;
       new_contact = (CONTACT *)malloc(sizeof(struct contact));
       new_contact->ll = NULL;
       new_contact->rl = NULL;
       char name[100], email[250];
       long long int ph;
       printf("Enter Name:");
       scanf("%s", name);
jump:
       printf("Enter Phone Number:");
       scanf("%lld", &ph);
       long long n = ph, count = 0;
       while (n > 0)
       {
              n = n / 10;
              count = count + 1;
       }
       if (count != 10)
       {
              printf("Invalid Number\nEnter again\n");
              goto jump;
       }

       printf("Enter Mail Id:");
       scanf("%s", email);
       strcpy(new_contact->name, name);
       strcpy(new_contact->email, email);
       new_contact->ph = ph;

       if (start == NULL)
       {
              start = new_contact;
       }
       else
       {
              ptr = start;
              while (ptr->rl != NULL)
              {
                     if (strcmp(ptr->name, name) == 0 && ptr->ph == ph)
                     {
                            printf("Contact already exists!!\n");
                            return start;
                     }
                     ptr = ptr->rl;
              }

              if (strcmp(ptr->name, name) == 0 && ptr->ph == ph)
              {
                     printf("Contact already exists!!\n");
                     return start;
              }

              ptr->rl = new_contact;
              new_contact->ll = ptr;
       }
       printf("\nContact Created Successfully!!\n");
       return start;
}

CONTACT *search_id()
{
       system("cls");
       char id[250];
       printf("Enter the Mail id to be searched:\n");
       scanf("%s", id);
       CONTACT *ptr;
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (strcmp(ptr->email, id) != 0))
              {
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
              {
                     printf("Contact not found!!\n");
              }
              else
              {
                     printf("Contact Details:\n");
                     printf("------------------------------------------------------\n");
                     printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                     printf("------------------------------------------------------\n");
                     printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              }
       }
       return start;
}

CONTACT *search_name()
{
       system("cls");
       char name[100];
       printf("Enter the Name to be searched:\n");
       scanf("%s", name);
       CONTACT *ptr;
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              int flag = 0;
              ptr = start;
              printf("Contact Details:\n");
              printf("------------------------------------------------------\n");
              printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
              printf("------------------------------------------------------\n");
              while (ptr != NULL)
              {
                     if (strcmp(strlwr(ptr->name), strlwr(name)) == 0)
                     {
                            flag = 1;
                            printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
                     }
                      ptr = ptr->rl;
              }
              printf("------------------------------------------------------\n");                    
              if (flag == 0)
              {
                     printf("No matches found\n");
              }
       }
       return start;
}

CONTACT *search_phno()
{
       system("cls");
       long long int num;
jump2:
       printf("Enter the phone number to be searched:\n");
       scanf("%lld", &num);
       long long n = num, count = 0;
       while (n > 0)
       {
              n = n / 10;
              count = count + 1;
       }
       if (count != 10)
       {
              printf("Enter Valid Number\n");
              goto jump2;
       }
       CONTACT *ptr;
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (ptr->ph != num))
              {
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
              {
                     printf("Contact not found!!\n");
              }
              else
              {
                     printf("Contact Details:\n");
                     printf("------------------------------------------------------\n");
                     printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
                     printf("------------------------------------------------------\n");
                     printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              }
       }
       return start;
}

CONTACT *search_contact()
{
       system("cls");
       printf("How would you like to search\n");
       printf("1.Name\n2.Phone no.\n3.Email id\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d", &ch);
       switch (ch)
       {
       case 1:
              search_name();
              break;
       case 2:
              search_phno();
              break;
       case 3:
              search_id();
              break;
       default:
              printf("Enter a valid input\n");
              break;
       }
       return start;
}

CONTACT *update_id()
{
       system("cls");
       char crr_id[150], id[250];
       printf("Enter the Mail id to be updated\n");
       scanf("%s", crr_id);
       printf("Enter the new mail id\n");
       scanf("%s", id);
       CONTACT *ptr;
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (strcmp(ptr->email, crr_id) != 0))
              {
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
              {
                     printf("Please check the email id once\n");
              }
              else
              {
                     if (id[0] != '\0')
                     {
                            strcpy(ptr->email, id);
                            printf("Name updated to %s sucessfully\n", ptr->email);
                     }
              }
       }
       return start;
}

CONTACT *update_name()
{
       system("cls");
       char name[100], crr_name[100];
       printf("Enter the Name to be updated:\n");
       scanf("%s", crr_name);
       printf("Enter the new Name:\n");
       scanf("%s", name);
       CONTACT *ptr;
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (strcmp((strlwr(ptr->name)), (strlwr(crr_name))) != 0))
              {
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
              {
                     printf("Please check the name once\n");
              }
              else
              {
                     if (name[0] != '\0')
                     {
                            strcpy(ptr->name, name);
                            printf("Name updated to %s sucessfully\n", ptr->name);
                     }
              }
       }
       return start;
}

CONTACT *update_phno()
{
       system("cls");
       long long int num, crr_num;
jump3:
       printf("Enter the phone number to be updated:\n");
       scanf("%lld", &crr_num);
       long long n = crr_num, count = 0;
       while (n > 0)
       {
              n = n / 10;
              count = count + 1;
       }
       if (count != 10)
       {
              printf("Enter Valid Number\n");
              goto jump3;
       }
jump4:
       printf("Enter the new phone number\n");
       scanf("%lld", &num);
       int ctr = 0;
       long long int n2 = num;
       while (n2 > 0)
       {
              n2 = n2 / 10;
              ctr = ctr + 1;
       }
       if (ctr != 10)
       {
              printf("Enter Valid Number\n");
              goto jump4;
       }
       CONTACT *ptr;

       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return start;
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (ptr->ph != crr_num))
              {
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
              {
                     printf("Please check the phone number once\n");
              }
              else
              {
                     ptr->ph = num;
                     printf("%s Phone number have been updated to %lld\n", ptr->name, ptr->ph);
              }
       }
       return start;
}

CONTACT *update_contact()
{
       system("cls");
       printf("What would you like to update\n");
       printf("1.Name\n2.Phone no.\n3.Email id\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d", &ch);
       switch (ch)
       {
       case 1:
              update_name();
              break;
       case 2:
              update_phno();
              break;
       case 3:
              update_id();
              break;
       default:
              printf("Enter a valid option\n");
              break;
       }
       return start;
}

CONTACT *delete_name()
{
       system("cls");
       char keyname[100];
       printf("Enter the Name to be deleted:\n");
       scanf("%s", keyname);
       CONTACT *ptr, *temp;
       if (start == NULL)
       {
              printf("Phonebook is Empty\n");
              return start;
       }
       else if (strcmp(start->name, keyname) == 0)
       {
              ptr = start;
              start = start->rl;
              printf("Item Deleted: %s\n", ptr->name);
              free(ptr);
              printf("Contact Deleted successfully!!\n");
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && strcmp(ptr->name, keyname) != 0)
              {
                     temp = ptr;
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
                     printf("Contact not found!!\n");
              else
              {
                     temp->rl = ptr->rl;
                     if (ptr->rl != NULL)
                     {
                            (ptr->rl)->ll = temp;
                     }
                     printf("Item deleted:  %s\n", ptr->name);
                     free(ptr);
                     printf("Contact Deleted successfully!!\n");
              }
       }
       return start;
}

CONTACT *delete_id()
{
       system("cls");
       char keyid[100];
       printf("Enter the id to be deleted:\n");
       scanf("%s", keyid);
       CONTACT *ptr, *temp;
       if (start == NULL)
       {
              printf("Phonebook is Empty\n");
              return start;
       }
       else if (strcmp(start->email, keyid) == 0)
       {
              ptr = start;
              start = start->rl;
              printf("Item Deleted: %s\n", ptr->email);
              free(ptr);
              printf("Contact Deleted successfully!!\n");
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && strcmp(ptr->email, keyid) != 0)
              {
                     temp = ptr;
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
                     printf("Contact not found!!\n");
              else
              {
                     temp->rl = ptr->rl;
                     if (ptr->rl != NULL)
                     {
                            (ptr->rl)->ll = temp;
                     }
                     printf("Item deleted:  %s\n", ptr->email);
                     free(ptr);
                     printf("Contact Deleted successfully!!\n");
              }
       }
       return start;
}

CONTACT *delete_phno()
{
       system("cls");
       long long int num;
jump4:
       printf("Enter the phone number to be deleted:\n");
       scanf("%lld", &num);
       long long n = num, count = 0;
       while (n > 0)
       {
              n = n / 10;
              count = count + 1;
       }
       if (count != 10)
       {
              printf("Enter Valid Number\n");
              goto jump4;
       }
       CONTACT *ptr, *temp;
       if (start == NULL)
       {
              printf("Phonebook is Empty\n");
              return start;
       }
       else if (start->ph == num)
       {
              ptr = start;
              start = start->rl;
              printf("Item Deleted: %lld\n", ptr->ph);
              free(ptr);
       }
       else
       {
              ptr = start;
              while ((ptr != NULL) && (ptr->ph != num))
              {
                     temp = ptr;
                     ptr = ptr->rl;
              }
              if (ptr == NULL)
                     printf("Invalid Contact Name\n");
              else
              {
                     temp->rl = ptr->rl;
                     if (ptr->rl != NULL)
                     {
                            (ptr->rl)->ll = temp;
                     }
                     printf("Item deleted:  %lld\n", ptr->ph);
                     free(ptr);
                     printf("Contact Deleted successfully!!\n");
              }
       }
       return start;
}

CONTACT *delete_contact()
{
       system("cls");
       printf("What would you like to delete\n");
       printf("1.Name\n2.Phone no.\n3.Mail id\n");
       int ch;
       printf("Enter your choice\n");
       scanf("%d", &ch);
       switch (ch)
       {
       case 1:
              delete_name();
              break;
       case 2:
              delete_phno();
              break;
       case 3:
              delete_id();
              break;
       default:
              printf("Please Choose a valid option\n");
              break;
       }
       return start;
}

void bubbleSort(CONTACT *start)
{
       int swapped;
       CONTACT *ptr1;
       CONTACT *lptr = NULL;
       if (start == NULL)
              return;

       do
       {
              swapped = 0;
              ptr1 = start;
              while (ptr1->rl != lptr)
              {
                     if (strcmp(ptr1->name, ptr1->rl->name) > 0)
                     {
                            char temp[30];
                            strcpy(temp, ptr1->name);
                            strcpy(ptr1->name, ptr1->rl->name);
                            strcpy(ptr1->rl->name, temp);

                            long long int temp1;
                            temp1 = ptr1->ph;
                            ptr1->ph = ptr1->rl->ph;
                            ptr1->rl->ph = temp1;

                            char temp3[50];
                            strcpy(temp3, ptr1->email);
                            strcpy(ptr1->email, ptr1->rl->email);
                            strcpy(ptr1->rl->email, temp3);
                            swapped = 1;
                     }
                     ptr1 = ptr1->rl;
              }
              lptr = ptr1;
       } while (swapped);
}

void display_contacts()
{
       system("cls");
       if (start == NULL)
       {
              printf("Phone book is empty\n");
              return;
       }
       printf("Contacts in the phone book:\n");
       printf("----------------------------------------------------------------------------------------\n");
       printf("%-30s%-20s%-30s\n", "Name", "Phone Number", "Email");
       printf("----------------------------------------------------------------------------------------\n");
       CONTACT *ptr = start;
       bubbleSort(ptr);
       while (ptr != NULL)
       {
              printf("%-30s%-20lld%-30s\n", ptr->name, ptr->ph, ptr->email);
              ptr = ptr->rl;
       }
       printf("----------------------------------------------------------------------------------------\n");
}

int main()
{
       int choice;
       system("cls");
       while (1)
       {
              printf("\nMENU\n");
              printf("----------------------------------------------------------------------------------------");
              printf("\n1.Add Contact\n2.Search Contact\n3.Update Contact\n4.Delete Contact\n5.Display\n6.Exit\n");
              printf("----------------------------------------------------------------------------------------\n");
              printf("Enter Your Choice: ");
              scanf("%d", &choice);
              switch (choice)
              {
              case 1:
                     start = add_contact();
                     break;
              case 2:
                     start = search_contact();
                     break;
              case 3:
                     start = update_contact();
                     break;
              case 4:
                     start = delete_contact();
                     break;
              case 5:
                     display_contacts();
                     break;
              case 6:
                     printf("Exited from the program\nThank You\n");
                     exit(0);
              default:
                     printf("Enter a valid choice\n");
                     break;
              }
       }
       return 0;
}
