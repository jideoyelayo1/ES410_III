import React, { useState } from 'react';

const generateFertiliserAdvice = ({ nitrogen, phosphorus, potassium }) => {
const fertilise = 'Add fertiliser';
const addNitrogen = (17 - nitrogen) * 700000 / 100000;
const addPhosphorus = (6 - phosphorus) * 700000 / 100000;
const addPotassium = (6 - potassium) * 700000 / 100000;

if (fertilise === 'Add fertiliser') {
  let fertiliseMessage = '';

  if (nitrogen < 17 && phosphorus < 5.5 && potassium < 5.5) {
    addNitrogen = addNitrogen / 4;
    addPhosphorus = addPhosphorus / 4;
    fertiliseMessage = `Apply ${addNitrogen.toFixed(1)} kg/ha of nitrogen fertiliser and apply ${addPhosphorus.toFixed(1)} kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Apply ${addPotassium.toFixed(1)} kg/ha of potassium fertiliser at basal stage.`;

  } else if (nitrogen < 17 && phosphorus < 5.5 && potassium > 5.5) {
    addNitrogen = addNitrogen / 4;
    addPhosphorus = addPhosphorus / 4;
    fertiliseMessage = `Apply ${addNitrogen.toFixed(1)} kg/ha of nitrogen fertiliser and apply ${addPhosphorus.toFixed(1)} kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough potassium in the soil.`;

  } else if (nitrogen < 17 && phosphorus > 5.5 && potassium < 5.5) {
    addNitrogen = addNitrogen / 4;
    fertiliseMessage = `Apply ${addNitrogen.toFixed(1)} kg/ha of nitrogen fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages and apply ${addPotassium.toFixed(1)} kg/ha of potassium fertiliser at basal stage. Enough phosphorus in the soil.`;

  } else if (nitrogen < 17 && phosphorus > 5.5 && potassium > 5.5) {
    addNitrogen = addNitrogen / 4;
    fertiliseMessage = `Apply ${addNitrogen.toFixed(1)} kg/ha of nitrogen fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough phosphorus and potassium in the soil.`;

  } else if (nitrogen > 17 && phosphorus < 5.5 && potassium < 5.5) {
    addPhosphorus = addPhosphorus / 4;
    fertiliseMessage = `Apply ${addPhosphorus.toFixed(1)} kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages and apply ${addPotassium.toFixed(1)} kg/ha of potassium fertiliser at basal stage. Enough nitrogen in the soil.`;

  } else if (nitrogen > 17 && phosphorus < 5.5 && potassium > 5.5) {
    addPhosphorus = addPhosphorus / 4;
    fertiliseMessage = `Apply ${addPhosphorus.toFixed(1)} kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and heading stages. Enough nitrogen and potassium in the soil.`;
  } else if (nitrogen > 17 && phosphorus > 5.5 && potassium < 5.5) {
    addPhosphorus = addPhosphorus / 4;
    fertiliseMessage = `Apply ${addPotassium.toFixed(1)} kg/ha of potassium fertiliser at basal stage. Enough nitrogen and phosphorus in the soil.`;
  }

  return (
    <View >
        <Text >${fertiliseMessage}</Text>
    </View>
  );


}
}
