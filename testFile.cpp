#include <ncurses.h>
#include <curses.h>

int main() {
    int ch;

    initscr();
    keypad(stdscr,TRUE);
    noecho();

     while ((ch = getch()) != 'q') {
        switch(ch) {
            case KEY_UP: printw("\nUp");
            break;

            case KEY_DOWN: printw("\nDown");
            break;

            case KEY_LEFT: printw("\nLeft");
            break;

            case KEY_RIGHT: printw("\nRight");
            break;

            default: printw("%c", ch);
        }
    }
    refresh();
    getch();
    endwin();

    return 0;
}