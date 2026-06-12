# STM32 GPIO Bare-Metal Programming

## LEARNING THROUGH IMPLEMENTATION

## GPIO IMPLEMENTATION 

This is my first STM32 bare-metal programming  using the STM32F103RB NUCLEO board.

In this Implementation, I controlled LEDs connected to PA5, PB9, and PC7 by directly accessing STM32 registers without using HAL libraries.

## Hardware Used

* STM32F103RB NUCLEO Board
* On-board ST-LINK Debugger
* LEDs

## Software Used

* STM32CubeIDE 2.1.1
* C Programming Language

## What I Learned

* Enabling GPIO clocks
* Configuring GPIO pins as outputs
* Using GPIO registers
* Controlling LEDs through register-level programming
* Creating delays using software loops

## Registers Used

* RCC->APB2ENR
* GPIOA->CRL
* GPIOB->CRH
* GPIOC->CRL
* GPIOA->ODR
* GPIOB->ODR
* GPIOC->ODR

## Output

The LEDs connected to PA5, PB9, and PC7 blink in different patterns using direct register access.

## Goal

To learn STM32 embedded systems programming from scratch using bare-metal (register-level) programming.
