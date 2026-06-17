using System; 
using System.Collections.Generic;

/*permitbounce는 점수 낮은 곳임*/

class Trainee : IComparable<Trainee>
{
    public string SoldierCode{get; private set;}
    public string Name{get; private set;}
    public List<int> Scores{get; private set;}
    public List<int> AspireCodes{get; private set;}
    private int _idx; 
    public int Idx{
        get {return _idx; }
        set {_idx = Math.Min(value, 3); }
    }
    public bool IsColorBlind; 
    public bool IsAtopy; 
    public List<int> PreSpecialityCodes{get; set;}
    public Trainee()
    {
        SoldierCode  = "";
        Name         = ""; 
        Scores       = new List<int>(); 
        AspireCodes  = new List<int>();  
        Idx          = 0;  
        IsColorBlind = false; 
        IsAtopy      = false; 
        PreSpecialityCodes = new List<int>();
    }
    public Trainee(string soldier_code, string name, List<int> scores, 
                   List<int> aspireCodes, bool isColor, bool isAtopy)
    {
        SoldierCode  = soldier_code; 
        Name         = name; 
        Scores       = scores;
        AspireCodes  = aspireCodes;  
        Idx          = 0; 
        Scores.Add(0); 
        IsColorBlind = isColor; 
        IsAtopy      = isAtopy; 
    }
    public int CompareTo(Trainee other)
    {
        if(other == null) return 1; 
        int ScoreCmp = other.Scores[other.Idx].CompareTo(this.Scores[this.Idx]); 
        if(ScoreCmp != 0) return ScoreCmp;
        ScoreCmp = this.Idx.CompareTo(other.Idx); 
        if(ScoreCmp != 0) return ScoreCmp; 
        /*peem 뜯어서 봐야되는 부분, 나중에 수정*/
        ScoreCmp = this.SoldierCode.CompareTo(other.SoldierCode);
        return ScoreCmp;   
    }
    public bool IsPreSpec(int code)
    {
        for(int i = 0; i < PreSpecialityCodes.Count; i++)
        {
            if(code == PreSpecialityCodes[i]) return true; 
        }
        return false; 
    }
}

class Speciality
{
    public int Code{get;}
    public int Capacity{get;} 
    public bool PermitColorBlind{get;}
    public bool PermitAtopy{get;}
    public SortedSet<Trainee> AcceptedList{get;} 
    public Speciality()
    {
        Code = 0; 
        Capacity = 0; 
        PermitAtopy = false; 
        PermitColorBlind = false;  
        AcceptedList = new SortedSet<Trainee>();
    }
    public Speciality(int code, int capacity, bool atopy, bool colorBilnd)
    {
        Code = code; 
        Capacity = capacity; 
        PermitAtopy = atopy; 
        PermitColorBlind = colorBilnd; 
        AcceptedList = new SortedSet<Trainee>(); 
    }
    public bool IsRemain()
    {
        return AcceptedList.Count < Capacity; 
    }
    public Trainee AddTrainee(Trainee t)
    {
        if(t.IsAtopy == true && this.PermitAtopy == false) return t; 
        if(t.IsColorBlind == true && this.PermitColorBlind == false) return t; 
        
        AcceptedList.Add(t); 
        if(AcceptedList.Count <= Capacity) return null;
        Trainee lastTrainee = AcceptedList.Max; 
        AcceptedList.Remove(lastTrainee); 
        return lastTrainee; 
    }
    public int CompareTo(Speciality other)
    {
        if(other == null) return 1;
        if(this.AcceptedList.Count == 0 && other.AcceptedList.Count == 0) return 0;
        if(this.AcceptedList.Count == 0) return -1;  // 빈 특기는 뒤로
        if(other.AcceptedList.Count == 0) return 1;
        return this.AcceptedList.Max.CompareTo(other.AcceptedList.Max);
    }
}

class AssignManager
{
    public Stack<Trainee> TraineeStack{get;} 
    public Stack<Trainee> AfterStack{get;}
    public List<Speciality> AllSpecialities{get; set;} 
    public SortedSet<Speciality> SortedSpecialites{get; set;}
    public AssignManager()
    {
        TraineeStack = new Stack<Trainee>();
        AfterStack = new Stack<Trainee>();
        AllSpecialities = new List<Speciality>();
        SortedSpecialites = new SortedSet<Speciality>();
    }

