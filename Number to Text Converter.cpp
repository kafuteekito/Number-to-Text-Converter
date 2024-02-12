#include <iostream>
#include <string>

using namespace std;

void printTens(int n, int sim, string tens[], string simple[], string &final)
{
    int te=n%100;
    int ten=te/10;

    //for numbers divided by 10 like 10,20,30 etc. 
    if(sim==0)
    {
        final.append(tens[ten-1]);
    }

    //for numbers >=100 if second number equals 0 like 101,102
    else if(ten==0)
    {
        final.append(simple[sim]);
    }

    //print tens 
    else
    {
        final.append(tens[ten-1]).append(" ").append(simple[sim]);
    }
}

void printHuns(int n, int sim, string tens[], string simple[], string &final)
{
    int hu=n%1000;
    int hun = hu/100;

    //if in hundred first number is 1
    if(hun==1)
    {
        final.append(tens[9]).append(" "); 
    }

    //if it is not 0 print number
    else if(hun!=0)
    {
        final.append(simple[hun]).append(" ").append(tens[9]).append(" ");
    }

    //if number <100 print it tens
    if(n%100!=0)
    {
        printTens(n, sim, tens, simple, final);
    }
}

void printThousands(int n, int sim, string tens[], string simple[], string &final)
{
    int th = n/1000;

    //print thousands
    final.append(simple[th]).append(" ").append(tens[10]).append(" ");

    //then print other numbers
    n=n%1000;
    printHuns(n, sim, tens, simple, final);
}

void printTenThousands(int n, int sim, string tens[], string simple[], string &final)
{
    int tth=n;

    //print ten thousands
    n=n/1000;
    sim=n%10;
    printTens(n, sim, tens, simple, final);
    final.append(" ").append(tens[10]).append(" ");

    //then print other numbers
    n=tth%1000;
    sim=n%10;
    printHuns(n, sim, tens, simple, final);        
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, cn=0;
    string simple[10] = {"нөл", "бир", "эки", "үч", "төрт", "беш", "алты", "жети", "сегиз", "тогуз"}; 
    string tens[11] = {"он", "жыйырма", "отуз", "кырк", "элүү", "алтымыш", "жетимиш", "сексен", "токсон", "жүз", "миң"}; 
    cin>>n;
    int sim=n%10;
    string final{};

    // function that count how many numbers are there in number
    int num=n;
    while(num!=0)
    {
        num/=10;
        cn++;
    }

    /// for 0
    if(n==0)
    {
        final.append(simple[0]);
    }

    // lower than 10
    else if(cn==1)
    {
        final.append(simple[n]);
    }
    
    // from 10 to 99
    else if(cn==2)
    {
        printTens(n, sim, tens, simple, final);
    }

    // from 100 to 999
    else if(cn==3)
    {
        printHuns(n, sim, tens, simple, final);
    }

    // from 1000 to 9999
    else if(cn==4)
    {
        printThousands(n, sim, tens, simple, final);
    }
    
    //from 10000 to 99999
    else if(cn==5)
    {
        printTenThousands(n, sim, tens, simple, final);
    }
    
    cout<<final;
}