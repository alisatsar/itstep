#include <stdio.h>
 
#define STRUCT_SIZE 3
 
enum Type
{
    BeginType,
    Int,
    Float,
    Char,
    EndType
};
 
union Data
{
    int valueInt;
    float valueFloat;
    char* valueStr;
};
 
struct DataItem
{
    enum valueType type;
    union Data data;
};
 
void clearChar()
{
    char ch;
    do
    {
        ch = getchar();
    } while (ch != '\n' && ch != EOF);
}
 
void print(struct DataItem* values)
{
    for (int i = 0; i < STRUCT_SIZE; i++)
    {
        switch (values[i].type)
        {
        case Int:
            printf("%i\n", values[i].data.valueInt);
            break;
        case Float:
            printf("%.2f\n", values[i].data.valueFloat);
            break;
        default:
            printf("%s\n", values[i].data.valueStr);
            break;
        }
    }
}
 
void main()
{
    struct DataItem values[STRUCT_SIZE];
    printf("Types:\n %i - int\n %i - float\n %i - char\n", Int, Float, Char);
    enum Type type;
    for (int i = 0; i < STRUCT_SIZE; i++)
    {
        do
        {
            printf("#%i: Enter the type: ", i + 1);
            scanf("%i", &type);
        } while (type >= EndType || type <= BeginType);
        clearChar();
        switch (type)
        {
        case Int:
            printf("Enter int: ");
            scanf("%i", &values[i].data.valueInt);
            values[i].type = Int;
            break;
        case Float:
            printf("Enter float: ");
            scanf("%f", &values[i].data.valueFloat);
            values[i].type = Float;
            break;
        default:
            printf("Enter char: ");
            scanf("%c", &values[i].data.valueStr);
            clearChar();
            values[i].type = Char;
            break;
        }
    }
    print(values);
}
