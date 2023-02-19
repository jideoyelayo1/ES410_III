import Reac, { useState } from 'react';
import { StyleSheet, View, Text, Button,TextInput,Keyboard,KeyboardAvoidingView  } from 'react-native';
import { globalStyles } from '../styles/global';
import {generateFertiliserAdvice} from './AI_fert'


export default function Calculator({ navigation }) {

  const pressHandler = () => { navigation.goBack(); }


    const [N_val, setN_val] = useState(0.0);
    const [P_val, setP_val] = useState(0.0);
    const [K_val, setK_val] = useState(0.0);
    const [sum, setSum] = useState(0.0);
    const [fertMsg, SetfertMsg] = useState("");
    

 
  const handleSubmit = (e) => {
    e.preventDefault();
    //console.log(setN_val+setP_val+setK_val);
    //alert(N_val+P_val+K_val);
    setSum(N_val + P_val + K_val);

    let fertilise = 'Add fertiliser';
    let addN_val = (17 - N_val) * 700000 / 100000;
    let addP_val = (6 - P_val) * 700000 / 100000;
    let addK_val = (6 - K_val) * 700000 / 100000;

    if (fertilise === 'Add fertiliser') {
        let fertiliseMessage = '';

        if (N_val < 17 && P_val < 5.5 && K_val < 5.5) {
            addN_val = addN_val / 4;
            addP_val = addP_val / 4;
            fertiliseMessage = `Apply ${addN_val.toFixed(1)} kg/ha of N_val fertiliser and apply ${addP_val.toFixed(1)} kg/ha of P_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Apply ${addK_val.toFixed(1)} kg/ha of K_val fertiliser at basal stage.`;

        } else if (N_val < 17 && P_val < 5.5 && K_val > 5.5) {
            addN_val = addN_val / 4;
            addP_val = addP_val / 4;
            fertiliseMessage = `Apply ${addN_val.toFixed(1)} kg/ha of N_val fertiliser and apply ${addP_val.toFixed(1)} kg/ha of P_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough K_val in the soil.`;

        } else if (N_val < 17 && P_val > 5.5 && K_val < 5.5) {
            addN_val = addN_val / 4;
            fertiliseMessage = `Apply ${addN_val.toFixed(1)} kg/ha of N_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages and apply ${addK_val.toFixed(1)} kg/ha of K_val fertiliser at basal stage. Enough P_val in the soil.`;

        } else if (N_val < 17 && P_val > 5.5 && K_val > 5.5) {
            addN_val = addN_val / 4;
            fertiliseMessage = `Apply ${addN_val.toFixed(1)} kg/ha of N_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough P_val and K_val in the soil.`;

        } else if (N_val > 17 && P_val < 5.5 && K_val < 5.5) {
            addP_val = addP_val / 4;
            fertiliseMessage = `Apply ${addP_val.toFixed(1)} kg/ha of P_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages and apply ${addK_val.toFixed(1)} kg/ha of K_val fertiliser at basal stage. Enough N_val in the soil.`;

        } else if (N_val > 17 && P_val < 5.5 && K_val > 5.5) {
            addP_val = addP_val / 4;
            fertiliseMessage = `Apply ${addP_val.toFixed(1)} kg/ha of P_val fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough N_val and K_val in the soil.`;
        } else if (N_val > 17 && P_val > 5.5 && K_val < 5.5) {
            addP_val = addP_val / 4;
            fertiliseMessage = `Apply ${addK_val.toFixed(1)} kg/ha of K_val fertiliser at basal stage. Enough N_val and P_val in the soil.`;
        }else{
          fertiliseMessage = `Invalid Results`;
        }

        SetfertMsg(fertiliseMessage);
        //alert(fertMsg)
        Keyboard.dismiss();



    }
}


  return (
    <KeyboardAvoidingView  style={globalStyles.container}>
      <Text style={globalStyles.titleText}>Tillage Tool Calculator</Text>
      <Text>Nitrogen levels (mg/kg):</Text><TextInput style={globalStyles.Calc_buttons}
        onChangeText={(value) => setN_val(value)}
        value={N_val}
        placeholder='0.0'
        keyboardType='numeric'
      />
      <Text>Phorphous levels (mg/kg):</Text><TextInput style={globalStyles.Calc_buttons}
        onChangeText={(value) => setP_val(value)}
        value={P_val}
        placeholder='0.0'
        keyboardType='numeric'
      />
      <Text>Potassium levels (mg/kg):</Text><TextInput style={globalStyles.Calc_buttons}
        onChangeText={(value) => setK_val(value)}
        value={K_val}
        placeholder='0.0'
        keyboardType='numeric'
      />
      <Button title='Run' color='#c9efc7' onPress={handleSubmit} />
      <Text>{fertMsg}</Text>
      <Button title='back to home screen' color='#c9efc7' onPress={pressHandler} />
    </KeyboardAvoidingView >
  );
}