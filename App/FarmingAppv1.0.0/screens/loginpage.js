import React,{useState,useEffect} from 'react';
import { StyleSheet, View, Text, Button,TextInput,SafeAreaView,ScrollView } from 'react-native';
import { globalStyles } from '../styles/global';
import axios from 'axios';


export default function LoginPage({ navigation }) {

  const pressHandler = () => { navigation.goBack(); }  
  const toSignUp = () => {;navigation.push('SignUp');  }
 

  const [user, setUser] = useState("");
  const [pwd, setPwd] = useState("");




  const toLoginMenu = () => {
    
    
    if(user !== "Jim" && pwd !== "Pass"){
      alert("Invalid Username or Password");
      setUser("");setPwd("");
      return;
    }
    setUser("");setPwd("");
    navigation.push('LoginMenu');  
  
  }

  const retrieveData = async () => {

  };

  


  return (
    <ScrollView style={globalStyles.container}>

      <Text style={globalStyles.titleText}>Login Page</Text>
      <Text>Username</Text><TextInput style={globalStyles.Calc_buttons}
      autoComplete="username"
      placeholder="Enter username"
      autoCompleteType="username"
        onChangeText={(value) => setUser(value)}
        value={user}
      />
      <Text>Password</Text><TextInput style={globalStyles.Calc_buttons}
      secureTextEntry={true}
      placeholder="Enter password"
      autoCompleteType="password"
        onChangeText={(value) => setPwd(value)}
        value={pwd}
      />

      <Button title='Log In' color='#c9efc7' onPress={toLoginMenu} />
      <Button title='Sign Up' color='#c9efc7' onPress={toSignUp} />

    <Text> Login Example: {"\n"}Username:"Jim" Password:"Pass"</Text>

      <Button title='back to home screen' color='#c9efc7' onPress={pressHandler} />
    </ScrollView>
  );
}