# 🧠 Modeling Signal Mixing Effects in Neurons using NEURON Simulator

This repository contains code for modelling **signal mixing and heterodyning effects in myelinated neurons** using the **NEURON simulator** and **MATLAB**.

The central idea of this project is that a biologically realistic neuron may behave, under certain stimulation conditions, like a **non-linear electrical mixer**. When endogenous and exogenous alternating-current stimulation signals interact with the non-linear membrane dynamics of a neuron, new frequency components may appear in the voltage response.

The workflow combines:

- 🧠 **NEURON simulation** of a myelinated axon.
- ⚡ **Endogenous and exogenous AC stimulation**.
- 📈 **Voltage trace recording** from neuronal compartments.
- 📂 Exported simulation data as `.dat` files.
- 🧮 **MATLAB signal processing** using IQ demodulation, envelope extraction, cross-correlation, RMS analysis, and FFT.

---

## 📌 Project Aim

The purpose of this project is to investigate whether a myelinated neuron can produce **mixed-frequency components** when stimulated by two electrical signals.

In electronic circuits, this behaviour is known as **heterodyning** or **frequency mixing**. This project explores whether a similar concept can occur in a biological neuron because of the non-linear behaviour of voltage-gated ion channels.

---

## 🧠 What is a Neuron?

A **neuron** is an electrically active biological cell that receives, processes, and transmits information through changes in membrane voltage.

A simplified neuron contains:

- **Dendrites** — receive incoming signals.
- **Soma** — cell body where signals are integrated.
- **Axon hillock** — trigger region where action potentials are initiated.
- **Axon** — long cable-like structure that transmits action potentials.
- **Nodes of Ranvier** — exposed gaps in myelinated axons where ion exchange is concentrated.
- **Myelin sheath** — insulating layer that increases conduction speed.

From a circuit point of view, a neuron can be interpreted as an **active non-linear cable**. The membrane behaves like a capacitor, ion channels behave like voltage-dependent conductances, and the intra/extracellular media behave like resistive pathways.

---

## ⚙️ Circuit-Theory View of a Neuron

The neuronal membrane can be represented using an equivalent circuit containing:

- 🧱 A **membrane capacitance** $C_m$
- 🔋 Ionic reversal potentials $E_{Na}$, $E_K$, and $E_L$
- 🔌 Voltage-dependent conductances $g_{Na}$ and $g_K$
- 🧯 Leakage conductance $g_L$
- 🧵 Axial resistance along the axon
- 🌍 Extracellular resistance and capacitance paths

A simplified membrane-current equation is:

$$
C_m \frac{dV_m}{dt}
=
-I_{ion}
+
I_{stim}
$$

where:

- $V_m$ is the membrane voltage.
- $C_m$ is the membrane capacitance.
- $I_{ion}$ is the total ionic current.
- $I_{stim}$ is the applied stimulation current or field.

The total ionic current can be written as:

$$
I_{ion}
=
I_{Na}
+
I_K
+
I_L
$$

For Hodgkin-Huxley-style dynamics:

$$
I_{Na}
=
g_{Na}m^3h(V_m - E_{Na})
$$

$$
I_K
=
g_Kn^4(V_m - E_K)
$$

$$
I_L
=
g_L(V_m - E_L)
$$

Therefore:

$$
I_{ion}
=
g_{Na}m^3h(V_m - E_{Na})
+
g_Kn^4(V_m - E_K)
+
g_L(V_m - E_L)
$$

The important point is that the sodium and potassium currents are **non-linear**, because the gating variables $m$, $h$, and $n$ depend on voltage and appear with powers such as $m^3h$ and $n^4$.

---

## 🧩 The Axon Hillock and Non-Linearity

The **axon hillock** is the region where the soma connects to the axon. It is important because it acts as the decision point for action-potential initiation.

It is highly non-linear because it contains dense voltage-gated ion channels. Small changes in voltage can cause large changes in sodium and potassium conductance.

This makes the axon hillock similar, in an abstract circuit sense, to a **non-linear electronic device** such as a diode, transistor, or mixer.

A general non-linear current-voltage relationship can be expanded as:

$$
I(V)
=
a_1V
+
a_2V^2
+
a_3V^3
+
\cdots
$$

If the input voltage contains two sinusoidal components:

$$
V(t)
=
A_1\cos(2\pi f_1t)
+
A_2\cos(2\pi f_2t)
$$

