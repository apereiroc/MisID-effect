//
// Created by Asier Pereiro on 07/05/2020.
//

#include "../include/funs.h"


void GenerateDecay(TGenPhaseSpace& event, Daughters& D, TRandom3 *rand) {
    int j = 0;
    while (j < 1) {
        // Store the weight of the event
        const double w      = event.Generate();
        const double height = rand->Uniform(1.0/w);

        if (height < 1.0) { // We accept the event
            D.p1 = event.GetDecay(0);
            D.p2 = event.GetDecay(1);
            j++;
        }
    }
}

void SetMisID(Daughters& D, string misID) {
    if (misID_type == "Pion->Kaon") {
        D.p1->SetPtEtaPhiM( D.p1->Pt(), D.p1->Eta(), D.p1->Phi(), mK);
    }

    elif (misID_type == "Kaon->Pion") {
        
        D.p2->SetPtEtaPhiM( D.p2->Pt(), D.p2->Eta(), D.p2->Phi(), mPi);
    }

    else std::cout << "MisID not understood!" << std::endl;
    
}