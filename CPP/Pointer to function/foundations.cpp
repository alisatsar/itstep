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

const double* рх = ра[0] (аѵ, 3); 
const double* ру = (*pb[l]) (av,3); 

//Получить значение double
double х = *ра[0](аѵ,3); 
double у = *(*pb[l])(av,3); 

*pd[3] // массив из трех указателей
(*pd)[3] // указатель на массив из трех элементов 

**&ра == *ра == ра[0];

//typedef
typedef const double *(*p_fun)(const double *, int); //p_fun теперь является именем типа
p_fun p1 = fl;//p1 указывает на функцию f1()
p_fun pa[3] = {f1, f2, f3};
p_fun (*pd)[3] = &pa;//pd Указывает на массив из 3 указателей на функции

