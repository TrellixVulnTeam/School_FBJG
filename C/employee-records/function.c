#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "function.h"

void header()
{

clear();
gotoxy(1,1);
printf("Welcome to LUMO company (TM) Termlink\n\n");

}

int load(Temployee company[])
{
  
  int i = 0,checker = 0, base = 0, count = 0, number = 0, change = 0, found = 0;
 
  FILE *f;
  
  Temployee local;
 
  if((f=fopen("udaje.bin","rb")) == NULL) //otevreni s osetrenim
  {  
	printf("\n No such file in directory\n");
  }

   while( fread(&local, sizeof(Temployee), 1, f) == 1) 
        { 
          company[i] = local;
          i++;
          number++;
         }  
    header();
    
    printf(" Number of adding employee: ");
    scanf("%d", &count);
    
    system("cls");
    for(base = 0; base < count; base ++)
    {
     do //kontrola jedinecnosti ID
     {
     header();     
     do //id musi byt vetsi nez 0
     {        
     printf(" Choose ID: ");
     scanf("%d", &checker);
     }while(checker < 1);
     
     found = 0;
     
     for(i = 0; i < number; i++) //porovnavani zadaneho ID s temi co mame jiz v bin souboru
     {
         if(checker == company[i].id)
         {
           found = 1;
         }

     }    
     
     }while(found == 1);
     company[base].id = checker; //pripsani cisla do pole
     getchar();
       
     printf(" Add FIRST NAME of employee: "); //jmeno
     gets(company[base].first_name);
  

  
     printf(" Add LAST NAME of employee: "); //prijmeni        
     gets(company[base].last_name);  
     system("cls");          
             
    }
  if (fclose(f)==EOF) //uzavreni bin 
  { 
        printf("\n File was unable to close\n"); 
  }  
    
return count; //vraci hodnotu nami zadaneho poctu zaznamu   
}

int from_min(Temployee company[]) //serazeni od min po max id
  {
  int i = 0, count = 0, change = 0;
  
  FILE *f;
  
  Temployee local;
   
  if((f=fopen("udaje.bin","rb")) == NULL) //otevreni v rezimu r s osetrenim
  {  
	printf("\n No such file in directory\n");
  }

   while( fread(&local, sizeof(Temployee), 1, f) == 1) //precteni a ulozeni zaznamu do company[i]
        { 
          company[i] = local;
          i++;
          count++;
         }  

  do
  {
  change = 0;
  header();
  for(i = 0; i < count-1; i++) //serazeni zaznamu
  {
   if(company[i].id > company[i + 1].id)
   {
    local = company[i];                    
    company[i]   = company[i+1];
    company[i+1] = local;
    change = 1;   
   }
  }  
                    
  }while(change == 1);

  if (fclose(f)==EOF) //uzavreni bin
  { 
        printf("\n Soubor se nepodarilo zavrit\n"); 
 
  }
  return count;
}


void add(Temployee company[], int count)  //pridavani zaznamu do bin souboru  
{
  FILE *f;
  int i;
  if((f=fopen("udaje.bin","ab"))==NULL) //otevre v rezimu add
  {  
	printf("\n No such file in directory\n");
  }
  for(i=0; i<count; i++) //zapis
  {
        fwrite(&company[i], sizeof(Temployee), 1, f);
  }
  printf("\n Your employees were successfully added\n"); //potvrzeni uzivateli
  if (fclose(f)==EOF) //uzavreni bin
  { 
        printf(" File was unable to close"); 
 
  }

}

