import React from 'react';
import { StyleSheet, View, Text, Button, FlatList,SafeAreaView,ScrollView } from 'react-native';
import { globalStyles } from '../styles/global';

export default function Product_List({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }
  const products = [
    { id: 1, name: 'Farming Support' ,price:'0.00' ,info:"free online service for support" },
    { id: 2, name: 'Tillage Tool Lite' ,price:'50.00',info:"Basic NPK and temperature sensor" },
    { id: 3, name: 'Tillage Tool 2.0' ,price:'70.00' ,info:"Comes loaded with latest AI farming assist, Machine modelings to track soil levels"},
    { id: 4, name: 'Till Tool Pro' ,price:'100.00' ,info:"Now with WIFI support and 24/7 Customer service"},
    { id: 5, name: 'Machine Learning Online' ,price:'0.00' ,info:"Coming Soon"},
  ];


  return (
      <SafeAreaView style={globalStyles.HomePage}>

      <FlatList
        data={products}
        renderItem={({ item }) => (
          <View style={{ padding: 20 }}>
            <Text style={globalStyles.Product_titles} >{item.name}</Text>
            <Text style={globalStyles.Product_cost}>Costs only £{item.price}</Text>
            <Text style={globalStyles.Product_info}>{item.info}</Text>
          </View>
        )}
        keyExtractor={item => item.id.toString()}
        
      />
      <Button title='back to home screen'  color='#c9efc7' onPress={pressHandler} />
      </SafeAreaView>
    
  );
}