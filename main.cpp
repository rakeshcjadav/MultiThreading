#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

/* Multi threading
// Print Odd and Even number using two threads and semaphors
pthread_t odd, even;
sem_t sOdd, sEven;

int g_Counter = 0;

int idOddThread = 10, idEvenThread = 11;
bool g_bContinue = true;
void *OddFucntion(void *params)
{
    bool *bContinue = (bool *)params;
    while (bContinue)
    {
        // sleep(1);
        sem_wait(&sOdd);
        g_Counter++;
        cout << "Thread Odd : " << g_Counter << endl;
        sem_post(&sEven);
    }
    //cout<<"Thread : "<<*bContinue<<endl;
}

void *EvenFunction(void *params)
{
    bool *bContinue = (bool *)params;
    while (bContinue)
    {
        //sleep(1);
        sem_wait(&sEven);
        g_Counter++;
        cout << "Thread Even : " << g_Counter << endl;
        sem_post(&sOdd);
    }
    //cout<<"Thread : "<<*bContinue<<endl;
}

void MultiThreading()
{
    sem_init(&sOdd, 0, 1);
    sem_init(&sEven, 0, 0);

    pthread_create(&odd, nullptr, OddFucntion, &g_bContinue);
    pthread_create(&even, nullptr, EvenFunction, &g_bContinue);

    while (g_bContinue)
    {
        char c = getchar();
        switch (c)
        {
        case 'q':
            g_bContinue = false;
            break;
        }
    }
    pthread_join(odd, nullptr);
    pthread_join(even, nullptr);
}
*/

class CPerson
{
public:
    CPerson(std::string _name);
    CPerson(const CPerson & person);
    void operator=(const CPerson & person);
    void Dispay();
    bool operator<(const CPerson & rhs);
    bool operator>(const CPerson & rhs);

private:
    std::string m_strName;
};

CPerson::CPerson(std::string _name)
{
    m_strName = _name;
}

// Copy Constructor
CPerson::CPerson(const CPerson & person)
{
    this->m_strName = person.m_strName;
}

// Assignment operator
void CPerson::operator=(const CPerson & person)
{
    this->m_strName = person.m_strName;
}

void CPerson::Dispay()
{
    cout<<"Name : "<<m_strName<<endl;
}

// Less than operator
bool CPerson::operator<(const CPerson & rhs)
{
    return this->m_strName.length() < rhs.m_strName.length();
}

// Greter than operator
bool CPerson::operator>(const CPerson & rhs)
{
    return this->m_strName.length() > rhs.m_strName.length();
}

class CNumber
{
public:
    CNumber(int _n, float _f)
    {
        m_nNumber = _n;
        m_fNumber = _f;
    }

    CNumber(const CNumber & _n)
    {
        this->m_nNumber = _n.m_nNumber;
        this->m_fNumber = _n.m_fNumber;
    }

    void operator=(const CNumber & _n)
    {
        this->m_nNumber = _n.m_nNumber;
        this->m_fNumber = _n.m_fNumber;
    }

    CNumber operator-()
    {
        return CNumber(-m_nNumber, -m_fNumber);
    }

    void operator-=(const CNumber & _n)
    {
        this->m_nNumber -= _n.m_nNumber;
        this->m_fNumber -= _n.m_fNumber;
    }

    CNumber operator-(const CNumber & _n)
    {
        return CNumber(this->m_nNumber - _n.m_nNumber, this->m_fNumber - _n.m_fNumber);
    }

    friend std::ostream &  operator<<(std::ostream & out, const CNumber & _n)
    {
        out<<"Int : "<<_n.m_nNumber<<" Float : "<<_n.m_fNumber<<endl;
        return out;
    }

    friend std::istream & operator>>(std::istream & in, CNumber & _n)
    {
        in>>_n.m_nNumber>>_n.m_fNumber;
        return in;
    }

    CNumber operator()(const CNumber & _n)
    {
        return CNumber(this->m_nNumber + _n.m_nNumber + 1, this->m_fNumber + _n.m_fNumber + 1.0f);
    }

    void Dispay()
    {
        cout<<"Int : "<<m_nNumber<<" Float : "<<m_fNumber<<endl;
    }

private:
    int m_nNumber;
    float m_fNumber;
};

int main()
{
    CNumber m(2, 4.53f);
    CNumber n(5, 7.02f);
    CNumber a(0, 0.0f);
    
    //m.Dispay();
    //n.Dispay();
    //a.Dispay();
    
    //cin >> m;
    a = m - n;
    cout <<"m : "<< m <<"n : "<< n <<"a : "<< a;

    CNumber b = m(n(a));
    cout<<"b : "<<b;
   // getchar();
    return 0;
}