# Thesis

### Modeling Heterodyning Effects in Neurons using NEURON Simulator

This code demonstrates how to construct a **myelinated neuron model** in **NEURON** that is stimulated by **alternating current (AC)** sources through both the **extracellular** and **intracellular** media.

---

### 🧠 Concept Overview

**Heterodyning** is a process in which two signals of different frequencies are fed into a **non-linear electrical component**, resulting in the generation of new frequencies — specifically, the **sum** and **difference** of the original frequencies.

If two input frequencies are:

- \( f_1 \)
- \( f_2 \)

Then, the resulting frequencies after heterodyning are:

- **Sum frequency:** \( f_1 + f_2 \)
- **Difference frequency:** \( |f_1 - f_2| \)

This principle is fundamental in **telecommunications**, where it enables frequency translation and allows communication using **smaller antennas**.

---

### ⚙️ The Mixer and Non-Linearity

A **mixer** is a non-linear circuit component that combines two input signals. Its current–voltage (I–V) relationship is **non-linear**, typically involving conductance that varies with voltage.

A common implementation is the **Gilbert Cell Mixer**:

🔗 [A Gilbert Cell Mixer with a Digitally Controlled Performance Space (ResearchGate)](https://www.researchgate.net/publication/228977791_A_Gilbert_cell_mixer_with_a_digitally_controlled_performance_space)

---

### 🧩 Biological Analogy — The Axon Hillock

Interestingly, the **axon hillock** in neurons is also **non-linear**, and its ionic current can be expressed as:

\[
I_t = g_{Na,\text{init}} \, m^3 h (V - E_{Na}) \;+\; g_{K,\text{init}} \, n^4 (V - E_{K}) \;+\; g_{L,\text{init}} (V - E_{L})
\]

This suggests that if two different electrical signals are applied to a neuron, **heterodyning** could theoretically occur — leading to **frequency mixing** in biological systems.

---

### 🧪 Model Objective

To test this hypothesis, the NEURON model:

- Simulates a **myelinated axon**.
- Applies **two AC signals** via intracellular and extracellular stimulation.
- Observes whether **heterodyned frequency components** appear in the resulting membrane potential.

---

### 📷 Figure

<div align="center">
  <img src="https://github.com/user-attachments/assets/139307e5-e0e9-41fb-8343-7644806e2f3d" width="350" alt="Neuron heterodyning model diagram">
</div>

---

### 💻 Implementation Notes

The NEURON simulation uses:

- Hodgkin–Huxley style ion channel equations.  
- Custom extracellular field stimulation.  
- FFT analysis to detect mixed-frequency components.

---

*This section bridges neuroscience and communication theory — exploring how a biological non-linearity can exhibit an effect fundamental to signal processing.*
