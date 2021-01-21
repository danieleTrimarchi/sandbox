classdef MyClass < handle % deriving from handle allows working on class members
   properties
      Prop
   end
   methods (Access = public)
       myFunc(obj,arg1)
   end
   
   methods (Access = public)
      function obj = MyClass(val)
         if nargin > 0
            obj.Prop = val;
         end
         myFunc(obj,val);
      end
   end
end