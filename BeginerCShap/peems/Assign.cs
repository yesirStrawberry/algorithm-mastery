using System; 
using System.Collections.Generic;

class Trainee
{
    public string SoldierCode{get;}
    public string Name{get;}
    public List<int> Scores{get;}
    public List<int> AspireCodes{get;}
    private int _idx; 
    public int Idx{
        get {return _idx; }
        set {_idx = Math.Min(value, 4); }
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
}

class Speciality
{
    public int Code{get;}
    public int Capacity{get;} 
    public bool PermitColorBlind{get;}
    public bool PermitAtopy{get;}
    public bool PermitBounce{get;}
    public SortedSet<Trainee> AcceptedList{get;} 
    public Speciality()
    {
        Code = 0; 
        Capacity = 0; 
        PermitAtopy = false; 
        PermitColorBlind = false; 
        PermitBounce = false;  
        AcceptedList = new SortedSet<Trainee>();
    }
    public Speciality(int code, int capacity, bool atopy, bool colorBilnd, bool bounce)
    {
        Code = code; 
        Capacity = capacity; 
        PermitAtopy = atopy; 
        PermitColorBlind = colorBilnd; 
        PermitBounce = bounce;  
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
}

class AssignManager
{
    public Stack<Trainee> TraineeStack{get;} 
    public Stack<Trainee> AfterStack{get;}
    public List<Speciality> AllSpecialities{get; set;} 
    public AssignManager()
    {
        TraineeStack = new Stack<Trainee>();
        AfterStack = new Stack<Trainee>();
        AllSpecialities = new List<Speciality>();
    }
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
        return null; 
    }

    public void RunAssignment()
    {
        while(TraineeStack.Count > 0 || AfterStack.Count > 0)
        {
            if(TraineeStack.Count != 0)
            {
                Trainee tr = TraineeStack.Pop();
                Speciality spec = this.FindSpeciality(tr.AspireCodes[tr.Idx]);
                Trainee returnedTr = spec.AddTrainee(tr); 
                returnedTr.PreSpecialityCodes.Add(spec.Code); 
                returnedTr.Idx++; 
                if(returnedTr.Idx == 4) this.AfterStack.Push(returnedTr); 
            }
            else if(AfterStack.Count != 0)
            {
                bool isAssigned = false; 
                Trainee tr = AfterStack.Pop();

                /*spec의 남는 거부터 넣음*/
                for(int i = 0; i < AllSpecialities.Count; i++)
                {
                    Speciality spec = AllSpecialities[i];
                    /*PreSpecialityCodes 식별 필요*/

                    if (spec.IsRemain())
                    {
                        bool atopyPass = !tr.IsAtopy || spec.PermitAtopy;
                        bool colorPass = !tr.IsColorBlind || spec.PermitColorBlind;

                        if(atopyPass && colorPass) /*PreSpecialityCodes 식별 필요*/
                        {
                            spec.AcceptedList.Add(tr); 
                            isAssigned = true; 
                            break; 
                        }
                    }
                }

                /*PermitBounce가 True인지 Specailty검사*/
                if (!isAssigned)
                {
                    for(int i = 0; i < AllSpecialities.Count; i++)
                    {
                        Speciality spec = AllSpecialities[i]; 
                        
                        bool atopyPass = !tr.IsAtopy || spec.PermitAtopy;
                        bool colorPass = !tr.IsColorBlind || spec.PermitColorBlind;
                        bool bouncePass = spec.PermitBounce;
                        /*PreSpecialityCodes 식별 필요*/

                        if(atopyPass && colorPass && bouncePass) /*PreSpecialityCodes 식별 필요*/
                        {
                            Trainee ReturnedTr = spec.AddTrainee(tr);
                            if(ReturnedTr != null)
                            {
                               ReturnedTr.PreSpecialityCodes.Add(spec.Code); 
                               TraineeStack.Push(ReturnedTr); 
                               isAssigned = true;   
                               break; 
                            } 
                        }   
                    }
                }
                if (!isAssigned)
                {
                    /*Error상황*/
                    /*Bounce로 넣을 특기가 다빠진 상황*/
                    /*특기번호부여 파일에서 bounce할 때 넣을 꺼 추가*/

                    Console.WriteLine("특기분류가 완료되지 못했습니다.");
                    Console.WriteLine("튕긴 훈련병들이 갈 곳을 추가로 지정해주십시오");  
                    break; 
                }

            }
        }
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