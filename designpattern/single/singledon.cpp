#include <iostream>
using namespace std;
 
class CSingleton
{
public:
    static CSingleton* getInstance();
    static void cleanInstance();
    int getValue();
    void setValue(int iValue);
private:
    int m_iValue;
    static CSingleton* m_pSingleton;
    CSingleton();
    ~CSingleton();
};
 
CSingleton* CSingleton::m_pSingleton = NULL;
 
CSingleton::CSingleton()
{
    cout << "Constructor" << endl;
}
 
CSingleton::~CSingleton()
{
    cout << "Destructor" << endl;
}
 
CSingleton* CSingleton::getInstance()
{
    if (NULL == m_pSingleton)
    {
        m_pSingleton = new CSingleton();
    }
    return m_pSingleton;
}
 
void CSingleton::cleanInstance()
{
    delete m_pSingleton;
}
 
int CSingleton::getValue()
{
    return m_iValue;
}
 
void CSingleton::setValue(int iValue)
{
    m_iValue = iValue;
}
 
int main()
{
    CSingleton* pSingleton1 = CSingleton::getInstance();
    CSingleton* pSingleton2 = CSingleton::getInstance();
    pSingleton1->setValue(123);
    if (pSingleton1->getValue() == pSingleton2->getValue())
    {
        cout << "Two objects is the same instance" << endl;
    }
    else
    {
        cout << "Two objects isn't the same instance" << endl;
    }
 
    CSingleton::cleanInstance();
    return 0;
}
