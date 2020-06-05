#include <stdio.h>
#define ROWS 2
#define COL 2

char arr[ROWS][COL];
char flip_id[ROWS][COL] = {0};

void get_input()
{
    int i, j;
    for( i =0; i < ROWS; i++)
    {
        for( j=0; j < COL; j++)
        {
            printf("Enter element no [%d][%d]:\n",i,j);
            scanf("%d",&arr[i][j]);
        }

    }

}

void print_arr()
{
    int i, j;
    printf("Array is: \n");
    for( i =0; i < ROWS; i++)
    {
        for( j=0; j < COL; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void print_flip_arr()
{
    int i, j;
    printf("Flip Array is: \n");
    for( i =0; i < ROWS; i++)
    {
        for( j=0; j < COL; j++)
        {
            printf("%d ",flip_id[i][j]);
        }
        printf("\n");
    }
}
int all_flipped()
{
     int i, j;
    int status  = 0;

    for(i =0; i < ROWS; i++)
    {
        for( j=0; j < COL; j++)
        {
            if(arr[i][j] == 0)
                return status;
        }
    }
    status = 1;
    return status;
}

int no_of_flips()
{
    int i, j;
    static int flip;
    int m,n;
    for(m =0; m < ROWS; m++)
    {
        for(n =0; n < COL; n++)
        {
            flip_id[m][n] = 0;
        }
    }
   printf("Flip %d : \n",flip);
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j< COL; j++)
        {
            if(arr[i][j] == 1 && flip_id[i][j] != 1) {
                /*Left index*/
                if(i != 0) {
                    int left_index = i -1;
                    if(arr[left_index][j] != 1) {
                        arr[left_index][j] = 1;
                        flip_id[left_index][j] = 1;
                    }
                }
                /*Right index*/
                int right_index = i + 1;
                if(right_index < COL)
                {
                    if(arr[right_index][j] != 1)
                    {
                        arr[right_index][j] = 1;
                        flip_id[right_index][j] = 1;
                    }
                }
                /*top index*/
                int top_index = j - 1;
                if(top_index >= 0)
                {
                    if(arr[i][top_index] != 1)
                    {
                        arr[i][top_index] = 1;
                        flip_id[i][top_index] = 1;
                    }
                }
                /*bottom index*/
                int bottom_index = j + 1;
                if(bottom_index < COL)
                {
                    if(arr[i][bottom_index] != 1)
                    {
                        arr[i][bottom_index] = 1;
                        flip_id[i][bottom_index] = 1;
                    }
                }
                flip_id[i][j] = 1;
            }
        }
    }

    print_arr();
    print_flip_arr();
    flip++;
    if(all_flipped())
        return flip;
    else
    {
        no_of_flips();
    }
}

int main()
{
    printf("Hello World");
    get_input();
    print_arr();
    int count = no_of_flips();
    printf("No of flips = %d\n",count);
    print_arr();
    return 0;
}

                         
