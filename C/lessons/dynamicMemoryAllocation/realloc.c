#include <stdlib.h>
#include <stdbool.h>
 
struct Transaction
{
    float Summ;
    char* To;
    char* Reason;
};
 
enum Operation
{
    Exit = 0,
    Add,
    Pay,
    PrintTransactions,
    PrintTotal
};
 
enum Operation getOperation()
{
    printf("==== Menu ====\n");
    printf("1. Add money\n");
    printf("2. Pay money\n");
    printf("3. Print transactions\n");
    printf("4. Print total\n");
    printf("0. Exit\n\n");
 
    enum Operation result;
    scanf("%i", &result);
 
    return result;
}
 
struct Transaction* addTransaction(struct Transaction* const transations,
    int* const transactionsCount, float summ,
    char* to, char* reason)
{
    transations[*transactionsCount].Summ = summ;
    if (to != NULL)
    {
        transations[*transactionsCount].To = calloc(1, 100);
        strcpy(transations[*transactionsCount].To,
            to);
    }
    if (reason != NULL)
    {
        transations[*transactionsCount].Reason = calloc(1, 50);
        strcpy(transations[*transactionsCount].Reason,
            reason);
    }
    (*transactionsCount)++;
    struct Transaction* transationsNew = realloc(transations,
        (*transactionsCount + 1) * sizeof(struct Transaction));
   
    return transationsNew;
}
 
void printTransactions(struct Transaction* const transations,
    int* const transactionsCount)
{
    printf("Summ\t| To\t| Reason\n");
    for (int i = 0; i < *transactionsCount; i++)
    {
        printf("%.2f\t| %s\t| %s\n", transations[i].Summ,
            transations[i].To ? transations[i].To : "-",
            transations[i].Reason ? transations[i].Reason : "-");
    }
}
 
void main()
{
    struct Transaction* transations =
        calloc(1, sizeof(struct Transaction));
 
    int transationsCount = 0;
 
    // Add initial balans
    float money;
    printf("Initial balans: ");
    scanf("%f", &money);
    struct Transaction* transationsNew = addTransaction(transations, &transationsCount, money,
        NULL, NULL);
    if (transationsNew != NULL)
    {
        transations = transationsNew;
    }
 
    while (true)
    {
        enum Operation operation = getOperation();
        switch (operation)
        {
        case Exit:
            return;
            break;
        case Add:
            printf("Add money: ");
            scanf("%f", &money);
            transationsNew = addTransaction(transations, &transationsCount, money,
                NULL, NULL);
            if (transationsNew != NULL)
            {
                transations = transationsNew;
            }
            break;
        case Pay:
            break;
        case PrintTransactions:
            printTransactions(transations, &transationsCount);
            break;
        case PrintTotal:
            break;
        default:
            break;
        }
    }
 
    free(transations);
}
