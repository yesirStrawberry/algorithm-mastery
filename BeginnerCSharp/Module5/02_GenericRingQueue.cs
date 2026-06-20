using System; 

class GenericQueue<T>{
    public T[] q; 
    public int putidx; 
    public int popidx;
    public int size; 
    
    public GenericQueue(int size){
        if(size <= 0){
            throw new ArgumentException("Size must be greater than zero."); 
        }
        this.size = size;
        q = new T[size + 1]; 
        putidx = popidx = 0;
    }
    
    public void put(T item){
        int next = (putidx + 1) % q.Length; 
        if(next == popidx){
            Console.WriteLine("Queue is full");
            return; 
        }
        q[putidx] = item; 
        putidx = next; 
        return; 
    }
    
    public T pop(){
        if(popidx == putidx){
            Console.WriteLine("Queue is empty"); 
            return default(T);  
        }
        int next = (popidx + 1) % q.Length;
        T ret = q[popidx]; 
        popidx = next; 
        return ret; 
    }
}


// 테스트용 일반 객체 클래스
class Student {
    public string Name { get; set; }
    public int Id { get; set; }

    public Student(string name, int id) {
        Name = name;
        Id = id;
    }

    public void ShowInfo() {
        Console.WriteLine($"[학생] ID: {Id}, 이름: {Name}");
    }
}

class GenericQueueDemo {
    static void Main(string[] args) {
        // 객체(Student)를 저장하는 큐 생성 (크기: 2)
        Console.WriteLine("=== Student 객체 큐 생성 ===");
        GenericQueue<Student> studentQueue = new GenericQueue<Student>(2);

        // 1. 객체 생성 및 삽입
        Student s1 = new Student("홍길동", 202601);
        Student s2 = new Student("이순신", 202602);
        Student s3 = new Student("강감찬", 202603);

        Console.WriteLine("put: 홍길동"); studentQueue.put(s1);
        Console.WriteLine("put: 이순신"); studentQueue.put(s2);
        Console.Write("put: 강감찬 -> "); studentQueue.put(s3); // 가득 차서 안 들어감

        // 2. 객체 꺼내기 및 메서드 호출
        Console.WriteLine("\n=== pop 및 객체 기능 실행 ===");
        
        Student popped1 = studentQueue.pop();
        if (popped1 != null) popped1.ShowInfo(); // 홍길동 출력

        Student popped2 = studentQueue.pop();
        if (popped2 != null) popped2.ShowInfo(); // 이순신 출력

        // 3. 비어있을 때 pop 처리 (null 반환 확인)
        Console.Write("\npop (빈 상태) -> ");
        Student popped3 = studentQueue.pop();
        if (popped3 == null) {
            Console.WriteLine("큐가 비어있어 null이 반환되었습니다.");
        }

        // 참고: 같은 클래스로 정수(int) 큐도 만들 수 있습니다.
        Console.WriteLine("\n=== 정수(int) 큐 테스트 ===");
        GenericQueue<int> intQueue = new GenericQueue<int>(5);
        intQueue.put(10);
        intQueue.put(20);
        Console.WriteLine($"pop: {intQueue.pop()}"); // 10
    }
}
