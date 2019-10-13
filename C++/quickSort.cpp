#include<iostream>
using namespace std;
class sort
{
    int a[100],n;
public:
    int input()
    {
      cout<<"\nEnter length of array: ";
      cin>>n;
      cout<<"\nEnter Elements: ";
      for(int x=0;x<n;x++)
      {
        cin>>a[x];
      }
      return n;
    }

    void qsort(int p,int q){
         int j;
         if(p<q)
         {
             j = partition(p,q+1);
             qsort(p,j-1);
             qsort(j+1,q);
         }
    }
    int partition(int m,int r)
    {
        int i=m,j=r;
        float piot = a[m];
        do{
            do{
                i++;
            }while(a[i]<piot);
            do{
                j--;
            }while(a[j]>piot);
            if(i<j)
                swap(i,j);
        }while(i<j);
        swap(m,j);
        return j;

        }
    void swap(int h,int g)
    {
        float temp = a[h];
        a[h] = a[g];
        a[g] = temp;
    }
    void display()
    {
        cout<<"\nthe o/p is";
        for(int u=0;u<n;u++)
        {
            cout<<a[u]<<"  ";
        }
    }
};
int main()
{
    sort obj;
    int c;
    c=obj.input();
    obj.qsort(0,c-1);
    obj.display();
    return 0;
}
