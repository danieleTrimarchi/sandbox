clear all
close all
clc

%Load the DLL
loadkeylok

%load client unique codes
client

%% Check for KeyLock presence.

command            = 1; % <= KLCHECK
arg1               = ValidateCode1;
arg2               = ValidateCode2;
arg3               = ValidateCode3;

% get results from KFUNC
% find the cmd codes in keylock.h
[result1 result2] = kfunc(command, arg1, arg2, arg3);

command            = bitxor(bitxor(ReadCode3, result2), rotate_16bit_left(result1, bitand(result2, 7)));
arg1               = rotate_16bit_left(result2, bitand(result1, 15));
arg2               = bitxor(result1, result2);
arg3               = 0;

% get results from KFUNC
[result1 result2] = kfunc(command, arg1, arg2, arg3);

% Check result.

r = (result1 == ClientIDCode1) & (result2 == ClientIDCode2);