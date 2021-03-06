/***
 *       ___   ___   _____   ___   ___   ___   ___     ___    __    _   ____
 *      / __| | __| |_   _| | __| |_ _| | __| | _ \   |_  )  /  \  / | |__  |
 *     | (__  | _|    | |   | _|   | |  | _|  |  _/    / /  | () | | |   / /
 *      \___| |___|   |_|   |___| |___| |___| |_|     /___|  \__/  |_|  /_/
 *
 * TEI of Epirus - Department of Computer Engineering
 * Gogos Christos - Arta 2017
 */

#include "lab03_board.hpp"
#include "lab03_human.hpp"
#include "lab03_solvers.hpp"

int main(int argc, char *argv[]) {
  if (argc != 3)
    exit(-1);
  string solver = argv[1];
  int plies = atoi(argv[2]);
  char **board = initialize_board();
  bool flag{false};
  int moves{0};
  draw_board(board);
  while (!flag) {
    bool player1_moved{false};
    bool player2_moved{false};
    if (!(get_valid_positions(board, 'X').empty())) {
      human_move(board, 'X');
      player1_moved = true;
      moves++;
    }
    if (!(get_valid_positions(board, 'O').empty())) {
      if (solver.compare("MINIMAX")==0)
        computer_move_using_min_max(board, plies, 'O');
      else
        computer_move_using_alpha_beta(board, plies, 'O');
      player2_moved = true;
      moves++;
    }
    if ((moves == ROWS * COLS - 4) || (!player1_moved && !player2_moved))
      flag = true;
  }
  delete_board(board);
}