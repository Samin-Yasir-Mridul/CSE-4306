#include <stdio.h>
#include <string.h>

struct Plane
{
    char id[10];
    int priority;
};

struct Plane queue[10];
int count = 0;

void enqueue()
{
    if (count >= 10)
    {
        printf("Hangar full!\n");
        return;
    }

    printf("Enter Flight ID: ");
    scanf("%s", queue[count].id);
    printf("Enter Priority (1-Emergency, 2-Fuel Critical, 3-Normal): ");
    scanf("%d", &queue[count].priority);
    count++;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (queue[j].priority > queue[j + 1].priority)
            {
                struct Plane temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

void landPlane()
{
    if (count == 0)
    {
        printf("No planes in queue.\n");
        return;
    }
    printf("Plane %s has landed safely.\n", queue[0].id);

    for (int i = 0; i < count - 1; i++)
    {
        queue[i] = queue[i + 1];
    }
    count--;
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Add Plane  2. Land Plane  3. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
            enqueue();
        else if (choice == 2)
            landPlane();
        else
            break;
    }
    return 0;
}