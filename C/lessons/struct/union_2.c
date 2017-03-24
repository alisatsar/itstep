struct CarStruct
{
    char model[50];
    char make[50];
    int year;
};
 
enum DataType
{
    Model,
    Make,
    Year,
    Pointer
};
 
union CarData
{
    char model[50];
    char make[50];
    int year;
    char* pointer;
};
 
struct Car
{
    union CarData carData;
    enum DataType dataType;
};
 
int main()
{
    struct Car car1;
    car1.carData.year = 1098;
    car1.dataType = Year;
 
    /*car1.carData.pointer = &car1;
    car1.dataType = Pointer;*/
 
    switch (car1.dataType)
    {
    case Year:
        printf("%i\n", car1.carData.year);
        break;
    case Pointer:
        printf("%p\n", car1.carData.pointer);
        break;
    default:
        break;
    }
 
    struct Car car2;
    strcpy(car2.carData.make, "BMW");
 
    printf("%s\n", car2.carData.model);
    printf("%s\n", car2.carData.make);
