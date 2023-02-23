---
layout: home
permalink: index.html

# Please update this with your repository name and title
repository-name: e16-4yp-Configurable-ECU-Emulator
title: Configurable ECU Emulator
---

# Configurable ECU Emulator for Creating Digital Twins in the Car Manufacturing Industry

#### Team

- e16061, Chandula J.P.D.M, [email](mailto:e16061@eng.pdn.ac.lk)
- e16203, Isuru Lakshan, [email](mailto:e16203@eng.pdn.ac.lk)
- e16261, Aruna Nuwantha, [email](mailto:e16261@eng.pdn.ac.lk)

#### Supervisors

- Dr. Mahanama Wickramasinghe, [email](mailto:mahanamaw@eng.pdn.ac.lk)
- Dr. Isuru Nawinne, [email](mailto:isurunawinne@eng.pdn.ac.lk)

#### Table of content

1. [Abstract](#abstract)
2. [Related works](#related-works)
3. [Methodology](#methodology)
4. [Conclusion](#conclusion)
5. [Links](#links)

---

<!-- DELETE THIS SAMPLE before publishing to GitHub Pages !!!
This is a sample image, to show how to add images to your page. To learn more options, please refer [this](https://projects.ce.pdn.ac.lk/docs/faq/how-to-add-an-image/)
![Sample Image](./images/sample.png) -->


## Abstract
Consumer vehicles of today are loaded with several electronic systems. Electronic Control Units (ECUs), which are embedded systems, are used to control these electronic systems. Vehicle manufacturers employ highly realistic simulated models to test these ECUs. But there are several problems with those simulators. Therefore we conduct research with the objective of building a configurable ECU emulator for the automobile industry. The architecture of the Infineon tri-core processor, a significant processor in automotive ECUs, the main methods of developing an instruction set simulator (ISS), various optimization techniques researchers have used to increase the performance of ISS, and what ISAs are supported by currently available simulators were all reviewed in related work in this paper. Then, we included our methodology of implementation of the configurable ECU emulator. As the first milestone, in this work researchers focused on developing ISS according to the infinion ISA. The implementation details were highly described here along with Memory implementation and Testing. Finally we describe how the future work can be done to have this simulator to develop the full ECU emulator.

## Related works
### A. Ecu modeling in automobile industry
1) Silver Emulator: Jakob Mauss and Matthias Simons have authored a research paper on Silver [5], an ECU emulator that comes with an integrated chip simulator. This emulator can directly simulate TriCore targets on a computer. However, there are three requirements to use this emulator.
    1) Application software in the form of a hex file.
    2) The starting addresses of the simulated functions.
    3) An ASAP2/a2l file containing the conversion rules for the inputs, outputs, and characteristics involved, as well as the corresponding addresses.

    The Silver emulator simulation is instruction accurate, but not cycle-accurate, which means that the simulator cannot predict the exact execution time of instructions. The simulator can execute a task infinitely fast, making it impossible for the operating system to interrupt tasks. Moreover, silicon bugs are not simulated, which could lead to different behavior in some cases. This type of simulator is used to make processes faster, cheaper, and more efficient. For instance, Daimler now uses this new modeling technique to assist in developing controls for gasoline engines.

2) HIL Simulator: The automotive industry has been using Hardware-in-loop (HIL) [6] testing for ECU (Electronic Con-trol Unit) testing for quite some time now, as it is easier and more efficient than testing in a real vehicle. HIL produces a more accurate and actual hardware-like simulation than SILVER. There are two main methods in HIL testing: Open-loop testing and Closed-loop testing. However, the main issue is that HIL systems are often expensive and time-consuming, with many processes involved in doing configurations.

    To address these concerns, K. ENISZ, P. TOTH, D. FODOR, and T. KULCSAR conducted research to develop a software and hardware HIL simulation environment that is easily re-configurable [7]. The modular architecture of this simulator achieved the reconfigurability, resulting in an ECU simulator that was consistent with expectations, though there is still room for improvement.

3) Configurable ECU Emulator for Integration Testing: The authors of this paper present a solution for a configurable ECU emulator for integration testing. Typically, this testing is done by connecting real ECU hardware through a vehicle communication interface (VCI) to diagnostic software that interprets messages from the vehicle. With their solution, manufacturers can eliminate the need for real ECU hardware in this type of testing. Reconfigurability is achieved by various low-level protocols that vehicle manufacturers use to build communication between ECUs, such as Controller Area Network (CAN), LIN, and K-Line. Currently, they have implemented CAN and K-Line protocols. Their ECU emulator is generic and compatible with various communication protocols, including CAN, LIN, and Flexray. The block diagram of their solution can be found in Figure 1.
The ECU simulator developed by the authors simulates a real-time ECU environment like real ECU hardware. The test steps code is located in the test server, which is connected to the VCI through a TCP/IP connection. The VCI and the ECU emulator are connected via the physical bus being tested, such as CAN or K-Line. The ECU emulator is given a table indicating how it should operate by the test server via a TCP/IP connection.

    The ECU simulator comprises three parts: Logic, Table, and TCP server. The TCP server communicates with the test server, receives configuration information for the ECU simulator, and sends feedback on the communication at the end of the test session. The table holds information about the message direction, CAN message IDs, Payload DATA, and timing information, and is provided by the test server. The Logic interprets the table line by line after receiving the initial table from the test server. While the researchers have implemented only CAN and K-line protocols, this methodology can be used to test any type of communication protocol without requiring real ECU hardware and the necessary interconnections. The table design and code modularity make it easy to add other physical protocols such as LIN, which is needed for their project.

