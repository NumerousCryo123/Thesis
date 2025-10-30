# Thesis
/*Code showing how to construct a model that can prove heterodyning effect in neurons- Using NEURON 
This code constructs a model of a myelinated neuron that is stimulated by alternating current sources through the extracellular medium and intracellular medium.
Heterodyning is a process, where two signals of different frequency are fed into a non-linear electrical component, that can lead to the concept of heterodyning.
So,if you have a signal of frequency f2 and another of frequency f1, they will be mixed to get a difference frequency abs(f1-f2) and sum frequencies f1+f2.
This is a vital component in telecommunication electronics and allows people to communicate with smaller antennas.
The main component is the mixer which is non-linear. It usually relates current to voltage and conductance with non-linear relation..
A transistor is one example of mixer. Here is a link to this : https://www.researchgate.net/publication/228977791_A_Gilbert_cell_mixer_with_a_digitally_controlled_performance_space
\nNext, consider the fact, that the axon-hillock is a non-linear component too:It = gNa_init*m^3*h*(V - ENa) + gK_init*n^4*(V - EK) + gL_init*(V - EL)
It follows that if I have two different electrical signals, then perhaps there might be heterodyning!
*/
<img width="270" height="148" alt="image" src="https://github.com/user-attachments/assets/139307e5-e0e9-41fb-8343-7644806e2f3d" />
