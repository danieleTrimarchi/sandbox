function  [result1, result2] = kfunc(command, arg1, arg2,arg3)

switch computer
    case 'PCWIN'
        result = calllib('kl2dll32', 'KFUNC', command, arg1, arg2, arg3);
    case 'PCWIN64'
        result = calllib('kl2dll64', 'KFUNC', command, arg1, arg2, arg3);
    otherwise
        display('Operating System Not supported');
end

bitstr = dec2bin(result);

N = length(bitstr);

if N < 32
    for i = 1:(32-N)
        bitstr = strcat('0', bitstr);
    end
end
result1 = bin2dec(bitstr(17:32));
result2 = bin2dec(bitstr(1:16));