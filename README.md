# frama-c-problems
A repository dedicated for problems related to verification of programs using the tool frama-c.

## This repository contains various problems solved in frama-c

###  What is frama-c?
<to be filled>
  

# Installing frama-c

> NOTE: This is a living document ie is being actively modified. Keep checking every now and then for updates! 

Frama-C is a suite of tools dedicated to the analysis of the source code of software written in C. This is available as part of the OCaml suite.

##### For more details:   
https://frama-c.com/
https://opam.ocaml.org/

This tool has been written primarily with Linux in mind and can thus be installed in three ways - as a package in a Linux distro or using WSL2 (Windows Subsystem for Linux 2 - a way to run Linux apps - although not very well at the present moment - on Windows) or using cygwin (a framework that enables the usage of serveral GNU tools on Windows). There also exists a beta version of the OCaml Package Manager for Windows.

# Requirements

### Method 1 - Native Linux install / VM
  - Ubuntu or Arch Linux based distro recommended.
  - A stable internet connection
  - Lots of patience ;p
  
> NOTE: Some Ubuntu / Debian distros like Pop!OS and Kali Linux don't have all the packages necessary - stock Ubuntu is preferred for a relatively hassle free installation.


# Method 1

  - We begin by making sure package repositories are updated. 
    
    ```sh
    > Ubuntu 
    sudo apt update 
    ```
    
    ```sh
    > Arch Linux
    sudo pacman -Syu 
    ```
    
  - Install the ocaml package manager (opam)
 
    ```sh
    > Ubuntu
    sudo apt install opam 
    ```
    
    ```sh
    > Arch Linux
    sudo pacman -S opam 
    ```
![image](https://user-images.githubusercontent.com/59725174/97779283-102dfa80-1ba3-11eb-8ad4-fe841f865501.png)


    
  - Initlialize opam in your home directory.
    ```sh
    opam init 
    ```
    - The process will take user inputs a couple of times, it is safe to say yes (type y) whenever this happens. 

![image](https://user-images.githubusercontent.com/59725174/97779305-2936ab80-1ba3-11eb-9363-079ba12312cb.png)

  - Run this command: ``` eval $(opam env) ```
    
![image](https://user-images.githubusercontent.com/59725174/97779340-64d17580-1ba3-11eb-9c42-6585d590b751.png)

    
  - This package is used to identify system packages that are necessary for frama-c to function as intended. To identify and install the dependencies for frama-c, run
  
    ```sh
    opam install depext
    ```
    
    followed by 
    
    ```sh
    opam depext frama-c
    ```

![image](https://user-images.githubusercontent.com/59725174/97779356-7b77cc80-1ba3-11eb-87a5-f485ce340ed4.png)

![image](https://user-images.githubusercontent.com/59725174/97779361-803c8080-1ba3-11eb-9f28-be4d2035422b.png)

    
    > While depext works as expected in Ubuntu, it might complain saying it doesn't know how to install packages on an Arch 
    > based system. The solution is to copy the package names and install them manually. If yay is installed, run
    > ``` yay -S package1 package2 package3 ... ``` 
    >  as some packages are not available in the official repos and can only be found in AUR (Arch User Repository).

 - For Arch Linux users only:
![image](https://user-images.githubusercontent.com/59725174/97779449-24bec280-1ba4-11eb-8f24-78206c3d42f4.png)

 
 - Now that dependencies have been installed, it's time for the important step! To install frama-c, run
    ```sh
    opam install frama-c
    ```

![image](https://user-images.githubusercontent.com/59725174/97779407-c85ba300-1ba3-11eb-8ca6-daa085be10c7.png)

    
- This installs frama-c, provers and other related packages from source so depending on network and system power might take a while. Feel free to have a coffee while you wait! If there is an error at this point saying some package is missing, go back, run ```opam depext frama-c``` again and check for any missed dependency installs. 

    #### Final configuration
    
 - Time for final configuration and clean up. Run the following commands:
    
    ```sh
    eval $(opam env)
    why3 config --full-config      
    ```
    
    > If ```why3 config --full-config``` fails to execute, run ```why3-config --full-config``` instead.
    
## Congrats!
You've successfully installed frama-c. 

#### Usage instructions:

To use frama-c, you need a ```.c``` file that has the requisite frama-c code added to it. To test, you can download one of the files listed in this repo.

#### Step 1: Navigating to the folder in question
##### Method 1: 
 - Open the folder where this file is present, right click and select the 'open in terminal' option. The name and location of said option might vary depending on the file manager you are using. 
 - Type ```ls``` and a list of files in the directory will be listed. If the ```.c``` file is listed, you are in the right directory. 
 
##### Method 2: 
  - Open a terminal session and navigate to the folder with the ```.c``` file using a combination of ```cd``` and ```ls```.
  

#### Step 2: Opening frama-c
##### Option 1: CLI
 - To run frama-c as a command line app, execute the following command: 
     ```
    frama-c -wp filename.c
    ```
    where ```filename.c ``` should be replaced with the name of the file you're testing. 
    
- To run frama-c with ```rte``` guards enabled, run the following command: 

    ```
    frama-c -wp -rte filename.c
    ```
    
##### Option 2: Graphical
 - To run frama-c as a graphical application, execute the following command: 
    ```
    frama-c-gui -wp filename.c
    ```
 - To run frama-c as a graphical application with ```rte``` enabled, execute the following command: 
    ```
    frama-c-gui -wp -rte filename.c
    ```
    
 #### Troubeshooting measures
 
 - If ```frama-c``` complains about something or if provers are not found, try the following: 
 
Possible solutions: 
: run ```opam init``` and ```eval $(opam env)``` again
: run ```why3 config --full-config``` again

: As a last resort, alt-ergo-2.3.3 can be replaced with alt-ergo-2.3.1, the officially supported version (but not default install, which is alt-ergo-2.3.3)
``` opam install alt-ergo-2.3.1 ```
: This has to be followed by ```eval $(opam env)``` and ```why3 config --full-config```
    
    
    
    

    

