#include <stdio.h>

double get_num_row();
double get_num_col();
void addup(double num_row, double num_col);

int main() {
  double num_row = get_num_row();
  double num_col = get_num_col();

  addup(num_row, num_col);

}

double get_num_row() {
  double row;

  printf("Please enter the number of rows: ");
  scanf("%lf", &row);

  return row;
}

double get_num_col() {
  double col;

  printf("Please enter the number of columns: ");
  scanf("%lf", &col);

  return col;
}

void addup(double num_row, double num_col){
  double mat_A [(int)num_row][(int)num_col];

  printf("Enter Matrix A\n");

  for(int i = 0; i < num_row; i++) {
    for (int j = 0; j < num_col; j++) {
      scanf(" %lf", &mat_A[i][j]);
    }
  }

  double mat_B [(int)num_row][(int)num_col];

  printf("Enter Matrix B\n");

  for(int i = 0; i < num_row; i++){
    for(int j = 0; j < num_col; j++){
      scanf(" %lf", &mat_B[i][j]);
    }
  }

  printf("A + B =\n");

  for(int i = 0; i < num_row; i++){
    for(int j = 0; j < num_col; j++){
      printf("%.0lf ", mat_A[i][j] + mat_B[i][j]);
    }
    printf("\n");
  }
}

/*double get_mat_A(double num_row, double num_col) {
  double mat_A [(int)num_row][(int)num_col];

  printf("Enter Matrix A\n");

  for(int i = 0; i < num_row; i++) {
    for (int j = 0; j < num_col; j++) {
      scanf(" %lf", &mat_A[i][j]);
    }
  }

  return mat_A[(int)num_row][(int)num_col];
}

double get_mat_B(double num_row, double num_col) {
  double mat_B [(int)num_row][(int)num_col];

  printf("Enter Matrix B\n");

  for(int i = 0; i < num_row; i++){
    for(int j = 0; j < num_col; j++){
      scanf(" %lf", &mat_B[i][j]);
    }
  }

  return mat_B[(int)num_row][(int)num_col];
}*/

