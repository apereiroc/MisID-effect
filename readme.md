
# MisID simulator
This little program is intended to visualize the degradation on the reconstructed invariant mass 
when your detector misidentifies a particle.

In the example it's generated the decay `Bs -> K+ Pi^- K- Pi^+`: firstly true generation, then the first 
Kaon is misidentified as a Pion and then the second Pion is misidentified as a Kaon. These three situations 
occurs independently. Finally, the three histograms are plotted on the same canvas.

You will need CMake and ROOT.


Instructions for building:
- Go to the directory
- run `cmake .` on your terminal
- run `make`
- run `./simulation`

and a PDF named "output.pdf" will be produced at the same directory.
