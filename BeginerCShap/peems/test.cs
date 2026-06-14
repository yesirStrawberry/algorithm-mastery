using System;
using System.Collections.Generic;
using System.IO;
using System.Text;


public class Student
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Score { get; set; }
}


class Program
{
    static void Main()
    {
        // 1. .NET Core 이상에서 EUC-KR(CP949) 인코딩을 사용하기 위해 필요한 코드
        // (폐쇄망 환경이라도 기본 프레임워크에 포함되어 있으므로 외부 다운로드가 필요 없습니다)
        Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);

        string filePath = "BeginerCShap/peems/test.csv";
        List<Student> students = new List<Student>();

        // 2. 파일의 인코딩에 맞게 설정 (엑셀로 만든 CSV라면 보통 "EUC-KR" 또는 "KS_C_5601-1987")
        // 만약 메모장 등에서 UTF-8로 저장했다면 Encoding.UTF8 을 사용하면 됩니다.
        Encoding koreanEncoding = Encoding.UTF8;

        // 지정한 인코딩으로 파일의 모든 줄을 읽어옴
        string[] lines = File.ReadAllLines(filePath, koreanEncoding);

        // 첫 번째 줄(헤더: id,name,score)은 건너뛰고 데이터 처리
        for (int i = 1; i < lines.Length; i++)
        {
            string line = lines[i];
            if (string.IsNullOrWhiteSpace(line)) continue;

            // 콤마(,)를 기준으로 분할
            string[] values = line.Split(',');

            // 예외 방지를 위해 데이터 개수 검증
            if (values.Length < 3) continue;

            // 클래스 인스턴스 생성 및 데이터 할당
            Student student = new Student
            {
                Id =int.Parse(values[0].Trim()),
                Name = values[1].Trim(), // 한글 데이터가 정상적으로 저장됨
                Score = int.Parse(values[2].Trim())
            };

            students.Add(student);
        }

        // 결과 확인용 출력 (콘솔 창도 한글 출력을 지원해야 깨지지 않습니다)
        Console.OutputEncoding = Encoding.UTF8; 
        foreach (var s in students)
        {
            Console.WriteLine($"ID: {s.Id}, 이름: {s.Name}, 점수: {s.Score}");
        }
    }
}