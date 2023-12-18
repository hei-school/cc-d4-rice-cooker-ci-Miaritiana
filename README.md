# Rice-cooker (C Version)
## Standard
C language Style Guide = https://isocpp.org/wiki/faq/coding-standards

## Prerequisites

Before you begin, ensure you have the D compiler installed. If not, you can install it following the instructions for your platform [here](https://gcc.gnu.org/install/).

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/hei-school/cc-d2-my-rice-cooker-Miaritiana.git
    ```

2. Change into the project directory:

    ```bash
    cd cc-d2-my-rice-cooker-Miaritiana/
    git checkout feature/c
    ```

## Usage
1. Compile the C program:

    ```bash
    gcc main.c -o rice_cooker
    ```

2. Run the compiled program:

    ```bash
    ./rice_cooker
    ```

3. Follow the on-screen prompts to set the capacity, choose ingredients, and configure cooking options.

## Test

1. Install googletest

2. Run this command:

    ```bash
    g++ rice_cooker.c rice_cooker_test.c -o rice_cooker_test -lgtest -lgtest_main -pthread
    ./rice_cooker_test
    ```


[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/__xb4cFP)
