load detectsoilproperties_testdata.mat

temperature = temperature'; % load test data
humidity = humidity';
nitrogen = nitrogen';
phosphorus = phosphorus';
potassium = potassium';

for i = 1:20 % creates a for loop to create a decision for each test case
fertiliseDecisions(i) = detectsoilproperties(temperature(i), humidity(i), nitrogen(i), phosphorus(i), potassium(i));
end

compare = strcmpi(fertiliseDecisions,testcases'); % compares decision tree output with true decisions
correctPrediction = find(compare > 0);
correctValues = length(correctPrediction); % finds the number of incorrect predictions

testValidatonAccuracy = (correctValues/20)*100; % calculates validation accuracy of test