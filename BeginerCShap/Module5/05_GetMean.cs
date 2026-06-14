using System;

class GetMean
{
    public static void Main()
    {
        double[] arr = {100.0, 235.6, 234.8, 263.3, 773.6, 
                        654.3, 634.7, 216.3, 774.2, 342.8}; 
        double sum = 0; 
        foreach(double x in arr) sum += x; 
        double mean = sum / (double)arr.Length; 

        foreach(double x in arr) Console.Write(x + " ");
        Console.WriteLine("\nmean : {0:F2}", mean);
    }
}