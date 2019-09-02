#include <stdio.h>
#include <stdlib.h>

int getRow();
int getCols();
int **make_array(int rows, int cols);
int **add_array(int rows, int cols, int** arrayA, int** arrayB);
void free_array(int rows, int ***array);
void ask_A();
void ask_B();

int main() {
  int rows = getRow();
  int cols = getCols();

  ask_A();
  int **arrayA = make_array(rows, cols);

  ask_B();
  int **arrayB = make_array(rows, cols);

  int **array_sum = add_array(rows, cols, arrayA, arrayB);

  free_array(rows, &array_sum);
  free_array(rows, &arrayA);
  free_array(rows, &arrayB);

  return 0;
}

int **make_array(int rows, int cols) {
  int **array = (int**)malloc(rows * sizeof(int*));
  for(int i = 0; i < rows; i++){
    array[i] = (int*) malloc(cols * sizeof(int));
    for(int j = 0; j < cols; j++){
      scanf("%d", &array[i][j]);
    }
  }
  return array;
}



int **add_array(int rows, int cols, int** arrayA, int** arrayB) {
  printf("A + B =\n");
  int **array = (int**)malloc(rows * sizeof(int*));
  for(int i = 0; i < rows; i++){
    array[i] = (int*)malloc(cols * sizeof(int));
    for(int j = 0; j < cols; j++){
      array[i][j] = arrayA[i][j] + arrayB[i][j];
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  return array;
}

void ask_A() {
  printf("Enter Matrix A\n");
}

void ask_B() {
  printf("Enter Matrix B\n");
}


int getRow() {
  int x;
  printf("Please enter the number of rows: ");
  scanf("%d", &x);

  return x;
}

int getCols() {
  int x;
  printf("Please enter the number of columns: ");
  scanf("%d", &x);

  return x;
}


void free_array(int rows, int ***array) {
  for(int i = 0; i < rows; i++){
    free((*array)[i]);
  }
  free(*array);
  *array = NULL;
}

//Hi!
