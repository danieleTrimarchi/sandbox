switch computer
    case 'PCWIN'
        unloadlibrary kl2dll32
    case 'PCWIN64'
        unloadlibrary kl2dll64
    otherwise
        display('Operating System Not supported');
end