#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [Sooyeon Yim]  [2020039017] -----]\n");

    int row, col;
    srand(time(NULL));  //랜덤값 생성

    printf("Input row and col : ");
    scanf("%d %d", &row, &col); //행과 열의 값 입력받는다.
    //matrix_a,_b,_a_t(double pointer) 메모리 할당.
    int** matrix_a = create_matrix(row, col); 
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) { return -1; }    //matrix_a또는 b가 널이면 -1(not ok)을 반환한다.

    do {
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command); //사용자가 원하는 기능을 Matrix Manipulation을 보고 선택한 값을 입력받는다.

        switch (command) {
            //입력값과 일치하는 케이스에 따라 각 명령을 수행하는 부분입니다.
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    /*check pre conditions*/
    if (row <= 0 || col <= 0) {
        //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 Null값 반환
        printf("Check the sizes of row and col!\n");
        return NULL;
    }
    
    int** matrix;
    matrix = (int**)malloc(sizeof(int*) * row);//행을 가리키는 포인터의 메모리 할당.
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);//각행마다의 열을 가리키는 포인터의 메모리 할당.(32bit머신은 4bytes, 64 bit머신은 64bytes)
    }

    /*Check post conditions*/
    if (matrix == NULL) {
        //생성된 matrix가 NULL이면 에러문자 표시.
        printf("ERROR");

    }

    return matrix; //(int**)matrix리턴
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    //matrix의 각행과 열마다의 값을 이중for문을 통해 출력하는 부분입니다.
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");   // 한 행을 출력한 뒤 다음 행으로 개행.
    }

}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{   //for문을 통해 각 열을 가르키던 포인터의 메모리 할당을 해제
    for(int i=0;i<row;i++){
        free(matrix[i]);
    }
    free(matrix);   //행을 가르키던 포인터의 메모리 할당 해제

    return 1;


}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{   /*check pre conditions*/
    //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 -1값 반환
    if (row <= 0 || col <= 0) {
        printf("Check the sizes of row and col!\n");
        return -1;
    }
    int i, j;
    //이중 포문을 통해 행이 가리키는 곳의 열이 가리키는 곳에 랜덤값을 넣는 부분입니다.
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(*(matrix + i) + j) = rand() % 20;//%20을 통해 0~19 사이 값만 입력되도록 한다.
        }
    }
    /*Check post conditions*/
    if (matrix == NULL) {
        printf("ERROR");
        return -1;
        //생성된 matrix가 NULL이면 에러문자 표시하고 -1값리턴
    }

    return 1;
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{   /*check pre conditions*/
    if (row <= 0 || col <= 0) {
        //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 -1값 반환
        printf("Check the sizes of row and col!\n");
        return -1;
    }

    //a와 b matrix의 합을 저장할 다른 matrix 선언하고 메모리 할당하는 부분입니다.
    int** matrix;   
    matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);
    }

    //이중 포문을 통해 matrix에 a와 b의 합을 저장하는 부분입니다.
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(*(matrix + i) + j) = *(*(matrix_a + i) + j) + *(*(matrix_b + i) + j);
        }
    }

    print_matrix(matrix, row, col); //둘의 합을 저장한 matrix의 행렬을 프린트.

    /*Check post conditions*/
    
    if (matrix == NULL) {
        printf("ERROR");
        return -1;
        //생성된 matrix가 NULL이면 에러문자 표시하고 -1값리턴
    }
    return 1;

}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    /*check pre conditions*/
    //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 -1값 반환
    if (row <= 0 || col <= 0) {
        printf("Check the sizes of row and col!\n");
        return -1;
    }

    //a와 b matrix의 차를 저장할 다른 matrix 선언하고 메모리 할당하는 부분입니다.
    int** matrix;
    matrix = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * col);
    }

    //이중 포문을 통해 matrix에 a와 b의 차를 저장하는 부분입니다.
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(*(matrix + i) + j) = *(*(matrix_a + i) + j) - *(*(matrix_b + i) + j);
        }
    }
    print_matrix(matrix, row, col);
    /*Check post conditions*/
    if (matrix == NULL) {
        printf("ERROR");
        return -1;
        //생성된 matrix가 NULL이면 에러문자 표시하고 -1값리턴
    }

    return 1;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    int i, j;
    /*check pre conditions*/
    //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 -1값 반환
    if (row <= 0 || col <= 0) {
        printf("Check the sizes of row and col!\n");
        return -1;
    }

    //이중 포문을 통해 행렬을 전치하는 부분입니다., matrix_t의 각각의 행과 열이 가리키는 곳을 matrix의 각각의 행과 열을 바꾸어 입력합니다. 
    for (int i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            *(*(matrix_t + i) + j) = *(*(matrix + j) + i);

        }
    }
    

    /*Check post conditions*/
    if (matrix_t == NULL) {
        printf("ERROR");
        return -1;
        //생성된 matrix가 NULL이면 에러문자 표시하고 -1값리턴
    }

    return 1;

}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    /*check pre conditions*/
    //행과 열의 값이 0이거나 0보다 작으면  check th esizes of row and col!출력하고 -1값 반환
    if (row <= 0 || col <= 0) {
        printf("Check the sizes of row and col!\n");
        return -1;
    }

    //matrix_axt를 선언하고 메모리를 할당하는 부분입니다.
    int** matrix_axt;
    matrix_axt = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        matrix_axt[i] = (int*)malloc(sizeof(int) * row);
    }

    //선언한 matrix_axt에 삼중 포문을 통해 (iXn)행렬과 (nXj)행렬의 곱을 계산해 저장하는 부분입니다.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++)
        {
            int sum = 0;  
            for (int n = 0; n < col; n++) {
                sum += *(*(matrix_a + i) + n) * (*(*(matrix_t + n) + j));
            }
            *(*(matrix_axt + i) + j) = sum;
        }
    }

    print_matrix(matrix_axt, row, row); //생성한 matrix_axt를 프린트하는 부분입니다.

    /*Check post conditions*/
    if (matrix_axt == NULL) {
        printf("ERROR");
        return -1;
        //생성된 matrix가 NULL이면 에러문자 표시하고 -1값리턴
    }
    return 1;

}


