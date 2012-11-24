#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &, int&);
template <class T> void compexch(T &, T &, int&);
template <class T> void selection(T *, int, int, int&, int&);
template <class T> void insertion(T *, int, int);
template <class T> void bubble(T *, int, int);
using namespace std;
int main(int argc, char *argv[])
{
    int i, N = 1000; 
    int kiekS = 0;
    int kiekL = 0;
    //N = atoi(argv[1]), KaDaryt = atoi(argv[2]);
    int *a = new int[N];
    /*if (KaDaryt) // Atsitiktinai sugeneruoja N skaičių intervale: 1,...,1000.*/
     srand ( time(NULL) );
     for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
   /* else // Savo nuožiūra įvedame skaičius. Norėdami baigti įvedimą, įvedame bet kokį simbolį - ne skaičių.
      { N = 0; while (cin >> a[N]) N++; }*/
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    selection(a, 0, N-1, kiekS, kiekL);
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout<<endl;
    cout<<"Sukeitimu skaicius: "<<kiekS<<endl;
    cout<<"Lyginimu skaicius: "<<kiekL<<endl;
       
    system("PAUSE");
    
}
// Sukeicia elementus vietomis
template <class T>
  void exch(T &A, T &B, int &kiekS)
    { T t = A ; A = B; B = t; kiekS++;} //kiekS padidinama vienetu
// Sukeicia elementus vietomis tik jei patenkinta salyga
template <class T>
  void compexch(T &A, T &B, int &kiekS)
    { if (B < A) exch(A, B, kiekS); }
// I�?rinkimo algoritmo realizacija
template <class T>
void selection(T a[], int l, int r, int &kiekS, int &kiekL)
  { for (int i = l; i < r; i++)
      { int min = i;
        for (int j = i+1; j <= r; j++)
        {
            if (a[j] < a[min])  min = j;
            kiekL++;// kiekL padydinama vienetu         
        }
        exch(a[i], a[min], kiekS);
      }
  }
// Įterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i]);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; }
        a[j] = v;
      }
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        compexch(a[j-1], a[j]);
  }

