import React from 'react';
import { StatusBar } from 'expo-status-bar';
import { StyleSheet, Text, Button,SafeAreaView,Image,View } from 'react-native';
import { globalStyles } from '../styles/global';


export default function Home({ navigation }) {

  const toReviewDetails = () => {    navigation.push('MyOrders');  }
  const toFarmingUpdates = () => {    navigation.push('FarmingUpdates');  }
  const toLoginPage = () => {    navigation.push('LoginPage');  }
  const toAbout = () => {    navigation.push('About');  }
  const toCalc = () => {    navigation.push('Calculator');  }
  const toProductList = () => {    navigation.push('Product_List');  }
  const toContacts = () => {    navigation.push('Contacts');  }

  return (
    <SafeAreaView style={globalStyles.HomePage} >
      <StatusBar style={globalStyles.StatusBar} />
      <Image source={require("../assets/logo-no-background.png")}
      style={{width: "100%", height:160}} 
      />
      <Text style={globalStyles.titleText}>{"\n"}Insight,Interface,Intelligence Warwick{"\n"}The future of farming is growing nearer{"\n"}</Text>
      <View style={globalStyles.HomePage_buttons_wrap} >
      <Button title='About' onPress={toAbout} color='#c9efc7' style={globalStyles.HomePage_buttons}/>
      <Button title='Login' onPress={toLoginPage} color='#c9efc7' style={globalStyles.HomePage_buttons}/>
      <Button title='Farming Updates' onPress={toFarmingUpdates} color='#c9efc7' style={globalStyles.HomePage_buttons} />
      <Button title='Fertiliser Usage Calculator' onPress={toCalc} color='#c9efc7' style={globalStyles.HomePage_buttons}/>
      <Button title='Product List' onPress={toProductList} color='#c9efc7' style={globalStyles.HomePage_buttons}/>
      <Button title='Contacts' onPress={toContacts} color='#c9efc7' style={globalStyles.HomePage_buttons}/>
      
      <Text> *Still Under development*</Text>

      </View>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
    container: {
      flex: 1,
      padding:20,
      backgroundColor: '#fff',
      alignItems: 'center',
      justifyContent: 'center',
    },
  });