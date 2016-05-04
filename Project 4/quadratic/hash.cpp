#include "hash.hpp"
//quadratic_probing_insert(int *hashtable);
/*
void quadratic_probing_insert(int *hashtable, int size, int *randomArray)
{
    for (int i=0; i<size; i++)
    {
        int hash=randomArray[i] % size;//gets original hashing position
        int j=0;
        while (hashtable[hash]!=0)//if space to hash to is not empty, probe
            {
                hash=(randomArray[i]+(j*j))%size;//quadradic probing alrogithm.
                j++;
            }
        hashtable[hash]=randomArray[i];//put element in hash position
    }
}

void quadratic_probing_deletion(int *hashtable, int size,int *randomArray)
{
    for (int i=0; i<size; i++)
    {
        int j=0;
        int hash=randomArray[i] % size;//initial hashing position
        while (hashtable[hash]!=randomArray[i])//if hashing space does not contain the element, probe
        {
            hash=((randomArray[i]%size)+(j*j)%size);//quadradic probing algorithm
            j++;
        }
        hashtable[hash]=0;
    }
}
*/
