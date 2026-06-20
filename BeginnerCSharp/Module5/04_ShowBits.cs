using System; 

class ShowBits
{
    public int numbits;

    public ShowBits(int numbits)
    {
        this.numbits = numbits; 
    }
    public void Show(ulong val)
    {
        int spacer = 0; 
        ulong mask = 1; 
        mask <<= numbits - 1; 

        for(; mask != 0; mask >>= 1)
        {
            if((val & mask) != 0) Console.Write("1"); 
            else Console.Write("0");

            spacer++; 
            if(spacer % 8 == 0) Console.Write(" ");  
        }
        Console.WriteLine(); 
    } 
}

class ShowBitsDemo
{
    public static void Main()
    {
        ShowBits b = new ShowBits(8); 
        ShowBits i = new ShowBits(32);
        ShowBits li = new ShowBits(64); 

        Console.WriteLine("123 in binary"); 
        b.Show(123); 

        Console.WriteLine(); 
        Console.WriteLine("87987918293 in binary"); 
        i.Show(87987918293);

        Console.WriteLine(); 
        Console.WriteLine("2376587681425342477 in binary"); 
        li.Show(2376587681425342477);
    }
}