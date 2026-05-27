# Thesis

## Modeling Signal Mixing Effects in Neurons using the NEURON Simulator

This repository contains code for modelling **signal mixing effects in myelinated neurons** using the **NEURON simulator**.

The project investigates whether a biologically realistic neuron model can behave similarly to a non-linear electronic mixer when stimulated by alternating-current electrical signals. The model applies endogenous and exogenous AC stimulation to a myelinated axon and analyses whether new frequency components appear in the membrane voltage response.

The workflow combines:

- **NEURON simulation** of a myelinated neuron.
- **AC stimulation** through intracellular and extracellular pathways.
- **Exported voltage traces** saved as `.dat` files.
- **MATLAB signal analysis** using IQ demodulation, envelope extraction, normalisation, cross-correlation, RMS analysis, and FFT.

---

## Concept Overview

### Signal mixing

**Signal mixing** is a process in which two signals of different frequencies interact through a **non-linear electrical system**, producing new frequency components. These new components commonly include the **sum** and **difference** of the original frequencies.

If the two input frequencies are \(f_1\) and \(f_2\), then signal mixing can produce:

\[
f_{\text{sum}} = f_1 + f_2
\]

\[
f_{\text{difference}} = |f_1 - f_2|
\]

This principle is widely used in communication systems, radio receivers, modulation circuits, and frequency translation systems.

In this project, the same idea is applied to a biological neuron model. The aim is to test whether a neuron, particularly around a non-linear region such as the axon hillock or spike initiation zone, can generate mixed-frequency components when stimulated by multiple sinusoidal electrical inputs.

---

## Neurons as Electrical Circuits

A neuron can be treated as an electrical circuit because its membrane separates charge across a thin insulating lipid layer. This creates a membrane capacitance, while ion channels act as voltage-dependent conductances.

The membrane voltage is defined as:

\[
V_m = V_{\text{inside}} - V_{\text{outside}}
\]

The capacitive current through the membrane is:

\[
I_C = C_m \frac{dV_m}{dt}
\]

The ionic current through a conductance \(g_i\) with reversal potential \(E_i\) is:

\[
I_i = g_i(V_m - E_i)
\]

A simplified membrane equation can therefore be written as:

\[
C_m \frac{dV_m}{dt}
=
-I_{\text{ion}} + I_{\text{stim}}
\]

where:

- \(C_m\) is the membrane capacitance.
- \(V_m\) is the membrane voltage.
- \(I_{\text{ion}}\) is the total ionic current.
- \(I_{\text{stim}}\) is the applied stimulation current.

In a passive membrane model, the ionic current can be approximated as a leak current:

\[
I_{\text{leak}} = g_L(V_m - E_L)
\]

This gives:

\[
C_m \frac{dV_m}{dt}
=
-g_L(V_m - E_L) + I_{\text{stim}}
\]

However, real neurons are non-linear because ion channel conductances depend on voltage and time. This non-linearity allows the neuron to potentially behave like a biological signal mixer.

---

## Axon Hillock and Non-Linearity

The **axon hillock** is the region where input signals from the soma and dendrites are integrated before action potential initiation. It contains a high density of voltage-gated sodium channels, making it strongly non-linear.

A simplified Hodgkin-Huxley-style sodium current can be written as:

\[
I_{\text{Na}}
=
\bar{g}_{\text{Na}} m^3 h (V_m - E_{\text{Na}})
\]

The potassium current can be written as:

\[
I_{\text{K}}
=
\bar{g}_{\text{K}} n^4 (V_m - E_{\text{K}})
\]

The leak current is:

\[
I_{\text{L}}
=
g_{\text{L}}(V_m - E_{\text{L}})
\]

The full membrane equation becomes:

\[
C_m \frac{dV_m}{dt}
=
-
\left(
I_{\text{Na}}
+
I_{\text{K}}
+
I_{\text{L}}
\right)
+
I_{\text{stim}}
\]

Substituting the ionic currents gives:

\[
C_m \frac{dV_m}{dt}
=
-
\left[
\bar{g}_{\text{Na}} m^3 h (V_m - E_{\text{Na}})
+
\bar{g}_{\text{K}} n^4 (V_m - E_{\text{K}})
+
g_{\text{L}}(V_m - E_{\text{L}})
\right]
+
I_{\text{stim}}
\]

The gating variables \(m\), \(h\), and \(n\) evolve according to voltage-dependent differential equations:

\[
\frac{dx}{dt}
=
\alpha_x(V_m)(1-x)
-
\beta_x(V_m)x
\]

where:

\[
x \in \{m,h,n\}
\]

Because these gating variables depend on \(V_m\), the neuron is not a linear resistor-capacitor circuit. This voltage-dependent behaviour is what can allow frequency components to interact and generate new frequencies.

---

## Input Signal Model

The stimulation signal can be represented as a sum of two sinusoidal inputs:

\[
x(t)
=
A_1 \cos(2\pi f_1 t)
+
A_2 \cos(2\pi f_2 t)
\]

where:

- \(A_1\) and \(A_2\) are the amplitudes of the two input signals.
- \(f_1\) and \(f_2\) are the two input frequencies.
- \(t\) is time.

If this signal passes through a non-linear system, the output may contain additional frequency components.

For example, if the system has a square-law non-linearity:

\[
y(t) = x^2(t)
\]

then:

\[
x^2(t)
=
\left[
A_1 \cos(2\pi f_1 t)
+
A_2 \cos(2\pi f_2 t)
\right]^2
\]

Expanding:

\[
x^2(t)
=
A_1^2 \cos^2(2\pi f_1 t)
+
A_2^2 \cos^2(2\pi f_2 t)
+
2A_1A_2
\cos(2\pi f_1 t)
\cos(2\pi f_2 t)
\]

Using the trigonometric identity:

\[
2\cos(a)\cos(b)
=
\cos(a+b)
+
\cos(a-b)
\]

the cross-term becomes:

\[
2A_1A_2
\cos(2\pi f_1 t)
\cos(2\pi f_2 t)
=
A_1A_2
\cos(2\pi(f_1+f_2)t)
+
A_1A_2
\cos(2\pi(f_1-f_2)t)
\]

Therefore, the non-linear system can generate:

\[
f_{\text{sum}} = f_1 + f_2
\]

\[
f_{\text{difference}} = |f_1 - f_2|
\]

This is the mathematical basis for the signal mixing analysis performed in this project.

---

## Purpose of the Project

The purpose of this project is to test whether a myelinated neuron model can produce signal mixing behaviour under AC stimulation.

The project aims to:

- Build a biologically realistic myelinated axon model in NEURON.
- Apply sinusoidal stimulation through both intracellular and extracellular pathways.
- Record membrane voltage responses across the neuron.
- Export simulation results for MATLAB analysis.
- Use FFT and IQ demodulation to detect frequency components.
- Compare demodulated waveform shapes using normalisation and cross-correlation.
- Investigate whether sum and difference frequencies appear in the neuronal response.

---

## Repository Structure

```text
Thesis/
│
├── README.md
│
├── neuron_simulation/
│   ├── axon_model.py
│   ├── stimulation.py
│   ├── run_simulation.py
│   └── output_data/
│       ├── voltage_trace.dat
│       ├── time.dat
│       └── stimulation_signal.dat
│
├── matlab_analysis/
│   ├── iq_demodulation.m
│   ├── fft_analysis.m
│   ├── correlation_analysis.m
│   ├── rms_analysis.m
│   └── plot_results.m
│
└── results/
    ├── figures/
    └── processed_data/
