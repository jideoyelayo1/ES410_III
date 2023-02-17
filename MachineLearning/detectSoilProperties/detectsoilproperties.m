function fertilise = detectsoilproperties(temperature, humidity, nitrogen, phosphorus, potassium) %#codegen
mdl = loadLearnerForCoder('TrainingDatasetv4.mat'); % imports trained decision tree model
predictorValues = [temperature, humidity, nitrogen, phosphorus, potassium]; % takes inputs of predictors from sensors or numerical input
fertilise = predict(mdl,predictorValues); % uses model to make a decision and output the decision for the farmer
end