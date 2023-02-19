import React from 'react';
import { StyleSheet, View, Text, Button, TextInput,FlatList } from 'react-native';
import { globalStyles } from '../styles/global';

export default function MyOrders({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }

  const Devices = [
    { DeviceId: "L5H-ZJ7-M8P", ModelName: 'Tillage Tool Lite' ,DateAdded:'14-02-2023' ,DaysRemainingOnWarraty:7,id:1 },
    { DeviceId: "4W2-1E6-X9B", ModelName: 'Tillage Tool Lite' ,DateAdded:'14-02-2023',DaysRemainingOnWarraty:43, id:2},
    { DeviceId: "C8N-F0K-J7Z", ModelName: 'Tillage Tool 2.0' ,DateAdded:'14-02-2023' ,DaysRemainingOnWarraty:67,id:3},
    { DeviceId: "H9L-W7Q-E1M", ModelName: 'Till Tool Pro' ,DateAdded:'14-02-2023' ,DaysRemainingOnWarraty:532,id:4},
    { DeviceId: "Z2R-M8T-G6J", ModelName: 'Till Tool Pro' ,DateAdded:'14-02-2023' ,DaysRemainingOnWarraty:43,id:5},
  ];

  return (
    <View style={globalStyles.container}>
      <View>
      <Text style={globalStyles.titleText}>My Incoming Orders</Text>
      <Text>You have {0} incoming orders.</Text>
      </View>

      <Text>Want to add a new Device?</Text>
      <Text style={globalStyles.subheader}>Enter Device ID</Text><TextInput
      style={globalStyles.Calc_buttons}
                  placeholder="XXX-XXX-XXX"
                />

      <Text style={globalStyles.titleText}>My Devices</Text>

      <FlatList
        data={Devices}
        renderItem={({ item }) => (
          <View style={{ padding: 20 }}>
            <Text style={globalStyles.Product_titles} >{item.ModelName}</Text>
            <Text >Device ID: {item.DeviceId} {"\n"}Date Added:{item.DateAdded}</Text>
            <Text >Days Remaining on Warranty: {item.DaysRemainingOnWarraty}</Text>
          </View>
        )}
        keyExtractor={item => item.id.toString()}
        
      />
      
      <Button title='back' color='#c9efc7' onPress={pressHandler} />
    </View>
  );
}