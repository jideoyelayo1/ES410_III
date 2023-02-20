load detectsoilproperties_data.mat % loads training dataset of temperature, humidity and NPK values as predictors, labels as the estimators

ctree = fitctree(sensordata, labels); % creates decision tree based on training dataset
view(ctree);
view(ctree, 'Mode','graph'); % plots trained decision tree model

saveLearnerForCoder(ctree,'detectsoilproperties_trainingdata'); % saves model for C-code generation