% Convertit une date en format 16 bit
% TODO CHECK DES PARAMETRES
% [a,b,c] = convert16bit2time(converttime216bit(2045,8,30))
function [date] = converttime216bit(Y,M,D)
    date = 512 * (Y - 1990) + (32 * M) + D;
end
