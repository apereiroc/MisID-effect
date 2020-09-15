//
// Created by Asier Pereiro on 07/05/2020.
//

#include "../include/funs.h"
#include <iostream>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>

const double mPi = 0.139571, mK = 0.493677;


void GenerateDecay(TGenPhaseSpace& event, Daughters& D, TRandom3 *rand) {
    int j = 0;
    while (j < 1) {
        // Store the weight of the event
        const double w      = event.Generate();
        const double height = rand->Uniform(1.0/w);

        if (height < 1.0) { // We accept the event
            D.p1 = event.GetDecay(0);
            D.p2 = event.GetDecay(1);
            D.p3 = event.GetDecay(2);
            D.p4 = event.GetDecay(3);
            j++;
        }
    }
}

void SetMisID(Daughters& D, std::string misID) {
    if (misID == "Kaon->Pion") {
        D.p1->SetPtEtaPhiM( D.p1->Pt(), D.p1->Eta(), D.p1->Phi(), mPi);
    }

    else if (misID == "Pion->Kaon") {
        D.p2->SetPtEtaPhiM( D.p2->Pt(), D.p2->Eta(), D.p2->Phi(), mK);
    }

    else std::cout << "MisID not understood!" << std::endl;

}

void PlotDistributions(TH1D* original, TH1D* misID_1, TH1D* misID_2) {

    // Create canvas
    TCanvas *c = new TCanvas("", "", 800, 600);

    // Create legend and add entries
    auto leg = new TLegend(0.13,0.6,0.53,0.8);
    leg->SetFillColor(kWhite);
    leg->SetLineColor(kWhite);
    leg->AddEntry(original, "Original distribution", "pe");
    leg->AddEntry(misID_1, "Pion->Kaon", "pe");
    leg->AddEntry(misID_2, "Kaon->Pion", "pe");

    // Draw the original distribution
    original->SetLineColor(kGreen);
    original->Draw("h");

    // Draw the first misID
    misID_1->SetLineColor(kRed);
    misID_1->Draw("h,same");

    // Draw the second misID
    misID_2->SetLineColor(kBlue);
    misID_2->Draw("h,same");

    // Draw the legend
    leg->Draw("same");

    // Save canvas
    c->Print("./output.pdf");
}