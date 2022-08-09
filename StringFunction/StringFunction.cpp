
#include <iostream>
#include <vector>

std::string StringChange(const std::string& _Src, const std::string& _Old, const std::string& _New)
{
    // 일치하면 교체작업시작
    // BBB이전부터 있던 모든 문자열 가져와서 붙이기
    // BBB 이후부터 새문자열을 교체
    // 합치기


 // std::string Name = StringChange("AAABBBCCC", "BBB", "DDD");

    size_t SrcSize = _Src.length();
    size_t OldSize = _Old.length();
    size_t NewSize = _New.length();

    for (int CurrentIndex = 0; CurrentIndex < SrcSize; ++CurrentIndex)
    {
        if (_Src[CurrentIndex] == _Old[0])
        {
            bool FirstCheck = false;

            for (int Count = 1; Count < OldSize; ++Count)
            {
                if (_Src[CurrentIndex + Count] == _Old[Count])
                {
                    FirstCheck = true;
                    continue;
                }

                else
                {
                    FirstCheck = false;
                    break;
                }
            }

            if (!FirstCheck)
            {
                continue;
            }

            // 교체해야하는 문장의 구간을 찾아냈다.
            else
            {
                std::string NewString;

                NewString.append(_Src.c_str(), 0, CurrentIndex);
                NewString.append(_New.c_str(), 0, NewSize);
                NewString.append(_Src.c_str(), CurrentIndex + OldSize, SrcSize);

                return NewString;
            }
        }
    }

    return "";
}

std::vector<std::string> StringSplit(const std::string& _Src, const std::string& _Value)
{
    // _Src 길이만큼 문장 검사.
    // _Src의 N번째 인덱스가 _Value의 N번째 인덱스랑 일치할경우
    // N - 1번째까지의 인덱스를 만큼을 새 문자열에 strcat후 PushBack.
    // N + 1번째를 기록.
    // 사이즈 벗어날때까지 검사.

    //std::vector<std::string> Test = StringSplit("aaa,bbb,ccc", ",");
    
    std::vector<std::string> vec;

    size_t SrcSize = _Src.length();
    size_t ValueSize = _Value.length();
    int LastIndex = 0;

    for (int CurrentIndex = 0; CurrentIndex < SrcSize; ++CurrentIndex)
    {
        if (_Src[CurrentIndex] == _Value[0])
        {
            bool FirstCheck = true;

            for (int j = 1; j < ValueSize; ++j)
            {
                if (_Src[CurrentIndex + j] == _Value[j])
                {
                    FirstCheck = true;
                    continue;
                }

                else
                {
                    FirstCheck = false;
                    break;
                }
            }

            if (!FirstCheck)
            {
                continue;
            }

            // 교체해야하는 문장의 구간을 찾아냈다.
            else
            {
                std::string NewString;
                NewString.append(_Src, LastIndex, CurrentIndex - LastIndex);
                
                LastIndex = CurrentIndex + 1;

                vec.push_back(NewString);
            }
        }
    }

    std::string NewString;

    NewString.append(_Src, LastIndex, SrcSize - LastIndex);

    vec.push_back(NewString);

    return vec;
}

int main()
{
    std::string Name = StringChange("AAABBBCCC", "BBB", "DDD");

    std::vector<std::string> Test = StringSplit("aaa,bbb,ccc", ",");
 
    std::cout << Name.c_str() << std::endl;
    
    std::cout << "\n" << std::endl;

    for (int Index = 0; Index < Test.size(); ++Index)
    {
        std::cout << Test[Index].c_str() << std::endl;
    }

    // Test[0] == "aaa"
    // Test[1] == "bbb"
    // Test[2] == "ccc"

    return 0;
}
