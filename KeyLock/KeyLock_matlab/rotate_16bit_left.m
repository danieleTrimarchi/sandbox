%**************************************************************************************
% Rotate a 16-bit value a few bits to the left.
%**************************************************************************************

function [y] = rotate_16bit_left(x, bits)

y = x;
for i = 1:bits
    MSB_one = bitand(y, hex2dec('8000'));
    y       = bitand(y, hex2dec('7FFF'));
    if (MSB_one)
        y = 2*y + 1;
    else
        y = 2*y;
    end
end