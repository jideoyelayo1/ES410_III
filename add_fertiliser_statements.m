if strcmp('Add fertiliser', fertilise)
    if nitrogen < 17 && phosphorus < 5.5 && potassium < 5.5
        add_nitrogen = (17 - nitrogen)*700000/100000;
        formatspec = ['Apply %.1f kg/ha of nitrogen fertiliser and apply %.1f kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages. Apply %.1f kg/ha of potassium fertiliser at basal stage.'];
        add_nitrogen = add_nitrogen/4;
        add_phosphorus = (6 - phosphorus)*700000/100000;
        add_phosphorus = add_phosphorus/4;
        add_potassium = (6 - potassium)*700000/100000;
        fertilise = {sprintf(formatspec, add_nitrogen, add_phosphorus, add_potassium)};
        
    elseif nitrogen < 17 && phosphorus < 5.5 && potassium > 5.5
        add_nitrogen = (17 - nitrogen)*700000/100000;
        add_nitrogen = add_nitrogen/4;
        add_phosphorus = (6 - phosphorus)*700000/100000;
        add_phosphorus = add_phosphorus/4;
        formatspec = ['Apply %.1f kg/ha of nitrogen fertiliser and apply %.1f kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages. Enough potassium in the soil.'];
        fertilise = {sprintf(formatspec, add_nitrogen, add_phosphorus)};

    elseif nitrogen < 17 && phosphorus > 5.5 && potassium < 5.5
        add_nitrogen = (17 - nitrogen)*700000/100000;
        add_nitrogen = add_nitrogen/4;
        add_potassium = (6 - potassium)*700000/100000;
        formatspec = ['Apply %.1f kg/ha of nitrogen fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages and apply %.1f kg/ha of potassium fertiliser at basal stage. Enough phosphorus in the soil.'];
        fertilise = {sprintf(formatspec, add_nitrogen, add_potassium)};

    elseif nitrogen < 17 && phosphorus > 5.5 && potassium > 5.5
        add_nitrogen = (17 - nitrogen)*700000/100000;
        add_nitrogen = add_nitrogen/4;
        formatspec = ['Apply %.1f kg/ha of nitrogen fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages. Enough phosphorus and potassium in the soil.'];
        fertilise = {sprintf(formatspec, add_nitrogen)};

    elseif nitrogen > 17 && phosphorus < 5.5 && potassium < 5.5
        add_phosphorus = (6 - phosphorus)*700000/100000;
        add_phosphorus = add_phosphorus/4;
        add_potassium = (6 - potassium)*700000/100000;
        formatspec = ['Apply %.1f kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages and apply %.1f kg/ha of potassium fertiliser at basal stage. Enough nitrogen in the soil.'];
        fertilise = {sprintf(formatspec, add_phosphorus, add_potassium)};

    elseif nitrogen > 17 && phosphorus < 5.5 && potassium > 5.5
        add_phosphorus = (6 - phosphorus)*700000/100000;
        add_phosphorus = add_phosphorus/4;
        formatspec = ['Apply %.1f kg/ha of phosphorus fertiliser in four equal splits at basal, tillering, panicle initiation and ' ...
            'heading stages. Enough nitrogen and potassium in the soil.'];
        fertilise = {sprintf(formatspec, add_phosphorus)};

    elseif nitrogen > 17 && phosphorus > 5.5 && potassium < 5.5
        add_potassium = (6 - potassium)*700000/100000;
        formatspec = ['Apply %.1f kg/ha of potassium fertiliser at basal stage. Enough nitrogen and phosphorus in the soil.'];
        fertilise = {sprintf(formatspec, add_potassium)};
    end
    
end