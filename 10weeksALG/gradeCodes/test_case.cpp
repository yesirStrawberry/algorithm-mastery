#include "header.h"

std::vector<TestCase> test_cases = {
    {"abba\n", "1\n"},
    {"abcba\n", "1\n"},
    {"abca\n", "0\n"},
    {"z\n", "1\n"},
    {"abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba\n", "1\n"},
    {"hxbuauhlrezpjjmjciullqnhypifxqrodavnpcnzhhzncpnvadorqxfipyhnqlluicjmjjpzerlhuaubxh\n", "1\n"},
    {"aoyuqlcxuxclquyoa\n", "1\n"},
    {"odzxytfkxcnklrgxcwcdxucysnrbrrdoyzmwcqvbsdlccldsbvqcwmzyodrrbrnsycuxdjwcxgrlkncxkftyxzdo\n", "0\n"},
    {"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n", "1\n"},
    {"cfvrgxqtopwbeqfjgoasjxmicnfjrcvgnpwswrbhpklnjfudzvuprmfnmzgqnsnkaergpvyjdohgsiomhoqrbbvwutfqnprqbjmn\n", "0\n"},
    {"ijsbeqd\n", "0\n"},
    {"lemjaquihopwhemkcpagyfpjerqdeofuddufoedqrejpfygapckmehwpohiuqajmel\n", "1\n"},
    {"ymy\n", "1\n"},
    {"numwpnlnpqxanchrbiiyspawnhwwwhnwapsyiibrhcpaxqpnlnpwmun\n", "0\n"},
    {"ppppppppppppppppppppppppppppppppppppp\n", "1\n"},
    {"jkezzsnibtsfvzcwnvmfetcwwinkqdecupsdtydebushjhesdtbdydcpnfzxfsxrkydpgvbunbqpjlgdapvuucrldmvhlzumoggt\n", "0\n"},
    {"kkejd\n", "0\n"},
    {"i\n", "1\n"},
    {"ioyydubqsgfwqrigkxzovskxekrzialhygkeaxvcnwwncvxaekgyhlaizrkexksvozxkgirqwfgsqbudyyoi\n", "1\n"},
    {"foyof\n", "1\n"},
    {"qemcapujzhvymhuesqbydxppottjmlxamvbzhshzbvmaxlmtttoppxdybqseuhmyvhzjupacmeq\n", "0\n"},
    {"ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n", "1\n"},
    {"blbihrnyxtqyrbzkvguczjmqxhsfzmxaxvoiyutinswmxewdfhhmzyvzpwpegbhdpxbmivkkibdwaccobxqtximaxxqrhpdsgqgj\n", "0\n"},
    {"brdfpty\n", "0\n"},
    {"savvntodhuhlduowfvcvnvssyxsczzjcaacjzzcsxyssvnvcvfwoudlhuhdotnvvas\n", "1\n"}
};