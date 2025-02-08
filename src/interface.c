#include "include/interface.h"

int startup()
{
  signal(SIGINT, keybint_handler);
  initscr();
  start_color();
  init_pair(1, COLOR_RED, 232);
  init_pair(2, COLOR_WHITE, 232);
  bkgd(COLOR_PAIR(2));
  refresh();

  int row, col;  // variables for screen dimensions

  getmaxyx(stdscr, row, col); 

  char* name = get_name(1, 1);

  cbreak();
  echo();

  endwin();
  close_name(name);
}


void keybint_handler()
{
  endwin();
  printf("Keyboard Interrupt\n");
  exit(0);
}


char* get_name(int y, int x)
{
  char* name = (char*) malloc(22 * sizeof(char));
  mvaddstr(y, x, "Your name:"); // get username
  do
  {
    move(y, x+11);
    clrtoeol();
    mvscanw(y, x+11, "%21s", name);
    if(strlen(name) > 20)
    {
      attron(COLOR_PAIR(1));
      mvaddstr(x+1, y+1, "The username must be less than 20 characters long!");
      attroff(COLOR_PAIR(1));
    }
  }while(strlen(name) > 20);
  return name;
}

void close_name(char* ptr)
{
  free(ptr);
}
