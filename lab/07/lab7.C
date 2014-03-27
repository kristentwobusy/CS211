#include <iostream>
using namespace std;

#include "tenureTrackProf.h"
#include "adjunctProf.h"

int main()
{
    cout << "AdjunctProf: \n";
    AdjunctProf AP("Adam Smith","asmith@csusm.edu",12345,'M',2,1);
    AP.print();
    AP.findSalary();

    cout << "TenureTrackProf: \n";
    TenureTrackProf TP("Jim Anderson","janderson@csusm.edu",54321,'S',8);
    TP.print();
    TP.findSalary();

    return 0;
}
