# First Dynamic Kernel Module

This repository contains a simple example of a dynamic Linux kernel module that demonstrates the creation of a custom `/proc` entry and reading data from it.

## Features

- **Custom `/proc` Entry**: The module creates a `/proc/ldd_driver` entry.
- **Simple Read Operation**: Reading from `/proc/ldd_driver` returns the string `"awk\n"`.
- **Kernel Debugging Messages**: Includes `printk` statements for tracking function calls.

## Files

- `ldd.c`: The kernel module source code.

## Requirements

- Linux kernel development environment.
- Root privileges for loading and unloading kernel modules.
- Kernel version with support for `proc_ops`.

## Usage

To build, load, interact with, and unload the kernel module, follow these steps:

1. **Build the Module**:  
   Ensure you have the Linux kernel headers installed, then compile the module with:  
   ```bash
   make
2. **Load the Module into Kernel Space:**
    Inject the compiled kernel object file (ldd_driver.ko) into the kernel:
    ```bash
   sudo insmod ldd.ko

3. **Verify /proc Entry:**
    After loading the module, check if the /proc/ldd_driver file has been created:
    ```bash
    ls /proc/ldd_driver

4. **Read from /proc/ldd_driver:**
    Read the contents of the custom /proc entry:
    ```bash
    cat /proc/ldd_driver
5. **Remove the Module from Kernel Space:**
    To unload the kernel module and clean up the /proc entry, use:
    ```bash
    sudo rmmod ldd_driver

