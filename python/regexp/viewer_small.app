2
app container 0.............. ""
  meta container 0.............. ""
    info system 1+i----------.. ""
      initial state 1+ip---------.. ""
        state stateName 1+ip-----L---.. "initial"
          sub value_str 1+ip-----L---.. ""
        meta meta 1+ip---------.. ""
          type value_str 1+ip-----L---.. "info"
          _x value_integer 1+ip---------.. 100
          _y value_integer 1+ip---------.. 100
          ignoreDefByDefault value_boolean 1+ip-----L---.. false
        app object 1+ip-----L---.. ""
          home value_path 1+ip---------.. platform.home
          bin value_path 1+ip-----L---.. platform.bin
          data value_path 1+ip-----L---.. home / "data"
          source value_path 1+ip-----L---.. auto
          autorun value_boolean 1+ip---------.. false
          autoclose value_boolean 1+ip---------.. false
          guiStyle value_str 1+ip---------.. "windowsvista"
          qtStyleSheets value_path 1+ip---------.. path("")
          checkLicense value_boolean 1+ip----u----.. false
          algoAutorun value_boolean 1+ip----u----.. true
        to_debug transition 1+ip---------.. ""
          condition value_boolean 1+ip---------.. true
          preProcess statement 1+ip---------.. 
          postProcess statement 1+ip---------.. 
          silent value_boolean 1+ip-----L---.. false
        to_release transition 1+ip---------.. ""
          condition value_boolean 1+ip---------.. false
          preProcess statement 1+ip---------.. 
          postProcess statement 1+ip---------.. 
          silent value_boolean 1+ip-----L---.. false
        app object 1+-p-----L---.. ""
          home value_path 1+-p---------.. path("")
          bin value_path 1+-p-----L---.. path("")
          data value_path 1+-p-----L---.. path("")
          source value_path 1+-p-----L---.. path("")
          autorun value_boolean 1+-p---------.. false
          autoclose value_boolean 1+-p---------.. false
          guiStyle value_str 1+-p---------.. ""
          qtStyleSheets value_path 1+-p---------.. path("")
          checkLicense value_boolean 1+ip----u----.. false
          algoAutorun value_boolean 1+ip----u----.. false
        to_initial transition 1+ip---------.. ""
          condition value_boolean 1+Ip-----L---.. false
          preProcess statement 1+ip---------.. 
          postProcess statement 1-ip-----L---.. 
          silent value_boolean 1+ip-----L---.. true
      release state 1+ip---------.. ""
        state stateName 1+-p-----L---.. "release"
          sub value_str 1+ip-----L---.. "release"
        meta meta 1+ip---------.. ""
          type value_str 1+-p-----L---.. "system"
          _x value_integer 1+ip---------.. 160
          _y value_integer 1+ip---------.. 180
          ignoreDefByDefault value_boolean 1+ip-----L---.. true
        timer timer 1-ip---------.. ""
          interval value_integer 1-ip--s------.. 100
          triggered value_boolean 1-Ip---e-----.. auto
          count value_integer 1-Ip---------.. auto
          misses value_integer 1-Ip---------.. auto
        configuration value_str 1+-p-----L---.. ""
        platform object 1+-p-----L---.. ""
          version value_str 1+-p-----L---.. ""
          homeSlash value_str 1+-p----u----.. ""
          home value_path 1+-p-----L---.. path("")
          binSlash value_str 1+-p----u----.. ""
          bin value_path 1+-p-----L---.. path("")
          projects value_path 1+-p-----L---.. path("")
          cascade object 1+-p-----L---.. ""
            version object 1+-p-----L---.. ""
              supervisor value_str 1+-p-----L---.. ""
              dll value_str 1+-p-----L---.. ""
            home value_path 1+-p-----L---.. path("")
            bin value_path 1+-p-----L---.. path("")
            userAlgos object 1+-p-----L---.. ""
              checkProcessAtStartup value_boolean 1+-p---------.. false
              matlabScripts value_path 1+-p---------.. path("")
              cpp object 1+-p-----L---.. ""
                path value_path 1+-p---------.. path("")
                builder value_path 1+-p---------.. path("")
            watcher object 1+-p-----L---.. ""
              autorun value_boolean 1+Ip---------.. false
              enabled value_boolean 1+Ip---------.. false
          startup object 1+-p-----L---.. ""
            openPropertyEditor value_boolean 1+-p---------.. false
          autosave value_integer 1+-p---------.. 0
          crashOnDemand value_boolean 1+-p---------.. false
          enableTransitionsInEditMode value_boolean 1+-p---------.. false
          newReferenceResolutionAlgorithm value_boolean 1+-p-----L---.. true
          interpretor object 1+-p-----L---.. ""
            enabled value_boolean 1+ip---------.. true
          profiler object 1+-p-----L---.. ""
            enabled value_boolean 1+ip---------.. false
          debugger object 1+-p-----L---.. ""
            assertion object 1+-p-----L---.. ""
              dynamic object 1+-p-----L---.. ""
                enabled value_boolean 1+ip---------.. false
              static object 1+-p-----L---.. ""
                enabled value_boolean 1+-p---------.. false
            maxTimeRunningStep value_integer 1+-p---------.. 0
            maxTimeParamLock value_integer 1+-p---------.. 0
          compiler object 1+-p-----L---.. ""
            trace value_boolean 1+-p---------.. false
            threads value_integer 1+-p---------.. 0
          editor object 1+-p-----L---.. ""
            code object 1+-p-----L---.. ""
              position value_point 1+-p---------.. point(0, 0)
              size value_sizeI 1+-p---------.. size(0, 0)
              font value_font 1+-p---------.. font("default")
        app object 1+-p-----L---.. ""
          home value_path 1+-p---------.. path("")
          bin value_path 1+-p-----L---.. path("")
          data value_path 1+-p-----L---.. path("")
          source value_path 1+-p-----L---.. path("")
          autorun value_boolean 1+-p---------.. false
          autoclose value_boolean 1+-p---------.. false
          guiStyle value_str 1+-p---------.. ""
          qtStyleSheets value_path 1+-p---------.. path("")
          checkLicense value_boolean 1+ip----u----.. true
          algoAutorun value_boolean 1+ip----u----.. true
        to_initial transition 1+ip---------.. ""
          condition value_boolean 1+Ip-----L---.. false
          preProcess statement 1+ip---------.. 
          postProcess statement 1-ip-----L---.. 
          silent value_boolean 1+ip-----L---.. true
  