import React from 'react';
import { StyleSheet, View, Text, Button } from 'react-native';
import { globalStyles } from '../styles/global';

export default function LoginMenu({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }
  const toMyAccount = () => {;navigation.push('MyAccount');  }
  const toMyOrders = () => {;navigation.push('MyOrders');  }
  const toCustomerService = () => {;navigation.push('CustomerService');  }
  const toGraphs = () => {;navigation.push('Graphs');  }


  return (
    <View style={globalStyles.container}>
      <Text style={globalStyles.titleText}>Login Menu</Text>
      <Button title='My Account' color='#c9efc7' onPress={toMyAccount} />
      <Button title='My orders' color='#c9efc7' onPress={toMyOrders} />
      <Button title='Graphs' color='#c9efc7' onPress={toGraphs} />
      <Button title='Customer Service' color='#c9efc7' onPress={toCustomerService} />
      
      <Button title='log out' color='#c9efc7' onPress={pressHandler} />
    </View>
  );
}