#include <iostream>

using namespace std;

class phone{
public:
    phone(){}
    virtual ~phone(){}
    virtual void Show(){}
};

class iphone : public phone{
private:
    string m_name;
public:
    iphone(string name):m_name(name){}
    ~iphone(){}
    void Show(){cout << m_name << endl;}
};

class Nokia : public phone{
private:
    string m_name;
public:
    Nokia(string name):m_name(name){}
    ~Nokia(){}
    void Show(){cout << m_name << endl;}
};

class DecoratorPhone : public phone{
private:
    phone *m_phone;
public:
    DecoratorPhone(phone *_phone):m_phone(_phone){}
    virtual void Show() { m_phone->Show(); }
};

class DecoratorPhoneA : public DecoratorPhone{
public:
    DecoratorPhoneA(phone *_phone) : DecoratorPhone(_phone){}
    void Show() { 
    DecoratorPhone::Show();
    AddDecorate();		
    }
private:
    void AddDecorate() { cout << "add A" << endl; }
};

class DecoratorPhoneB : public DecoratorPhone{
public:
    DecoratorPhoneB(phone* _phone): DecoratorPhone(_phone){}
    void Show() {
    DecoratorPhone::Show();
    AddDecorate();
    }
private:
    void AddDecorate(){
    cout << "add B" << endl;
    }
};

int main()
{
    phone* rphone = new iphone("6300");
    phone* dpa = new DecoratorPhoneA(rphone);
    phone* dpb = new DecoratorPhoneB(dpa);
    dpb->Show();

    return 0; 
}
