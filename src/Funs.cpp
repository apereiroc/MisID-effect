#include "Funs.h"

void GenerateDecay(TGenPhaseSpace& event, Daughters& D, TRandom3 *rand)
{
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

