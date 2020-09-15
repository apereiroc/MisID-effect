
# MisID simulator
This little program is intended to show the effect on the reconstructed invariant mass 
when a detector misidentifies a particle.

In the example the decay `Bs -> K+ Pi^- K- Pi^+` is generated: first a true generation, then the first 
Kaon is misidentified as a Pion and finally the second Pion is misidentified as a Kaon. These three situations 
occurs independently. Finally, the three histograms are plotted on the same canvas.

You will need CMake and ROOT.


Instructions for building:
- Go to the directory
- run `cmake .` on your terminal
- run `make`
- run `./simulation`

and a PDF named "output.pdf" will be produced at the same directory.
