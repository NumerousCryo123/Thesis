
Where:

- `g_Na_init`, `g_K_init`, `g_L_init` = maximal conductances  
- `m`, `h`, `n` = gating variables  
- `V` = membrane potential  
- `E_Na`, `E_K`, `E_L` = reversal potentials  

This suggests that two different electrical signals applied to a neuron could result in **heterodyning**, producing mixed-frequency components.

---

## 🧪 Model Objective

The NEURON model:

1. Simulates a **myelinated axon**.  
2. Applies **two AC signals** (intracellular + extracellular).  
3. Detects whether **heterodyned frequencies** appear in the membrane potential.

---

## 📷 Figures

**Neuron Heterodyning Model Diagram**  

<div align="center">
  <img src="https://github.com/user-attachments/assets/139307e5-e0e9-41fb-8343-7644806e2f3d" width="350" alt="Neuron heterodyning model diagram">
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
| `axonB10.hoc`   | Constructs a myelinated CNS neuron stimulated **exogenously** by a sinusoidal wave and **endogenously**. |
| `axonB5.hoc`    | Stimulates the neuron **endogenously**. |
| `axonA.hoc`     | Stimulates the neuron with **two exogenous waves** simultaneously. |
| `mosinit.hoc`   | Launches a **GUI** to visualize results. |

---

## 🏃 How to Run the Code

1. Open NEURON and load the desired `.hoc` file (e.g., `mosinit.hoc`).  
2. Use the GUI to **start simulations** and visualize membrane potentials.  
3. For dual-signal heterodyning experiments, run `axonA.hoc`.  
4. Analyze results using NEURON tools or export data for **FFT analysis**.  

*This workflow bridges neuroscience and communication theory, showing how non-linear biological components can mimic engineered signal mixers.*
