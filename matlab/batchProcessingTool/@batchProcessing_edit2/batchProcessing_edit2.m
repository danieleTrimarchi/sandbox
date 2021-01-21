classdef batchProcessing_edit2 < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                      matlab.ui.Figure
        TabGroup                      matlab.ui.container.TabGroup
        ChooseprocessingtypeTab       matlab.ui.container.Tab
        IQprocessingLabel             matlab.ui.control.Label
        superlocButton                matlab.ui.control.Button
        BandwisedopplerButton         matlab.ui.control.Button
        AcquisitioneditorLabel        matlab.ui.control.Label
        scaneditingButton             matlab.ui.control.Button
        SuppressionArtefactsButton    matlab.ui.control.Button
        MultianalysisprocessingLabel  matlab.ui.control.Label
        ConnectivityButton            matlab.ui.control.Button
        HemoDynamicsresponseButton    matlab.ui.control.Button
        RecalageButton                matlab.ui.control.Button
        SuperLocTab                   matlab.ui.container.Tab
        Panel                         matlab.ui.container.Panel
        GridLayout                    matlab.ui.container.GridLayout
        SelectdatatoprocessPanel      matlab.ui.container.Panel
        SelectsourcefolderButton      matlab.ui.control.Button
        UITable                       matlab.ui.control.Table
        Label                         matlab.ui.control.Label
        SignalprocessingparametersPanel  matlab.ui.container.Panel
        selecttimespantotreatPanel    matlab.ui.container.Panel
        WholeacquisitionCheckBox      matlab.ui.control.CheckBox
        StartsEditFieldLabel          matlab.ui.control.Label
        StartsEditField               matlab.ui.control.NumericEditField
        EndsEditFieldLabel            matlab.ui.control.Label
        EndsEditField                 matlab.ui.control.NumericEditField
        ChartDropDownLabel            matlab.ui.control.Label
        ChartDropDown                 matlab.ui.control.DropDown
        BlocksperimgEditFieldLabel    matlab.ui.control.Label
        BlocksperimgEditField         matlab.ui.control.NumericEditField
        ImgviewPanel                  matlab.ui.container.Panel
        GridLayout2                   matlab.ui.container.GridLayout
        PositionPanel                 matlab.ui.container.Panel
        VelocityPanel                 matlab.ui.container.Panel
        UIAxes_2                      matlab.ui.control.UIAxes
        UIAxes                        matlab.ui.control.UIAxes
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: superlocButton
        function superlocButtonPushed(app, event)
           app.TabGroup.SelectedTab = app.SuperLocTab;
        end

        % Size changed function: SuperLocTab
        function SuperLocTabSizeChanged(app, event)
        
        end

        % Button pushed function: SelectsourcefolderButton
        function SelectsourcefolderButtonPushed(app, event)
            % Récupère et affiche le chemin d'accès du dossier souhaité, qui contient les
            % données à traiter (source folder)
            chosenDir = uigetdir();

            for k=1:10 %length(size(app.UITable.Data, 1))
                app.UITable.Data{k, 1} = chosenDir; 
                app.UITable.Data{k, 2} = true; 
                app.UITable.Data{k, 3} = false; 
            end
        end
        
        % Cell edit callback: UITable
        function UITableCellEdit(app, event)
            %indices = event.Indices;
            %newData = event.NewData;
            app.UITable.Data{k, 1} = 'a'; % Vidange des cases
            app.UITable.Data{k, 2} = false; % Vidange des cases
            app.UITable.Data{k, 3} = false; % Vidange des cases
        end
        
        % Create UIFigure and components
        output = createComponents(app)

    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = batchProcessing_edit2

            disp("in ctor!") 
            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end