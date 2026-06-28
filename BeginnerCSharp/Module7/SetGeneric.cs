using System;
using System.Collections.Generic;
class Set<T>
{
    private T[] _arr; 
    private int _len; 
    private int _count;

    public Set(int cnt)
    {
        _count = cnt; 
        _len = 0; 
        _arr = new T[cnt]; 
    }

    public Set(Set<T> od)
    {
        _count = od.Count; 
        _len = od.Len; 
        _arr = new T[od.Count]; 
        for(int i = 0; i < od.Len; i++)
        {
            _arr[i] = od[i]; 
        }
    }
    public T this[int idx]
    {
        get
        {
            if(0 <= idx && idx < Len) return _arr[idx]; 
            else return default(T); 
        }
    }

    public int Count
    {
        get
        {
            return _count; 
        }
    }

    public int Len // _arr에 있는 ele의 개수
    {
        get
        {
            return _len; 
        }
    }

    public int find(T x)
    {
        for(int i = 0; i < Len; i++)
        {
            if(EqualityComparer<T>.Default.Equals(_arr[i], x)) return i; 
        }
        return -1; 
    }
    
    public void Push(T x)
    {
        if(find(x) == -1 && Len < Count)
        { 
            _arr[Len] = x; 
            ++_len;
        }
    }
    public T Pop(T x)
    {
        int idx = find(x); 
        T ret = default(T); 
        if(idx != -1)
        {
            ret = _arr[idx]; 
            for(int i = idx + 1; i < Len; i++)
            {
                _arr[i - 1] = _arr[i]; 
            }
            _arr[Len - 1] = default(T); 
            _len--; 
        }
        return ret; 
    }

    public static Set<T> operator +(Set<T> s1, Set<T> s2)
    {
        Set<T> s3 = new Set<T>(s1.Count + s2.Count); 
        for(int i = 0; i < s1.Len; i++)
        {
            s3.Push(s1[i]); 
        }
        for(int i = 0; i < s2.Len; i++)
        {
            s3.Push(s2[i]); 
        }
        return s3; 
    }

    public static Set<T> operator -(Set<T> s1, Set<T> s2)
    {
        Set<T> s3 = new Set<T>(s1);
        for(int i = 0; i < s2.Len; i++)
        {
            s3.Pop(s2[i]); 
        }
        return s3; 
    }

    public static bool operator < (Set<T> s1, Set<T> s2)
    {
        for(int i = 0; i < s1.Len; i++)
        {
            if(s2.find(s1[i]) == -1) return false; 
        }
        return true; 
    }

    public static bool operator > (Set<T> s1, Set<T> s2)
    {
        return s2 < s1; 
    }

    public static Set<T> operator & (Set<T> s1, Set<T> s2)
    {
        Set<T> s3 = new Set<T>(s1.Count);
        int idx;  
        for(int i = 0; i < s1.Len; i++)
        {
            idx = s2.find(s1[i]);
            if(idx != -1)
            {
                s3.Push(s1[idx]);
            }
        }
        return s3; 
    }

    public static Set<T> operator | (Set<T> s1, Set<T> s2)
    {
        return (s1 + s2) - (s1 & s2); 
    }


    public void Show()
    {
        Console.WriteLine("-----------------"); 
        for(int i = 0; i < Len; i++)
        {
            Console.WriteLine("Set[{0}] : {1}", i, this[i]); 
        }
    }
}

class Program
{
    public static void Main()
    {
        // 1. int형 집합 테스트
        Set<int> intSet1 = new Set<int>(5);
        intSet1.Push(1);
        intSet1.Push(2);
        intSet1.Push(3);

        Set<int> intSet2 = new Set<int>(5);
        intSet2.Push(3);
        // intSet2.Push(4);

        // Console.WriteLine("=== int 차집합 (intSet1 - intSet2) ===");
        // (intSet1 - intSet2).Show(); // 1, 2 출력

        Console.WriteLine("true  : " + (intSet2 < intSet1)); 
        Console.WriteLine("true  : " + (intSet1 > intSet2));
        
        Console.WriteLine("true  : " + (intSet2 < intSet2));
        Console.WriteLine("true  : " + (intSet2 > intSet2));
        
        intSet2.Push(4);
        Console.WriteLine("false : " + (intSet2 < intSet1));

        (intSet1 & intSet2).Show(); 
        (intSet1 | intSet2).Show(); 
        

    }
}