### B. Instruction Set Simulation

The researchers have utilized two main methods for developing instruction set simulators: interpretation-based simulation and compilation-based simulation. Compilation-based simulation, in turn, can be further divided into two sub-methods: static compilation-based and dynamic compilation-based. The following review is based on the most recent research in this area.

1) Interpretation-Based Simulation: In the interpretation-based simulation method, each hardware unit in a processor is simulated, including the fetching, decoding, and execution units. To simulate instructions, the method utilizes a loop in which each cycle involves fetching, decoding, executing, and saving the result of an instruction. A data structure is used to represent the state of the target processor in memory. Figure 2 illustrates the simulation process, which begins by reading the next instruction according to the program counter. The simulator then analyzes the instruction and extracts the opcode field using the decode function. Next, the simulator selects the appropriate code to handle the instruction based on the opcode using a switch-case statement and executes the corresponding code.

    In summary, while the interpretation-based simulation approach is a popular and flexible way to simulate processors, it is not without its drawbacks. The approach can be inefficient and slow due to the overhead required for instruction fetching, decoding, and dispatching. Additionally, the fidelity of the simulation may not be as high as desired, and the approach can be up to 25-30 times slower than native execution.

2) Compilation-Based Simulation: The approach of compilation-based simulation involves the direct translation of target machine instructions into a sequence of host machine instructions, which then manipulate the simulated machine state. This process is depicted in Figure 3. The purpose of this method is to mimic the behavior of the set of instructions on the host machine, using a different set of instructions that are appropriate for the host machine.


    After the target machine instructions are translated, the resulting code is compiled according to the host machine and executed on the host machine, which simulates the behavior of the original source code. Typically, the compilation-based method yields higher simulation performance compared to the interpretive method. This is due to the fact that in the compilation-based method, time-consuming operations are shifted to compile time, thereby reducing the time consumed during runtime. One of the most time-consuming operations is instruction decoding, with instruction fetching and dispatching also significantly contributing to the time consumed. Although the host machine has to decode and dispatch, the simulated machine state is stored in the host machine's memory. There are two approaches to compilation-based simulation: static compilation-based simulation and dynamic compilation-based simulation.

