#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define MAX 10

static int stack[SIZE][2];
static int top_stack = 0;
static char maze[MAX][MAX];
static int number_steps = 10;
static int p = 0;
static int jump;
static int top;
int i, j;


static int itch_l = 0;
static int itch_r = 0;
static int itch_f = 0;
static int itch_b = 0;
static int itch_left;
static int itch_right;
static int itch_front;
static int itch_back;
static int max_j;
static int maxi;
static int path[SIZE][2];


void MARK(){

    maze[stack[top_stack - 1][0]][stack[top_stack - 1][1]] = '.';
    // '.' represent pheromone

}


//move forward one step (x + 1);
void MOVE_F(){


    if (maze[stack[top_stack - 1][0] + 1][stack[top_stack - 1][1]] == '*') {

        printf("The ant touch the wall \n");

    }

    else if ((stack[top_stack - 1][0] + 1) > (MAX - 1) ) {

        printf("The ant move beyond the scope \n");
    }

    else if (number_steps == 0 ) {

        printf("The ant cannot make any movements \n");

        exit(1);
    }

    else {

        stack[top_stack][0] = stack[top_stack - 1][0] + 1;	//x + 1
        stack[top_stack][1] = stack[top_stack - 1][1];	//y

        number_steps --;

    }


}


//move back one step (x - 1);
void MOVE_B(){


    if (maze[(stack[top_stack - 1][0] - 1)][stack[top_stack - 1][1]] == '*') {

        printf("The ant touch the wall \n");

    }

    else if ((stack[top_stack - 1][0] - 1) < 0 ) {

        printf("The ant move beyond the scope \n");
    }

    else if (number_steps == 0 ) {

        printf("The ant cannot make any movements \n");

        exit(1);

    }

    else {

        stack[top_stack][0] = stack[top_stack - 1][0] - 1; 	//x - 1
        stack[top_stack][1] = stack[top_stack - 1][1];	// y

        number_steps --;

    }


}


//move to right one step (y + 1);
void MOVE_R(){


    if (maze[stack[top_stack - 1][0]][stack[top_stack - 1][1] + 1] == '*') {

        printf("The ant touch the wall \n");

    }

    else if ((stack[top_stack - 1][1] + 1) > (MAX - 1) ) {

        printf("The ant move beyond the scope \n");
    }

    else if (number_steps == 0 ) {

        printf("The ant cannot make any movements \n");
    }

    else {

        stack[top_stack][0] = stack[top_stack - 1][0]; 	//x
        stack[top_stack][1] = stack[top_stack - 1][1] + 1;	// y + 1

        top_stack++;

        number_steps --;

    }


}


//move to left one step (y - 1);
void MOVE_L(){


    if (maze[stack[top_stack - 1][0]][stack[top_stack - 1][1] - 1] == '*') {

        printf("The ant touch the wall \n");

    }

    else if ((stack[top_stack - 1][1] - 1) < 0 ) {

        printf("The ant move beyond the scope \n");
    }

    else if (number_steps == 0 ) {

        printf("The ant cannot make any movements \n");

        exit(1);
    }

    else {

        stack[top_stack][0] = stack[top - 1][0]; 	//x
        stack[top_stack][1] = stack[top - 1][1] - 1;	// y - 1

        top_stack;

        number_steps --;

    }


}



int CWL(){ 		//Michael checks if the next locations to the left (until meeting a wall) are pheromone free.
    //If the locations are free then Michael feels an itch. Otherwise,
    //if no location is free (e.g., because there is a pheromone mark or a wall on the left of Michael),then Michael does not feel the itch.

    itch_left = 0;
    top = 0;
    path [top][0] = stack[top_stack - 1][0];
    path [top][1] = stack[top_stack - 1][1];
    top++;



    while (maze[path [top - 1][0]][path [top - 1][1] + 1] != '*' || maze[path [top - 1][0]][path [top - 1][1] + 1] == '.'){

        if (path [top-1][1]-1 >= max_j || path [top-1] [1] - 1 < 0){
            break;
        }
        else{
            itch_left++;
            path[top][0] = path [top - 1][0];
            path[top][1] = path [top - 1][1] - 1;
            top++;

            printf("Michael feels an itch to the left.");

        }

    }


    return itch_left;

}

