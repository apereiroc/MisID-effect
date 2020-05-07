#include <iostream>
#include "../include/funs.h"
#include <TLorentzVector.h>
#include <TRandom3.h>
#include <TGenPhaseSpace.h>
#include <TH1D.h>
#include <TCanvas.h>

int main() {
    // Set up the initial variables and constants
    const double mB = 5.27964, mPi = 0.139571, mK = 0.493677;
    TRandom3 *rand = new TRandom3(42);
    const int NEvents = 10000;

    // Phase space generation
    TLorentzVector P(0, 0, 0, mB);      // Mother
    double FinalMasses[2] = {mPi, mPi}; // Daughters
    TGenPhaseSpace event;               // Event generator
    event.SetDecay(P, 2, FinalMasses);  // Set how the decay will be

    // Daughters structure (just two TLorentzVectors)
    Daughters D;
    TLorentzVector diPion;

    // Prepare the plots
    TCanvas *c = new TCanvas("", "", 800, 600);
    TH1D   *h1 = new TH1D("", "", 50, 5.2, 5.8);
    TH1D   *h2 = new TH1D("", "", 50, 5.2, 5.8);

    // Generate true decays
    for (unsigned int i = 0; i < NEvents; i++) {
        GenerateDecay(event, D, rand);
        diPion = *(D.p1) + *(D.p2);
        h1->Fill(diPion.M());
    }

    // Generate misID decays
    for (unsigned int k = 0; k < NEvents; k++) {
        GenerateDecay(event, D, rand);
        SetMisID(D);
        diPion = *(D.p1) + *(D.p2);
        h2->Fill(diPion.M());
    }

    c->cd();
    h1->Draw("h");
    h2->Draw("h,same");
    c->Print("./output.pdf");


    return 0;
}
