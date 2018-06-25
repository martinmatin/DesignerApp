s = serial('COM6')
s.Baudrate = 115200;
fopen(s)

%Ensemble des informations liées à chaque ID
idInfo(16,:) = {'RPM',13,1000};
valData = {0,0,'RPM',0};
for i=0:30
    
   
        busData  = str2num(fgetl(s));
        busData
        valData{1,1} = busData(1);
        valData{1,4} = busData(2);
        valData
        

    
    
end

fclose(s)
delete(s)
