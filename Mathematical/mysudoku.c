#include  <stdio.h>
int solve(int puzzle[][9]);
int is_valid(int puzzle[][9], int row, int col, int num);
int wrapper_funtion(int puzzle[][9], int row, int col);
void print_puzzle(int puzzle[][9]);
int main(){
    int puzzle[9][9] = {
                  6,0,0,5,0,8,0,0,9,
                  0,3,0,2,0,7,0,5,0,
                  0,0,8,0,3,0,2,0,0,
                  0,6,5,0,0,0,8,1,0,
                  8,0,0,0,0,0,0,0,3,
                  0,2,4,0,0,0,5,9,0,
                  0,0,7,0,2,0,1,0,0,
                  0,1,0,6,0,4,0,7,0,
                  2,0,0,7,0,1,0,0,4
               };
    printf("original puzzle:-\n");
    print_puzzle(puzzle);
    printf("*****************************\n");
    
    if( solve(puzzle) ){
        printf("solution:-\n");
        print_puzzle(puzzle);
    }
    
    else{
         printf("not solveable :( \n");
    }
    
    return 0;
}

int is_empty(int puzzle[][9], int row, int col){
    if(puzzle[row][col] == 0)
        return 1;
    return 0;
}

 int check_row(int puzzle[][9],int row, int col, int num){
    for(col = 8; col >= 0; col--)
        if(puzzle[row][col] == num)
            return 0;
    return 1;
}

int check_col(int puzzle[][9], int row, int col, int num){
    for(row = 8; row >= 0; row--)
        if(puzzle[row][col] == num)
            return 0;
    return 1;
}

int get_box_no(int row, int col){
    return (row/3)*3 + (col/3);
}

int check_box(int puzzle[][9],int row,int col,int num){
    /*find out the box to which given cell belongs*/
    int box = get_box_no(row,col);
    int i = 0, j =0;
    
    /*update row and column to get starting co-ordinates of the box*/
    row = (box / 3) * 3;
    col = (box % 3) * 3;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(puzzle[row + i][col + j] == num)
                return 0;
    return 1;
}

    
int is_valid(int puzzle[][9],int row,int col, int num){
    return check_row(puzzle,row,col,num) && check_col(puzzle,row,col,num) && check_box(puzzle,row,col,num);
} 



void print_puzzle(int puzzle[][9]){
    int row,col;
    for(row = 0; row < 9; row++){
        for(col = 0; col<9; col++){
            printf("%d  ",puzzle[row][col]);
        }
        printf("\n");
    }
}

int wrapper_function(int puzzle[][9], int row, int col){
    /*
     * Have we advanced past the puzzle?  If so, hooray, all
     * previous cells have valid contents!  We're done!
     */
    if (9 == row) {
        return 1;
    }

    /*
     * Is this element already set?  If so, we don't want to 
     * change it.
     */
    if (!is_empty(puzzle,row, col) ) {
        if (col == 8) {
            if (wrapper_function(puzzle, row+1, 0)) return 1;
        } else {
            if (wrapper_function(puzzle, row, col+1)) return 1;
        }
        return 0;
    }

    /*
     * Iterate through the possible numbers for this empty cell
     * and recurse for every valid one, to test if it's part
     * of the valid solution.
     */
    for (int num = 1; num < 10; num++) {
        if(is_valid(puzzle, row, col,num )) {
            puzzle[row][col] = num;
            if (col == 8) {
                if (wrapper_function(puzzle, row+1, 0))
                    return 1;
            } 
            else {
                if (wrapper_function(puzzle, row, col+1))
                    return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

int solve(int puzzle[][9]){
    return wrapper_function(puzzle,0,0);
}
