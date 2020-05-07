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
    double FinalMasses[4] = {mK, mPi, mK, mPi};  // Daughters
    TGenPhaseSpace event;                        // Event generator
    event.SetDecay(P, 4, FinalMasses);    // Set how the decay will be

    // Daughters structure (just four TLorentzVectors)
    Daughters D;
    TLorentzVector Reconstructed;

    // Prepare the histograms
    TCanvas *c       = new TCanvas("", "", 800, 600);
    TH1D   *original = new TH1D("", "", 50, 4.9, 5.6);
    TH1D   *misID_1  = new TH1D("", "", 50, 4.9, 5.6);
    TH1D   *misID_2  = new TH1D("", "", 50, 4.9, 5.6);

    // Generate true decays
    for (unsigned int i = 0; i < NEvents; i++) {
        GenerateDecay(event, D, rand);
        Reconstructed = *(D.p1) + *(D.p2) + *(D.p3) + *(D.p4);
        original->Fill(Reconstructed.M());
    }

    // Generate misID decays (true: Pion; identified: Kaon)
    for (unsigned int k = 0; k < NEvents; k++) {
        GenerateDecay(event, D, rand);
        SetMisID(D, "Pion->Kaon");
        Reconstructed = *(D.p1) + *(D.p2) + *(D.p3) + *(D.p4);
        misID_1->Fill(Reconstructed.M());
    }

    // Generate misID decays (true: Kaon; identified: Pion)
    for (unsigned int l = 0; l < NEvents; l++) {
        GenerateDecay(event, D, rand);
        SetMisID(D, "Kaon->Pion");
        Reconstructed = *(D.p1) + *(D.p2) + *(D.p3) + *(D.p4);
        misID_2->Fill(Reconstructed.M());
    }

    c->cd();
    original->Draw("h");
    misID_1->Draw("h,same");
    misID_2->Draw("h,same");
    c->Print("./output.pdf");


    return 0;
}
