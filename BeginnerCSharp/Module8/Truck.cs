using System; 

class Vehicle
{
    // 이동승객의 수, 연료효율, 마일당 연료효율량
    private int _passengers, _fuelcap, _mpg; 
    
    public int Passengers
    {
        get
        {
            return _passengers; 
        }
        set
        {
            _passengers = value; 
        }
    }
    public int Fuelcap
    {
        get
        {
            return _fuelcap; 
        }
        set
        {
            _fuelcap = value; 
        }
    }
    public int Mpg
    {
        get
        {
            return _mpg; 
        }
        set
        {
            _mpg = value; 
        }
    }

    public Vehicle(int passengers, int fuelcap, int mpg)
    {
        this._passengers = passengers; 
        this._fuelcap   = fuelcap; 
        this._mpg       = mpg; 
    }

    public int Range()
    {
        return Fuelcap * Mpg; 
    }
    public double FuelNeeded(int mile)
    {
        return (double) mile / Mpg; 
    }
}

class Truck : Vehicle
{
    private int _cargoCap; 
    
    public Truck(int cargoCap, int passengers, int fuelcap, int mpg) : base(passengers, fuelcap, mpg)
    {
        _cargoCap = cargoCap; 
    }
    public int CargeCap
    {
        get
        {
            return _cargoCap; 
        }
        set
        {
            _cargoCap = value; 
        }
    }
}

class Program
{
    public static void Main()
    {
        Truck t = new Truck(44000, 2, 200, 7); 
        Console.WriteLine("Cargo : {0}\nPassenger : {1}\nFuelCap : {2}\nMpg : {3}", 
                            t.CargeCap, t.Passengers, t.Fuelcap, t.Mpg); 
        Console.WriteLine("Range : {0}", t.Range());
        Console.WriteLine("100 mile FuelNeeded : {0:F2}", t.FuelNeeded(100)); 
    }
}