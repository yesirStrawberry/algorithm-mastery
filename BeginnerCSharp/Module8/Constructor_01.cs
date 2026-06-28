using System; 

class TwoDShape
{
    double pri_width; 
    double pri_height; 
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
    public Triangle(string s, double h, double w)
    {
        this.style = s; 
        this.Height = h; 
        this.Width = w; 
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
        Triangle t1 = new Triangle("right", 4, 8);
        t1.ShowDim(); 
        t1.ShowStyle(); 
        Console.WriteLine("Area : {0}", t1.Area()); 
    }
}