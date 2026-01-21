#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "functions.h"

#define P printf
#define S scanf
#define N 45
#define M 15

char city[N][M]={"NEW YORK","KIROV","MOSCOW","ST.PETERBURG","EKATERINBURG","ROSTOV",
         "KRASNODAR","PETROPAVLOVSK","NOVOSIBIRSK","OMSK","HABAROVSK","CHITA","YAKUTSK","MURMANSK",
       "ARKHANGELSK","STAVROPOL","ORENBURG","PERM","UFA","SAMARA","VOLGOGRAD","SARATOV",
       "IRKUTSK","IJEVSK","PSKOV","PETROZAVODSK","KAZAN","ULYANOVSK","VLADIVOSTOK","SURGUT",
       "BLAGOVESHENSK","ULAN-UDE","BELGOROD","VORONEJ","ABAKAN","KRASNOYARSK","KEMEROVO",
       "BARNAUL","CHELYABINSK","BRATSK","SYKTYVKAR","KIEV","MINSK","ASTANA","ADLER"};

//--------init---------------//
void initialize(Flight* p,int m)// initializing the database
{
       int i,j,k;
       srand(time(NULL));
        for(i = 0; i < m; i++)
        {
            k = 0 + rand() % N;// city name
            p[i].flightNumber = 1 + rand() % 999;// flight number
            for(j = 0; j < M; j++)
            {
               p[i].pointDestination[j] = city[k][j];
            }
            p[i].price=6000+rand()%3000;
            p[i].date.day=5+rand()%7;
            p[i].date.month=12;
            p[i].date.time.hour=0+rand()%24;
            p[i].date.time.minute=60/(2+rand()%3);
        }

} // init()

//--------print--------------//
void output_table(Flight* p,int z)//âûâîä òàáëèöû
{
    system("cls");
    system("color 1F");
    int y;
         P("\t| N|  N|           DESTINATION           |    DATE |    TIME |         PRICE|\n");
         P("\t-----------------------------------------------------------------------------\n");
    for(y = 0; y < z; y++)
    {
        P("\t|%2d|%3d|       %15s           |   %2d.%2d |   %2d: %2d|         %5d|\n"
        ,y+1,
        p[y].flightNumber,p[y].pointDestination,
        p[y].date.day,
        p[y].date.month,
        p[y].date.time.hour,
        p[y].date.time.minute,
        p[y].price
        );
    }
         P("\t-----------------------------------------------------------------------------\n\
            \\t<Esc> to return in menu...>");
         //P("\t<Esc> to return in menu...");
   while(1)
   {
   switch(getch())
    {
        case 27:
           break;
        default:
            continue;
    }
    break;
  }
     system("color 70"); // changes color like color in the menu
     return;
}// print()

//--------clear--------------//
int clear_entry(Flight* p,int z)
{
    int i;
         system("cls");
     P("\n\t\t\tCLEARING LINES.\n");
    while(1)
    {
          P("\r\t\t\t                               ");
          P("\r\t\t\tNUMBER of a LINE(or <Esc>):");
         i = input_numbers(5,0);
         if(i == -1)
            return i;
         if (i > z) // very large line number
          {
            P("\r\t\t\tWRONG NUMBER of the LINE          ");
            Sleep(1500);
            continue;
          }
        i--;
        p[i].flightNumber = 0;
        p[i].pointDestination[0] = '\0';
        p[i].price = 0;
        p[i].date.day = 0;
        p[i].date.month = 0;
        p[i].date.time.hour = 0;
        p[i].date.time.minute = 0;
    }
   return i;
}// clear()

