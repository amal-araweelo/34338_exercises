% Channels and fields
readChID = 0000000; % REDACTED
fID1 = 2;
fID2 = 3;

rAPIKey = 'REDACTED';

% first variable
[y1, t1] = thingSpeakRead(readChID, 'Field', fID1, 'NumPoints', 40, 'ReadKey', rAPIKey);

% second variable
[y2, t2] = thingSpeakRead(readChID, 'Field', fID2, 'NumPoints', 40, 'ReadKey', rAPIKey);

%plot

yyaxis left;
plot(t1, y1)
ylabel("RSSI (dBm)")

yyaxis right;
stairs(t2, y2);
ylabel("Led state (1 = on)")
ylim([-0.02, 1.02])
