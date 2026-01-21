#ifndef FUNCTIONS
#define FUNCTIONS

// departure time
typedef struct time
{
    int hour;
    int minute;
} Time;

// departure date
typedef struct date
{
    int month;
    int day;
    Time time;
} Date;

typedef struct flight
{
    int flightNumber;
    char pointDestination[20];
    int price;
    Date date;
} Flight;

void initialize(Flight*, int);
int clear_entry(Flight*, int);
void input_from_keyboard(Flight*, int);
void input_data(Flight*, int);
void output_menu(Flight*, int);
void output_data();
int search_free_entry(Flight*, int);
void search_min_menu(Flight*, int);
int search_min_price(Flight*, int);
int search_min_date(Flight*, int);
void search_menu_for_value(Flight*, int);
int search_for_date(Flight*, int);
int search_for_price(Flight*, int);
void sort_menu_for_value(Flight*, int);
void alphabet_sort(Flight*, int);
void date_sort(Flight*, int);
void price_sort(Flight*, int);
void delete_element(Flight*, int*);
void edit(Flight*, int);
void average_price(Flight*, int);
void output_table(Flight*, int);
int input_numbers(int, int);
int number_day_in_month(int);
int input_city_name();
int check_number_dialog();
int exit_dialog();

#endif // FUNCTIONS

