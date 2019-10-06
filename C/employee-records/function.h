#ifndef function_h
#define function_h

typedef struct
{

  char first_name[30], last_name[50];      
  int id;
}Temployee;

void gotoxy(int, int);
int MyGetch (void);
void color(int chosen_color);

void menu(void);
void press_continue();
void print_menu(int position, int count, int i);

int load(Temployee company[]);

int from_min(Temployee company[]);
void add(Temployee company[], int count);
void update_file(Temployee company[]);
void delete_file(Temployee company[]);

int read(Temployee company[]);
int read_chosen_id(Temployee company[]);
int read_chosen_first_name(Temployee company[]);
int read_chosen_last_name(Temployee company[]);
int status(Temployee company[]);

void print(Temployee company[], int count);
void print_chosen_id(Temployee company[], int count);
void print_chosen_name(Temployee company[], int count);

void fileOpen_r();
void fileOpen_a();
void fileClose();

#endif
