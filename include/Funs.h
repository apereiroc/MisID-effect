//
// Created by Asier Pereiro on 07/05/2020.
//

#ifndef SIMULATION_FUNS_H
#define SIMULATION_FUNS_H

#include <string>
#include <TLorentzVector.h>
#include <TRandom3.h>
#include <TGenPhaseSpace.h>


struct Daughters {
    TLorentzVector *p1 = new TLorentzVector();
    TLorentzVector *p2 = new TLorentzVector();
    TLorentzVector *p3 = new TLorentzVector();
    TLorentzVector *p4 = new TLorentzVector();
};

void GenerateDecay(TGenPhaseSpace& event, Daughters& D, TRandom3 *rand);

void SetMisID(Daughters& D, std::string misID);

#endif //SIMULATION_FUNS_H
