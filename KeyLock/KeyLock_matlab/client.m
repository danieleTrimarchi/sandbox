% UNIQUE TO DEVICE DATA 
      
% The below codes are for the demonstration device only.
% Unique codes will be assigned to your company when you purchase devices. 


ValidateCode1 = hex2dec('9275'); % Codes used as part of active algorithm to
ValidateCode2 = hex2dec('D691'); % check for installation of proper device
ValidateCode3 = hex2dec('697B');
ClientIDCode1 = hex2dec('ABAA');
ClientIDCode2 = hex2dec('A0DB');
ReadCode1     = hex2dec('E9A8'); % Codes used to authorize read operations
ReadCode2     = hex2dec('B7CE');
ReadCode3     = hex2dec('577E');
WriteCode1    = hex2dec('4388'); % Codes used to authorize write operations
WriteCode2    = hex2dec('C253');
WriteCode3    = hex2dec('E1AD');

RemoteUpdateEncryptKey	= hex2dec('07B6862A');	% Code used to protect AUTHORIZE.DAT file

% S-LOK related definitions */
RequiredSN     = hex2dec('0000'); % Required serial number
TargetLicense  = hex2dec('0000'); % License value