function varargout=getinput(input)

for k = 1:length(input)
    i=input{k};
    if iscell(i)
        for j=1:length(i)
            varargout{k}{j} = i{j};
        end
    else
        varargout{k} = i;
    end
end

 for kvoid=length(input)+1:nargout
        varargout{kvoid}=[];
    end

end
