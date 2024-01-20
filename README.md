# Sunrise Alarm Clock V3

**Table of Contents**

- [Introduction](#introduction)
- [Brief](#brief)
- [Development Roadmap](#development-roadmap)
- [Circuitry](#circuitry)
  - [Schematics](#schematics)
    - [Main PCB](#main-pcb)
    - [Button PCB](#button-pcb)
    - [Light PCB](#light-pcb)
  - [PCB Design](#pcb-design)
    - [Main PCB](#main-pcb-1)
    - [Button PCB](#button-pcb-1)
    - [Light PCB](#light-pcb-1)
  - [Soldering](#soldering)
    - [Main PCB](#main-pcb-2)
    - [Button PCB](#button-pcb-2)
    - [Light PCB](#light-pcb-2)
- [Enclosure](#enclosure)
  - [CAD Enclosure](#cad-enclosure)
  - [Assembled Enclosure](#assembled-enclosure)
- [Code](#code)
  - [Documentation](#documentation)
- [Further Work](#further-work)


## Introduction

This is the third version of the "Sunrise Alarm Clock" project. [The first version](https://github.com/SeanP2001/Arduino_Sunrise_Alarm_Clock) used an Arduino Mega and an LCD keypad shield. [The second version](https://github.com/SeanP2001/Sunrise_Alarm_Clock_V2) used a Wemos D1 mini (ESP8266) and 0.96" OLED on a single custom PCB. This design was fully functional but it did not look like an alarm clock. I started version 3 with the aim of making the alarm look more premium. 

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/V1_Alarm.jpg" alt="Alarm V1" style="width: 30%; object-fit: contain;">
    <img src="./Images/V2_Alarm.jpg" alt="Alarm V2" style="width: 30%; object-fit: contain;">
    <img src="./Images/V3_Alarm_Idea_Render.png" alt="Alarm V3 Concept" style="width: 30%; object-fit: contain;">
</div>
<p align="center"><i>Alarm V1, Alarm V2 and Alarm V3 Concept</i></p>

This project was sponsored by PCBWay. To order high-quality, custom PCBs go to [PCBWay.com](https://www.pcbway.com/)

## Brief

The alarm needed to:
- Tell the time
- Use a real-time clock (RTC) to keep the time 
- Use an NTP server to update the time periodically
- Include a larger, 1.5" OLED 
- Include three capacitive touch buttons
- Include two timed USB ports
- Include a bright ringlight on the clock face
- Include a buzzer
- Have a premium feel

## Development Roadmap

The following roadmap outlines the planned milestones for the project. Each step includes testing and documenting.

| **Version**   | **Description**                                            |
|---------------|------------------------------------------------------------|
| V3.1-alpha    | Capture Schematic                                          |
| V3.2-alpha    | Design Main PCB                                            |
| V3.3-alpha    | Design Light PCB                                           |
| V3.4-alpha    | Design Button PCB                                          |
| V3.5-alpha    | Design and Fabricate Enclosure                             |
| V3.6-alpha    | Solder and Assemble                                        |
| V3.7-alpha    | Test Hardware and Document                                 |
| V3.8-alpha    | Program Inputs and Outputs                                 |
| V3.9-alpha    | Implement App Infrastructure                               |
| V3.10-alpha   | Develop Alarm App                                          |
| V3.11-alpha   | Develop Light App                                          |
| V3.12-alpha   | Develop USB App                                            |
| V3.13-alpha   | Develop Settings App                                       |
| V3.14-alpha   | Implement WiFi, NTP Time Sync and Settings Portal          |
| V3.0-release  | Initial Release (Document, Test and Fix Bugs)              |

## Circuitry

### Schematics

#### Main PCB

<p align="center">
  <img src="./Images/PCB/Main_PCB_Schematic.png" />
</p>

#### Button PCB

<p align="center">
  <img src="./Images/PCB/Button_PCB_Schematic.png" />
</p>

#### Light PCB

<p align="center">
  <img src="./Images/PCB/Light_PCB_Schematic.png" />
</p>


### PCB Design

#### Main PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Main_PCB_Design_Front.png" alt="Main PCB Front" style="width: 49%; object-fit: contain; margin-right: 5px;">
    <img src="./Images/PCB/Main_PCB_Design_Back.png" alt="Main PCB Back" style="width: 49%; object-fit: contain; margin-left: 5px;">
</div>
<p align="center"><i>Main PCB Front and Back</i></p>

#### Button PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Button_PCB_Design_Front.png" alt="Main PCB Front" style="width: 49%; object-fit: contain; margin-right: 5px;">
    <img src="./Images/PCB/Button_PCB_Design_Back.png" alt="Main PCB Back" style="width: 49%; object-fit: contain; margin-left: 5px;">
</div>
<p align="center"><i>Button PCB Front and Back</i></p>

#### Light PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Light_PCB_Design_Front.png" alt="Main PCB Front" style="width: 49%; object-fit: contain; margin-right: 5px;">
    <img src="./Images/PCB/Light_PCB_Design_Back.png" alt="Main PCB Back" style="width: 49%; object-fit: contain; margin-left: 5px;">
</div>
<p align="center"><i>Light PCB Front and Back</i></p>

### Soldering

I was really impressed by the quality of the PCBs sent by PCBWay. To order high-quality, custom PCBs go to [PCBWay.com](https://www.pcbway.com/). 

#### Main PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Main_PCB_Front.jpg" alt="Main PCB Front" style="width: 49%; object-fit: cover; margin-right: 5px;">
    <img src="./Images/PCB/Main_PCB_Back.jpg" alt="Main PCB Back" style="width: 49%; object-fit: cover; margin-left: 5px;">
</div>
<p align="center"><i>Main PCB Front and Back</i></p>

<p align="center">
  <img src="./Images/PCB/Main_PCB_Soldered.jpg" />
</p>
<p align="center"><i>Main PCB Soldered</i></p>

#### Button PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Button_PCB_Front.jpg" alt="Main PCB Front" style="width: 49%; object-fit: cover; margin-right: 5px;">
    <img src="./Images/PCB/Button_PCB_Back.jpg" alt="Main PCB Back" style="width: 49%; object-fit: cover; margin-left: 5px;">
</div>
<p align="center"><i>Button PCB Front and Back</i></p>

<p align="center">
  <img src="./Images/PCB/Button_PCB_Soldered.jpg" />
</p>
<p align="center"><i>Button PCB Soldered</i></p>

#### Light PCB

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/PCB/Light_PCB_Front.jpg" alt="Main PCB Front" style="width: 49%; object-fit: cover; margin-right: 5px;">
    <img src="./Images/PCB/Light_PCB_Back.jpg" alt="Main PCB Back" style="width: 49%; object-fit: cover; margin-left: 5px;">
</div>
<p align="center"><i>Light PCB Front and Back</i></p>

<p align="center">
  <img src="./Images/PCB/Light_PCB_Soldered.jpg" />
</p>
<p align="center"><i>Light PCB Soldered</i></p>

## Enclosure

### CAD Enclosure

<div style="display: flex; justify-content: space-between;">
    <img src="./Images/CAD/Enclosure_Front.png" alt="Alarm Enclosure Front" style="width: 30%; object-fit: contain;">
    <img src="./Images/CAD/Enclosure.png" alt="Alarm Enclosure" style="width: 30%; object-fit: contain;">
    <img src="./Images/CAD/Enclosure_Back.png" alt="Alarm Enclosure Back" style="width: 30%; object-fit: contain;">
</div>
<div style="display: flex; justify-content: space-between; margin-top: 10px;">
    <img src="./Images/CAD/Enclosure_Open_Front_2.png" alt="Alarm Enclosure Open Front" style="width: 30%; object-fit: contain;">
    <img src="./Images/CAD/Enclosure_Open.png" alt="Alarm Enclosure Open" style="width: 30%; object-fit: contain;">
    <img src="./Images/CAD/Enclosure_Open_Front.png" alt="Alarm Enclosure Open Front" style="width: 30%; object-fit: contain;">
</div>

### Assembled Enclosure

<div style="display: flex; justify-content: center;">
    <img src="./Images/Alarm_2.jpg" style="width: 49%; object-fit: cover;">
    <img src="./Images/Alarm_Light_On.jpg" style="width: 49%; object-fit: cover;">
</div>
<div style="display: flex; justify-content: center;">
    <img src="./Images/Alarm_Front.jpg" alt="Alarm V1" style="width: 49%; object-fit: cover;">
    <img src="./Images/Alarm_Front_Light_On.jpg" alt="Alarm V2" style="width: 49%; object-fit: cover;">
</div>

## Code

### Documentation

View the Doxygen documentation for this project [here](https://raw.githack.com/SeanP2001/Sunrise_Alarm_Clock_V3/main/Code/Documentation/html/index.html).

## Further Work

In future I would like to;
- Change the design to not use vinyl as it is difficult to get a perfect result using it.
- Add software functions:
  - Wake up games
  - Daily weather forecast
  - Daily calendar events
  - Log sleep and wake times
  - Mood tracker
  - Habit tracker