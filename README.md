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
---

## 📷 Figures

**Neuron Heterodyning Model Diagram**  

<div align="center">
  <img src="https://github.com/user-attachments/assets/3fe820ef-4581-46d6-947a-671e52393870" >

</div>

**Electronic Circuit Representation of Neuron**  

<div align="center">
  <img src="https://github.com/user-attachments/assets/26c28683-59fb-49e2-8f4b-3da9f7938f92" width="590" alt="Neuron circuit representation">
</div>

---

## 💻 Implementation Notes

The neuron can be represented as an **electro-chemical integrate-and-fire cell**, analogous to an electronic RC circuit.  

**Files and their purposes:**

| File            | Purpose |
|-----------------|---------|
| `axon10.hoc`   | Constructs a model of a myelinated neuron and axon in the CNS. The model includes a synapse from where one can put in intracellular stimulus. Further it uses Double-Cable model that extends to electrical extracellular fields or RC network attached to a voltage source. Here, one can stimulate the neuron extracellularly |
| `initB5.hoc`     | Stimulates the neuron with **one endogenous wave** and another exogenous wave simultaneously. |
| `initA.hoc`    | Stimulates the neuron **with two   endogneously applied** sine waves. |
| `initB5.hoc`     | Stimulates the neuron with **two exogenously applied  waves** simultaneously. |
| `mosinit.hoc`   | Launches a **GUI** to visualize results. |

---

## 🏃 How to Run the Code

1. Download entire codebase to a location on your computer and unzip.
2. Open command terminal for windows and then cd to the place you have saved.
3. Run nrnivmodl.
4. Run mosinit.hoc or nrnguimosinit.hoc