3) Static Compilation-Based Simulation:
The initial stage of the static compilation-based simulation process involves the translation of the target program into C code. The entire source code is translated and stored in the memory of the host machine before execution commences. Next, the optimizing C compiler converts the C code into a program that can run on the host machine. However, static compiled simulation methods have some drawbacks. The primary disadvantage is that compiled simulation techniques cannot accommodate changes to the instruction set during runtime since it has already been decoded and compiled during compile time. As a result, these simulations require a fixed and predictable program code. Additionally, compiled simulations require a considerable amount of memory to store both the translated and compiled code. These types of simulations are designed for use in Digital Signal Processor (DSP). This process is depicted in Figure 4.

4) Dynamic Compilation-Based Simulation:
The dynamic compilation-based method is similar to the static compilation-based method, but the translation takes place during runtime while the translated code is being executed. This approach provides some flexibility to accommodate changes to the instruction set during runtime.

    The EMBRA simulator, as introduced in the paper, is designed to simulate the MIPS R3000/R4000 processor, including its cache memories and Memory Management Unit. The simulator can be modified to simulate multiprocessors and uses a dynamic binary translation technique to enhance performance. Binary translation involves translating a section of source code into simulation code that mimics the execution behavior of the source code. This technique removes many overhead instructions that may be present in the source code, and the dynamic nature of the translation enables the simulator to jump to critical sections of the code, skipping unwanted sections. This feature is particularly helpful when the code base has large setup times and initializations.

    A basic example of translation would be reading registers from a simulated register file, performing some operations on them, and then storing the results back into the simulated register file. This operation is similar to reading hardware registers, executing some operations on them, and storing the results in the register file. Since most source code consists of loops, the processor executes the same block of code repeatedly. Therefore, translating the same code block again and again during each loop run can result in performance lag. To address this issue, the authors of the paper proposed using a Translation Cache (TC). The TC stores recently executed translated code, and executing the same block of code involves finding the block in the TC and jumping into it. To identify where the translated block is in the TC, the authors maintain a mapping table between the Program Counter (PC) and the TC address of the translated code. This process is illustrated in Figure 5.

## Methodology
### A. Initial Development
The development of configurable ECU emulator is an approach with several milestones.As the first milestone, the researchers developed an initial version of the ISS that could simulate the infinion ISA as in the TC1.6.2p single-core processor. To accomplish this, the researchers used an interpretation-based simulation method where each instruction behavior was interpreted using the C++ language. This method involves identifying each instruction using its opcode and functional fields and then modeling its behavior in a switch-case manner. The register files were simulated as arrays, and the results were stored in those arrays.
During the simulation process, the machine code was fetched and executed iteratively, instruction by instruction. The simulation model is based on a single-cycle processor, where the instruction fetch, decode, execute, memory, and write-back phases of the pipeline are executed sequentially. In this way, the model simulates the entire instruction processing cycle.
For the development of the initial ISS, a subset of the whole instruction set was used. This was done to reduce the complexity of the model and to ensure that the simulator was able to function correctly before being expanded to include the entire instruction set. Once the initial ISS was developed and tested, the researchers hope to expand the simulator to include the complete instruction set.

### B. Memory Implementation
The TriCore™ processor has an addressable memory map organized into segments of 256 MB. The table 2 shows the detailed memory segmetation. Each segment is identified by the A[31:28] bits of the system address, and it allows access to a specific area that is used to define cacheable and non-cacheable areas. Understanding the memory structure is important to optimize code for optimal run-time performance. The implementation of a memory class in C++ for the TriCore™ processor can help achieve this goal.

The memory class is implemented using a hash map in C++. The hash map uses a key-value pair data structure, where the key is the address of the memory location and the value is the data stored at that location. The hash map enables O(1) time complexity for read and writes operations, essential for optimal run-time performance.

To implement the memory class, the following steps are followed:
Create a hash map object to store the memory data.
Define the segment size.
Create a method to check if the address is within the valid memory range.
Create methods to read and write data to the memory location.
Implement cacheable and non-cacheable areas based on segment identification.
Ensure that the implementation of the memory class enables the portability of applications across devices in the TriCore™ family.

