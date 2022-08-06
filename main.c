#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>

#include "src/Screen/Screen.h"
#include "src/Game/Game.h"


int main(int argc, char** argv) {
    while (true) {
        system("clear");
        printf("----JOGO DA COBRINHA----\n");
        printf("Escolha uma opção:\n");
        printf("(1) Jogar\n");
        printf("(2) Ver placares\n");
        printf("(3) Sair\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            break;
        } else if (option == 2) {
            // TODO: show scores
        } else if (option == 3) {
            return 0;
        }
    }


    Screen* screen = _Screen();

    initscr();
    refresh();
    noecho();
    curs_set(false);

    Game* game = _Game(screen);

    while (true) {
        process_input(game);
        update_state(game);
        redraw(game);

        if (game->is_over) {
            printw("Game over! Press 'p' to play again or 'q' to exit!");

            while (true) {
                chtype input = getch();

                if (input == 'p') {
                    restart(game);
                    break;
                } else if (input == 'q') {
                    endwin();
                    return 0;
                }
            }
        }
    }

    endwin();
}
