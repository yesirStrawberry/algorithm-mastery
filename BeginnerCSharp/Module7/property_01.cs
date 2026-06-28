using System; 

class SimpleProp
{
    int prop; 
    public SimpleProp(){prop = 0;}
    public int myprop
    {
        get
        {
            return prop; 
        }
        set
        {
            if(value >= 0) prop = value; 
        }
    }
}
class Program
{
    public static void Main()
    {
        Console.WriteLine("StartProgram"); 
        SimpleProp sp = new SimpleProp(); 
        sp.myprop = -1; 
        Console.WriteLine(sp.myprop); 
        sp.myprop = 3; 
        Console.WriteLine(sp.myprop); 
    }
}