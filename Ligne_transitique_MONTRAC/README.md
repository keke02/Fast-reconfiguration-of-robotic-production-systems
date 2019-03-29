# Fast reconfiguration of robotic production systems - Install project

> Command of a transport network

## Authors
- __Mekkid Oussama__ -- oussama.mekkid@gmail.com
- __Moumene Malek__ -- malekmoumene@gmail.com
- __Brisbare Kevin__ -- kevin.brisbare@gmail.com
- __Orbach Mano__ -- orb.mano@gmail.com
- __Monneret Viven__ -- vivien.monneret@univ-tlse3.fr
- __Meliouh Yles__ -- ylesmeliouh@gmail.com"


# TO DO

## Install ROS 

1. **To install the latest version of ROS, go to http://wiki.ros.org/ROS/Installation and install the appropiate version for your platform**

## Install Modbus

2. **Open a terminal and write**

	- $ sudo apt-get install libmodbus-dev 


## Create the workspace


3. **In ~/.../ Create a folder named for example "Working_Folder_Montrac", it will contain your workspace**
	- In this folder, copy the folders *img* and *V-REP* and the file *Simulation.ttt* (you can find them in ~/.../WFM, every time you will find "/.../" you have to replace this by the path that leads to the folder or the file we are talking about on YOUR computer)


4. **In ~/.bashrc, add these lines :**
	- source /opt/ros/*ROS_version*/setup.bash (source /opt/ros/jade/setup.bash for example if your installed ROS JADE)
	- export VREP_ROOT_DIR=~/ ... /Working_Folder_Montrac/V-Rep/

5. **Create the workspace ros_ws : in ~/.../Working_Folder_Montrac :**
	- $ mkdir -p ros_ws/src
	- $ cd ros_ws/src
	- $ catkin_init_workspace
	- $ cd ..
	- $ catkin_make

6. **In ~/.bashrc, add this line :**
	- source ~/ ... /Working_Folder_Montrac/ros_ws/devel/setup.bash (this line will avoid you to always write source devel/setup.bash every time you open a new terminal)
	- if you are using another ros workspace in parallel, don't add this line in ~/.bashrc, you will have to write the command "source devel/setup.bash" every time that you open a new terminal and that you are in /ros_ws

## Add the packages

7. **in ~/.../Working_Folder_Montrac/ros_ws/src**
	- copy the package *automates* of ~/.../WFM/ros_ws/src (which is the folder *automates*)

8. **in the packages automates**
	- open the file *CMakeLists.txt*, comment the lines 21, 22 and 23 using the character "#" and save (they correspond to the creation of the executable files)

9. **In ~/.../Working_Folder_Montrac/ros_ws/ :**
	- $ catkin_make

10. **Return to the file *CMakeLists.txt* of the package automates**
	- repeat these steps for each of the packages that have an executable (communication, commande_locale and commande)
	- Be carreful to add each package one by one, don't copy all the package at once to avoid errors.

11.  **In a terminal, write the command "roscore" if you haven't done it yet to launch the local master**


## Run the tranport network 


13. **To run the real transport network**

	- Before executing the following programs, make sure that you have configured all the PLC (Programmable Logic Controller, API in french) using Unity Pro (see README_configuration_automate.md)
	- in a new terminal, still in ~/ ... /Working_Folder_Montrac/ros_ws 
	- $ rosrun communication start


## Run a command


14. **In a new terminal, in ~/ ... /Working_Folder_Montrac/ros_ws**

	- $ rosrun commande run
	- This will run the command that is in ~/.../Workin_Folder/ros_ws/src/commande, you can choose the command you want to run in ~/ ... /WFM/Documentation/TER Commande d'une ligne transitique MONTRAC 2016/Commandes.

	- if your are using the real transport network, you have to put the shuttles on the tracks and power on them by connecting them to the tracks and turning on the yellow button on their right side.

	- if a shuttle is stuck on a stop, it is probably because of an error reading the value of a sensor, you can gently push the shuttle so it will continue its way. Don't wait too loog before pushing it because if it happends in a curve the others shuttles will bump in the stucked shuttle (the sensor proximity on each shuttle is not very efficient in the curves).


## MORE INFOS

**If you want to see the simulation.ttt on VREP :**
   - Execute ~/ ... /WFM/V-Rep/vrep.sh ~/CelluleFlexible/Simulation.ttt

**If you want more information about the project go to https://github.com/keke02/Transport-Network-and-Baxter/tree/Projet-18/19**

**The simulation with this modified project doesn't work successfully**