//--------input--------------//
void input_from_keyboard(Flight* pr,int x)
{

    int i,r;
    system("cls");
       P("\n\n\t\t\tINPUT DATA of a FLIGHT:\n");
    while(1)
    {
         r = search_free_entry(pr,x);
         if(r<0)
            {
                P("\n\n\t\t\tTHERE IS NOT ANY EMPTY LINE");
            Sleep(1700);
            }
     P("\r\t\t\tNUMBER of a LINE(or <Esc>):");
     i = input_numbers(5,0);
     if(i == -1)
        return;
       if(i > x)// very large number
       {
           P("\r\t\t\tTOO MUCH NUMBER!                           ");
           Sleep(1500);
           continue;
       }
       i--;
       if(pr[i].pointDestination[0]!='\0')
       {
           P("\r\t\t\tTHIS LINE is not EMPTY.                     ");
           Sleep(1500);
           P("\r\t\t\tDO YOU WANT REWRITE IT(Y/N)?");
        while(1)
           {
               switch (getch())
            {
            case 'n': case 'N': return;
            case 'y': case 'Y': break;
            default: continue;
            }
            break;
           }
       }

     break;
    }
    input_data(pr,i);
}// input()

//---------inputdata----------//
    void input_data(Flight* s, int a)
{
    int x, j, r_num;
    while(1){
        P("\n\t\t\tNUMBER of a FLIGHT:");
        r_num = input_numbers(5, 0);
        switch(r_num){
        case -1: continue;
        default:
            s[a].flightNumber = r_num;
            break;
        }
        break;
    }
        P("\n\t\t\tPOINT of the DESTINATION:");
        j = input_city_name();
        if(j >= 0)
        {
            int i;
            for(i = 0; city[j][i] != '\0'; i++)
            s[a].pointDestination[i] = city[j][i];
            s[a].pointDestination[i] = '\0';
        }
        if(j == -2)
            P("\tNO SUCH DIRECTIONS");

       P("\n\t\t\tDATE DEPARTURE:");
       while(1){
            P("\n\t\t\tmonth: ");
            switch(r_num = input_numbers(2,0)){
                case -1: continue;
                default: s[a].date.month = r_num;
                break;
            }
        break;
       }
       while(1){
            P("\n\t\t\tday: ");
                x = number_day_in_month(s[a].date.month);
            switch(r_num = input_numbers(1,x)){
                case -1: continue;
                default:
                s[a].date.day = r_num;
                break;
            }
            break;
       }
    P("\n\t\t\tTIME DEPARTURE:");
   while(1){
        P("\n\t\t\thour: ");
        switch(r_num = input_numbers(3, 0)){
            case -1: continue;
            default: s[a].date.time.hour= r_num;
            break;
        }
        break;
   }
    while(1){
        P("\n\t\t\tminute: ");
          switch(r_num = input_numbers(4,0)){
              case -1: continue;
              default: s[a].date.time.minute = r_num;
              break;
          }
          break;
    }
    while(1){
        P("\n\t\t\tPRICE of the TICKET:");
        switch(r_num = input_numbers(6, 0)){
        case -1: P("\n\t\tWrong price!");
            Sleep(1700);
            continue;
        default:
            s[a].price = input_numbers(6,0);
            break;
        }
        break;
    }
}// inputdata()

//--------output-------------//
void output_menu(Flight* p,int z)
{
    int j,i,k;
    while(1)
    {
        system("cls");
    P("\t\t\tOUTPUT DATA of FLIGHTS.\n\n");
    P("\n\t\t\t<Esc> to return : ");
    j = input_city_name();
     if(j == -1)
        return;
     if(j == -2)
      {
        P("\tNO SUCH DIRECTION!");
       Sleep(2500);
      continue;
      }
      for(k = i = 0; i < z; i++)
      {
          if(!strcmp(city[j],p[i].pointDestination))
            {
             output_data(p,i);
             k++;
            }
      }
      if(!k)// no matches
      P("\n\n\t\t\tTHERE are not FLIGHTS to this  CITY");
     switch(getch())
       {
        case 27:
            return;
        default:
            continue;
       }

    }
}// output()

//----------dataout---------//
void output_data(Flight* s,int a)// flight data output
{
    P("\n\n\t\t\tNUMBER of the FLIGHT:%d", s[a].flightNumber);
    P("\n\t\t\tPOINT of the DESTINATION: %s", s[a].pointDestination);
    P("\n\t\t\tDATE DEPARTURE: %d.%d", s[a].date.day,
      s[a].date.month);
    P("\n\t\t\tTIME DEPARTURE: %d:%d", s[a].date.time.hour,
      s[a].date.time.minute);
    P("\n\t\t\tPRICE of the TICKET: %d", s[a].price);

}// dataout()

