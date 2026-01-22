#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"


int main()
{
    system("color 70");
    int flights_number = 99;
    Flight* flights = (Flight*)malloc(flights_number * sizeof(Flight));
    initialize(flights, flights_number); // initializes the array

//----------MAIN_MENU----------------//
    while(1)
    {
      system("cls");
        printf("\n\t\t\t CHOOSE ITEM OF MENU.......:\n");
        printf("\n\t\t\t PRINT TABLE...............0");
        printf("\n\t\t\t INPUT DATA................1");
        printf("\n\t\t\t OUTPUT DATA...............2");
        printf("\n\t\t\t SEARCH MINIMAL............3");
        printf("\n\t\t\t SEARCH FOR VALUE..........4");
        printf("\n\t\t\t SORTING...................5");
        printf("\n\t\t\t EDIT ELEMENT..............6");
        printf("\n\t\t\t CALCULATE TICKET PRICE....7");
        printf("\n\t\t\t CLEAR LINE................8\n");
        printf("\n\t\t\t EXIT......................Esc");
      switch (getch())
       {            // call function
         case '0': output_table(flights, flights_number);
            break;
         case '1': input_data(flights,flights_number);
            break;
         case '2': output_menu(flights, flights_number);
          break;
         case '3': search_min_menu(flights, flights_number);
            break;
         case '4': search_menu_for_value(flights, flights_number);
            break;
         case '5': sort_menu_for_value(flights, flights_number);
            break;
         case '6': edit(flights, flights_number);
            break;
         case '7': average_price(flights, flights_number);
            break;
         case '8': clear_entry(flights, flights_number);
            break;
         case 27:  // exit attempt
             {
                int ex = exit_dialog();
                switch(ex){
                case 1: // exit
                    {
                        int count = 0;
                        for(; count < flights_number; ++count){
                            free(flights + count);
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
