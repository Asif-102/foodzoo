#include "stdio.h"
#include "stdbool.h"

struct Food
{
    char name[100];
    double price;
    double tax;
    int f_code;
};

struct Food input_foods()
{
    struct Food single_food;
    printf("Enter food_name, price, food_code: ");
    scanf(" %s %lf %d", single_food.name, &single_food.price, &single_food.f_code);
    single_food.tax = single_food.price * .05;
    return single_food;
}

void display_foods(struct Food f[], int sz)
{
    printf("\n________________________________\n");
    for (int i = 0; i < sz; i++)
    {
        printf("\n________________________________\n");
        printf("food name: %s\n", f[i].name);
        printf("food price: %0.2lf\n", f[i].price);
        printf("food tax: %0.2lf\n", f[i].tax);
        printf("food code: %d\n", f[i].f_code);
        printf("________________________________\n");
    }
    printf("________________________________\n");
}

bool check_food_code(struct Food f[], int sz, int code)
{
    bool chk = false;
    for (int i = 0; i < sz; i++)
    {
        if (f[i].f_code == code)
        {
            chk = true;
            break;
        }
    }
    return chk;
}

void display_ordered_food(struct Food f[], int sz, int ordered_food[], int order_size)
{
    double total_price = 0;
    for (int i = 0; i < order_size; i++)
    {
        int food_code = ordered_food[i];

        struct Food food;

        for(int k = 0; k < sz; k++)
        {
            if(f[k].f_code == food_code)
            {
                food = f[k];
            }
        }
        printf("food name = %s food price = %0.2lf\n", food.name, food.price);
        total_price += food.price;
    }
    printf("__________________________________\n");
    printf("total price = %0.2lf", total_price);
}

int main(void)
{
    printf("koita food input niba: ");
    int n;
    scanf("%d", &n);

    struct Food food_items[n];

    for (int i = 0; i < n; i++)
    {
        food_items[i] = input_foods();
    }

    display_foods(food_items, n);

    int ordered_food[100];
    int idx = 0;

    printf("order your food by enter food_code or enter 0 for exit: ");

    int food_code;
    while (scanf("%d", &food_code))
    {
        if (food_code == 0)
            break;
        display_foods(food_items, n);

        while (check_food_code(food_items, n, food_code) == false)
        {
            printf("Invalid food code, Please try again \n");
            printf("order your food by enter food_code or enter 0 for exit: ");
            scanf("%d", &food_code);

            if (food_code == 0)
                break;
        }
        if (food_code == 0)
            break;
        if (check_food_code(food_items, n, food_code) == true)
        {
            ordered_food[idx] = food_code;
            idx++;
        }
        printf("order your food by enter food_code or enter 0 for exit: ");
    }
    display_ordered_food(food_items, n, ordered_food, idx);
}