    public Speciality FindSpeciality(int code)
    {
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            if(code == AllSpecialities[i].Code) return AllSpecialities[i]; 
        }
        return null; 
    }

    public void AssignByPreference()
    {
        while(TraineeStack.Count > 0)
        {
            Trainee tr = TraineeStack.Pop();
            Speciality spec = this.FindSpeciality(tr.AspireCodes[tr.Idx]);
            if(spec == null){
                tr.Idx++; 
                if(tr.Idx >= 3)  // 지망이 0~3이므로 3 이상이면 끝
                    this.AfterStack.Push(tr);
                else
                    TraineeStack.Push(tr);  // 다시 스택에 넣어서 다음 지망 시도
                continue;    
            }
            Trainee returnedTr = spec.AddTrainee(tr); 
            if(returnedTr == null) continue;
            else {
                returnedTr.PreSpecialityCodes.Add(spec.Code);
                returnedTr.Idx++;
                if(returnedTr.Idx <= 3)  // Idx를 0~3으로 제한
                    TraineeStack.Push(returnedTr);
                else
                    AfterStack.Push(returnedTr);
            } 
        }
    }

    public void SortSpectiality()
    {
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            SortedSpecialites.Add(AllSpecialities[i]);
        }
    }

    public void AssignAfter()
    {
        /*색맹자 넣기*/
            /*AfterStack에서 색맹자들을 찾아, SortedSet<Trianee>에 내림차순으로 넣기*/
            /*Speciality중에 Capacity > AcecpedList.Count애들 찾기*/
            /*찾은 Speciality 중에 PermitColorBlind인 Speciality들 찾기*/
            /*찾은 Speciality에 뒤에서부터 색맹자 할당*/
            /*남은 색맹자는 SortSpectiality의 뒤에 해당하는 특기에 집어넣음*/
                /*만약 PermitColorBlind가 아니거나, Capacity가 남은 색맹자보다 작으면*/
                /*SortSpecialities의 그다음 뒤에 접근*/
            /*집어넣고, 다시 빠져나온 애들은 다음 지망으로 idx 바꿔놓고*/
            /*TraineeStack이나 AfterStack에 넣기*/
        /*아토피 넣기*/
            /*AfterStack에서 아토피 환자들을 찾아, SortedSet<Trianee>에 내림차순으로 넣기*/
            /*Speciality중에 Capacity > AcecpedList.Count애들 찾기*/
            /*찾은 Speciality 중에 PermitAtopic인 Speciality들 찾기*/
            /*찾은 Speciality에 뒤에서부터 아토피 환자 할당*/
            /*남은 아토피 환자는 SortSpectiality의 뒤에 해당하는 특기에 집어넣음*/
                /*만약 PermitAtopic가 아니거나, Capacity가 남은 아토피 환자보다 작으면*/
                /*SortSpecialities의 그다음 뒤에 접근*/
            /*집어넣고, 다시 빠져나온 애들은 다음 지망으로 idx 바꿔놓고*/
            /*TraineeStack이나 AfterStack에 넣기*/
        /*만약 TraineeStack에 남은 사람이 있다면*/
            /*return하고 끝내기*/
        /*아니면 AfterStack에 남은 사람들을 남은 TO에 넣기*/
    }

    public void RunAssignment()
    {
        AssignByPreference();
        SortSpectiality();
        AssignAfter();
        while(TraineeStack.Count > 0 || AfterStack.Count > 0)
        {
            AssignByPreference();
            AssignAfter();
        }
    }

    void LoadAllSpecialities()
    {
        /*특기번호부여.csv파일을 읽고, AllSpecialities을 채운다*/
        /*군번, 소대번호, 이름, 1지망 특기번호, 1지망 점수, 2지망 특기번호, 2지망 점수, 3지망 특기번호, 3지망 점수색맹, 아토피*/
    }
    
    void LoadData()
    {
        /*csv 파일을 읽음*/
        /*행별로 Trainee 객체를 생성*/
        /*TraineeStack에 넣음*/
    }
    public void SaveToCsv()
    {
        /*최종결과를 csv파일로 내보내기*/
    }
}

// ⭕ 빌드 에러 해결을 위한 진입점 클래스 추가
class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("특기 분류 시스템 빌드 성공");
    }
}