import React from 'react';
import { StyleSheet, View, Text,Button,Linking,Image,SafeAreaView,ScrollView } from 'react-native';
import { globalStyles } from '../styles/global';

export default function About({ navigation }) {
    const pressHandler = () => {
        navigation.goBack();
      }
      const gotoGithub = () => {
        Linking.openURL('https://github.com/jideoyelayo1/ES410_III');
      };
      
  return (
    <ScrollView style={globalStyles.container} >
      <SafeAreaView style={globalStyles.HomePage}>
      <Text style={globalStyles.titleText} >About Us</Text>
      

      <Image source={require("../assets/logo-no-background.png")}
      style={{width: "100%", height:160}} 
      />
      <Text style={globalStyles.header}>ES410: Insight, Interface, Intelligence Warwick – Group 5</Text>
      <Text>Low-Cost Smart Agricultural Sensing System for Small Holder Farms in South Asia</Text>

      <Text style={globalStyles.subheader}>Introduction</Text>
      <Text>
        The aim of this project is to design a low-cost smart agricultural sensing system for small-scale farms in South Asia, specifically focused on rice crops. The system will include sensors that can measure the nitrogen levels in the soil, as well as a radio frequency transceiver that can transmit this data to a central hub for processing. This data will be displayed on a graphical user interface (GUI) using data analysis techniques, providing the farmer with valuable information about the health of their soil. Machine learning models will also be used to predict future soil health, which will also be displayed on the GUI.
      </Text>

      <Text style={globalStyles.subheader}>Objectives</Text>
      <Text>The main objectives of the project are:</Text>
      <Text style={globalStyles.bullet}>
        * Research different options for sensors that can measure nitrogen levels in soil
      </Text>
      <Text style={globalStyles.bullet}>
        * Research different microcontrollers, displays, and machine learning models that can be used in the central hub
      </Text>
      <Text style={globalStyles.bullet}>
        * Design a printed circuit board (PCB) that can integrate the sensors, microcontrollers, RF transceiver, and power source
      </Text>
      <Text style={globalStyles.bullet}>
        * Design a GUI that can take user input and clearly display data
      </Text>
      <Text style={globalStyles.bullet}>
        * Develop methods for analyzing sensor data and use machine learning techniques to identify patterns and predict soil health
      </Text>
      <Text style={globalStyles.bullet}>
        * Test the integrated system and provide a proof of concept of the design
      </Text>
      
      <Text style={globalStyles.subheader}>Stretch Goals</Text>
      <Text style={globalStyles.bullet}>
        * Construct a fully-working prototype of the system
      </Text>
      <Text style={globalStyles.bullet}>
        * Connect the system to Wi-Fi to receive external data, such as weather data, for improved machine learning
      </Text>
      <Text style={globalStyles.bullet}>
        * Gather data from multiple sensors (e.g. temperature, humidity, moisture levels) and build an online database to store information from multiple sensor hubs.
      </Text>
      
      <Text style={globalStyles.subheader}>Project Description</Text>
      <Text style={globalStyles.subsubheader}>How the sensor works</Text>   
      <Text style={globalStyles.bullet}>...</Text>   

      <Text style={globalStyles.subsubheader}>What technologies were used</Text>
      <View style={globalStyles.bullet}>
        <Text>- Arduino IDE</Text>
        <Text>- Matlab</Text>
      </View>

      <Text style={globalStyles.subheader}>Challenges faced</Text>
      <View style={globalStyles.bullet}>
        <Text>NPK is given the same values repeatedly (we are assuming it is not working)</Text>
      </View>

      <Text style={globalStyles.subheader}>Credits</Text>
      <View style={globalStyles.bullet}>
        <Text>- Rhys Henwood: Project Lead and GUI Designer</Text>
        <Text>- Safura Colette: Radio-Frequency Engineer and PCB Designer</Text>
        <Text>- Jide Oyelayo: Sensor Hardware Engineer Lead</Text>
        <Text>- Kieran Lowe: Prototyping Engineer and Mechanical Design Engineer</Text>
        <Text>- Mawusi Ametewee: Machine Learning and Cloud Computing Lead</Text>
        <Text>- Anjali Gokal: Data Scientist and Machine Learning Data Researcher</Text>
      </View>
      <Text style={globalStyles.bullet}>
        This project was completed as part of the ES410 course at Warwick University. The research and development was conducted by Group 5, consisting of the individuals listed above. The project was supervised by Professor Jose Ortiz Gonzalez, who provided guidance and support throughout the project.
      </Text>
      <Text style={globalStyles.links} onPress={gotoGithub}>
      Visit Our GitHub Repo{"\n"}
      </Text>
      <Text 
        style={globalStyles.links}
        onPress={() => Linking.openURL('https://www.notion.so/invite/ad64deccb463d3e21adbe6e0b9dc0670409e2db7')}
      >
        Link to Notion which was used to track progress throughout the project.
      </Text>
      <Text>{"\n\n"}</Text>
      <Button title='back to home screen' color='#c9efc7' onPress={pressHandler} />
      <Text>{"\n\n\n"}</Text>
      </SafeAreaView>
    </ScrollView>
  );
}