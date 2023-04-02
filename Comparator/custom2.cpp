#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
        int rollno;
        string name;

        Student(int r,string n) {
            rollno = r;
            name = n;
        } 
};
class Comparator{
    public:
        bool operator()(Student s1,Student s2) {
        return s1.rollno > s2.rollno; 
    }
};    

int main()
{
    Student s[] = {{100,"Aman"},{50,"Ajay"},{60,"ankit"}};
    int n = sizeof(s)/sizeof(s[0]);
    priority_queue<Student,vector<Student>,Comparator> pq;
    // sort(s,s+n,compare);

    for(int i = 0; i < n ; i++ ) {
        pq.push(s[i]);
    }

    for(int i =0 ;i < n; i++) {
        Student s = pq.top();
        pq.pop();
        cout << s.name << " , " << s.rollno << endl;
    }

    return 0;
}