void update_file(Temployee company[]) //update zaznamu
{
 FILE *f;
  
  Temployee local;
  
  int i = 0, count = 1, chosen_id, holder = 0, found;   

  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
  }    
   while( fread(&local, sizeof(Temployee), 1, f) == 1) //precteni a ulozeni zaznamu do company[i]
        { 
          company[i] = local;
          i++;
          count++;
         } 
         header();
     do //Dokud nenajde ID
     {
       printf(" Choose ID to update: "); //vybirame id
       scanf("%d", &chosen_id);
       header();
       
            
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho ID s temi co mame jiz v bin souboru
     {
           
         if(chosen_id == company[i].id)
         {
           holder = i;
           found = 1;
         }

     }    
     if(found==0) //oznameni uzivateli
     {
     header();
     printf("\n ID not found\n\n");
     }
     
     }while(found == 0);
     
     do //Dokud najde ID
     {
     printf("\n (Leave [0] if you do not want to change ID)\n");
     printf("\n Change ID: ");
     scanf("%d", &chosen_id);
     
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho ID s temi co mame jiz v bin souboru
     {
           
         if(chosen_id == company[i].id) //zabrane
         {
           header();
           printf(" ID is already taken");
           found = 1;
         }

     }    
     if(chosen_id == 0) //pri zadani 0 nedela nic
     {
     header();
     printf(" ID is still %d", company[holder].id);
     }
     else if(found == 0) //prepsani
     {
     header();
     company[holder].id = chosen_id;
     printf(" ID is now %d", company[holder].id);    
     }
     }while(found == 1);
         
     getchar();
     press_continue();
     header();

     printf("\n Change First name: ");
     gets(company[holder].first_name);
     
     printf("\n Change Last name: ");
     gets(company[holder].last_name);     

  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }
  if((f=fopen("udaje.bin","wb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
  }    

  for(i=0; i<count - 1; i++) //zapis
  {
        fwrite(&company[i], sizeof(Temployee), 1, f);
  }
  
  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }
  header();         
  printf(" Employee was succesfully updated\n");
  press_continue();
}

void delete_file(Temployee company[]) //odstraneni zaznamu
{
 FILE *f;
  
  Temployee local;
  
  int i = 0, count = 1, chosen_id, holder = 0, found;   
  
  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
  }    
   while( fread(&local, sizeof(Temployee), 1, f) == 1) //precteni a ulozeni zaznamu do company[i]
        { 
          company[i] = local;
          i++;
          count++;
         } 
         header();
     do //Dokud nenajde ID
     {
       printf(" Choose ID to delete: "); //vybirame id
       scanf("%d", &chosen_id);
       header();
       
            
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho ID s temi co mame jiz v bin souboru
     {
           
         if(chosen_id == company[i].id)
         {
           holder = i;
           found = 1;
         }

     }    
     if(found==0) //oznameni uzivateli
     {
     header();
     printf("\n ID not found\n\n");
     }
     
     }while(found == 0);
  
  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }
  
  if((f=fopen("udaje.bin","wb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
  }  
  for(i=0; i<count - 1; i++) //zapis
  {
        if(i != holder)
        fwrite(&company[i], sizeof(Temployee), 1, f);
  }
  
  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }
  header();
  printf(" Employee was succesfully removed\n");
  getchar();
}

int read(Temployee company[]) //precte bin soubor NEvypise
{
  header();
  FILE *f;
  
  Temployee local;  
 
  int i = 0, count = 0;
  if((f=fopen("udaje.bin","rb")) == NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
	return -1;
  }

   while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
        { 
          company[i] = local;
          i++;
          count++;
         }
  if (fclose(f)==EOF) //uzavira
  { 
        printf("\n File was unable to close\n "); 
  }

  return count; //vraci pocet zaznamu
 }

int read_chosen_id(Temployee company[])
{
  FILE *f;
  color(2);
  Temployee local;
  
  int chosen_id, found = 1, i = 0, count = 0, holder;   
  
  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
	return -1;
  }     
     while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
        { 
          company[i] = local;  
          i++;
          count++;
         }

     header();
     do //Dokud nenajde ID
     {
       printf(" Choose ID: "); //vybirame id
       scanf("%d", &chosen_id);
       system("cls");
       
            
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho ID s temi co mame jiz v bin souboru
     {
           
         if(chosen_id == company[i].id)
         {
           holder = i;
           found = 1;
         }

     }    
     if(found==0) //oznameni uzivateli
     {
     header();
     printf("\n ID not found\n\n");
     }
     
     }while(found == 0);

  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }       
 count = holder;
 return count;    
}

int read_chosen_first_name(Temployee company[]) //hledani podle jmena
{
  FILE *f;
  color(2);
  Temployee local;
  
  int h = 0, found = 1, i = 0, count = 0, holder, name[20];   
  char chosen_first_name[30];
  
  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
	return -1;
  }     
     while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
        { 
          company[i] = local;  
          i++;
          count++;
         }

     header();
     do //Dokud nenajde jmeno
     {
       printf(" Choose First name: "); //vybirame jmeno
       gets(chosen_first_name);
       system("cls");
       
            
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho jmena s temi co mame jiz v bin souboru
     {
           
         if(strcmp(chosen_first_name, company[i].first_name) == 0)
         {
           company[h].id = i;
           h++;
           found = 1;
         }

     }    
     if(found==0)
     {
     header();
     printf("\n First name not found\n\n"); //oznameni
     }
     
     }while(found == 0);

  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }       
 return h; 
     
}

