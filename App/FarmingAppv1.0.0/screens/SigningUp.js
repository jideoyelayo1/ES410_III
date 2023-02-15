import React from "react";
import { StyleSheet,Text,View } from "react-native";

export default class SigningUp extends React.Component{
    
    async componentDidMount(){
        try {
            await fetch('https://webhook.site/cb184155-4b78-4189-88aa-082822ad1c51'),{
                method: 'post',
                mode:'no-cors',
                headers:{
                    'Accept':'application/json',
                    'Content-Type':'application/json'

                },
                body: JSON.stringify({
                    username:'Jide',
                    password:'pass',
                    
                })
            }
            
        } catch (e) {
            alert(e)
        }
    }

    render(){
        return(
            <View></View>
        )
    }
}