//--------search free--------//
int search_free_entry(Flight* p, int z)// search free variable
{
    int i,k;
    k = -1;
    for (i = 0; i <= z; ++i)
     {
        if(p[i].pointDestination[0] == '\0')
        {
           P("\tLINE %d IS EMPTY.\n", i+1);
          ++k;
        }

     }
return k;
}// search free()

//-------search minimal------//
void search_min_menu(Flight* p, int z)
 {
     int j=0;
    while (1)
    {
         system("cls");
     P("\n\t\t\tSEARCH MINIMAL\n\
        \\t\t\tCHOOSE the ELEMENT of DATA:\n\
        \\t\t\tDATE and TIME............1\n\
        \\t\t\tPRICE....................2\n\
        \\t\t\tRETURN...................Esc");

       switch (getch())
        {
            case '1': j = search_min_date(p,z);
              break;
            case '2': j = search_min_price(p,z);
              break;
            case 27: return;
            default : continue;// another key
         }

    output_data(p,j);
    getch();
      }
}// search minimal()

//------search value---------//
void search_menu_for_value(Flight* p, int z)
{
    int j = 0;
    while(1)
    {
         system("cls");
     P("\t\t\t\tSEARCH FOR VALUE\n");
     P("\n\t\t\tCHOOSE the ELEMENT of DATA:\n");
     P("\n\t\t\tDATE and TIME............1\n");
     P("\n\t\t\tPRICE....................2");
     P("\n\n\n\t\t\tRETURN...................Esc");
       switch (getch())
        {
            case '1': j = search_for_date(p,z);
            if(j == -2)// Esc
                continue;
            if(j == -1)
            {
            P("\n\t\t\tTHERE ARE NOT any FLIGHTS at that DAY");
            Sleep(1500);
            continue;
            }
               break;
            case '2': j = search_for_price(p,z);
            if(j == -1) // Esc
                continue;
                break;
            case 27: return;
            default: continue;
         }
   output_data(p,j);
   getch();
    }
}// search value()

//-------sorting-------------//
void sort_menu_for_value(Flight* p, int z)
{
     while (1)
    {
         system("cls");
     P("\t\t\t\tSORTING\n");
     P("\n\t\t\tCHOOSE the ELEMENT of DATA:\n");
     P("\n\t\t\tALPHABET..................1\n");
     P("\n\t\t\tDATE and TIME.............2\n");
     P("\n\t\t\tPRICE.....................3\n");
     P("\n\n\n\t\t\tRETURN....................Esc");
        switch (getch())
        {
            case '1':
            alphabet_sort(p,z);
            output_table(p,z);
               break;
            case '2':
            date_sort(p,z);
             output_table(p,z);
                break;
            case '3':
              price_sort(p,z);
               output_table(p,z);
              break;
            case 27:
                return;
            default:
                continue;
        }
     }
}// sorting()

//-------delete element-----//
void delete_element(Flight* p,int* x)
{
     int i,j;
    system("cls");
    P("\n\n\t\t\tDELETE ELEMENT.");
    while(1)
    {
    P("\n\n\n\t\t\tINPUT NUMBER of ELEMENT(or <Esc>):");
    j = input_numbers(5,0);
    if(j < 0)
        return;
    if(j < *x && j > 0)
    break;
    P("\n\n\t\t\t\tTOO MUCH NUMBER");
    Sleep(1500);
    }
     for(i = j-1; i < *x-1 ; ++i)
      {
        p[i] = p[i+1];
      }
    --(*x);
   free(p + i);
}// delete element()

//-------edit---------------//
void edit(Flight* p,int x)// edit element
{
    int i;

    system("cls");
    P("\t\t\tEDIT ELEMENT\n\n\n");
    while(1)
     {
    P("\r\t\t\tINPUT a NUMBER of a LINE(or <Esc>):");
    i = input_numbers(5,0);
    if(i == -1)
        return;
       if(i > x)
        {
    P("\r\t\t\tTOO MUCH NUMBER of a LINE           ");
        Sleep(1500);
        continue;
        }
        break;
     }
     i--;
    output_data(p,i);
    P("\n");
    while(1)
    {
       P("\r\t\tA YOU SURE YOU WANT to EDIT the ENTRY?(Y/N)");
      switch(getch())
        {
        case 'n':
            return;
        case 'y':
            break;
        default:
            continue;
        }
        break;
    }
    input_data(p,i);
}// edit()

