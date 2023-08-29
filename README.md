# Autonomous-Garden
### An autonomous garden project I made for my mom a few years back to address the chronic underwatering of our indoor plants.

My family loves indoor plants, but due to our busy schedules we often forgot to water them consistently. At the time, I was doing a lot of planning on building an internet-enabled hydroponic system for my mom, but wanted a smaller project to learn from before I did so. I ended up deciding on creating this garden box. 

As one of my first 'official' microcontroller projects, I wrote this simple program to actively monitor a bed of indoor plants and water them as necessary. It was written in the Arduino programming language, a variant of C++. 

I first built the plant box from cedar wood and fashioned a metal 'control panel' in the front of it to power the box on, indicate its status, and provide control via potentiometer knob to adjust how wet to set the soil moisture level. The internal water pump received signals from the Arduino Uno MCU whenever the soil was in need of watering (as detected by the resistance value between two metal prongs embedded in the soil), and would then trigger the water pump through a motor driver. 

I actually used an air pump, which would increase the pressure in a sealed internal 'water reservoir' (i.e. a repurposed vitamin bottle), and as the air pressure increased, the water would exit the reservoir via rubber tube, which was directed in a vein below the soil to evenly water the bed. 
