 %Load the DLL
loadkeylok
%load client unique codes
client
%% Check for KeyLock presence.
command            = 1;
arg1               = ValidateCode1;
arg2               = ValidateCode2;
arg3               = ValidateCode3;

% get results from KFUNC
[result1, result2] = kfunc(command, arg1, arg2, arg3);

command            = bitxor(bitxor(ReadCode3, result2), rotate_16bit_left(result1, bitand(result2, 7)));
arg1               = rotate_16bit_left(result2, bitand(result1, 15));
arg2               = bitxor(result1, result2);
arg3               = 0;

% get results from KFUNC
[result1, result2] = kfunc(command, arg1, arg2, arg3);

% Check result.
bool = (result1 == ClientIDCode1) & (result2 == ClientIDCode2);
    
      
%READ OPERATIONS
%READAUTH
[result1, result2] = kfunc(2, ReadCode1, ReadCode2, ReadCode3);
    
%WRITE OPERATIONS
%WRITEAUTH No return values
[result1, result2] = kfunc(5, WriteCode1, WriteCode2, WriteCode3);

%%
%read dongle serial number
[result1, result2] = kfunc(3, 1, 2, 3);
disp("Dongle serial number " + result1);

%get customer serial number
[lower, upper] = kfunc(89, 1, 2, 3);
disp(["Customer serial number : lower ", lower,", upper  ", upper]);

%-----------------------------------------------------------------------------------------------------------
%set dongle customer serial number
%param upper puis lower
%[lower, upper] = kfunc(31, 43132, 42565, 3);

%get customer serial number
[lower, upper] = kfunc(89, 1, 2, 3);
disp(["Customer serial number : lower ", lower,", upper  ", upper]);

%read expiration date
[result1, result2] = kfunc(8, 1, 2 , 3);
[Y, M, D] = convert16bit2time(result1);
disp("Expire : Annee = " + Y + ", Mois = " + M + ", Jour = " + D);

%set lease Expiration date
%AAAA MM JJ
%dateExp = converttime216bit(2022,3,2);
%[result1, result2] = kfunc(10, 1, dateExp , 3); %set la dateExp

%read expiration date
[result1, result2] = kfunc(8, 1, 2 , 3);
[Y, M, D] = convert16bit2time(result1);
disp("Expire : Annee = " + Y + ", Mois = " + M + ", Jour = " + D);

%check expiration date
[result1, result2] = kfunc(9, randi([0;65535],1,1), randi([0;65535],1,1), randi([0;65535],1,1));
[Y, M, D] = convert16bit2time(result1);
disp("result1 : Annee = " + Y + ", Mois = " + M + ", Jour = " + D);
disp("nbjour : " + result2)

% %check real clock
% [result1, result2] = kfunc(82, randi([0;65535],1,1), randi([0;65535],1,1), randi([0;65535],1,1));
% % uint32 status;
% status = uint32(getlastkeyerror());
% disp(['result1 = ' num2str(result1)]);
% disp(['result2 = ' num2str(result2)]);
% 
% lRTCSeconds = uint32(result2 * 65536 + result1);
% 
% time = datetime(1970,1,1,0,0,0,0);
% time2 = time + seconds(lRTCSeconds);
% 
% % time = datestr(lRTCSeconds,'dd:mmmm:yyyy:HH:MM:SS PM');
% disp(["Time : ", time2]);
% 
% [Y, M, D] = convert16bit2time(result2);
% disp("Year = " + Y + ", Month = " + M + ", Day = " + D);
