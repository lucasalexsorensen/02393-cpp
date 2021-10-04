#include <math.h>

#include <iostream>

using namespace std;

typedef enum { wood, stone } material;

struct tile {
  int x, y;
  bool isWall;
  material type;
};

struct player {
  int x, y;
};

void render(tile** playground, int rows, int cols, struct player player) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (player.x == j && player.y == i) {
        cout << "O";
      } else {
        if (playground[i][j].isWall) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
    }
    cout << "\n";
  }
}

player move_player(tile** playground, struct player player, char direction) {
  if (direction == 'u') {
    if (playground[player.y - 1][player.x].isWall) return player;
    player.y--;
  } else if (direction == 'd') {
    if (playground[player.y + 1][player.x].isWall) return player;
    player.y++;
  } else if (direction == 'l') {
    if (playground[player.y][player.x - 1].isWall) return player;
    player.x--;
  } else if (direction == 'r') {
    if (playground[player.y][player.x + 1].isWall) return player;
    player.x++;
  }

  return player;
}

int main() {
  int rows, cols;
  cin >> rows;
  cin >> cols;

  // initialize map

  tile** playground = new tile*[rows];
  for (int i = 0; i < rows; i++) {
    // Each pointer in the 'playground' array points to a
    // dynamically-allocated array of tiles
    playground[i] = new tile[cols];
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      playground[i][j].x = j;
      playground[i][j].y = i;
      playground[i][j].isWall =
          (j == 0 || i == (rows - 1) || (i == 0 && j != 3) || j == (cols - 1));
      if (playground[i][j].isWall) {
        playground[i][j].type = stone;
      } else {
        playground[i][j].type = wood;
      }
    }
  }

  // initialize player
  player player;
  player.x = floor((double)cols / 2.);
  player.y = floor((double)rows / 2.);

  // initial render
  render(playground, rows, cols, player);

  // process user input
  string moves;
  cin >> moves;

  if (moves.back() != 'q') {
    cout << "invalid sequence of moves!";
    exit(1);
  }

  for (char const& c : moves) {
    if (c == 'q') {
      break;
    } else if (c == 'l' || c == 'r' || c == 'u' || c == 'd') {
      player = move_player(playground, player, c);
    }

    // re-render game
    render(playground, rows, cols, player);
  }
}