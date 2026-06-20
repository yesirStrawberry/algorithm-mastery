/*
xor 연산 한 번에 암호화, 다시하면 복호화
*/

using System; 

class Encode
{
    public static void Main()
    {
        string msg = "This is a test"; 
        string encmsg = "";  
        string decmsg = ""; 
        string key = "abcdefgi";
        int keySize = key.Length;   

        for(int i = 0; i < msg.Length; i++)
        {
            encmsg += (char)(msg[i] ^ key[i % keySize]); 
        }
        for(int i = 0; i < encmsg.Length; i++)
        {
            decmsg += (char)(encmsg[i] ^ key[i % keySize]); 
        }

        Console.WriteLine("Oringinal Message : " + msg);
        Console.WriteLine("Encpyted Message  : " + encmsg);
        Console.WriteLine("Decpyted Message  : " + decmsg); 
    }
}