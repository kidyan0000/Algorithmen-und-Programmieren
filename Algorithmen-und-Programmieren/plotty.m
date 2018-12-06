%PLOTEN VON DATEN

clear all; %LOESCHEN ALLE ALTEN DATEN
load xy.dat; %LADEN DER DATENSAETZEN IN MATLAB
load kurve.dat;

x = xy(:,1);
y = xy(:,2);

plot(x,y,'or');
hold on; %HALTEN BILDINHALT FEST

x1 = kurve(:,1);
y1 = kurve(:,2);

plot(x1,y1,'or');