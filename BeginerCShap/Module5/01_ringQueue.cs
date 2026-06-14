using System; 

class Queue{
    public char[] q; 
    public int putidx; 
    public int popidx;
    public int size; 
    
    public Queue(int size){
        if(size <= 0){
            throw new ArgumentException("Size must be greater than zero."); 
        }
        this.size = size;
        q = new char[size + 1]; 
        putidx = popidx = 0;
    }
    
    public void put(char ch){
        int next = (putidx + 1) % q.Length; 
        if(next == popidx){
            Console.WriteLine("Queue is full");
            return; 
        }
        q[putidx] = ch; 
        putidx = next; 
        return; 
    }
    
    public char pop(){
        if(popidx == putidx){
            Console.WriteLine("Queue is empty"); 
            return (char)0; 
        }
        int next = (popidx + 1) % q.Length;
        char ret = q[popidx]; 
        popidx = next; 
        return ret; 
    }
}


class QueueDemo {
    static void Main(string[] args) {
        // 1. 크기가 3인 큐 생성 (실제 배열 크기는 4)
        Console.WriteLine("=== 1. 큐 생성 (크기: 3) ===");
        Queue bigQ = new Queue(3);
        
        // 2. 가득 찰 때까지 데이터 삽입
        Console.WriteLine("\n=== 2. 데이터 삽입 테스트 (A, B, C, D) ===");
        Console.WriteLine("put('A')"); bigQ.put('A');
        Console.WriteLine("put('B')"); bigQ.put('B');
        Console.WriteLine("put('C')"); bigQ.put('C');
        
        // 크기가 3이므로 4번째 삽입 시 "Queue is full"이 출력되어야 함
        Console.Write("put('D') -> "); bigQ.put('D'); 

        // 3. 데이터 꺼내기
        Console.WriteLine("\n=== 3. 데이터 추출 테스트 ===");
        Console.WriteLine($"pop(): {bigQ.pop()}"); // A
        Console.WriteLine($"pop(): {bigQ.pop()}"); // B

        // 4. 원형 순환(Ring) 검증
        // 데이터를 2개 뺐으므로 공간이 2칸 생겼어야 함. 추가 삽입 테스트.
        Console.WriteLine("\n=== 4. 원형 순환(재사용) 테스트 (X, Y, Z) ===");
        Console.WriteLine("put('X')"); bigQ.put('X');
        Console.WriteLine("put('Y')"); bigQ.put('Y');
        
        // 다시 가득 찼으므로 'Z'는 들어가지 않아야 함
        Console.Write("put('Z') -> "); bigQ.put('Z'); 

        // 5. 남은 데이터 전부 꺼내기 및 비어있을 때 예외 확인
        Console.WriteLine("\n=== 5. 잔여 데이터 추출 및 Empty 테스트 ===");
        Console.WriteLine($"pop(): {bigQ.pop()}"); // C
        Console.WriteLine($"pop(): {bigQ.pop()}"); // X
        Console.WriteLine($"pop(): {bigQ.pop()}"); // Y
        
        // 더 이상 꺼낼 데이터가 없으므로 "Queue is empty" 출력 및 (char)0 반환 확인
        Console.Write("pop() -> ");
        char emptyChar = bigQ.pop();
        if (emptyChar == (char)0) {
            Console.WriteLine("Returned (char)0 successfully.");
        }
    }
}
