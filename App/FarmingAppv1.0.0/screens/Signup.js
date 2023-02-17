import React,{useState,useEffect} from 'react';
import { StyleSheet, View, Text, Button,TextInput,AsyncStorage } from 'react-native';
import { globalStyles } from '../styles/global';
import { Checkbox } from 'react-native-paper';



export default function SignUp({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }
  const toTermsOfService = () =>{
    navigation.push('TermsOfService');
  }

  const [user, setUser] = useState("");
  const [email, setEmail] = useState("");
  const [pwd, setPwd] = useState("");
  const [Cnfpwd, setCnfPwd] = useState("");
  const [checked, setChecked] = useState(false);

 


  const SigningUp = () => {
    if(user===""){
      alert("Invalid username");return;
    }
    if(email===""){
      alert("Invalid Email");return;
    }
    if(pwd===""){
      alert("Invalid Password");return;
    }
    if(Cnfpwd===""){
      alert("Confirm Password");return;
    }
    if(pwd !== Cnfpwd){
      setPwd("");setCnfPwd("");
      alert("Passwords do not match"); return;
    }
    if(checked===false){
      alert("You have not agreed to terms of service");return;
    }      
    
    //
    //alert("This has not been implemented yet");
    const account ={
      "name":user,
      "password":pwd,
      "iD":Math.floor(Math.random() * (1000000 - 0 + 1)) + 0,
      "DeviceIDs":[]
    }

    //postData(account) 
    setUser("");setCnfPwd("");setPwd("");setEmail("");setChecked(false); 
    
  
  
  }

  const postData = async (newAccount) => {
      fetch('http://localhost:3000/accounts', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify(newAccount)
  })
  .then(response => response.json())
  .then(data => console.log(data))
  .catch(error => console.error(error));
  };
  

  
  

  return (
    <View style={globalStyles.container}>
      <Text style={globalStyles.titleText}>Create an Account</Text>
      <Text>Username:</Text><TextInput style={globalStyles.Calc_buttons}
      placeholder="Username"
      autoComplete="username"
        onChangeText={(value) => setUser(value)}
        value={user}
      />
      <Text>Email:</Text><TextInput style={globalStyles.Calc_buttons}
      placeholder="username123@email.com"
      autoComplete="email"
        onChangeText={(value) => setEmail(value)}
        value={email}
      />
      <Text>Password:</Text><TextInput style={globalStyles.Calc_buttons}
      secureTextEntry={true}
      placeholder="Enter password"
        onChangeText={(value) => setPwd(value)}
        value={pwd}
      />
      <Text>Confirm Password:</Text><TextInput style={globalStyles.Calc_buttons}
      secureTextEntry={true}
      placeholder="Enter password"
        onChangeText={(value) => setCnfPwd(value)}
        value={Cnfpwd}
      />
      <Button title='Agree to Terms and Conditions:' color='#c9efc7' onPress={toTermsOfService}/>
      <Checkbox style={globalStyles.checkbox}
        status={checked ? 'checked' : 'unchecked'}
        onPress={() => {
          setChecked(!checked);
        }}
      />

      <Button title='Submit' color='#c9efc7' onPress={SigningUp}/>
      <Button title='back' color='#c9efc7' onPress={pressHandler} />
    </View>
  );
}