//-------calculate----------//
void average_price(Flight* p,int x)// ñalculate the average ticket price for the entered date.
{
     int d,m,i,sum,a; // day, month, counter, sum
     float sr; // average price
     int k; // logic-index
    while(1)
    {
     system("cls");
       sr=0.0;
    P("\t\t\tCALCULATE\n\n\n");
    P("\t\t\tINPUT the DATE(or <Esc>):\n");
    P("\n\t\t\tmonth:");
    m=input_numbers(2,0);
    if(m < 0)
        return;
       a = number_day_in_month(m);
    P("\n\t\t\tday:");
    d = input_numbers(1,a);
    if(d < 0)
        return;
    for(k = sum = i = 0; i < x; i++)
       {
           if( p[i].date.day == d && p[i].date.month == m)
           {
              sum += p[i].price; // sum if prices
                k++;// number of flights per day
           }
       }
    if(k>0) // if there are flights
     {
        sr = (float)sum/k; // average price
     P("\n\t\t\tMEDIAN PRICE:%.2f",sr);
     }
     if(k == 0)// no flights
     {
         P("\n\t\t\tTHERE ARE NOT any FLIGHTS at that DATE");
        Sleep(2000);
        P("\r\t\t\t                                       \r");
     }

    getch();
   }
}// calculate()

//--------pricemin----------//
int search_min_price(Flight* f, int x)
{
    int i,j,m,c;// i, j - counters, m - minimum, c - minimum index
    for(i = 0, m = f[i].price, c = i; i < x-1; i++)
       {
           for(j = i+1; j < x; j++)
           {
            if(f[j].price < m) // if less
              {
               m = f[j].price;
               c = j;
              }
           }
       }
       return c;// return index
}// pricemin()

//----------datemin----------//
int search_min_date(Flight* f,int x)
{
    int i,j,c;// i,j - counters, c - minimum index
      Flight m;// minimum
     for(i = 0, m = f[i], c = i; i < x-1; i++)
      {
        for(j = i + 1; j < x; j++)
        {
          if((f[j].date.day < m.date.day)
             || (f[j].date.day == m.date.day
                 && f[j].date.time.hour < m.date.time.hour)
             || (f[j].date.day == m.date.day &&
                  f[j].date.time.hour == m.date.time.hour
             && f[j].date.time.minute < m.date.time.minute))
          {
            m=f[j];
             c=j;
          }
        }
      }
  return c;
}// datemin()

//----------search date--------//
int search_for_date(Flight *f,int x) // date and time
{
    int i, d, k, m, md, a;
    int da,hr; // desired date
    k=-1;
    P("\n\n\n\t\t\tSEARCH by DATE");
    P("\n\t\t\tINPUT a DATE(or <Esc>):");
    P("\n\t\t\tmonth:");
    m = input_numbers(2,0);
    if(m < 0) return -2;
    a = number_day_in_month(m);
    P("\n\t\t\tday:");
    da = input_numbers(1, a);// enter day
    if(da < 0)// cancel input
        return -2;
    for(i = 0; i < x; ++i)
     {
       if(da == f[i].date.day)
            ++k;
     }
     if(k < 0)
     return k;
    P("\n\t\t\thour:");
    hr = input_numbers(3, 0);// enter hour
    if(hr < 0) return -2;
     for(i = 0, md = 1000; i < x; i++)
     {
        if(f[i].date.day == da)
        {
         if(f[i].date.time.hour == hr &&
             f[i].date.time.minute==0)
                return i;
         d = abs(f[i].date.time.hour * 60 // calculate the closest flight
               + f[i].date.time.minute - hr * 60);
         if(d < md)
          {
            md=d;// nearest
            k=i;// nearest index
          }
        }

    }
  return k;
}// search date()

