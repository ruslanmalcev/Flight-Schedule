#ifndef FUNCTIONS
#define FUNCTIONS

//Определение составляющих структур "Дата вылета" и "Время вылета"

// время вылета
typedef struct time
{
    int hour;// час 0-23
    int minute;// минуты 0-59
} Time;

//дата вылета
typedef struct date
{
    int month;// месяц 1-12
    int day;// день 1-31
    Time time;
} Date;

//Определение структурного типа "Авиарейс"
typedef struct flight
{
    int flightNumber;// номер рейса
    char pointDestination[20];// пункт назначения
    int price;// цена билета
    Date date;// дата вылета
} Flight;

void initialize(Flight*, int);//инициализация, указатель на структуру,размер массива
int clear_entry(Flight*, int);// очистка записи
void input_from_keyboard(Flight*, int);//ввод данных
void input_data(Flight*, int);// блок ввода
void output_menu(Flight*, int);// вывод данных о рейсе
void output_data();
int search_free_entry(Flight*, int);// поиск свободной переменной
void search_min_menu(Flight*, int); //меню поиска минимального значения
int search_min_price(Flight*, int);// поиск минимума по цене
int search_min_date(Flight*, int);// поиск минимума по дате и времени
void search_menu_for_value(Flight*, int);// меню поиска по заданному значению
int search_for_date(Flight*, int);// поиск по дате
int search_for_price(Flight*, int);// поиск по цене
void sort_menu_for_value(Flight*, int);// меню сортировки массива структур
void alphabet_sort(Flight*, int);// сортировка по алфавиту(затем по дате и времени)
void date_sort(Flight*, int);// сортировка по дате и времени
void price_sort(Flight*, int);// сортировка по цене
void delete_element(Flight*, int*);// удаление заданного элемента
void edit(Flight*, int);// изменение заданного элемента
void average_price(Flight*, int);// вычисление средней стоимости билета по введенной дате
void output_table(Flight*, int);// вывод таблицы
int input_numbers(int, int);// ввод чисел
int number_day_in_month(int);// кол-во дней в месяце
int input_city_name();// ввод названия города
int check_number_dialog();
int exit_dialog(); // проверяет точно ли выйти?

#endif // FUNCTIONS
