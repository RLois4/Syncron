#ifndef INTERFACE_H
#define INTERFACE_H

#include <ncurses.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

int startup();
void keybint_handler();
char* get_name(int y, int x);
void close_name(char* name);

#endif