//----------searchprice-------//
int search_for_price(Flight* f,int x)
{
    int i,k,d,md;
    int pr; // desired price
    P("\n\n\n\t\t\tSEARCH by PRICE(<Esc> to return)\n");
    P("\n\t\t\tINPUT the PRICE:");
    pr = input_numbers(6,0);// enter price
    if(pr == -1) // exit(ESC)
        return pr;
     for(k = i = 0, md = 10000; i < x; i++)
    {
     d = abs(f[i].price - pr);// price difference
     if(d == 0)
        return i;
     if(d < md)
     {
       md = d;
       k = i;
     }
    }
     return k;
}// searchprice()

//--------alphabetsort-------//
void alphabet_sort(Flight* f,int z)
{
   int i, j;// counters
    Flight temp;// temporary structure
    do
    {
     j = 0;
     for(i = 0; i < z-1; i++)
     {
      if(strcmp(f[i].pointDestination,
                f[i+1].pointDestination) > 0
         || (strcmp(f[i].pointDestination,
                    f[i+1].pointDestination) == 0
          && f[i].date.day>f[i+1].date.day)
         ||(strcmp(f[i].pointDestination,f[i+1].pointDestination) == 0
          && f[i].date.day == f[i+1].date.day
           && f[i].date.time.hour > f[i+1].date.time.hour)
          || (strcmp(f[i].pointDestination,
                     f[i+1].pointDestination)
              && f[i].date.day == f[i+1].date.day
          && f[i].date.time.hour == f[i+1].date.time.hour
          && f[i].date.time.minute > f[i+1].date.time.minute))
        {
         temp=f[i];
         f[i]=f[i+1];
         f[i+1]=temp;
         j++;
        }
      }
    }
     while(j!=0);
}// alphabetsort()

//-------datesort------------//
void date_sort(Flight* f,int z)
{
   int i,j;
    Flight temp;
    do
    {
        j=0;
    for(i = 0; i < z-1; i++)
     {
         if((f[i].date.day == f[i+1].date.day)
            && (f[i].date.month == f[i+1].date.month)
            &&(f[i].date.time.hour == f[i+1].date.time.hour)
            &&(f[i].date.time.minute == f[i+1].date.time.minute))
            continue;
     if((f[i].date.month > f[i+1].date.month)
        ||(f[i].date.month == f[i+1].date.month
           && f[i].date.day > f[i+1].date.day)
        ||(f[i].date.day == f[i+1].date.day
           &&f[i].date.time.hour > f[i+1].date.time.hour)
        ||(f[i].date.time.hour == f[i+1].date.time.hour
           && f[i].date.time.minute > f[i+1].date.time.minute))
        {
         temp = f[i];
         f[i] = f[i+1];
         f[i+1] = temp;
         j++;
        }
      }
    }
     while(j!=0);
}// datesort()

//------pricesort------------//
void price_sort(Flight* f,int z)
{
    int i,j;
    Flight temp;
    do
    {
        j = 0;
    for(i = 0; i < z-1; i++)
     {
         if(f[i].price == f[i+1].price)
            continue;
     if(f[i].price > f[i+1].price)
        {
         temp = f[i];
         f[i] = f[i+1];
         f[i+1] = temp;
         j++;
        }
      }
    }
     while(j != 0);
}// pricesort()

