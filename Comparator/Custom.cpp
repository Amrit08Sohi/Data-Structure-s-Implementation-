#include<bits/stdc++.h>
using namespace std;
class Interval
{
    public:
        int start,end;
};

// Compare intervals based on starting time
bool compareIntervals(Interval i1,Interval i2) {
    return (i1.start < i2.start);
}


int main()
{   
    Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr,arr+n,compareIntervals);

    cout << "Intervals sorted by start time" << endl;
    for(int i = 0; i < n; i++) {
        cout << '[' << arr[i].start << "," << arr[i].end << ']' << endl;
    }


    return 0;
}