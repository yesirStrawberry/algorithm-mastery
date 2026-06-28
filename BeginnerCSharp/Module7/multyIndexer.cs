using System;
class FailSoft{
    int [ , ] arr; 
    int y, x;
    public int Count; 
    public bool errFlag; 

    public FailSoft(int y, int x)
    {
        this.y = y; 
        this.x = x; 
        arr = new int[y, x]; 
        Count = y * x; 
    }

    public int this[int yd, int xd]
    {
        get
        {
            if(ok(yd, xd))
            {
                errFlag = false; 
                return arr[yd, xd];
            }
            else
            {
                errFlag = true; 
                return -1; 
            }
        }
        set
        {
            if(ok(yd, xd))
            {
                errFlag = false; 
                arr[yd, xd] = value; 
            }
            else
            {
                errFlag = true; 
            }
        }
    }

    public bool ok(int yd, int xd)
    {
        return (0 <= yd && yd < y) && (0 <= xd && xd < x); 
    }
}


class Program
{
    public static void Main()
    {
        FailSoft fs = new FailSoft(3, 5); 
        int x; 
        for(int i = 0; i < 6; i++)
        {
            fs[i, i] = i*10; 
        }
        for(int i = 0; i < 6; i++)
        {
            x = fs[i, i]; 
            string line = string.Format("fs[{0}, {0}] : {1}", i, x); 
            if(fs.errFlag) line += " Out Of Bound"; 
            Console.WriteLine(line); 
        }
        
    }
}















