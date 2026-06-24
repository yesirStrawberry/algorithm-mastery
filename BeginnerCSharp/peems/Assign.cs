using System; 
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;

class Trainee : IComparable<Trainee>
{   
    public string SoldierCode{get; private set;}
    public string Name{get; private set;}
    public List<double> Scores{get; private set;}
    public List<int> AspireCodes{get; private set;}
    public Dictionary<int, double> ConvertedScores{get; private set;}
    private int _idx; 
    public int Idx{
        get {return _idx; }
        set {_idx = Math.Min(value, 3); }
    }
    public bool IsColorBlind {get; private set;} 
    public bool IsAtopy {get; private set;}
    public List<int> PreSpecialityCodes{get; set;}
    public int CurrentSpeciality{get; set;}
    public Trainee()
    {
        SoldierCode  = "";
        Name         = ""; 
        Scores       = new List<double>(); 
        AspireCodes  = new List<int>();  
        ConvertedScores = new Dictionary<int, double>();
        Idx          = 0;  
        IsColorBlind = false; 
        IsAtopy      = false; 
        PreSpecialityCodes = new List<int>();
        CurrentSpeciality = 0;
    }
    public Trainee(string soldier_code, string name, List<double> scores, 
                   List<int> aspireCodes, bool isColor, bool isAtopy)
    {
        SoldierCode  = soldier_code; 
        Name         = name; 
        Scores       = scores;
        AspireCodes  = aspireCodes;  
        ConvertedScores = new Dictionary<int, double>();
        Idx          = 0; 
        Scores.Add(0); 
        IsColorBlind = isColor; 
        IsAtopy      = isAtopy; 
        PreSpecialityCodes = new List<int>();
        CurrentSpeciality = 0;
    }
    public int CompareTo(Trainee other)
    {
        if(other == null) return 1; 
        int ScoreCmp = other.Scores[other.Idx].CompareTo(this.Scores[this.Idx]); 
        if(ScoreCmp != 0) return ScoreCmp;
        ScoreCmp = this.Idx.CompareTo(other.Idx); 
        if(ScoreCmp != 0) return ScoreCmp;
        
        // Idx >= 3인 경우, GetConvertedScore로 비교
        if(this.Idx >= 3 && other.Idx >= 3)
        {
            double thisScore = this.GetConvertedScore(this.CurrentSpeciality);
            double otherScore = other.GetConvertedScore(other.CurrentSpeciality);
            ScoreCmp = otherScore.CompareTo(thisScore); // 높은 점수가 먼저 오도록 역순
            if(ScoreCmp != 0) return ScoreCmp;
        }
        
        /*peem 뜯어서 봐야되는 부분, 나중에 수정*/
        ScoreCmp = this.SoldierCode.CompareTo(other.SoldierCode);
        return ScoreCmp;   
    }
    public double GetConvertedScore(int specialityCode)
    {
        double score;
        // ⭕ 딕셔너리에 특기 코드가 존재하면 그 점수를 반환합니다.
        if (ConvertedScores.TryGetValue(specialityCode, out score))
        {
            return score;
        }
        
        // ⭕ 데이터 파일에 해당 특기 점수가 없는 경우, 
        // 메시지를 띄우거나 에러를 내지 않고 기본점수 0.0점을 주어 안전하게 진행시킵니다.
        return 0.0;
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
    public static int TotalCount = 0;
    public int Code{get; private set;}
    public string Name{get; private set;}
    public int Capacity{get; private set;} 
    public bool PermitColorBlind{get; private set;}
    public bool PermitAtopy{get; private set;}
    public SortedSet<Trainee> AcceptedList{get; private set;} 
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
        Speciality.TotalCount++;
        if(t.IsAtopy == true && this.PermitAtopy == false) return t; 
        if(t.IsColorBlind == true && this.PermitColorBlind == false) return t;
        for(int i = 0; i < t.PreSpecialityCodes.Count; i++)
        {
            if(t.PreSpecialityCodes[i] == this.Code) return t; 
        }
        
        t.CurrentSpeciality = this.Code;
        AcceptedList.Add(t); 
        if(AcceptedList.Count <= Capacity) return null;
        Trainee lastTrainee = AcceptedList.Max; 
        AcceptedList.Remove(lastTrainee); 
        return lastTrainee; 
    }
    public Trainee AddTraineeForce(Trainee tr) // 특수조건자 강제 배치용
    {
        Speciality.TotalCount++;
        if(tr.IsAtopy == true && this.PermitAtopy == false) return tr; 
        if(tr.IsColorBlind == true && this.PermitColorBlind == false) return tr;
        for(int i = 0; i < tr.PreSpecialityCodes.Count; i++)
        {
            if(tr.PreSpecialityCodes[i] == this.Code) return tr; 
        }
        
        tr.CurrentSpeciality = this.Code; 
        if(AcceptedList.Count < Capacity)
        {
            AcceptedList.Add(tr);
            return null; 
        }
        Trainee lastTrainee = null; 
        
        using (var enumerator = AcceptedList.Reverse().GetEnumerator())
        {
            while (enumerator.MoveNext())
            {
                Trainee currTr = enumerator.Current; 
                if(currTr.Idx < 3) 
                {
                    lastTrainee = currTr; break; 
                } 
                if(!currTr.IsAtopy && !currTr.IsColorBlind)
                {
                    lastTrainee = currTr; break; 
                }
            }
        }

        if(lastTrainee != null)
        {
            AcceptedList.Remove(lastTrainee); 
            tr.CurrentSpeciality = this.Code; 
            AcceptedList.Add(tr);
            return lastTrainee;    
        }
        else
        {
            Trainee worstSpecialTrianee = AcceptedList.Max; 
            if(tr.CompareTo(worstSpecialTrianee) > 0)
            {
                return tr; 
            }
            else
            {
                AcceptedList.Remove(worstSpecialTrianee); 
                tr.CurrentSpeciality = this.Code; 
                AcceptedList.Add(tr);
                return worstSpecialTrianee; 
            }
        }
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
    public Stack<Trainee> TraineeStack{get; private set;} 
    public Stack<Trainee> AfterStack{get; private set;}
    public List<Speciality> AllSpecialities{get; set;} 
    public int AllTo{get; private set;}  // 총 수용 인원
    public AssignManager()
    {
        TraineeStack = new Stack<Trainee>();
        AfterStack = new Stack<Trainee>();
        AllSpecialities = new List<Speciality>();
        AllTo = 0;  // 초기화
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
        AssignByPreference();
        AssignAfter();
        while(TraineeStack.Count > 0 || AfterStack.Count > 0)
        {
            AssignByPreference();
            AssignAfter();
        }
    }
    
    public void AssignByPreference()
    {
        while(TraineeStack.Count > 0)
        {
            Trainee tr = TraineeStack.Pop();
            if(tr.Idx >= 3)
            {
                this.AfterStack.Push(tr);
                continue;
            }

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
                if(returnedTr.Idx < 3)  // Idx를 0~3으로 제한
                    TraineeStack.Push(returnedTr);
                else
                    AfterStack.Push(returnedTr);
            } 
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
            SimulatePlacement(specialNeeds, eligible, candidate, plan);
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
                Trainee dropped = spec.AddTraineeForce(tr);
                if(dropped != null)
                {
                    dropped.PreSpecialityCodes.Add(spec.Code);
                    droppedList.Add(dropped);
                }
            }
        }
        return droppedList;
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
            if(parts.Length < 5) continue;

