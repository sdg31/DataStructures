#include"hash.hpp"
#include "Complexity_Timer.hpp"
#include "Complexity_Recorder.hpp"
#include <stdlib.h>
#include <time.h>
using namespace std;



void ranarray(int size,int *randomArray)//creats a random array
{
    for (int i=0; i<size; i++)
    {
        randomArray[i]=(rand() % 100000+1);//fills array with random numbers 1-1000
    }

}



timer timer1;

int main()
{
    int size=38;
    int numInserts = 30;
    HashTable<int> myHash(size);

    int randomArray[size]={0};
    ranarray(size,randomArray);
    int oldprobes=0;
    int oldsamehash=0;
    cout<<"hash table size = " << size<<'\n';
    cout<<"Elements inserted  = " << numInserts<<'\n';
    for(int i=0;i<numInserts;++i)
    {
       myHash.insert(randomArray[i],i);
       cout<<"insert #"<<i;
       cout<<" value ="<<randomArray[i];
       cout<<" probes="<<myHash.totalprobes-oldprobes;
       cout<<" samehash="<<myHash.samehash-oldsamehash<<'\n';
       oldprobes = myHash.totalprobes;
       oldsamehash = myHash.samehash;
    }

    cout<<"Elements inserted  = " << numInserts<<'\n';
    cout<<"Total Number of Initial Collisions  = " << myHash.initialcollisions<<'\n';
    cout<<"Total Number of Probes  = " << myHash.totalprobes<<'\n';
    cout<<"Total Number of Collisions caused by same intial hash="<<myHash.samehash<<'\n';

    myHash.print();
    //for(int i=0;i<2000;++i)
       //myHash.erase(randomArray[i]);

    //for(int i=0;i<2000;++i)
       //myHash.insert(randomArray[i]*5,i);


//    for(int i=0;i<20;++i)
//       cout<<myHash[randomArray[i]*5]<<'\n';

}//end
