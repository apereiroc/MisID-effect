#ifndef Funs_H
#define Funs_H


struct Daughters
{
    TLorentzVector *p1;
    TLorentzVector *p2;
}

void GenerateDecay(TGenPhaseSpace& event, Daughters& D);

#endif
