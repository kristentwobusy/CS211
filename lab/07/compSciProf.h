#ifndef compSciProf_h
#define compSciProf_h

#include <string>
using namespace std;

class CompSciProf
{
 protected:
  string name;
  string email;
  long facultyId;
 
 public:
 CompSciProf(); //default
 ~CompSciProf(); //desructor
 CompSciProf(string n, string e, long id); //constructor
 void getName(string n){n=name;};
 void setName(string n){name=n;};
 void getEmail(string e){e=email;};
 void setEmail(string e){email=e;};
 void getId(long id){id=facultyId;};
 void setId(long id){facultyId=id;};
};

#endif
