#include <iostream>



class Cstring {
public:
    Cstring();
    Cstring(const char x[]) {
        std::cout << "Contructed " << std::endl;
        int i;
        for (i = 0; x[i] != '\0'; i++);
        str = new char[i];
        size = i;
        for (i = 0; x[i] != '\0'; i++) {
            str[i] = x[i];
        }
    }
    Cstring(Cstring& s) {
        str = new char[s.size];
        for (int i = 0; i < s.size; i++)
            str[i] = s.str[i];
        size = s.size;
    }

    ~Cstring() {
        std::cout << "Deleting  = ";
        for (int i = 0; i < size; i++)
            std::cout << str[i];
        std::cout << std::endl;
        delete[] str;
    }

    void print() {
        std::cout << "Size : " << size << "\t";
        //for(int i=0; i < size; i++)
            //std::cout << str[i];
        std::cout << str;
    }

private:
    char* str = nullptr;
    int size;
};

int main()
{
    char test[] = { 'H', 'e','l' };
    Cstring s1("Hello"), s2("THIS IS A TEST");
    Cstring s3(s2), s4(test);
    s4.print();
    std::cout << std::endl;
    s3.print();
    std::cout << std::endl;



    return 0;
}