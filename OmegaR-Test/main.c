#include <stdio.h>
#include <math.h>

void findUnpairedNumber();
void findTwoUnpairedNumber();
void towerOfHanoi();
void moveDisk(int, int, int);

int main(int argc, const char * argv[])
{
    findUnpairedNumber();
    findTwoUnpairedNumber();
    towerOfHanoi();
    return 0;
}

//Поиск непарного числа в большом массиве
void findUnpairedNumber()
{
    int array[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int allXor = array[0];
    int size = sizeof(array)/sizeof(allXor);
    
    for (int i = 1; i < size; i++)
    {
        allXor ^= array[i];
    }
    printf("Unpaired number - %d\n", allXor);
}

//Поиск двух непарных чисел в большом массиве
void findTwoUnpairedNumber()
{
    int array[] = {1, 3, 2, 4, 5, 2, 1, 4};
    int allXor = array[0];
    int size = sizeof(array)/sizeof(allXor);
    
    for (int i = 1; i < size; i++)
    {
        allXor ^= array[i];
    }
    
    int mask = 1;
    while ((allXor & mask) == 0)
    {
        mask <<= 1;
    }
    
    int xorWithMask = 0;
    for (int i = 0; i < size; i++)
    {
        if ((array[i] & mask) > 0)
        {
            xorWithMask ^= array[i];
        }
    }
    
    printf("Unpaired Numbers - %d, %d\n", xorWithMask, allXor^xorWithMask);
}

//Ханойская башня без рекурсии
void towerOfHanoi()
{
    int numberOfDisks, diskForTurn, turn, count;
    
    numberOfDisks = 3;
    turn = 1;
    
    while (turn <= pow(2, numberOfDisks) - 1)
    {
        if (turn % 2 != 0)
        {
            printf("Turn %d ", turn);
            moveDisk(numberOfDisks, turn, 1);
        }
        else
        {
            count = turn;
            diskForTurn = 0;
            
            while (count % 2 == 0)
            {
                diskForTurn++;
                count = count / 2;
            }
            printf("Turn %d ", turn);
            moveDisk(numberOfDisks, turn, diskForTurn + 1);
        }
        turn++;
    }
}

void moveDisk(int numberOfDisks ,int turn, int diskNumber)
{
    int move, a, b, c;
    
    if (numberOfDisks % 2 == 0)
    {
        a = 1;
        b = 2;
        c = 3;
    }
    else
    {
        a = 1;
        b = 3;
        c = 2;
    }
    move = ((turn / pow(2, diskNumber - 1)) - 1) / 2;
    
    if (diskNumber % 2 != 0)
    {
        switch (move % 3)
        {
            case 0:
                printf("disk number %d move from %d to %d\n", diskNumber, a, b);
                break;
            case 1:
                printf("disk number %d move from %d to %d\n", diskNumber, b, c);
                break;
            case 2:
                printf("disk number %d move from %d to %d\n", diskNumber, c, a);
                break;
        }
    }
    else
    {
        switch (move % 3)
        {
            case 0:
                printf("disk number %d move from %d to %d\n", diskNumber, a, c);
                break;
            case 1:
                printf("disk number %d move from %d to %d\n", diskNumber, c, b);
                break;
            case 2:
                printf("disk number %d move from %d to %d\n", diskNumber, b, a);
                break;
        }
    }
}