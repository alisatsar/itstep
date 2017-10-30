process(think); //передача адреса think() функции process()
thought(think());//передача возвращаемого значения think() функции thought();

double pam(int); //прототип

double (*pf)(int);//pf указывает на функцию, которая принимает
//один аргумент типа int и возвращает тип double

double* pf(int);//pf() - функция, возвращающая указатель на double

///////////
double pam(int);
double (*pf)(int);
pf = pam; //pf теперь указывает на функцию pam()

//ОБЪЯВЛЕНИЕ ФУНКЦИИ, ПРИНИМАЮЩЕЙ УКАЗАТЕЛЬ НА ФУНКЦИЮ
void estimate(int count, double (*pf)(int));

//ВЫЗОВ
estimate(25, pam);//вызов сообщает estimate(), что она должна использовать pam();

//////////
//ИСПОЛЬЗОВАНИЕ УКАЗАТЕЛЯ НА ФУНКЦИЮ
double pam(int);
double (*pf)(int);
pf = pam;//pf теперь указывает на функцию pam()
double x = pam(4);//вызываем pam(), используя ее имя
double y = (*pf)(5);//Вызываем pam(), используя указатель pf
double z = pf(5);//также вызывает pam(), используя указатель pf


/////////
//array
const double* (*pa[3])(const double*, int) = {f1, f2, f3};
//*pa[3] - pa представляет собой массив из трех указателей.
//pa - это массив из трех указателей, каждый из которых указывает 
//на функцию, принимающую const double* и int аргументы
// и возвращающую const double*
