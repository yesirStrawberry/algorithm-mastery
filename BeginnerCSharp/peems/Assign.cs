using System; 
using System.Collections.Generic;

/*permitbounce는 점수 낮은 곳임*/

class Trainee : IComparable<Trainee>
{
    public string SoldierCode{get; private set;}
    public string Name{get; private set;}
    public List<double> Scores{get; private set;}
    public List<int> AspireCodes{get; private set;}
    public Dictionary<string, double> ConvertedScores{get; private set;}
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
        Scores       = new List<double>(); 
        AspireCodes  = new List<int>();  
        ConvertedScores = new Dictionary<string, double>();
        Idx          = 0;  
        IsColorBlind = false; 
        IsAtopy      = false; 
        PreSpecialityCodes = new List<int>();
    }
    public Trainee(string soldier_code, string name, List<double> scores, 
                   List<int> aspireCodes, bool isColor, bool isAtopy)
    {
        SoldierCode  = soldier_code; 
        Name         = name; 
        Scores       = scores;
        AspireCodes  = aspireCodes;  
        ConvertedScores = new Dictionary<string, double>();
        Idx          = 0; 
        Scores.Add(0); 
        IsColorBlind = isColor; 
        IsAtopy      = isAtopy; 
        PreSpecialityCodes = new List<int>();
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
    public double GetConvertedScore(int specialityCode)
    {
        string key = specialityCode.ToString();
        double score;
        if(!ConvertedScores.TryGetValue(key, out score))
        {
            Console.WriteLine("특수조건자에 점수를 입력해주세요");
            throw new KeyNotFoundException("특수조건자 점수가 없습니다: " + key);
        }
        return score;
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

class Speciality : IComparable<Speciality>
{
    public int Code{get;}
    public string Name{get;}
    public int Capacity{get;} 
    public bool PermitColorBlind{get;}
    public bool PermitAtopy{get;}
    public SortedSet<Trainee> AcceptedList{get;} 
    public Speciality()
    {
        Code = 0; 
        Name = "";
        Capacity = 0; 
        PermitAtopy = false; 
        PermitColorBlind = false;  
        AcceptedList = new SortedSet<Trainee>();
    }
    public Speciality(int code, string name, int capacity, bool atopy, bool colorBlind)
    {
        Code = code; 
        Name = name;
        Capacity = capacity; 
        PermitAtopy = atopy; 
        PermitColorBlind = colorBlind; 
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
        if(this.AcceptedList.Count == 0 && other.AcceptedList.Count == 0)
            return this.Code.CompareTo(other.Code);
        if(this.AcceptedList.Count == 0) return -1;  // 빈 특기는 뒤로
        if(other.AcceptedList.Count == 0) return 1;
        int result = this.AcceptedList.Max.CompareTo(other.AcceptedList.Max);
        if(result != 0) return result;
        return this.Code.CompareTo(other.Code);
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
        SortedSpecialites.Clear();
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            SortedSpecialites.Add(AllSpecialities[i]);
        }
    }

    public void AssignAfter()
    {
        // AfterStack에서 특수조건자만 추출하고, 남은 일반 AfterStack은 유지한다.
        List<Trainee> specialNeeds = ExtractSpecialNeeds();
        if(specialNeeds.Count == 0)
        {
            FillRemainingSlots();
            return;
        }

        List<Speciality> eligible = BuildEligible(specialNeeds);
        if(eligible.Count == 0)
        {
            for(int i = 0; i < specialNeeds.Count; i++)
                AfterStack.Push(specialNeeds[i]);
            return;
        }

        Speciality reference = SelectReference(eligible, specialNeeds);
        Dictionary<Speciality, List<Trainee>> plan = new Dictionary<Speciality, List<Trainee>>();
        SimulatePlacement(specialNeeds, eligible, reference, plan);
    
        List<Trainee> dropped = ApplyPlacement(plan);

        // dropped 처리만 남음
        for(int i = 0; i < dropped.Count; i++)
        {
            Trainee tr = dropped[i];
            if(tr.Idx <= 3)
                TraineeStack.Push(tr);
            else
                AfterStack.Push(tr);
        }
    }

    private List<Trainee> ExtractSpecialNeeds()
    {
        List<Trainee> list = new List<Trainee>();
        Stack<Trainee> temp = new Stack<Trainee>();
        while(AfterStack.Count > 0)
        {
            Trainee tr = AfterStack.Pop();
            if(tr.IsColorBlind || tr.IsAtopy)
            {
                list.Add(tr);
            }
            else
            {
                temp.Push(tr);
            }
        }
        while(temp.Count > 0)
        {
            AfterStack.Push(temp.Pop());
        }
        return list;
    }

    private List<Speciality> BuildEligible(List<Trainee> specialNeeds)
    {
        List<Speciality> fullList = new List<Speciality>();
        List<Speciality> openList = new List<Speciality>();
        List<Speciality> eligible = new List<Speciality>();

        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            Speciality spec = AllSpecialities[i];
            if(!HasPermitForAny(spec, specialNeeds))
            {
                continue;
            }
            if(spec.AcceptedList.Count >= spec.Capacity)
            {
                fullList.Add(spec);
            }
            else
            {
                openList.Add(spec);
            }
        }

        fullList.Sort();
        openList.Sort();

        for(int i = fullList.Count - 1; i >= 0; i--)
            eligible.Add(fullList[i]);
        for(int i = openList.Count - 1; i >= 0; i--)
            eligible.Add(openList[i]);
        return eligible;
    }

    private bool HasPermitForAny(Speciality spec, List<Trainee> specialNeeds)
    {
        for(int i = 0; i < specialNeeds.Count; i++)
        {
            Trainee tr = specialNeeds[i];
            if(tr.IsAtopy && tr.IsColorBlind)
            {
                if(spec.PermitAtopy && spec.PermitColorBlind)
                    return true;
            }
            else if(tr.IsAtopy)
            {
                if(spec.PermitAtopy) return true;
            }
            else if(tr.IsColorBlind)
            {
                if(spec.PermitColorBlind) return true;
            }
        }
        return false;
    }

    private Speciality SelectReference(List<Speciality> eligible, List<Trainee> specialNeeds)
    {
        int index = eligible.Count - 1;
        while(index >= 0)
        {
            Speciality candidate = eligible[index];
            Dictionary<Speciality, List<Trainee>> plan = new Dictionary<Speciality, List<Trainee>>();
            SimulatePlacement(specialNeeds, eligible, candidate, plan);  // ← 이제 반환값 없음
            Speciality best = BestSpecialityInPlan(plan);
            if(best == candidate)
                return candidate;
            index--;
        }
        return eligible[eligible.Count - 1];
    }

    private Speciality BestSpecialityInPlan(Dictionary<Speciality, List<Trainee>> plan)
    {
        Speciality best = null;
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            Speciality spec = AllSpecialities[i];
            if(!plan.ContainsKey(spec)) continue;
            if(best == null)
                best = spec;
            else if(spec.CompareTo(best) > 0)
                best = spec;
        }
        return best;
    }

    private void SimulatePlacement(List<Trainee> specialNeeds, List<Speciality> eligible, Speciality reference, Dictionary<Speciality, List<Trainee>> plan)
    {
        plan.Clear();
        for(int i = 0; i < eligible.Count; i++)
            plan[eligible[i]] = new List<Trainee>();

        SortSpecialNeeds(specialNeeds, reference);

        for(int i = 0; i < specialNeeds.Count; i++)
        {
            Trainee tr = specialNeeds[i];
            for(int j = eligible.Count - 1; j >= 0; j--)
            {
                Speciality spec = eligible[j];
                if(!CanEnter(spec, tr)) continue;
                
                plan[spec].Add(tr);  // ← plan에만 추가
                break;
            }
        }
    }
    // 특수조건자들을 reference 특기 기준으로 점수 내림차순 정렬;
    private void SortSpecialNeeds(List<Trainee> specialNeeds, Speciality reference)
    {
        for(int i = 0; i < specialNeeds.Count - 1; i++)
        {
            for(int j = i + 1; j < specialNeeds.Count; j++)
            {
                if(specialNeeds[j].GetConvertedScore(reference.Code) > specialNeeds[i].GetConvertedScore(reference.Code))
                {
                    Trainee temp = specialNeeds[i];
                    specialNeeds[i] = specialNeeds[j];
                    specialNeeds[j] = temp;
                }
            }
        }
    }

    private bool CanEnter(Speciality spec, Trainee tr)
    {
        if(tr.IsAtopy && tr.IsColorBlind)
            return spec.PermitAtopy && spec.PermitColorBlind;
        if(tr.IsAtopy)
            return spec.PermitAtopy;
        if(tr.IsColorBlind)
            return spec.PermitColorBlind;
        return false;
    }

    private void FillRemainingSlots()
    {
        Stack<Trainee> temp = new Stack<Trainee>();

        while(AfterStack.Count > 0)
        {
            Trainee tr = AfterStack.Pop();
            bool placed = false;
            for(int i = 0; i < AllSpecialities.Count; i++)
            {
                Speciality spec = AllSpecialities[i];
                if(spec.AcceptedList.Count >= spec.Capacity)
                    continue;
                if(tr.IsPreSpec(spec.Code))
                    continue;

                Trainee dropped = spec.AddTrainee(tr);
                if(dropped == null)
                {
                    placed = true;
                    break;
                }
                temp.Push(dropped);
            }

            if(!placed)
                temp.Push(tr);
        }

        while(temp.Count > 0)
            AfterStack.Push(temp.Pop());
    }

    private List<Trainee> ApplyPlacement(Dictionary<Speciality, List<Trainee>> plan)
    {
        List<Trainee> droppedList = new List<Trainee>();
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            Speciality spec = AllSpecialities[i];
            if(!plan.ContainsKey(spec)) continue;
            List<Trainee> assigned = plan[spec];
            for(int j = 0; j < assigned.Count; j++)
            {
                Trainee tr = assigned[j];
                Trainee dropped = spec.AddTrainee(tr);
                if(dropped != null)
                {
                    dropped.PreSpecialityCodes.Add(spec.Code);
                    droppedList.Add(dropped);
                }
            }
        }
        return droppedList;
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

    void LoadAllSpecialities(string filePath)
    {
        if(!System.IO.File.Exists(filePath))
        {
            Console.WriteLine("특기 파일을 찾을 수 없습니다: " + filePath);
            return;
        }

        string[] lines = System.IO.File.ReadAllLines(filePath, System.Text.Encoding.UTF8);
        for(int i = 1; i < lines.Length; i++)
        {
            string line = lines[i].Trim();
            if(string.IsNullOrEmpty(line)) continue;

            string[] parts = line.Split(',');
            if(parts.Length < 4) continue;

            try
            {
                int code = int.Parse(parts[0].Trim());
                string name = parts[1].Trim();
                int capacity = int.Parse(parts[2].Trim());
                bool permitColorBlind = bool.Parse(parts[3].Trim() != "" ? "true" : "false");
                bool permitAtopy = bool.Parse(parts[4].Trim() != "" ? "true" : "false");

                Speciality spec = new Speciality(code, name, capacity, permitAtopy, permitColorBlind);
                AllSpecialities.Add(spec);
            }
            catch(FormatException ex)
            {
                Console.WriteLine("특기 파일 파싱 오류 (라인 " + (i + 1) + "): " + ex.Message);
            }
        }
    }
    
    void LoadData(string filePath)
    {
        if(!System.IO.File.Exists(filePath))
        {
            Console.WriteLine("훈련병 파일을 찾을 수 없습니다: " + filePath);
            return;
        }

        string[] lines = System.IO.File.ReadAllLines(filePath, System.Text.Encoding.UTF8);
        string[] headerParts = lines[0].Split(',');
        for(int i = 1; i < lines.Length; i++)
        {
            string line = lines[i].Trim();
            if(string.IsNullOrEmpty(line)) continue;

            string[] parts = line.Split(',');
            if(parts.Length < 10) continue;

            try
            {
                string soldierCode = parts[0].Trim();
                string name = parts[1].Trim();
                
                List<int> aspireCodes = new List<int>();
                aspireCodes.Add(int.Parse(parts[2].Trim()));
                aspireCodes.Add(int.Parse(parts[4].Trim()));
                aspireCodes.Add(int.Parse(parts[6].Trim()));

                List<double> scores = new List<double>();
                scores.Add(double.Parse(parts[3].Trim()));
                scores.Add(double.Parse(parts[5].Trim()));
                scores.Add(double.Parse(parts[7].Trim()));

                bool isColorBlind = bool.Parse(parts[8].Trim() != "" ? "true" : "false");
                bool isAtopy = bool.Parse(parts[9].Trim() != "" ? "true" : "false");

                Trainee trainee = new Trainee(soldierCode, name, scores, aspireCodes, isColorBlind, isAtopy);
                TraineeStack.Push(trainee);

                // ConvertedScores 채워주기 (특수조건자인 경우만)
                if(isColorBlind || isAtopy)
                {
                    for(int j = 10; j < headerParts.Length && j < parts.Length; j++)
                    {
                        string specCode = headerParts[j].Trim();
                        string scoreStr = parts[j].Trim();
                        
                        if(!string.IsNullOrEmpty(specCode) && !string.IsNullOrEmpty(scoreStr))
                        {
                            try
                            {
                                double score = double.Parse(scoreStr);
                                trainee.ConvertedScores[specCode] = score;
                            }
                            catch(FormatException)
                            {
                                Console.WriteLine("변환 점수 파싱 오류 (라인 " + (i + 1) + ", 컬럼 " + (j + 1) + ")");
                            }
                        }
                    }
                }
            }
            catch(FormatException ex)
            {
                Console.WriteLine("훈련병 파일 파싱 오류 (라인 " + (i + 1) + "): " + ex.Message);
            }
        }
    }
    public void SaveToCsv()
    {
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            Speciality spec = AllSpecialities[i];
            string safeName = spec.Name;
            char[] invalidChars = System.IO.Path.GetInvalidFileNameChars();
            for(int j = 0; j < invalidChars.Length; j++)
            {
                safeName = safeName.Replace(invalidChars[j].ToString(), "_");
            }

            string fileName = safeName + "결과.csv";
            System.IO.StreamWriter writer = null;
            try
            {
                writer = new System.IO.StreamWriter(fileName, false, System.Text.Encoding.UTF8);
                writer.WriteLine("군번,이름,합격점수");

                foreach(Trainee tr in spec.AcceptedList)
                {
                    double score;
                    if(tr.Idx < 3)
                    {
                        score = tr.Scores[tr.Idx];
                    }
                    else
                    {
                        try
                        {
                            score = tr.GetConvertedScore(spec.Code);
                        }
                        catch(KeyNotFoundException)
                        {
                            score = 0.0;
                        }
                    }

                    writer.WriteLine(tr.SoldierCode + "," + tr.Name + "," + score);
                }
            }
            catch(System.Exception ex)
            {
                Console.WriteLine("CSV 저장 오류: " + fileName + " - " + ex.Message);
            }
            finally
            {
                if(writer != null)
                {
                    writer.Close();
                }
            }
        }
    }
    // ⭕ 빌드 에러 해결을 위한 진입점 클래스 추가
    class Program
    {
        static void Main(string[] args)
        {
            string baseDir = "BeginnerCSharp/peems/";
            
            AssignManager manager = new AssignManager();
            manager.LoadAllSpecialities(baseDir + "특기TO 일반.csv");
            manager.LoadData(baseDir + "훈련병_일반.csv");
            manager.RunAssignment();
            Console.WriteLine("배치가 완료되었습니다.");
        }
    }
}