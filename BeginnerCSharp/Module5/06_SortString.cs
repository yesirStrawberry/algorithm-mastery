using System; 

class SortString
{
    public string[] strings; 
    public void Sort()
    {
        int size = strings.Length; 
        for(int i = 1; i < size; i++)
        {
            for(int j = size - 1; j >= i; j--)
            {
                if(strings[j-1].CompareTo(strings[j]) > 0)
                {
                    string tmp = strings[j-1]; 
                    strings[j-1] = strings[j];
                    strings[j] = tmp; 
                }
            }
        }
    }

    public void ShowStrings()
    {
        for(int i = 0; i < strings.Length; i++)
        {
            Console.WriteLine("strings[{0:D2}] : {1}", i, strings[i]);
        }
    }
}

class SortStringDemo
{
    public static void Main()
    {
        SortString strs = new SortString();
        strs.strings = new string[] {"Grape", "Banana", "Apple", "Cherry", "Date", "Elderberry","Fig", 
                                     "Cherry", "Honeydew", "Kiwi", "Date", "Cherry", "Lemon"};
        Console.WriteLine("-----before sort----");
        strs.ShowStrings();
        strs.Sort(); 
        Console.WriteLine("-----after sort----");
        strs.ShowStrings();
    }
}