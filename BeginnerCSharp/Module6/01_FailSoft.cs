using System;

class FailSoftArray
{
    private int[] a; 
    private int errval; 
    public int Length; 

    public FailSoftArray(int size, int errv)
    {
        a = new int[size];
        Length = size; 
        errval = errv; 
    }

    public bool ok(int idx)
    {
        return 0 <= idx && idx < Length;
    }

    public int get(int idx)
    {
        if(!ok(idx)) return errval; 
        return a[idx];  
    }
    public bool put(int idx, int val)
    {
        if(!ok(idx)) return false;
        a[idx] = val; 
        return true; 
    }
}

class FSDemo
{
    static void Main()
    {
        // 크기가 5이고, 에러 발생 시 -1을 반환하는 FailSoftArray 생성
        FailSoftArray fs = new FailSoftArray(5, -1);
        
        Console.WriteLine("--- 1. 데이터 삽입 테스트 ---");
        // 의도적으로 인덱스 범위를 초과하는 루프 실행 (0부터 6까지)
        for (int i = 0; i < 7; i++)
        {
            bool success = fs.put(i, i * 10);
            if (success)
            {
                Console.WriteLine($"fs.put({i}, {i * 10}) -> 성공");
            }
            else
            {
                Console.WriteLine($"fs.put({i}, {i * 10}) -> 실패 (인덱스 범위 초과)");
            }
        }

        Console.WriteLine("\n--- 2. 데이터 출력 테스트 ---");
        // 의도적으로 인덱스 범위를 초과하는 루프 실행 (0부터 6까지)
        for (int i = 0; i < 7; i++)
        {
            int val = fs.get(i);
            if (val != -1)
            {
                Console.WriteLine($"fs.get({i}) = {val}");
            }
            else
            {
                Console.WriteLine($"fs.get({i}) = {val} (인덱스 범위 초과로 에러 값 반환)");
            }
        }
    }
}