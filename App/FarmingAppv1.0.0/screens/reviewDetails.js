import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, Button, FlatList } from 'react-native';
import { globalStyles } from '../styles/global';


export default function ReviewDetails({ navigation }){
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

  return (
    <View>
      <TextInput style={globalStyles.subheader}
        value={postTitle}
        onChangeText={setPostTitle}
        placeholder="Enter post title"
      />
      <TextInput style={globalStyles.Forum_text}
        value={postText}
        onChangeText={setPostText}
        placeholder="Enter post text"
      />
      <Button title="Add Post" onPress={addPost} />

      <FlatList
        data={posts}
        renderItem={({ item: post }) => (
          <View key={post.id}>
            <Text>{post.title}</Text>
            <Text>{post.text}</Text>
            <Text>{post.time}</Text>
            {selectedPostId === post.id ? (
              <View>
                <TextInput style={globalStyles.Forum_comment_text}
                  value={commentText}
                  onChangeText={setCommentText}
                  placeholder="Enter a comment"
                />
                <Button title="Add Comment" onPress={addComment} />
              </View>
            ) : (
              <Button
                title="Add a Comment"
                onPress={() => setSelectedPostId(post.id)}
              />
            )}
            {post.comments.map((comment, index) => (
              <View key={index}>
                <Text>{comment.text}</Text>
                <Text>{comment.time}</Text>
              </View>
            ))}
          </View>
        )}
        keyExtractor={(post) => post.id.toString()}
      />
    </View>
  );
};