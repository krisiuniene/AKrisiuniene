#include <iostream>
#include <stdlib.h>
template <class T> void exch(T &, T &, int&);
template <class T> void compexch(T &, T &, int&);
template <class T> void selection(T *, int, int, int&, int&);
template <class T> void insertion(T *, int, int, int&, int&);
template <class T> void bubble(T *, int, int, int&, int&);
using namespace std;
int main(int argc, char *argv[])
{
    int i, kiekS, kiekL, N = 50; 
    int *a = new int[N];
    srand ( time(NULL) );
   cout<< "Isrinkimo algoritmas:"<<endl; 
    cout<< "_____Atsitiktine seka_____"<<endl; 
    for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    kiekS = 0;
    kiekL = 0;
    cout<< "Isrinkimo kiekL = "<<kiekL<<endl;
    selection(a, 0, N-1, kiekS, kiekL);
    cout<< "--------------------------------------"<<endl; 
   //  for (i = 0; i < N; i++) cout << a[i] << " ";
    
    cout<< "--------------------------------------"<<endl; 
   /* 
    cout<< " Iterpimo algoritmas:"<<endl; 
    cout<< endl; 
    //_____Atsitiktine seka_____
    cout<< "_____Atsitiktine seka_____"<<endl; 
    for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    kiekS = 0;
    kiekL = 0;
    insertion(a, 0, N-1, kiekS, kiekL);
    cout<< "--------------------------------------"<<endl; 
    */
    cout<< " Burbuliuko algoritmas:"<<endl; 
    cout<< endl; 
    //_____Atsitiktine seka_____
    cout<< "_____Atsitiktine seka_____"<<endl; 
    for (i = 0; i < N; i++)
        a[i] = 1000*(1.0*rand()/RAND_MAX);
    cout << "Ivestas skaiciu masyvas yra:" << endl;
    for (i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    kiekS = 0;
    kiekL = 0;
    bubble(a, 0, N-1, kiekS, kiekL);
    cout<< "--------------------------------------"<<endl; 
       
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
// Isrinkimo algoritmo realizacija
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
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    // for (i = l; i < r; i++) cout << a[i] << " ";
     cout<<endl;
     cout<<"Sukeitimu skaicius: "<<kiekS<<endl;
     cout<<"Lyginimu skaicius: "<<kiekL<<endl; 
  }
// Iterpimo algoritmo realizacija
template <class T>
void insertion(T a[], int l, int r,int &kiekS, int &kiekL)
  { int i;
    for (i = r; i > l; i--) compexch(a[i-1], a[i], kiekS);
    for (i = l+2; i <= r; i++)
      { int j = i; T v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--; kiekL++;}
        a[j] = v;
        kiekL++;
      }
      cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    // for (i = l; i < r; i++) cout << a[i] << " ";
     cout<<endl;
     cout<<"Sukeitimu skaicius: "<<kiekS<<endl;
     cout<<"Lyginimu skaicius: "<<kiekL<<endl;
  }
// Burbulo algoritmas
template <class T>
void bubble(T a[], int l, int r,int &kiekS, int &kiekL)
  { for (int i = l; i < r; i++)
      for (int j = r; j > i; j--)
        {
        compexch(a[j-1], a[j], kiekS);
        kiekL++; 
        }
    cout << "Surusiuotas skaiciu masyvas yra:" << endl;
    // for (i = l; i < r; i++) cout << a[i] << " ";
    cout<<endl;
    cout<<"Sukeitimu skaicius: "<<kiekS<<endl;
    cout<<"Lyginimu skaicius: "<<kiekL<<endl;
  }

