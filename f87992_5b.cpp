// f87992 Martin Kolev & F88232 Petar Dudov
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct neighbor {
  int c, i;

  bool operator > (neighbor const& n) const {
    return c > n.c;
  }
};
int X, Y;
int main() {
    int n;
    while(cin >> n >> X >> Y){


  vector<vector<int>> board (n, vector<int>(n, 0));
  vector<vector<int>> moves = {{1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}};

  function<bool(int, int)> moveable = [n](int x, int y) {
    return x > -1 && y > -1 && x < n && y < n;
  };
  function<bool(int, int)> visited = [&board](int x, int y) {
    return board[x][y] > 0;
  };
  function<bool(int, int, int)> tourable =
  [
    moves,
    n,
    &board,
    &moveable,
    &tourable,
    &visited
  ](int x, int y, int p) {
    board[x][y] = p;
    if (p == n * n) return true;
    priority_queue<neighbor, vector<neighbor>, greater<neighbor>> heap;
    for (int i = 0; i < moves.size(); i++) {
      int nx = x + moves[i][0];
      int ny = y + moves[i][1];
      if (moveable(nx, ny) && !visited(nx, ny)) {
        int count = 0;
        for (int j = 0; j < moves.size(); j++) {
          int mx = nx + moves[j][0];
          int my = ny + moves[j][1];

          if (moveable(mx, my) && !visited(mx, my)) count++;
        }
        neighbor ne;
        ne.c = count;
        ne.i = i;
        heap.push(ne);
      }
    }
    if (heap.size() > 0) {
      neighbor ne = heap.top();
      int nx = moves[ne.i][0];
      int ny = moves[ne.i][1];

      if(tourable(x + nx, y + ny, p + 1)) return true;
    }
    return false;
  };
  function<void()> printBoard = [n, &board]() {
    int maxdigit = log10(n * n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int step = board[i][j];
        int digit = log10(step);

        for (int k = 0; k < maxdigit - digit; k++)
          printf(" ");

        printf(" %d", step);

        if (j < n - 1) printf(" ");
      }

      printf("\n");
    }
  };
  function<void()> initializeBoard = [n, &board]() {
    vector<vector<int>> v (n, vector<int>(n, 0));

    board = v;
  };
  function<float(clock_t)> toSecs = [](clock_t start) {
    return (clock() - start) / 1000000.0;
  };

  clock_t start = clock();
  function<void()> findAllSolutions =
  [
    n,
    &initializeBoard,
    &printBoard,
    &toSecs,
    &tourable,
    &start
  ]() {
    int fails = 0;
    int success = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf(" (%d, %d)\n", i, j);

        if (tourable(i, j, 1)) {
          success++;
          printBoard();
        }
        else {
          fails++;
        }

        printf("\n");

        initializeBoard();
      }
    }
  };


  function<void()> findRandomSolution =
  [
    n,
    &initializeBoard,
    &printBoard,
    &toSecs,
    &tourable,
    &start
  ]() {
    srand(time(0));
    X = n-X;
    Y = Y-1;
   int  x = X;
   int y = Y;
    int tries = 0;
    printf("\n");
    while (!tourable(x, y, 1) && tries < n * n) {
      tries++;
      x = rand() % n;
      y = rand() % n;
      initializeBoard();
    }
    if (tries >= n * n)
    {
      for(int i = 0; i < n; ++i)
      {
            for (int j = 0; j < n; ++j)
            {
                  printf(" 0 ");
            }
            printf("\n");
      }
    }
    else {
      printBoard();
    }

   // printf("\n");
   // printf(" Took about %.2f seconds", toSecs(start));
   // printf(" after %d", ++tries);
    if (tries < 2) printf("\n");
  };
  findRandomSolution();
    }
  return 0;
}
