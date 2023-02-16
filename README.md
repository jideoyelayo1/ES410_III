![logo-no-background](https://user-images.githubusercontent.com/41443216/207383351-564382f6-e482-47be-8a85-25595eddfa14.png)

<h1>ES410: Insight, Interface, Intelligence Warwick – Group 5</h1>
Low-Cost Smart Agricultural Sensing System for Small Holder Farms in South Asia

<h2>Introduction</h2>
<p>The aim of this project is to design a low-cost smart agricultural sensing system for small-scale farms in South Asia, specifically focused on rice crops. The system will include sensors that can measure the nitrogen levels in the soil, as well as a radio frequency transceiver that can transmit this data to a central hub for processing. This data will be displayed on a graphical user interface (GUI) using data analysis techniques, providing the farmer with valuable information about the health of their soil. Machine learning models will also be used to predict future soil health, which will also be displayed on the GUI.</p>

<h2>Objectives</h2>
The main objectives of the project are:
	
- [x]  Research different options for sensors that can measure nitrogen levels in soil (WP1)
- [x]  Research different microcontrollers, displays, and machine learning models that can be used in the central hub (WP2)
- [x]  Design a printed circuit board (PCB) that can integrate the sensors, microcontrollers, RF transceiver, and power source (WP1 & WP2)
- [x]  Design a GUI that can take user input and clearly display data (WP2)
- [x]  Develop methods for analyzing sensor data and use machine learning techniques to identify patterns and predict soil health (WP3)
- [x]  Test the integrated system and provide a proof of concept of the design (WP2)
<h2>Stretch Goals</h2>

- [ ]  Construct a fully-working prototype of the system (All)
- [ ]  Connect the system to Wi-Fi to receive external data, such as weather data, for improved machine learning (WP2 & WP3)
- [x]  Gather data from multiple sensors (e.g. temperature, humidity, moisture levels) and build an online database to store information from multiple sensor hubs. (WP2)
<h2>Project Description</h2>
<h3> How the sensors works </h3>
<h4>DHT11</h4>

<h3> What technologies were used </h3>

* Arduino IDE (C/ C++)
* Matlab 
* React Native (React JS)
* Altium 
* AutoDesk Fusion 360
* ...

...
<h3> Challenges faced </h3>

* NPK is given the same values repeatedly (we are assuming it is not working)
* Due to the cost restrictions it is difficult to  accurately test the NPK sensor because that would require buying another NPK sensor
* Issues with MCU (only 2/3 boards work) which lead to a problems with RF testing (was resolved by changing the board)
* Issues converting MATLAB ML mode to C ( the MATLAB to C code result was trying to write into illegal memory)
* React-Native mobile App issue with pulishing (Unable to publish to expo without SDK error issue)
* React-Native mobile App requried a lot of non native libraries and dependancies which led to errors ( but still was preferable to Flutter because of knowlegde of javascript in the group) 
* Issue with running the app on the web because of react-native imports. A website in react Js is undevelopment.
* Issue with completion of mechanical goals - ...
* 

...


<h2> Credits </h2>

* Rhys Henwood: Project Lead and GUI Designer
* Safura Colette: Radio-Frequency Engineer and PCB Designer
* Jide Oyelayo: Sensor Hardware Engineer Lead
* Kieran Lowe: Prototyping Engineer and Mechanical Design Engineer
* Mawusi Ametewee: Machine Learning and Cloud Computing Lead 
* Anjali Gokal: Data Scientist and Machine Learning Data Researcher
</br>
This project was completed as part of the ES410 course at Warwick University. The research and development was conducted by Group 5, consisting of the individuals listed above. The project was supervised by Professor Jose Ortiz Gonzalez, who provided guidance and support throughout the project.

[Link to Notion which was used to track progress throughout the project.](https://www.notion.so/invite/ad64deccb463d3e21adbe6e0b9dc0670409e2db7)

