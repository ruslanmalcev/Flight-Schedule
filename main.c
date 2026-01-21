#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"

#define P printf
#define S scanf
#define N 45
#define M 15

int main()
{
    system("color 70");
    int n; // number of elements
    Flight* pt;
    n=35;
    pt = (Flight*)malloc(n * sizeof(Flight));
    initialize(pt,n); // initializes the array

//----------MAIN_MENU----------------//
    while(1)
    {
      system("cls");
        P("\n\t\t\t CHOOSE ITEM OF MENU.......:\n");
        P("\n\t\t\t PRINT TABLE...............0");
        P("\n\t\t\t INPUT DATA................1");
        P("\n\t\t\t OUTPUT DATA...............2");
        P("\n\t\t\t SEARCH MIN VALUE..........3");
        P("\n\t\t\t SEARCH FOR VALUE..........4");
        P("\n\t\t\t SORTING...................5");
        P("\n\t\t\t DELETE ELEMENT............6");
        P("\n\t\t\t EDIT ELEMENT..............7");
        P("\n\t\t\t CALCULATE TICKET PRICE....8");
        P("\n\t\t\t CLEAR LINE................9\n");
        P("\n\t\t\t EXIT......................Esc");
      switch (getch())
       {            // call function
         case '9': clear_entry(pt,n);
            break;
         case '0': output_table(pt,n);
            break;
         case '1': input_data(pt,n);
            break;
         case '2': output_menu(pt,n);
          break;
         case '3': search_min_menu(pt,n);
            break;
         case '4': search_menu_for_value(pt,n);
            break;
         case '5': sort_menu_for_value(pt,n);
            break;
         case '6': delete_element(pt,&n);
            break;
         case '7': edit(pt,n);
            break;
         case '8': average_price(pt,n);
            break;
         case 27:  // exit attempt
             {
                int ex = exit_dialog();
                switch(ex){
                case 1: // exit
                    {
                        int count = 0;
                        for(; count < n; ++count){
                            free(pt + count);
                        }
                        return 0;
                    }

                case 0:
                    break;
                }
                break;
             }
        default: continue;
      }
    }
return 0;
}// main()
