import { StyleSheet } from 'react-native';

export const globalStyles = StyleSheet.create({
  titleText: {
    fontSize: 20,
    fontWeight: 'bold',
    color: '#333',
    textAlign: 'center',
  },
  paragraph: {
    marginVertical: 8,
    lineHeight: 20,
  },
  container: {
    flex: 200,
    padding: 20,
    width:"100%",
    backgroundColor: '#31c48d',
  },
  Calc_buttons: { 
    height: 40, 
    borderColor: '#31c48d', 
    borderWidth: 1, 
    backgroundColor: 'white',
  },
Product_titles: {
   fontSize: 24, 
   fontWeight: 'bold',
},
Product_cost: {
  fontSize: 11, 
  fontWeight: 'bold',
},
Product_info: {
  fontSize: 11, 
},
links: {
  color: '#c9efc7',
  textDecorationLine: 'underline',
},
header: {
  color: 'Green',
  textDecorationLine: 'underline',
  fontSize:24,
},
subheader: {
  color: 'black',
  textDecorationLine: 'underline',
  fontSize:18,
},
bullet: {
  color: 'black',
},
subsubheader: {
  color: 'black',
  textDecorationLine: 'underline',
  fontSize:14,
},
checkbox: {
  borderWidth: 1,
  borderColor: 'grey',
  padding: 10,
  borderRadius: 5,
  flexDirection: 'row',
  alignItems: 'center',
  backgroundColor:'black',
},
text: {
  marginLeft: 10,
},
Forum_text: { 
  height: 120,  
  borderWidth: 3, 
  borderColor: '#c9efc7',
  backgroundColor: 'white',
},
HomePage_buttons: {
  flex: 1,
  justifyContent: 'space-between',
  alignItems: 'center',
  width:"100%",
  fontSize: 24,
  borderWidth: 1,
  backgroundColor: '#528265',
  fontWeight: 'bold',
  color: '#c9efc7',
},
HomePage: {
  flex: 200,
  padding: 20,
  width:"100%",
  backgroundColor: '#528265',
  color:'#c9efc7',
},
HomePage_buttons_wrap:{
  flex: 1,
  flexDirection: 'column',
  justifyContent: 'space-between',
  alignItems: 'center',
  width:"100%",
  fontSize: 24,
  borderWidth: 10,
  borderColor: '#31c48d',
  backgroundColor: '#528265',
  fontWeight: 'bold',
},
StatusBar: {
  backgroundColor: '#31c48d',
  color: '#31c48d',
},
Graph_settings:{
  backgroundColor: 'white',
},
Farming_Alerts_box: {
  flex: 1,
  flexDirection: 'column',

  alignItems: 'center',
  width:"100%",
  fontSize: 24,
  borderWidth: 10,
  borderColor: '#31c48d',
  backgroundColor: '#528265',
  fontWeight: 'bold',
  color: '#c9efc7',
},
Forum_comment_text: {
  height: 60,  
  borderWidth: 3, 
  borderColor: '#c9efc7',
  backgroundColor: 'white',
},
Forum_message_text: {  
  borderWidth: 3, 
  borderColor: 'black',
  backgroundColor: '#c9efc7',
},
Forum_sent_comment: {  
  borderWidth: 3, 
  borderColor: 'black',
  backgroundColor: '#c9efc7',
},


});