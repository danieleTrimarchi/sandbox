function [methodinfo,structs,enuminfo,ThunkLibName] = keylokdllproto
switch computer
    case 'PCWIN'
        ival = {cell(1,0)};
        structs = [];
        enuminfo = [];
        fcns = struct('name',ival,'calltype',ival,'LHS',ival,'RHS',ival,'alias',ival);
        ThunkLibName = [];
        
        % extern unsigned long int KFUNC ( int command , int arg1 , int arg2 , int arg3 );
        fcns.name{1} = 'KFUNC';
        %fcns.calltype{1} = 'cdecl';
        fcns.calltype{1} = 'stdcall';
        fcns.LHS{1} = 'uint32';
        fcns.RHS{1} = {'int32', 'int32', 'int32', 'int32'};
        
        % extern unsigned int GETLASTKEYERROR ( void );
        fcns.name{2} = 'GETLASTKEYERROR';
        fcns.calltype{2} = 'cdecl';
        fcns.LHS{2} = 'uint32';
        fcns.RHS{2} = [];
       
        % KEYBD(int Arg1) As Short
        fcns.name{3} = 'KEYBD';
        fcns.calltype{3} = 'cdecl';
        fcns.LHS{3} = 'int16';
        fcns.RHS{3} = 'int32';

        methodinfo = fcns;
    case 'PCWIN64'
        ival = {cell(1,0)};
        structs = [];
        enuminfo = [];
        fcns = struct('name',ival,'calltype',ival,'LHS',ival,'RHS',ival,'alias',ival);
        ThunkLibName = [];
        
        % extern unsigned long int KFUNC ( int command , int arg1 , int arg2 , int arg3 );
        fcns.name{1} = 'KFUNC';
        %fcns.calltype{1} = 'cdecl';
        fcns.calltype{1} = 'cdecl';
        fcns.LHS{1} = 'uint32';
        fcns.RHS{1} = {'int32', 'int32', 'int32', 'int32'};
        
        % extern unsigned int GETLASTKEYERROR ( void );
        fcns.name{2} = 'GETLASTKEYERROR';
        fcns.calltype{2} = 'cdecl';
        fcns.LHS{2} = 'uint32';
        fcns.RHS{2} = [];
     
        
        % KEYBD(int Arg1) As Short
        fcns.name{3} = 'KEYBD';
        fcns.calltype{3} = 'cdecl';
        fcns.LHS{3} = 'int16';
        fcns.RHS{3} = 'int32';

        methodinfo = fcns;
    otherwise
        display('Not supported')
end