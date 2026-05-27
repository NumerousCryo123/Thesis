# Thesis

## 🧠 Modeling Signal Mixing Effects in Neurons using NEURON Simulator

This repository contains code for modelling **signal mixing effects in myelinated neurons** using the **NEURON simulator**.

The project investigates whether a biologically realistic neuron model can behave similarly to a non-linear electronic mixer when stimulated by alternating-current electrical signals. The model applies endogenous and exogenous AC stimulation to a myelinated axon and analyses whether new frequency components appear in the membrane voltage response.

The workflow combines:

- **NEURON simulation** of a myelinated neuron.
- **AC stimulation** through intracellular and extracellular pathways.
- **Exported voltage traces** saved as `.dat` files.
- **MATLAB signal analysis** using IQ demodulation, envelope extraction, normalisation, cross-correlation, RMS analysis, and FFT.

---

## 🧠 Concept Overview

**Signal mixing** is a process in which two signals of different frequencies interact through a **non-linear electrical component**, resulting in the generation of new frequencies — specifically, the **sum** and **difference** of the original frequencies.

If two input frequencies are:

- $f_1$
- $f_2$

Then, the resulting frequencies after signal mixing are:

- **Sum frequency:** $f_1 + f_2$
- **Difference frequency:** $|f_1 - f_2|$

This principle is fundamental in **telecommunications**, where it enables frequency translation and allows communication using smaller antennas.

---

## ⚙️ The Mixer and Non-Linearity

A **mixer** is a non-linear circuit component that combines two input signals. Its current-voltage relationship is non-linear, meaning the output can contain new frequencies that were not present in the original input signals.

A common implementation is the **Gilbert Cell Mixer**:

🔗 [A Gilbert Cell Mixer with a Digitally Controlled Performance Space](https://www.researchgate.net/publication/228977791_A_Gilbert_cell_mixer_with_a_digitally_controlled_performance_space)

---

## 🧩 Biological Analogy — The Axon Hillock

Interestingly, the **axon hillock** in neurons is also highly **non-linear** because it contains voltage-gated ion channels. Its ionic current can be expressed as:

$$
I_t =
g_{Na,\text{init}} m^3h(V - E_{Na})
+ g_{K,\text{init}} n^4(V - E_K)
+ g_{L,\text{init}}(V - E_L)
$$

This suggests that if two different electrical signals are applied to a neuron, **signal mixing** could theoretically occur, leading to the generation of new frequency components in biological systems.

---

## 🧪 Model Objective

To test this hypothesis, the NEURON model:

- Simulates a **myelinated axon**.
- Applies AC signals through intracellular and extracellular stimulation.
- Observes whether **mixed-frequency components** appear in the resulting membrane potential.
- Exports membrane voltage traces for signal-processing analysis in MATLAB.
- Uses IQ demodulation and FFT analysis to determine whether low-frequency information can be recovered from high-frequency stimulation.

---

## 📷 Figures

### Neuron Signal Mixing Model Diagram

<div align="center">
  <img src="https://github.com/user-attachments/assets/3fe820ef-4581-46d6-947a-671e52393870">
</div>

### Electronic Circuit Representation of Neuron

<div align="center">
  <img src="https://github.com/user-attachments/assets/26c28683-59fb-49e2-8f4b-3da9f7938f92" width="590" alt="Neuron circuit representation">
</div>

---

## 📁 Repository Structure

Recommended structure:

```text
Thesis/
│
├── axon10.hoc
├── initA.hoc
├── initB5.hoc
├── initB6.hoc
├── mosinit.hoc
│
├── analysis/
│   └── iq_demodulation_analysis.m
│
├── data/
│   ├── Synapse_3Hz.dat
│   ├── DBS_Suprathreshold_1000.dat
│   ├── DBS_Suprathreshold_2000.dat
│   └── DBS_Suprathreshold_5000.dat
│
└── results/