then the squared term in the non-linear system becomes:

$$
V^2(t)
=
\left[
A_1\cos(2\pi f_1t)
+
A_2\cos(2\pi f_2t)
\right]^2
$$

Expanding this gives a cross-product term:

$$
2A_1A_2
\cos(2\pi f_1t)
\cos(2\pi f_2t)
$$

Using the trigonometric identity:

$$
\cos(a)\cos(b)
=
\frac{1}{2}
\left[
\cos(a-b)
+
\cos(a+b)
\right]
$$

the cross-product becomes:

$$
A_1A_2
\left[
\cos(2\pi(f_1-f_2)t)
+
\cos(2\pi(f_1+f_2)t)
\right]
$$

This shows that a non-linear system can generate two new frequencies:

$$
f_{difference}
=
|f_1-f_2|
$$

$$
f_{sum}
=
f_1+f_2
$$

This is the theoretical basis for investigating **heterodyning in neurons**.

---

## 📡 What is Heterodyning?

**Heterodyning** is the process where two signals of different frequencies are mixed inside a non-linear system to generate new frequency components.

If the two input frequencies are:

$$
f_1
\quad \text{and} \quad
f_2
$$

then a non-linear mixer can produce:

$$
f_1 + f_2
$$

and

$$
|f_1 - f_2|
$$

This principle is widely used in telecommunications, radio receivers, modulation systems, and signal-processing circuits.

For example, if:

$$
f_1 = 5000 \text{ Hz}
$$

and:

$$
f_2 = 5003 \text{ Hz}
$$

then the difference frequency is:

$$
|5003 - 5000| = 3 \text{ Hz}
$$

This means two high-frequency signals can interact through a non-linear system and produce a low-frequency envelope or difference component.

In this project, the hypothesis is that the non-linear ion-channel dynamics of the neuron may allow similar frequency mixing to occur.

---

## 🧪 Biological Analogy — Neuron as a Mixer

An electronic mixer uses a non-linear device to combine signals.

This project uses the same idea, but replaces the electronic non-linearity with biological membrane non-linearity.

| Electronic Mixer | Neuronal Analogy |
|---|---|
| Transistor or diode | Voltage-gated ion channels |
| Input RF signal | Exogenous AC stimulation |
| Local oscillator | Endogenous/synaptic activity |
| Non-linear I-V curve | Non-linear membrane dynamics |
| Sum and difference frequencies | Mixed components in membrane voltage |
| Demodulated output | Recovered low-frequency neural signal |

The key idea is:

> If a neuron is stimulated by two electrical signals, and the neuron contains non-linear voltage-dependent dynamics, then the output membrane voltage may contain new frequency components that were not directly applied.

---

## 📷 Figures

### 🧠 Neuron Signal Mixing Model Diagram

<div align="center">
  <img src="https://github.com/user-attachments/assets/3fe820ef-4581-46d6-947a-671e52393870">
</div>

This diagram illustrates the biological signal-mixing idea. A neuron receives endogenous and exogenous electrical stimulation, and the resulting membrane voltage is analysed for mixed-frequency behaviour.

---

### ⚡ Electronic Circuit Representation of a Neuron

<div align="center">
  <img src="https://github.com/user-attachments/assets/26c28683-59fb-49e2-8f4b-3da9f7938f92" width="590" alt="Neuron circuit representation">
</div>

This circuit-style view shows why the neuron can be interpreted using electrical engineering concepts. The membrane capacitance, ionic conductances, axial resistance, and extracellular pathway together form a distributed non-linear electrical system.

---

## 🧪 Model Objective

The NEURON model is used to:

- Build a biologically realistic **myelinated axon**.
- Apply endogenous and exogenous stimulation signals.
- Inject sinusoidal electrical stimulation through intracellular and extracellular pathways.
- Observe the resulting membrane voltage.
- Export voltage traces for MATLAB analysis.
- Use IQ demodulation, envelope extraction, correlation, RMS, and FFT to identify possible mixed-frequency components.

---

## 🛠️ Requirements

### Software

- **NEURON Simulator**
- **MATLAB**
- A terminal or command prompt
- Git, optional but recommended

### NEURON mechanisms

This repository includes `.mod` mechanism files. These may need to be compiled before running the simulations.

Typical NEURON compilation commands:

```bash
nrnivmodl
