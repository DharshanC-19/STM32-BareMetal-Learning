# STM32 Interrupt-Based LED Control

## 📌 Overview

This project is developed using the STM32F103RBTx NUCLEO board and Bare-Metal Embedded C programming.

The project demonstrates:

* GPIO configuration
* External interrupts (EXTI)
* NVIC interrupt priorities
* SysTick timer delays
* LED control using register-level programming

---

# 🔧 Hardware Used

* STM32F103RBTx NUCLEO Board
* External LEDs
* Push Buttons
* Breadboard

---

# 💻 Software Used

* STM32CubeIDE 2.1.1
* Embedded C

---

# 📖 Documentation Referred

* STM32F103x8/xB Datasheet (DS5319)
* STM32F10xxx Reference Manual (RM0008)
* STM32 Nucleo-64 Boards User Manual (UM1724)

---

# 🧠 What I Learned

* Register-level programming
* GPIO configuration
* EXTI interrupt handling
* NVIC priorities
* SysTick timer delays
* Debugging using ST-LINK

I also learned the importance of checking board schematics, pin mappings, and official documentation while debugging Embedded Systems projects.

---

# 🔌 Interrupt Pins Used

| Interrupt | Pin  |
| --------- | ---- |
| EXTI0     | PA0  |
| EXTI9_5   | PB8  |
| EXTI15_10 | PC13 |

---

# 💡 LED Pins Used

| LED  | Pin |
| ---- | --- |
| LED1 | PA5 |
| LED2 | PA6 |
| LED3 | PA7 |

---
