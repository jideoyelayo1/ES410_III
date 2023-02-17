function fertilise = detectsoilproperties(temperature, humidity, nitrogen, phosphorus, potassium) %#codegen
mdl = loadLearnerForCoder('TrainingDatasetv4.mat');
predictorValues = [temperature, humidity, nitrogen, phosphorus, potassium];
fertilise = predict(mdl,predictorValues);
end