            try
            {
                int code = int.Parse(parts[0].Trim());
                string name = parts[1].Trim();
                int capacity = int.Parse(parts[2].Trim());
                bool permitAtopy = parts[3].Trim() == ""; 
                bool permitColorBlind = parts[4].Trim() == "";

                Speciality spec = new Speciality(code, name, capacity, permitAtopy, permitColorBlind);
                AllSpecialities.Add(spec);
                AllTo += capacity;  // 총 수용 인원 계산
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
        int lineLenght = lines.Length;
        if(lines.Length - 1 != AllTo)
        {
            Console.WriteLine("훈련병 파일의 행 수가 예상과 다릅니다: " + filePath);
            return;
        }

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
                        string specCodeStr = headerParts[j].Trim();
                        string scoreStr = parts[j].Trim();
                        
                        if(!string.IsNullOrEmpty(specCodeStr) && !string.IsNullOrEmpty(scoreStr))
                        {
                            try
                            {
                                double score = double.Parse(scoreStr);
                                int specCodeInt = int.Parse(specCodeStr);
                                trainee.ConvertedScores[specCodeInt] = score;
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
    public void SaveToCsvSpec()
    {
        for(int i = 0; i < AllSpecialities.Count; i++)
        {
            Speciality spec = AllSpecialities[i];
            string safeName = spec.Name;
            string numberPrefix = i.ToString("D2") + "_";
            char[] invalidChars = System.IO.Path.GetInvalidFileNameChars();
            for(int j = 0; j < invalidChars.Length; j++)
            {
                safeName = safeName.Replace(invalidChars[j].ToString(), "_");
            }

            string fileName = numberPrefix + safeName + "결과.csv";
            System.IO.StreamWriter writer = null;
            try
            {
                writer = new System.IO.StreamWriter(fileName, false, System.Text.Encoding.UTF8);
                writer.WriteLine("군번,이름,합격점수,색맹여부, 아토피여부, 1~3지망낙방여부");

                List<Trainee> acceptedList = new List<Trainee>(spec.AcceptedList);
                for(int k = 0; k < acceptedList.Count; k++)
                {
                    Trainee tr = acceptedList[k];

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

                    string ColorBlindFlag = tr.IsColorBlind ? "예" : "아니오";
                    string AtopyFlag = tr.IsAtopy ? "예" : "아니오";
                    string rejectedAllChoicesFlag = (tr.Idx >= 3) ? "예" : "아니오";

                    writer.WriteLine(tr.SoldierCode + "," + tr.Name + "," + score + "," + ColorBlindFlag + "," + AtopyFlag + "," + rejectedAllChoicesFlag);
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
        Console.WriteLine("배치가 완료되었습니다.");
    }
    
    public void SaveToCsvFile(string TraineeFileName)
    {
        string pureName = System.IO.Path.GetFileNameWithoutExtension(TraineeFileName);
        string fileName = pureName + "_결과.csv";
        System.IO.StreamWriter writer = null;

        try
        {
            // 파일 오픈을 try 블록 전체의 최상단에서 수행
            writer = new System.IO.StreamWriter(fileName, false, System.Text.Encoding.UTF8);
            writer.WriteLine("군번, 이름, 색약, 아토피, 최종특기번호, 최종점수, 1여부, 2여부, 3여부");

            for (int i = 0; i < AllSpecialities.Count; i++)
            {
                Speciality spec = AllSpecialities[i];
                
                // 데이터 접근 중 터질 수 있는 예외를 개별적으로 잡아내기 위함
                using (var enumerator = spec.AcceptedList.GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        try
                        {
                            Trainee tr = enumerator.Current;
                            string scoreStr = "";

                            // tr.Scores나 인덱스 범위 확인에서 에러가 날 수 있으므로 방어 코드 필요 && tr.Scores != null && tr.Scores.Count > tr.Idx
                            if (tr.Idx < 3 && tr.Scores != null && tr.Scores.Count > tr.Idx)
                            {
                                scoreStr = tr.Scores[tr.Idx].ToString();
                            }
                            else
                            {
                                scoreStr = "임의분류";
                            }

                            string colorBlindFlag = tr.IsColorBlind ? "o" : "x";
                            string atopyFlag = tr.IsAtopy ? "o" : "x";
                            string acquireFlag = (tr.Idx == 0 ? "o" : "x") + "," +
                                                (tr.Idx == 1 ? "o" : "x") + "," +
                                                (tr.Idx == 2 ? "o" : "x");

                            string line = string.Format("{0},{1},{2},{3},{4},{5},{6}",
                                tr.SoldierCode, tr.Name, colorBlindFlag, atopyFlag,
                                spec.Name, scoreStr, acquireFlag);

                            writer.WriteLine(line);
                        }
                        catch (System.Exception ex)
                        {
                            // 특정 교육생 한 명의 데이터 오류로 전체 파일 작성이 중단되거나 깨지는 것을 방지
                            Console.WriteLine("교육생 데이터 처리 오류: " + ex.Message);
                        }
                    }
                }
            }
        }
        catch (System.Exception ex)
        {
            Console.WriteLine("CSV 파일 쓰기 오류: " + fileName + " - " + ex.Message);
        }
        finally
        {
            // SaveToCsvSpec처럼 어떤 상황에서든 반드시 안전하게 파일을 닫도록 보장
            if (writer != null)
            {
                writer.Close();
            }
        }

        Console.WriteLine("배치가 완료되었습니다.");
    }
    // ⭕ 빌드 에러 해결을 위한 진입점 클래스 추가
    class Program
    {
        static void Main()
        {
            string baseDir = "/workspaces/algorithm-mastery/BeginnerCSharp/peems/"; 
            //Console.Write("특기 파일 이름을 입력하세요:");
            // string SpecialityFileName = Console.ReadLine();

            // Console.Write("훈련병 파일 이름을 입력하세요:");
            // string TraineeFileName = Console.ReadLine();

            string SpecialityFileName = "특기TO_일반.csv";
            string TraineeFileName = "훈련병_일반_비선호반영.csv";

            AssignManager manager = new AssignManager();
            manager.LoadAllSpecialities(baseDir + SpecialityFileName);

            manager.LoadData(baseDir + TraineeFileName);
            manager.RunAssignment();
            manager.SaveToCsvFile(TraineeFileName);
            manager.SaveToCsvSpec(); 
            Console.WriteLine("총 AddTrainee 회수: " + Speciality.TotalCount);
        }
    }
}