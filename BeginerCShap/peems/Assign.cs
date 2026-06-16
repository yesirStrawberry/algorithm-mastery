using System; 
using System.Collections.Generic;

class Trainee
{
    private string SoldierCode{get;}
    private string Name{get;}
    private List<int> Scores{get;}
    private List<int> AspireCodes{get;}
    private int _idx; 
    private int Idx{
        get {return _idx; }
        set {_idx = Math.Min(value, 4); }
    }
    private bool IsColorBlind; 
    private bool IsAtopy; 
    private List<int> PreSpecialityCodes{get; set;}
    public Trainee(){}
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
        int ScoreCmp = other.CurrentScore.CompareTo(this.CurrentScore); 
        if(ScoreCmp != 0) return ScoreCmp;
        ScoreCmp = this.Idx.CompareTo(other.idx); 
        if(ScoreCmp != 0) return ScoreCmp; 
        /*peem 뜯어서 봐야되는 부분, 나중에 수정*/
        ScoreCmp = this.SoldierCode.CompareTo(other.SoldierCode);
        return ScoreCmp;   
    }
}

class Speciality
{
    private int Code{get;}
    private int Capacity{get;} 
    private bool PermitColorBlind{get;}
    private bool PermitAtopy{get;}
    private bool PermitBounce{get;}
    private SortedSet<Trainee> AcceptedList{get;} 
    public Speciality(){}
    public Speciality(int code, int capacity, bool atopy, bool colorBilnd, bool bounce)
    {
        Code = code; 
        Capacity = capacity; 
        PermitAtopy = atopy; 
        PermitColorBlind = colorBilnd; 
        PermitBounce = bounce;  
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
}

class AssignManager
{
    private Stack<Trainee> TraineeStack{get;} 
    private Stack<Trainee> AfterStack{get;}
    private list<Speciality> AllSpecialities{get; set;} 
    public AssignManager(){}
    void LoadAllSpecialities()
    {
        /*특기번호부여.csv파일을 읽고, AllSpecialities을 채운다*/
    }
    
    void LoadData()
    {
        /*csv 파일을 읽음*/
        /*행별로 Trainee 객체를 생성*/
        /*TraineeStack에 넣음*/
    }
    public Speciality FindSpeciality(int code)
    {
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            if(code == AllSpecialities[i].Code) return AllSpecialities[i]; 
        }
    }

    public void RunAssignment()
    {
        while(TraineeStack.Count == 0 || AfterStack.Count == 0)
        {
            if(TraineeStack.Count != 0)
            {
                Trainee tr = TraineeStack.Pop();
                Speciality spec = this.FindSpeciality(tr.AspireCodes[tr.Idx]);
                Trainee returnedTr = spec.AddTrainee(t); 
                returnedTr.PreSpecialityCodes.Add(spec.Code); 
                returnedTr.Idx++; 
                if(returnedTr.Idx == 4) this.AfterStack.Push(returnedTr); 
            }
            else if(AfterStack.Count != 0)
            {
                /*spec의 남는 거부터 넣음*/
                /*PermitBounce가 True인지 Specailty검사*/
            }
        }
    }

    public void SaveToCsv()
    {
        /*최종결과를 csv파일로 내보내기*/
    }
}