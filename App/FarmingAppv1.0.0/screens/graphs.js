import React from 'react';
import { StyleSheet, View, Text, Button,ScrollView,SafeAreaView } from 'react-native';
import { globalStyles } from '../styles/global';
import N_vals from './Graphs/N_val';
import P_vals from './Graphs/P_vals';
import K_vals from './Graphs/K_vals';
import Temperature from './Graphs/temp';
import Humidity from './Graphs/humd';

export default function Graph({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }

  return (
    <ScrollView style={globalStyles.Graph_settings}>
      <SafeAreaView >
        
      <N_vals/>      
      <P_vals/>
      <K_vals/>
      <Temperature/>
      <Humidity/>
      <Button title='back' color='#c9efc7' onPress={pressHandler} />

      </SafeAreaView>
    </ScrollView>
    
  );
}