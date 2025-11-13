#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <ncurses.h>
int HEIGHT = 20;
int LENGTH = 40;
int MAXSIZE = 200;
int INITIAL = 1;

typedef struct SNAKE {
    int x;
    int y;
    bool isHead;
} Snake;

typedef struct Food {
    int x;
    int y;
    bool isFound;
} Food;

struct SNAKE canPlaceSnake(struct SNAKE snake[] , int *snake_size , int x , int y){
    int size = *snake_size;
    for(int i=0;i<size;i++){
        if(snake[i].x == x && snake[i].y == y){
            return snake[i];
        }
    }
    struct SNAKE null_snake = { -1 , -1 , true};
    return null_snake;
}

void constructFence(struct SNAKE snake[] , int *snake_size , Food *food){
    bool isHeadFoundFood = false;
    if(snake[0].x == food->x && snake[0].y == food->y){
        isHeadFoundFood = true;
    }
    for(int row=1;row<=HEIGHT;row++){
        for(int col=1;col<=LENGTH;col++)
        {
            if(row == 1 || row == HEIGHT){
                printf("-");
            }
            else if( col == 1 || col == LENGTH ){
                printf("|");
            }
            else{
                struct SNAKE canPlace = canPlaceSnake(snake , snake_size , row , col);
                if(canPlace.x != -1 && canPlace.y != -1){
                    if(food->x  == canPlace.x && food->y == canPlace.y){
                        printf("🕺");
                    }
                    else if(canPlace.isHead == true){
                        if(isHeadFoundFood) printf("🕺");
                        else printf("⚰️");
                    }
                    else {
                        if(isHeadFoundFood) printf("🕺");
                        else printf("⚰️");
                    }
                }
                else if( food->x == row && food->y == col ){
                    printf("✝️");
                }
                else {
                    printf(" ");
                }
            }
            

            if(col == LENGTH){
                printf("\n");
            }
            
        }
    }
}

void sleep_ms(int millisecond) {
    usleep(millisecond * 1000);
}

void updateSnake(struct SNAKE snake[] , int *snake_size , int x , int y){
    (*snake_size) += 1;
    for(int i=(*snake_size)-1;i>0;i--){
        snake[i] = snake[i-1];
        snake[i].isHead = false;
    }
    Snake temp = { .x = x , .y = y , .isHead = true};
    (*snake) = temp;
    
}

int find_random( int min , int max){
    return min + ( rand() % (max - min + 1) );
}

void updateFoodPlace(Food *food){
    int x_rand = find_random( 2 , HEIGHT - 1 );
    int y_rand = find_random( 2 , LENGTH - 1 );
    Food temp = { .x = x_rand , .y = y_rand , .isFound = false };
    *food = temp;
}

void moveSnake(Snake *snake , int *snake_size , Food *food){
    
    int food_x = food->x;
    int food_y = food->y;
    
    int snake_x = snake[0].x;
    int snake_y = snake[0].y;

    for(int i=(*snake_size)-1;i>=1;i--){
        snake[i] = snake[i-1];
    }

    if(food_x < snake_x){
        (*snake).x -= 1;
    }
    else if( food_y < snake_y){
        (*snake).y -= 1;
    }
    else if(food_x > snake_x){
        (*snake).x += 1;
    }
    else if( food_y > snake_y ){
        (*snake).y += 1;
    }
    else {
        food->isFound = true;
    }
    
}

int main(){
    srand(time(NULL));
    bool isGameOver = false;
    struct SNAKE *snake = (struct SNAKE *) calloc( MAXSIZE , sizeof(struct SNAKE)) ;
    int *snake_size = &INITIAL;
    


    struct SNAKE head = { .x = 4 , .y = 8 , .isHead = true };
    snake[(*snake_size) - 1] = head;

    
    Food *food = malloc(1 * sizeof(struct Food*));

    updateFoodPlace(food);

    while(!isGameOver){
        constructFence(snake , snake_size , food);
        moveSnake(snake , snake_size , food);
        if(food->isFound){
            updateSnake(snake , snake_size , food->x , food->y );
            updateFoodPlace(food);
        }
        sleep_ms(200); // Sleep for 500 milliseconds
        system("clear");
    }
    if(isGameOver){
        printf("GAME OVER");
    }
}