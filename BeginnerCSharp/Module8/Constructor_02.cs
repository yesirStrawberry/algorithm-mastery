using System; 

class TwoDShape
{
    double pri_width; 
    double pri_height; 
    public TwoDShape()
    {
        pri_height = 0; 
        pri_width = 0; 
        Console.WriteLine("TwoDShape Constructor");
    }
    public TwoDShape(double w, double h)
    {
        pri_height = h; 
        pri_width = w; 
        Console.WriteLine("TwoDShape Constructor");
    }
    public double Width
    {
        get
        {
            return pri_width; 
        }
        set
        {
            pri_width = value; 
        }
    }
    public double Height
    {
        get
        {
            return pri_height; 
        }
        set
        {
            pri_height = value; 
        }
    }

    public void ShowDim()
    {
        Console.WriteLine("Width : {0}, Height : {1}", Width, Height); 
    }
}

class Triangle : TwoDShape
{
    string style;

    public Triangle() : base()
    {
        style = "null"; 
        Console.WriteLine("Triangle Constructor"); 
    } 
    public Triangle(string s, double w, double h) : base(w, h)
    {
        this.style = s; 
        Console.WriteLine("Triangle Constructor"); 
    }

    public double Area()
    {
        return Height * Width / 2; 
    }

    public void ShowStyle()
    {
        Console.WriteLine("Triangle is {0}", style); 
    }
}

class Program
{
    public static void Main()
    {
        Console.WriteLine("----t1----"); 
        Triangle t1 = new Triangle("right", 4, 8);
        t1.ShowDim(); 
        t1.ShowStyle(); 
        Console.WriteLine("Area : {0}", t1.Area()); 
        
        Console.WriteLine("----t2----");
        Triangle t2 = new Triangle();
        t2.ShowDim(); 
        t2.ShowStyle(); 
        Console.WriteLine("Area : {0}", t2.Area()); 
        
    }
}