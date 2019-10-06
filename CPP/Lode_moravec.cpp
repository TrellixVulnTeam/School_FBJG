#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h>
#include <iostream>
#include <windows.h>
#include <locale.h>
 
int main()
{
    FILE *f;
    
    int N=10;
    char battlefield[N][N];
    char boat='#', X='X', O='O', save=0, nick, file, open=0;

    int size=0, x=0, y=0, hit=0, miss=0, total, bx, by, count, i, missing=0, ano, ne;  
    
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

do
{
    if(size>2 || size<10)
    {
printf("Zadejte velikost bitevniho pole (max. 10): "); //Zadání velikosti pole
scanf("%d", &size);
system("cls");
    }
    else
    {
printf("Zadejte spravnou velikost bitevniho pole (max. 10): "); //Oprava zadavání
scanf("%d", &size);           
system("cls");
}
}while(size>10 || size<2);

    N=size;


    for(y=1; y<=N; y++)
    {
         for(x=1; x<=N; x++) 
         {
              battlefield[x][y]='^';
         }
    }
    do
    {
    printf("Zadejte pocet lodi(max. %d): ", size); //Zádání poctu lodí
    scanf("%d", &count);
    system("cls");
    }while(count>size);
  srand( (unsigned) time(NULL) );
                                 
  for (i=0; i<count; i++)   
  {                      
       bx = rand() % N+1;
       by = rand() % N+1;
       battlefield[bx][by]=boat; 
  }  

total=count;     
missing=count;

 do
 {
printf("                                    HIT: %d\n\n", hit);
printf("                                   MISS: %d\n\n", miss);
printf("                                  BOATS: %d\n\n", missing);   
  SetConsoleTextAttribute(hConsole, 15);
         printf("0 |  ", x);                 
    for(x=1; x<=N; x++)
    {             
         if(x<10)
         {    
         printf("%d ", x);        
         }
         else
         {
         printf("%d", x);                     
         }
    }
         printf("\n---------------------------------------------\n");    

    for(y=1; y<=N; y++)
    {
       SetConsoleTextAttribute(hConsole, 15);
         if(y<10)
         {    
         printf("%d | ", y);        
         }
         else
         {
         printf("%d| ", y);                     
         }

         for(x=1; x<=N; x++) 
         {

              printf(" ");        

              if (battlefield[x][y] == boat)
                 {
                   printf("^");
                 }      
              else 
                 {
                   SetConsoleTextAttribute(hConsole, 15);                                
                   printf("%c", battlefield[x][y]);
                 }
         }
         printf("\n");
    }
    x=0;
do
{    
     
if(x<N)
{
printf("\nZadejte souradnici X: ");
scanf("%d", &x);
}
else
{
printf("\nZadejte spravnou souradnici X: "); 
scanf("%d", &x);
}
}while(x>N || x<1);
do
{
if(y<N )
{
printf("Zadejte souradnici Y: ");
scanf("%d", &y);
}
else
{
printf("Zadejte spravnou souradnici Y: ");    
scanf("%d", &y);
}
}while(y>N || y<1 || battlefield[x][y] == X || battlefield[x][y] == O);
if (battlefield[x][y] == boat)         //trefa  
{ 
  battlefield[x][y] = X;
  system("COLOR 0A");
  hit ++;
  missing --;
}
   else //veldle
{
   battlefield[x][y] = O;    
   system("COLOR 4");
   miss ++;   
}

system("cls");

 }while(total>hit);
 
 //konec hry
 
  system("cls");

  
  if(f == NULL)
  {
       printf("Error\n");
       exit(1);
  }
  do
  {
  printf("                         Gratuluji vyhral jste!!\n\nPrejete si ulozit statistiky? \ny/n: ");
  scanf("%s", &save);
  }while(save == 0);
  
  if(save == 'y')
  {
       do
       {   
       f= fopen("statistic.txt", "a");
  if(f == NULL)
  {
       printf("Error\n");
       exit(1);
  }       
       system("cls");
       printf("Zadejte nickname: ");  
       scanf("%s", &nick);
       }while(nick==' ');
       
       fprintf(f, "\nNICKNAME: %s\nBOATS: %d\nHIT: %d\nMISS: %d\nSIZE OF BATTLEFIELD: %d\n\n", &nick, count, hit, miss, size);
       fclose(f);       
  }
  else
  {
       system("cls");
       printf("                       NASHLEDANOU\n\n");  
  }


    printf("Chcete vypsat statistiku?\ny/n:");
    scanf("%s", &open);
    if(open == 'y')
    {
    f = fopen("statistic.txt", "r"); //priprava cteni
  if(f == NULL)
  {
       printf("Error\n");
       exit(1);
  }    
    while( ( file = fgetc(f) ) != EOF )
    printf("%c", file); //velké finále
    fclose(f);
    }
    system("pause");
    getchar(); 
    return 0;
}
