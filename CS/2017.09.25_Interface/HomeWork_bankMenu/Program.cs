using System;

namespace _2017._09._25_2
{
    class Program
    {
        static void Main(string[] args)
        {
            //var Student = new Student();

            //Human h = null;
            //h = new Student();

            //// варианты обратно получить студента:
            ////1
            //var st1 = (Student)h;

            ////2
            //Console.WriteLine(h is Student);
            //h = new Teacher();
            //Console.WriteLine(h is Student);

            ////3
            //var st2 = h as Student; // если студент в st2 запишется студент, иначе null
            //Console.WriteLine(st2 == null);
            //var st3 = h as Teacher;
            //Console.WriteLine(st3);

            //h.SayHello();
            //h = st1;
            //h.SayHello();

            var bank = new Bank();

            var balanceMenu = new MenuItemCollection("Баланс", new MenuItem[]
                {
                    new ActionMenuItem("На экран", new ShowBalanceHandler(bank)),
                    new MenuItem("На чек")
                });

            var withrawMenu = new MenuItemCollection("Снять", new MenuItem[]
                {
                    new MenuItem("BUN"),
                    new MenuItem("USD")
                });

            var chargePinMenu = new MenuItem("Смена пина");

            var depositMenu = new ActionMenuItem("Пополнить баланс", new DepositHandler(bank));

            var withdrawMenu = new ActionMenuItem("Снять деньги", new WithdrawHandler(bank));

            var atmMenu = new MenuItemCollection(null, new MenuItem[]
            {
               balanceMenu, 
               withrawMenu,
               depositMenu,
               withdrawMenu,
               chargePinMenu                
            });
            atmMenu.SelectItem();
        }
    }
}
