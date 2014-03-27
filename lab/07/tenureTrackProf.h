#ifndef tenureTrackProf_h
#define tenureTrackProf_h

#include "compSciProf.h"

class TenureTrackProf: public CompSciProf
{
 protected:
    char rank; //A = Assistant, S = Associate, F = Full
    int yearOfExp;
 public:
    TenureTrackProf();
    ~TenureTrackProf();
    TenureTrackProf(string n, string e, long id, char r, int y);
    char getRank(){return rank;};
    void setRank(char r){rank = r;};
    int getExp(){return yearOfExp;};
    void setRank(int y){yearOfExp = y;};
    float findSalary() const;
    void print() const;
};
#endif