int read_chosen_last_name(Temployee company[]) //hledani prijmeni
{
  FILE *f;
  color(2);
  Temployee local;
  
  int h = 0, found = 1, i = 0, count = 0, holder, name[20];   
  char chosen_last_name[30];
  
  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  
	printf("\nNo such file in directory\n");
	return -1;
  }     
     while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
        { 
          company[i] = local;  
          i++;
          count++;
         }

     header();
     do //Dokud nenajde prijmeni
     {
       printf(" Choose Last name: "); //vybirame prijmeni
       gets(chosen_last_name);
       system("cls");
       
            
     found = 0;
     
     for(i = 0; i < count; i++) //porovnavani zadaneho prijmeni s temi co mame jiz v bin souboru
     {
           
         if(strcmp(chosen_last_name, company[i].last_name) == 0) //shoda
         {
           company[h].id = i;
           h++;
           found = 1;
         }

     }    
     if(found==0)
     {
     header();
     printf("\n Last name not found\n\n");
     }
     
     }while(found == 0);

  if (fclose(f)==EOF) //uzavira bin
  { 
        printf("\n File was unable to close\n"); 
 
  }       
 return h; 
     
}

int status(Temployee company[]) // status kolik zamestnancu, min a max id vypise zde
{
  header();
  FILE *f;
  
  Temployee local;
  
  int i = 0, count = 0, min, imin, max, imax;   
  
  if((f=fopen("udaje.bin","rb"))==NULL) //otevira
  {  

	printf("\n No such file in directory\n");
	return -1;
  }     
     while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
        { 
          company[i] = local;  
          i++;
          count++;
         }

         printf(" You have %d employees\n They are happy and healthy\n", count); //kolik zaznamu
         
         min = company[0].id; //priprava na urceni minima a maxima
         max = company[0].id;
         imin = 0;
         imax = 0; 
         for(i = 1; i < count; i++) //urceni minima a maxima
         {
         
         if(company[i].id < min)
         {
          min = company[i].id;
          imin = i;
         }
         if(company[i].id > max)
         {
          max = company[i].id;
          imax = i;     
         }
         }
         
         printf(" Lowest ID is %d\n Highest ID is %d\n", min, max); //vypsani min a max
         
  if (fclose(f)==EOF) //zavira
  { 
        printf("\n File was unable to close\n"); 
 
  }

}

void print(Temployee company[], int count)//vseobecne vypsani
{

int i = 0;

do
{ 
           printf(" Id: %d\t", company[i].id);  
           printf("| First name: %s \t", company[i].first_name);
           printf("| Last name: %s\n", company[i].last_name);      
           i++;
}while(i < count);
     
}

void print_chosen_id(Temployee company[], int count) //vypsani vybraneho id
{
           header();
           printf(" Id: %d\t", company[count].id);
           printf("| First name: %s\t", company[count].first_name);
           printf("| Last name: %s |\t\n", company[count].last_name);    
}

void print_chosen_name(Temployee company[],int count) //vypsani vybraneho jmena
{
           header();
           
           FILE *f;
           
           Temployee local;
           int i = 0, h = 0, name[20];
           for(i = 0; i < count; i++)
           {
                 name[i] = company[i].id; //prepis nalezenych pozic
           }       
     
           if((f=fopen("udaje.bin","rb"))==NULL) //otevira
           {  
               	printf("\n No such file in directory\n");
           } 
           
           i = 0;
           while( fread(&local, sizeof(Temployee), 1, f) == 1) //cte a uklada do company[i]
           { 
            company[i] = local;  
            i++;
           }
           do //vypise VSECHY nalezene
           {
           i = name[h];
           printf(" Id: %d\t", company[i].id);
           printf("| First name: %s\t", company[i].first_name);
           printf("| Last name: %s |\t\n", company[i].last_name);    
           h++;
           }while(h < count);

           if (fclose(f)==EOF) //zavira
           { 
           printf("\n File was unable to close\n"); 
           }
           
}
