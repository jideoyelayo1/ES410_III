import React,{useState,useEffect} from 'react';
import { StyleSheet, View, Text, Button,TextInput,AsyncStorage } from 'react-native';
import { globalStyles } from '../styles/global';



export default function newPost({ navigation }) {

  const pressHandler = () => {
    navigation.goBack();
  }

  const [user, setUser] = useState("");
  const [topic, setTopic] = useState("");
  const [msg, setMsg] = useState("");

 


  const Post = () => {
    if(user===""){
      alert("Invalid username");return;
    }
    if(topic===""){
        alert("Invalid topic");return;
    }
    if(msg===""){
        alert("Invalid message");return;
    }

    const account ={
        "username":user,
        "topic":topic,
        "message":msg,
      }
  
      postData(account)


    setUser("");setTopic("");setMsg("");
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
    alert("uploaded")
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
      <Text>Username:</Text><TextInput style={globalStyles.Calc_buttons}
      autoComplete="username"
      placeholder="Enter username"
        onChangeText={(value) => setUser(value)}
        value={user}
      />

      <Button title='Post' onPress={Post} color='#c9efc7'/>
      <Button title='back' onPress={pressHandler} color='#c9efc7' />
    </View>
  );
}