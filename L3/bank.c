#include <stdio.h>

typedef struct 
{
    /* data */
    char *name;
    char *account_number;
    float balance;
}
customer;

void balance_less_than_x (customer *customers, int n, int min_balance);
void add_revenue (customer *customers, int n, int min_balance, int amount);

const int NUMBER_OF_CUSTOMERS = 4;

int main (void)
{   
    // create 10 customers 
    customer customers[NUMBER_OF_CUSTOMERS];
    customers[0].name = "Ehab";
    customers[0].account_number = "7872881920";
    customers[0].balance = 150.0;
    customers[1].name = "Ahmed";
    customers[1].account_number = "7872881921";
    customers[1].balance = 120.0;
    customers[2].name = "Ramadan";
    customers[2].account_number = "7872881922";
    customers[2].balance = 12000.0;
    customers[3].name = "Arun";
    customers[3].account_number = "7972881922";
    customers[3].balance = 16009.0;
    // print the names of all customers who have less than $200 in their account
    // balance_less_than_x(all_customers, number_of_customers, balance_to_cmp_against)
    balance_less_than_x(customers, NUMBER_OF_CUSTOMERS, 200.0);
    
    // Add $10 revenue for all customers having more than $1000
    // add_revenue(all_customers, number_of_customers, min_balance, revenue_amount)
    add_revenue(customers, NUMBER_OF_CUSTOMERS, 1000.0, 10.0);
}

void balance_less_than_x (customer *customers, int n, int min_balance)
{   
    for (int i = 0; i < n; i++) {
        if (customers[i].balance < min_balance) {
            printf("%s\n", customers[i].name);
        }
    }
}

void add_revenue (customer *customers, int n, int min_balance, int amount)
{
    for (int i = 0; i < n; i++) {
        if (customers[i].balance > min_balance) {
            customers[i].balance += amount;
            printf("Customer: %s --> Incremented Balance: %f\n", customers[i].name, customers[i].balance);
        }
    }
}


// Write a function to add $100 in the balance of all the customers  
// in their balance and then print the incremented value of their balance
