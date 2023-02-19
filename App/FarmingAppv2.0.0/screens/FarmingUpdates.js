import React, { useState, useEffect } from 'react';
import { StyleSheet, View, Text, Button, TextInput,FlatList,SafeAreaView,ScrollView } from 'react-native';
import { globalStyles } from '../styles/global';
import axios from "axios";


export default function FarmingUpdates({ navigation }) {

  const [posts, setPosts] = useState([]);
  const [postTitle, setPostTitle] = useState("");
  const [postText, setPostText] = useState("");
  const [commentText, setCommentText] = useState("");
  const [selectedPostId, setSelectedPostId] = useState(null);

  const addPost = () => {
    if(postTitle === "" || postText === "") return alert("Please enter a title and text");
    setPosts([
      ...posts,
      {
        id: posts.length,
        title: postTitle,
        text: postText,
        comments: [],
        time: new Date().toLocaleString(),
      },
    ]);
    setPostTitle("");
    setPostText("");
  };

  const addComment = () => {
    if (commentText === "") return alert("Please enter a comment");
    setPosts(
      posts.map((post) =>
        post.id === selectedPostId
          ? {
              ...post,
              comments: [...post.comments, { text: commentText, time: new Date().toLocaleString() }],
            }
          : post
      )
    );
    setCommentText("");
    setSelectedPostId(null);
  };

  const pressHandler = () => {
    navigation.goBack();
  }
  
  const [weather, setWeather] = useState({});

  useEffect(() => {
    const fetchData = async () => {
      const { data } = await axios.get(
        "https://api.openweathermap.org/data/2.5/weather?q=mumbai&appid=0bb15373a22894cf2b9307790e67b5c2"
      );
      setWeather(data);
    };

    fetchData();
  }, []);

  const convertUnixToHM = (unix) => {
    var date = new Date(unix * 1000);
    var hours = date.getHours();
    var minutes = "0" + date.getMinutes();
    var seconds = "0" + date.getSeconds();
    var formattedTime = hours + ':' + minutes.substr(-2) + ':' + seconds.substr(-2);
    return formattedTime;
  }
  
  return (
    <SafeAreaView style={globalStyles.container}>
      <Text style={globalStyles.titleText}>Farming Updates{"\n"} </Text>
      
        <View>
      <TextInput style={globalStyles.Calc_buttons}
        value={postTitle}
        onChangeText={setPostTitle}
        placeholder="Enter post title"
      />
      <TextInput style={globalStyles.Forum_text}
        value={postText}
        onChangeText={setPostText}
        placeholder="Enter post text"
      />
      <Button title="Add Post" color='#c9efc7' onPress={addPost} />
      
      <View>
        <FlatList
        data={posts}
        renderItem={({ item: post }) => (
          <View key={post.id}>
            <Text style={globalStyles.subheader} >{post.title}</Text>
            <Text style={globalStyles.Forum_message_text}>{post.text}</Text>
            <Text>Posted at {post.time}</Text>
            {selectedPostId === post.id ? (
              <View>
                <TextInput style={globalStyles.Forum_comment_text}
                  value={commentText}
                  onChangeText={setCommentText}
                  placeholder="Enter a comment"
                />
                <Button title="Add Comment" color='#c9efc7' onPress={addComment} />
              </View>
            ) : (
              <Button
                title="Add a Comment"
                color='#c9efc7'
                onPress={() => setSelectedPostId(post.id)}
              />
            )}
            {post.comments.map((comment, index) => (
              <View key={index} style={globalStyles.Forum_sent_comment}>
                <Text >{comment.text}</Text>
                <Text >Posted at {comment.time}</Text>
              </View>
            ))}
          </View>
        )}
        keyExtractor={(post) => post.id.toString()}
      />
      </View>

      </View>
      
      
      <ScrollView>

      <Text style={globalStyles.subheader}>Weather Updates</Text>
      <View style={globalStyles.Farming_Alerts_box} color= '#c9efc7'>
      
      <Text>The temperature is {Math.round((weather.main && weather.main.temp - 273.15 )* 10) / 10}° in {weather.name},{weather.sys && weather.sys.country} 
      but it feels like {Math.round( (weather.main && weather.main.feels_like - 273.15 )* 10) / 10}°. Humidity is {weather.main && weather.main.humidity} and
       . </Text>
       <Text> Sunrise is at {convertUnixToHM(weather.sys && weather.sys.sunrise)} and sunset is at {convertUnixToHM(weather.sys && weather.sys.sunset)}.</Text>
       <Text> Wind speed is {weather.wind && weather.wind.speed} m/s and wind direction is {weather.wind && weather.wind.deg}°.</Text>
       <Text> The weather is {weather.weather && weather.weather[0].description}.</Text>
       <Text> The pressure is {weather.main && weather.main.pressure} hPa.</Text>
       <Text> The visibility is {weather.visibility} m.</Text>
       <Text> The cloudiness is {weather.clouds && weather.clouds.all} %.</Text>
       <Text> The rain in the last 1 hour is {weather.rain && weather.rain["1h"]} mm.</Text>
        <Text> The snow in the last 1 hour is {weather.snow && weather.snow["1h"]} mm.</Text>
      </View>
      <Button title='back to home screen' onPress={pressHandler} color= '#c9efc7' />
      </ScrollView>

    
    </SafeAreaView>
  );
}