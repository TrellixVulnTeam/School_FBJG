#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "function.h"

void menu(void) // samotné menu
{
    header();
    int position = 1;
    int end = 0;
    int number, count = 10;
    print_menu(position, count, 1);
    Temployee company[40];
    color(2);
    while(end == 0) //kdy ukoncit a kdy ne
    {
        if (kbhit())
        {
            int Key;
            Key = MyGetch();
            if(Key) 
            {
            switch(Key) //co maji delat klavesy
            {
                case 27:  //escape
                end = 1;
                break;
                case 328: // up
                if (position > 1) position--;
                else position = count;
                break;
                case 336: // down
                if(position < count) position++;
                else position = 1;
                break;
                case 13: // enter
                switch(position) //funkce na pozicich
                {
                    case 1: 
                            number = load(company);
                            add(company, number);
                            press_continue();
                            menu();
                            break;
                    case 2: 
                            number = read(company);
                            print(company, number);
                            press_continue();
                            update_file(company);
                            press_continue();
                            menu();
                            break;        
                    case 3: 
                            number = read(company);
                            print(company, number);
                            press_continue();
                            delete_file(company);
                            press_continue();
                            menu();
                            break;                    
                    case 4: 
                            number = read(company);
                            print(company, number);
                            press_continue();
                            menu();
                            break;
                    case 5: 
                            number = from_min(company);
                            print(company, number);
                            press_continue();
                            menu();
                            break;        
                    case 6:        
                            number = read_chosen_id(company);
                            print_chosen_id(company, number);
                            getchar();                            
                            press_continue();
                            menu();                            
                            break;
                    case 7:        
                            number = read_chosen_first_name(company);
                            print_chosen_name(company, number);
                            press_continue();
                            menu();                            
                            break;
                    case 8:        
                            number = read_chosen_last_name(company);
                            print_chosen_name(company, number);
                            press_continue();
                            menu();                            
                            break;
                    case 9: 
                            status(company);
                            press_continue();
                            menu();                            
                            break;    
                    case 10: 
                            color(0);
                            clear();
                            end = 1;
                            }
                    default:
                    continue;
                }
            }
            print_menu(position, count, 1);
        }
    }
    
    exit(0);
}

void press_continue()
{     
printf("\n Press [ENTER] to continue");
getchar();
}

void print_menu(int position, int count, int i) // vypsání menu pole pomocí cyklu
{
    char *option[] = {"[Add employee]","[Update employee]","[Remove employee]","\n [Your employees]","\n [Your employees SORT by ID]","\n\n [Find employee by ID]","\n\n [Find employee by First name]","\n\n [Find employee by Last name]","\n\n\n [Status]","\n\n\n\n\n [End]"};
    for(i = 0; i < count; i++)
    {
        gotoxy(1,3+i);
        if ((i+1)==position) color(3); else color(2);
        printf("%s\n",option[i]);
    }
}