The implementation of a memory class in C++ for the TriCore™ processor using a hash map can help achieve optimal run-time performance. Understanding the memory structure and segment identification is important to implement cacheable and non-cacheable areas. The memory class implementation should enable the portability of applications across devices in the TriCore™ family. With this implementation, users can optimize their code for optimal run-time performance on the TriCore™ processor.

### C. Testing
The process of testing the functional accuracy of the Infinion ISA involved a multi-phase approach. In the first phase, a high-level code block was generated manually. This code block was designed to test the different features of the ISA, including arithmetic operations, logical operations, and control operations. The code block was carefully crafted to ensure that all of the different instructions in the subset selected from the ISA were executed at least once during the simulation process.

In the second phase, the code block was converted to assembly language using a suitable compiler. The assembly language code was carefully checked to ensure that it accurately reflected the functionality of the original high-level code block. Any discrepancies or errors were corrected at this stage to ensure that the assembly language code accurately represented the original high-level code block.

In the third phase, the assembly language code was converted to machine code using a suitable assembler. This machine code was then fed into the Infinion ISA Instruction Set Simulator (ISS). The ISS simulated the execution of the code block using the interpretation-based simulation method described earlier. During the simulation process, the machine code was fetched and executed instruction by instruction, and the final register values were stored in the register file array.

In the final phase, the final register values stored in the register file array were compared to the expected values. Any discrepancies or errors were identified and corrected. This process allowed the researchers to test the functional accuracy of the Infinion ISA, and to ensure that it was capable of executing all of the different instructions in the ISA correctly.

In conclusion, the process of testing the functional accuracy of the Infinion ISA involved a thorough and iterative approach. The use of a high-level code block, assembly language, and machine code allowed the researchers to simulate the execution of the ISA accurately, while the use of the ISS and register file array allowed for easy identification of any discrepancies or errors. The result is a highly accurate and efficient ISA that is capable of executing complex computations and supporting a wide range of applications.

## Conclusion
In conclusion, electronic control units (ECUs) have become an integral part of modern vehicles, controlling everything from engine management to safety systems. With the growing complexity of these systems, the need for reliable and efficient ECU emulation has become increasingly important for car manufacturers. This research paper has provided an overview of the current methods used for emulating ECUs and developing instruction set simulators, as well as introducing the Infineon TriCore 399x chipset used in modern ECUs.
Our project focused on developing an instruction set simulator for an ECU with the Infineon TriCore 399x microcontroller embedded. We used the interpretation-based simulation method to develop the simulator, which enabled us to accurately simulate the ECU's behavior. We also discussed the memory implementation and testing process for the simulator.
Overall, our research has demonstrated the feasibility of developing high-performance ECU emulators using instruction set simulators. This can greatly benefit car manufacturers in reducing development costs, improving software testing, and increasing the efficiency of the overall vehicle development process. In the future, further research can be conducted to enhance the performance and capabilities of ECU emulators and make them even more reliable and effective.

[//]: # "Note: Uncomment each once you uploaded the files to the repository"

<!-- 1. [Semester 7 report](./) -->
<!-- 2. [Semester 7 slides](./) -->
<!-- 3. [Semester 8 report](./) -->
<!-- 4. [Semester 8 slides](./) -->
<!-- 5. Author 1, Author 2 and Author 3 "Research paper title" (2021). [PDF](./). -->


## Links

[//]: # ( NOTE: EDIT THIS LINKS WITH YOUR REPO DETAILS )

- [Project Repository](https://github.com/cepdnaclk/e16-4yp-Configurable-ECU-Emulater)
- [Project Page](https://cepdnaclk.github.io/e16-4yp-Configurable-ECU-Emulater)
- [Department of Computer Engineering](http://www.ce.pdn.ac.lk/)
- [University of Peradeniya](https://eng.pdn.ac.lk/)

[//]: # "Please refer this to learn more about Markdown syntax"
[//]: # "https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet"
