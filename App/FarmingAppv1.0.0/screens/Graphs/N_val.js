import React from 'react';
import { StyleSheet, View, Text, Button,SafeAreaView } from 'react-native';
import { LineChart, Grid } from 'react-native-chart-kit';
import { globalStyles } from '../../styles/global';

export default function N_vals({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }
  const data = {
    labels:  ['Feb-09', 'Feb-10', 'Feb-11', 'Feb-12', 'Feb-13', 'Feb-14'],
    datasets: [
      {
        data: [1.9, 2.0, 2.15, 2.1, 2.4, 2.3],
      },
    ],
  };

  return (
    <SafeAreaView style={globalStyles.Graph_settings}>
      <Text style={globalStyles.titleText}>Nitrogen Values</Text>
      <LineChart
      data={data}
      width={375}
      height={220}
      chartConfig={{
        backgroundColor: '#c9efc7',
        backgroundGradientFrom: '#c9efc7',
        backgroundGradientTo: '#c9efc7',
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