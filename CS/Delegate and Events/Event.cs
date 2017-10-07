using System;

namespace Deleg
{
    public class PriceChagedEventArgs : EventArgs
    {
        public readonly decimal LastPrice;
        public readonly decimal NewPrice;
        public PriceChagedEventArgs(decimal lastPrice, decimal newPrice)
        {
            LastPrice = lastPrice;
            NewPrice = newPrice;
        }
    }
    //определение делегата
    
    public class Stock
    {
        string symbol;
        decimal price;

        public Stock(string symbol)
        {
            this.symbol = symbol;
        }
        //Объявление события
        public event EventHandler<PriceChagedEventArgs> PriceChanged;

        protected virtual void OnPriceChanged(PriceChagedEventArgs e)
        {
            PriceChanged?.Invoke(this, e);
        }

        public decimal Price
        {
            get
            {
                return price;
            }
            set
            {
                if (price == value) return;
                decimal oldPrice = price;
                price = value;
                OnPriceChanged(new PriceChagedEventArgs(oldPrice, price));
            }
        }
    }
    class Program
    {     
        static void Main(string[] args)
        {
            Stock stock = new Stock("a");
            stock.Price = 27.10M;
            stock.PriceChanged += stock_PriceChanged;
            stock.Price = 31.57M;
        }

        static void stock_PriceChanged(object sender, PriceChagedEventArgs e)
        {
            if ((e.NewPrice - e.LastPrice) / e.LastPrice > 0.1M)
            {
                Console.WriteLine("Alert, 10% stock price increase!");
            }
        }
    }    
}
