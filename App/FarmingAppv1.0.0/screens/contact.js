import React,{useState,useEffect} from 'react';
import { StyleSheet, View, Text, Button,TextInput,AsyncStorage } from 'react-native';
import { globalStyles } from '../styles/global';


export default function Contacts({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }

  const [email, setEmail] = useState("");
  const [topic, setTopic] = useState("");
  const [msg, setMsg] = useState("");

 


  const Post = () => {
    if(email===""){
      alert("Invalid email");return;
    }
    if(topic===""){
        alert("Invalid topic");return;
    }
    if(msg===""){
        alert("Invalid message");return;
    }

    const account ={
        "email":email,
        "topic":topic,
        "message":msg,
      }
  
      postData(account)


    setEmail("");setTopic("");setMsg("");
    alert("Message sent")
  }

  const postData = async (account) => {
    try {
      await fetch('https://webhook.site/cb184155-4b78-4189-88aa-082822ad1c51', {
        method: 'post',
        mode: 'no-cors',
        headers: {
          Accept: 'application/json',
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({
          account
        }),
      });
    } catch (e) {
      alert(e);
    }
  };

  
  

  return (
    <View style={globalStyles.container}>
      <Text>New Post  Form</Text>
      <Text>Topic:</Text><TextInput style={globalStyles.Calc_buttons}
      placeholder="Create a topic"
        onChangeText={(value) => setTopic(value)}
        value={topic}
      />
      <Text>Message:</Text><TextInput style={globalStyles.Forum_text}
      placeholder="New Message"
        onChangeText={(value) => setMsg(value)}
        value={msg}
        numberOfLines={4}
        multiline={true}
      />
      <Text>Email:</Text><TextInput style={globalStyles.Calc_buttons}
      autoComplete="email"
      placeholder="Email "
        onChangeText={(value) => setEmail(value)}
        value={email}
      />

      <Button title='Post' color='#c9efc7' onPress={Post}/>
      <Button title='back' color='#c9efc7' onPress={pressHandler} />
    </View>
  );
}