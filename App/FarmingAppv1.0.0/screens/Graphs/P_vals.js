import React from 'react';
import { StyleSheet, View, Text, Button,SafeAreaView } from 'react-native';
import { globalStyles } from '../../styles/global';
import { LineChart, Grid } from 'react-native-chart-kit';

export default function P_vals({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }
  const data = {
    labels: ['Feb-09', 'Feb-10', 'Feb-11', 'Feb-12', 'Feb-13', 'Feb-14'],
    datasets: [
      {
        data: [2.5, 2.8, 2.7, 1.9, 2.3, 2.5],
      },
    ],
  };

  return (
    <SafeAreaView style={globalStyles.Graph_settings}>
      <Text style={globalStyles.titleText}>Phosphorus Values</Text>
      <LineChart
      data={data}
      width={375}
      height={220}
      chartConfig={{
        backgroundColor: '#31c48d',
        backgroundGradientFrom: '#31c48d',
        backgroundGradientTo: '#31c48d',
        decimalPlaces: 2,
        color: (opacity = 1) => `rgba(255, 255, 255, ${opacity})`,
        labelColor: (opacity = 1) => `rgba(255, 255, 255, ${opacity})`,
      }}
      style={{
        marginVertical: 8,
        borderRadius: 16,
      }}
    />
      
    </SafeAreaView>
  );
}