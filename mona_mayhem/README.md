# MONA Background

![MONA](Mona.jpg?raw=true "MONA")


Swarm robotics is a field of research that explores the behaviour of large groups of simple robots that work together to achieve a common goal. The study of swarm robotics is motivated by the desire to develop intelligent, adaptive, and robust systems that can perform complex tasks in dynamic and uncertain environments.

One platform developed to enable researchers in this field were the MONA robots by the University of Manchester and sold by Ice9Robotics. These Arduino based differential drive robots can be used in many applications with a wide range of versatile features.

Swarm robotics and football can be compared in terms of their use of collective behaviour to achieve a common goal. In football, players work together to score goals and win matches. Each player has a specific role and must coordinate their movements with their teammates to create scoring opportunities and defend against the opposition. The success of the team depends on how well the players communicate, adapt to changing circumstances, and work together as a unit. Traits which is essential to have a functional swarm.

# Challenge

## <div align="center"> Create a basic swarm to play football against another team. </div>

## Info

Each team will be issued with 2 MONA robots, an Arduino Nano and 3 NRF24 radio modules to help in the challenge.

The football pitch for this challenge has been specially designed to track the position of both the robots and the football placed on the board. 

The pose of each robot is updated and stored on a webpage located at 192.168.4.1 and each robot is denoted by a number on the top cover corresponding to a robot on the webpage. Only the robots and ball located in the arena are displayed on the webpage and in any order.

The suggested route would involve:
-	Creating a web scrapper for 192.168.4.1 to receive pose data
-	Swarm football control system
-	PC-to-Robot communication
-	Basic robot locomotion

To test your system come to the arena and connect to the WiFi.
```
SSID: MONA_Arena
Password: MONA_Arena
```
Only 2 teams can test at a time.

Useful links to information, websites and examples can be found in the [info](info) folder.

For extra points, each team can fill out the MONA robot survey to provide feedback on the robots to help future development.

Winners will get prizes as well as their solution being hosted on the Ice9Robotics GitHub for people to reference in CV, LinkedIn and other mediums.


## Rules/Equipment:
-	Teams can use any resources online or otherwise to help them accomplish the task. 
-	Teams are not allowed to remove the plastic battery cover and robot identifier.
-	Teams are allowed to operate the robots on any table surface, on the ground away from foot traffic, or in the arena.
-	Teams are allowed to modify and add things to the MONA robots to help improve there chances given it doesn’t damage the system. (Extra points will be awarded to innovative software and hardware designs).
-	If the system or the battery become damaged in anyway report it to a supervisor (Purple shirt) and they will assist.
-	Teams will have access to 3D printers if they wish to use them. They will need to follow the 3D printing document on the GitHub.
-	Teams will have access to anything in the inventory which they may use in their solution.