//----------getnumber-------//
int input_numbers(int e,int c) // input numbers
{// (date, hour, number of flight, string, element...)
   int i,n,d,f; //i-counert, n-number, f- number of characters
    int* g;
    if(e >= 1 && e <= 4) f = 2; // for date and time
        if(e == 5) f = 3; // for flights number
        if(e == 6) f = 5;// for price
        g = malloc(f * sizeof(int));// memory for numbers
       for(i = 0; ; )
        {
            d=getch();
            if(d==27) return -1; // exit, Esc

        if(d == 13 && i > 0)// if at least one input and Enter
           break;
        if(d == 8 && i > 0) //edit
        {
          g[--i] = 0;// index back and free element
          P("\b \b");
          continue;
        }
        if(d >= '0' && d <= '9')
        {
              if(i >= f)
                continue;
            g[i] = d-'0';
            P("%d", g[i++]);
        }
     }
     int j;
       for(n = j = 0; j < i; ++j)
        n = n * 10 + g[j];// get a decimal number
        free(g);

    switch (e)
    {
        case 1:  //days
        if(n == 0) n = 1;// enter 0
        if(n > c)
        {
            if(check_number_dialog()) n = c;
            else  return -1;//n = -1;
    } break;
   case 2:// months
     if(n == 0) n = 1;
     if(n > 12)
     {

       if(check_number_dialog()) n = 12;
       else return -1;//n = -1;
     } break;
   case 3:// hours
    if(n > 23)
    {

     if(check_number_dialog()) n = 23;
     else return -1;//n=-1;
    } break;
   case 4:// minutes
    if(n > 59)
    {
     if(check_number_dialog()) n = 0;
     else return -1;//n = -1;
    } break;
   case 5://number of flight, strings and e.t.c.
    if(n == 0) n = 1;
        break;
 }
   /* if(n != -1)
    {
        for(j = 0; j < i; ++j) P("\b \b");
        P("\t\t\t%d",n);// printing the final form of the number
    }*/
    return n;
}// getnumber()

//---------checknumber-----------//
int check_number_dialog() // checking the entered number
{
    //char ch;
    while(1)
    {
        //system("cls");
       P("\n\t\t\t The number you input is not correct");
       Sleep(2000);
    P("\r\t\t\t     Do you want to input nearest correct value(Y/N)? ");
    //scanf("%c",&ch);
    switch (getch())
     {
        case 'y': case 'Y':
             return 1;
        case 'n': case 'N':
             return -1;
        default: continue;
     }
    }

}// checknumber()

//--------daymonth------------//
int number_day_in_month(int month) // returns the number of days in a month
{
    int day_number;
    if(month == 2)// February
        day_number = 28;
    if(month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 ||
        month == 10 || month == 12)
        day_number=31;
    if(month  == 4 || month == 6 || month == 9 || month == 11)
        day_number = 30;
    return day_number;
}// daymonth()

//----------inputcity----------//
int input_city_name()// find city name
{
    int i,j,k,t,s;
    char d,c[M];
    k = -2;
     P("\n\t\t\tINPUT a CITY NAME:   ");
    for(i = 0, c[0] = '\0';;)
    {
        d = getch(); // Esc
        if(d == 27)
            return -1;
        if(d == 13 && i > 0)// Enter
        {
           return k;
        }
        if(d == 8 && i > 0) // backspace
            {
                P("\b \b");
                c[i--] = '\0'; // shift the end of the line to the left
            }
    if((d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z') || d == '.')
      {
                c[i] = d; //  d - char
                c[i+1] = '\0'; // shift zero to the right
                P("%c", c[i++]);// printing a symbol and erasing the previous inscription
                P("                    \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        for(j = 0; j < N; ++j)// match check
         {
            t = s = 0;
            if((c[0] == city[j][0]) || (c[0]-32) == city[j][0])
            {
             for(k = -2, t = 1; c[t] != '\0'; ++t)
               {
                if((c[t] == city[j][t]) ||
                   ((c[t]-32) == city[j][t]))
                {
                    s++;
                }
               }

                 if(s == t-1)// all entered characters matched
                 {
                     int z,w;
                        for(z = 0; z <= s; ++z)
                            P("\b");// shift the beginning of the word to the left
                        P("%s",city[j]);// output the word
                      for(z = 0; city[j][z] != '\0'; z++);// word length
                      for(w = 0; w < z-s-1; w++) // return the cursor to the beginning of the word
                        P("\b");   // minus the typed characters
                         k = j; // get the index
                        break;
                  }

            }
      }
    }
  }


}

int exit_dialog()
{

    system("color f0");
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\t\t ARE YOU SURE to EXIT (Y / N)");
        switch(getch()){
        case 'n': case 'N':
            return 0; // remain

        case 'y': case 'Y':
            return 1; // exit

            default:
                continue;
        }
    }

}// inputcity()

