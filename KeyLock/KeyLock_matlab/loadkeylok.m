switch computer
    case 'PCWIN'
        if libisloaded('kl2dll32')
            unloadkeylok
        end
        loadlibrary('kl2dll32',  @keylokdllproto)
    case 'PCWIN64'
        if libisloaded('kl2dll64')
            unloadkeylok
        end
        loadlibrary('kl2dll64',  @keylokdllproto)
    otherwise
        display('Operating System Not supported');
end