int CWR (){

    itch_right = 0;
    top = 0;
    path [top][0] = stack [top_stack - 1][0];
    path [top][1] = stack [top_stack - 1][1];
    top++;

    while(maze[path [top - 1][0]][path [top - 1][1] + 1] != '*' ||  maze[path [top - 1][0]][path [top - 1][1] + 1] == '.'){
        if (path[top-1][1] + 1 > max_j ||path [top-1][1] + 1 < 0){
            break;
        }

        else{
            itch_right++;
            path[top][0] = path [top - 1][0];
            path [top][1] = path [top - 1][1] + 1;
            top++;

            printf ("Michael feels an itch to the right.");
        }

    }


    return itch_right;
}


int CWF() {

    itch_front = 0;
    top = 0;
    path [top][0] = stack [top_stack-1][0];
    path [top][1] = stack [top_stack-1][1];
    top++;

    while(maze [path[top-1][0] + 1][path[top - 1][1]] != '*'|| maze[path [top - 1][0]][path [top - 1][0] + 1] == '.'){
        if(path [top - 1][0] + 1 >= maxi || path[top - 1][0] + 1 < 0){
            break;
        }

        else
        {
            itch_front++;
            path [top][0] = path [top - 1][0] + 1;
            path [top][1] = path [top - 1][1];
            top++;

            printf ("Michael feels an itch to the front.");

        }

    }

    return itch_front;

}

int CWB() {

    itch_back = 0;
    top = 0;
    path [top][0] = stack[top_stack - 1][0];
    path [top][1] = stack[top_stack - 1][1];
    top++;

    while(maze[path[top-1][0]-1][path[top-1][1]] != '*' || maze[path [top - 1][0]][path [top - 1][0] - 1] == '.'){
        if(path[top-1][0]-1 >= maxi || path[top-1][0]-1 < 0)
        {
            break;
        }

        else
        {
            itch_back++;
            path [top][0] = path [top - 1][0] - 1;
            path [top][1] = path [top - 1][1];
            top++;

            printf ("Michael feels an itch to the back.");
        }
    }

    return itch_back;
}


void push( int x, int y) {

    if(top==MAX-1) {

        printf("the stack is full");

    }

    else {

        stack[top_stack][0] = x;
        stack[top_stack][1] = y;
        top_stack++;

    }

}

void pop() {

    if(top_stack==0) {

        printf("The stack is empty");

    }

    else {

        top_stack--;

    }

}

int isEmpty() {

    if (top_stack == 0) {

        return 1;
    }

    else{

        return 0;

    }

}

int peek_x() {

    if(isEmpty() == 0) {

        return stack[top_stack-1][0];

    }

}


int peek_y() {

    if(isEmpty() == 0) {


        return stack[top_stack-1][1];

    }

}



void clear() {

    while(isEmpty()  == 0){
        pop();

    }


}



//Bold jump for itching
void BJPI () {

    if (number_steps == 0) {

        printf("The ant cannot make any movements \n");

        exit(1);

    }

    else {

        if ( CWL () > 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1] - CWL();

            top_stack++;

        }

        else if (CWL() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        if ( CWR () > 0) {


            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1] + CWR();

            top++;

        }

        else if (CWR() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }




        if ( CWF() > 0){


            stack[top_stack][0] = stack[top_stack - 1][0] + CWF();
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        else  if (CWF() == 0){

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }



        if ( CWB() > 0){


            stack[top_stack][0] = stack[top_stack - 1][0] - CWB();
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }


        else if (CWB() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        number_steps--;


    }


}

//cautious jump for itching
void CJPI() {

    if (number_steps == 0) {

        printf("The ant cannot make any movements \n");

        exit(1);

    }

    else {

        if ( CWL() > 0){

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1] - 1;

            top_stack++;

        }

        else if ( CWL() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        if ( CWR() > 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1] + 1;

            top_stack++;

        }

        else if ( CWR() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        if ( CWF() > 0){

            stack[top_stack][0] = stack[top_stack - 1][0] + 1;
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        else if ( CWF() == 0){

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        if ( CWB() > 0) {

            stack[top_stack][0] = stack[top_stack - 1][0] - 1;
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        else if ( CWB() == 0) {

            stack[top_stack][0] = stack[top_stack - 1][0];
            stack[top_stack][1] = stack[top_stack - 1][1];

            top_stack++;

        }

        number_steps--;


    }


}

void BACKTRACK() {

    if (number_steps == 0) {

        printf("The ant cannot make any movements \n");

        exit(1);

    }

    else {

        pop();

        stack[top_stack][0] = stack[top_stack - 1][0];
        stack[top_stack][1] = stack[top_stack - 1][1];

        top_stack++;

    }

}