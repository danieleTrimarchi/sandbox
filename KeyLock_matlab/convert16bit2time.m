%return year month day
%TODO check des paramêtres (entier positif) et sorties (jours < 31...) année bisextile
function [Y,M,D] = convert16bit2time(x)
% Correction pour rajouter des 0 si la taille de la date en binaire(converti en chaine de char) est inférieur à 2 byte(16) 
    nExpDate = dec2bin(x);
    N = length(nExpDate);
    if  N < 16
        for i = 1:(16-N)
            nExpDate = strcat('0', nExpDate);
        end
    end

    Y = 1990 + bin2dec(nExpDate(1:7));
    M = bin2dec(nExpDate(8:11));
    D = bin2dec(nExpDate(12:16));
%     Y = bitand(x, hex2dec('FE00')) / 512 + 1990;
%     M = bitand(x, hex2dec('1E0') / 32);
%     D = bitand(x, hex2dec('1f'));
end
