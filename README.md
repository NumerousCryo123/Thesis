
Where:

- `g_Na_init`, `g_K_init`, `g_L_init` = maximal conductances  
- `m`, `h`, `n` = gating variables  
- `V` = membrane potential  
- `E_Na`, `E_K`, `E_L` = reversal potentials  

This suggests that applying two different electrical signals to a neuron could produce **heterodyned frequencies**.

---

## 🧪 Model Objective

The NEURON model:

1. Simulates a **myelinated axon**.  
2. Applies **two AC signals** (intracellular + extracellular).  
3. Observes whether **heterodyned frequency components** appear in the membrane potential.

---

## 📷 Figures

**Neuron Heterodyning Model Diagram**  

![](https://github.com/user-attachments/assets/139307e5-e0e9-41fb-8343-7644806e2f3d)  

**Electronic Circuit Representation of Neuron**  

![](https://github.com/user-attachments/assets/26c28683-59fb-49e2-8f4b-3da9f7938f92)

---

## 💻 Implementation Notes

The neuron can be represented as an **electro-chemical integrate-and-fire cell**, analogous to an **RC electronic circuit**. Resistance and capacitance naturally emerge in the model.

---

## 🗂 Work Done in the Files

| File           | Purpose |
|----------------|---------|
| `axonB10.hoc`  | Constructs a myelinated CNS neuron stimulated **exogenously** by a sinusoidal wave and **endogenously**. |
| `axonB5.hoc`   | Stimulates the neuron **endogenously**. |
| `axonA.hoc`    | Stimulates the neuron with **two exogenous waves**. |
| `mosinit.hoc`  | Launches a **GUI** to visualize results. |

---

## 🏃 How to Run the Code

1. Open NEURON and load the desired `.hoc` file (e.g., `mosinit.hoc`).  
2. Use the GUI to **start simulations** and visualize membrane potentials.  
3. For dual-signal heterodyning experiments, run `axonA.hoc`.  
4. Optionally, export data for **FFT analysis** to observe heterodyned frequencies.

*This workflow bridges neuroscience and communication theory, showing how non-linear biological components can mimic engineered signal mixers.*
