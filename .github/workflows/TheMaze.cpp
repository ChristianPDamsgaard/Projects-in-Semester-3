typedef enum { wood, stone } material;
struct tile {
int x, y;
bool isWall;
bool isPlayer;
material type;
};

int x2, y2;
#define NROWS 12
#define NCOLS 16
#include <iostream>
void draw(tile playground[NROWS][NCOLS], int i, int j);
bool isWall(int i, int j, tile playground[NROWS][NCOLS]);
int main() {
    tile playground[NROWS][NCOLS];

    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++) {
            playground[i][j].x = j;
            playground[i][j].y = i;

            // Determine if the tile is a wall
            if(isWall(i, j, playground) == true){
                playground[i][j].type = stone;
            }else {
               playground[i][j].type = wood; 
            }

            // Draw the playground
            draw(playground, i, j);
        }
        std::cout << std::endl;
    }

    return 0;
}
bool isWall(int i, int j, tile playground[NROWS][NCOLS]){
    // this function will simply return if it is at a wall, neat!
    return (j == 0 || i == (NROWS - 1) || (i == 0 && j != 3) || j == (NCOLS - 1));

}
bool isPlayer(int i, int j, tile playground[NROWS][NCOLS], int x, int y){
    // this function will simply return if we are where the player is currently!
   return playground[i][j].isPlayer == ( i == x && j == y);
}


void draw(tile playground[NROWS][NCOLS], int i, int j){
    if(playground[i][j].type == stone){
        std::cout << "*";
    }
    if(playground[i][j].type == wood){
        std::cout << " ";
    }

}

