classdef batchProcessing_edit < matlab.apps.AppBase

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
        SelectsourcefolderButton      matlab.ui.control.Button
        UITable                       matlab.ui.control.Table
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
            indices = event.Indices;
            newData = event.NewData;
            app.UITable.Data{k, 1} = 'a'; % Vidange des cases
            app.UITable.Data{k, 2} = false; % Vidange des cases
            app.UITable.Data{k, 3} = false; % Vidange des cases
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Color = [0.6588 0.2588 0.0863];
            app.UIFigure.Colormap = [0.2431 0.149 0.6588;0.2431 0.1529 0.6745;0.2471 0.1569 0.6863;0.2471 0.1608 0.698;0.251 0.1647 0.7059;0.251 0.1686 0.7176;0.2549 0.1725 0.7294;0.2549 0.1765 0.7412;0.2588 0.1804 0.749;0.2588 0.1843 0.7608;0.2627 0.1882 0.7725;0.2627 0.1922 0.7843;0.2627 0.1961 0.7922;0.2667 0.2 0.8039;0.2667 0.2039 0.8157;0.2706 0.2078 0.8235;0.2706 0.2157 0.8353;0.2706 0.2196 0.8431;0.2745 0.2235 0.851;0.2745 0.2275 0.8627;0.2745 0.2314 0.8706;0.2745 0.2392 0.8784;0.2784 0.2431 0.8824;0.2784 0.2471 0.8902;0.2784 0.2549 0.898;0.2784 0.2588 0.902;0.2784 0.2667 0.9098;0.2784 0.2706 0.9137;0.2784 0.2745 0.9216;0.2824 0.2824 0.9255;0.2824 0.2863 0.9294;0.2824 0.2941 0.9333;0.2824 0.298 0.9412;0.2824 0.3059 0.9451;0.2824 0.3098 0.949;0.2824 0.3137 0.9529;0.2824 0.3216 0.9569;0.2824 0.3255 0.9608;0.2824 0.3294 0.9647;0.2784 0.3373 0.9686;0.2784 0.3412 0.9686;0.2784 0.349 0.9725;0.2784 0.3529 0.9765;0.2784 0.3569 0.9804;0.2784 0.3647 0.9804;0.2745 0.3686 0.9843;0.2745 0.3765 0.9843;0.2745 0.3804 0.9882;0.2706 0.3843 0.9882;0.2706 0.3922 0.9922;0.2667 0.3961 0.9922;0.2627 0.4039 0.9922;0.2627 0.4078 0.9961;0.2588 0.4157 0.9961;0.2549 0.4196 0.9961;0.251 0.4275 0.9961;0.2471 0.4314 1;0.2431 0.4392 1;0.2353 0.4431 1;0.2314 0.451 1;0.2235 0.4549 1;0.2196 0.4627 0.9961;0.2118 0.4667 0.9961;0.2078 0.4745 0.9922;0.2 0.4784 0.9922;0.1961 0.4863 0.9882;0.1922 0.4902 0.9882;0.1882 0.498 0.9843;0.1843 0.502 0.9804;0.1843 0.5098 0.9804;0.1804 0.5137 0.9765;0.1804 0.5176 0.9725;0.1804 0.5255 0.9725;0.1804 0.5294 0.9686;0.1765 0.5333 0.9647;0.1765 0.5412 0.9608;0.1765 0.5451 0.9569;0.1765 0.549 0.9529;0.1765 0.5569 0.949;0.1725 0.5608 0.9451;0.1725 0.5647 0.9412;0.1686 0.5686 0.9373;0.1647 0.5765 0.9333;0.1608 0.5804 0.9294;0.1569 0.5843 0.9255;0.1529 0.5922 0.9216;0.1529 0.5961 0.9176;0.149 0.6 0.9137;0.149 0.6039 0.9098;0.1451 0.6078 0.9098;0.1451 0.6118 0.9059;0.1412 0.6196 0.902;0.1412 0.6235 0.898;0.1373 0.6275 0.898;0.1373 0.6314 0.8941;0.1333 0.6353 0.8941;0.1294 0.6392 0.8902;0.1255 0.6471 0.8902;0.1216 0.651 0.8863;0.1176 0.6549 0.8824;0.1137 0.6588 0.8824;0.1137 0.6627 0.8784;0.1098 0.6667 0.8745;0.1059 0.6706 0.8706;0.102 0.6745 0.8667;0.098 0.6784 0.8627;0.0902 0.6824 0.8549;0.0863 0.6863 0.851;0.0784 0.6902 0.8471;0.0706 0.6941 0.8392;0.0627 0.698 0.8353;0.0549 0.702 0.8314;0.0431 0.702 0.8235;0.0314 0.7059 0.8196;0.0235 0.7098 0.8118;0.0157 0.7137 0.8078;0.0078 0.7176 0.8;0.0039 0.7176 0.7922;0 0.7216 0.7882;0 0.7255 0.7804;0 0.7294 0.7765;0.0039 0.7294 0.7686;0.0078 0.7333 0.7608;0.0157 0.7333 0.7569;0.0235 0.7373 0.749;0.0353 0.7412 0.7412;0.051 0.7412 0.7373;0.0627 0.7451 0.7294;0.0784 0.7451 0.7216;0.0902 0.749 0.7137;0.102 0.7529 0.7098;0.1137 0.7529 0.702;0.1255 0.7569 0.6941;0.1373 0.7569 0.6863;0.1451 0.7608 0.6824;0.1529 0.7608 0.6745;0.1608 0.7647 0.6667;0.1686 0.7647 0.6588;0.1725 0.7686 0.651;0.1804 0.7686 0.6471;0.1843 0.7725 0.6392;0.1922 0.7725 0.6314;0.1961 0.7765 0.6235;0.2 0.7804 0.6157;0.2078 0.7804 0.6078;0.2118 0.7843 0.6;0.2196 0.7843 0.5882;0.2235 0.7882 0.5804;0.2314 0.7882 0.5725;0.2392 0.7922 0.5647;0.251 0.7922 0.5529;0.2588 0.7922 0.5451;0.2706 0.7961 0.5373;0.2824 0.7961 0.5255;0.2941 0.7961 0.5176;0.3059 0.8 0.5059;0.3176 0.8 0.498;0.3294 0.8 0.4863;0.3412 0.8 0.4784;0.3529 0.8 0.4667;0.3686 0.8039 0.4549;0.3804 0.8039 0.4471;0.3922 0.8039 0.4353;0.4039 0.8039 0.4235;0.4196 0.8039 0.4118;0.4314 0.8039 0.4;0.4471 0.8039 0.3922;0.4627 0.8 0.3804;0.4745 0.8 0.3686;0.4902 0.8 0.3569;0.5059 0.8 0.349;0.5176 0.8 0.3373;0.5333 0.7961 0.3255;0.5451 0.7961 0.3176;0.5608 0.7961 0.3059;0.5765 0.7922 0.2941;0.5882 0.7922 0.2824;0.6039 0.7882 0.2745;0.6157 0.7882 0.2627;0.6314 0.7843 0.251;0.6431 0.7843 0.2431;0.6549 0.7804 0.2314;0.6706 0.7804 0.2235;0.6824 0.7765 0.2157;0.698 0.7765 0.2078;0.7098 0.7725 0.2;0.7216 0.7686 0.1922;0.7333 0.7686 0.1843;0.7451 0.7647 0.1765;0.7608 0.7647 0.1725;0.7725 0.7608 0.1647;0.7843 0.7569 0.1608;0.7961 0.7569 0.1569;0.8078 0.7529 0.1529;0.8157 0.749 0.1529;0.8275 0.749 0.1529;0.8392 0.7451 0.1529;0.851 0.7451 0.1569;0.8588 0.7412 0.1569;0.8706 0.7373 0.1608;0.8824 0.7373 0.1647;0.8902 0.7373 0.1686;0.902 0.7333 0.1765;0.9098 0.7333 0.1804;0.9176 0.7294 0.1882;0.9255 0.7294 0.1961;0.9373 0.7294 0.2078;0.9451 0.7294 0.2157;0.9529 0.7294 0.2235;0.9608 0.7294 0.2314;0.9686 0.7294 0.2392;0.9765 0.7294 0.2431;0.9843 0.7333 0.2431;0.9882 0.7373 0.2431;0.9961 0.7412 0.2392;0.9961 0.7451 0.2353;0.9961 0.7529 0.2314;0.9961 0.7569 0.2275;0.9961 0.7608 0.2235;0.9961 0.7686 0.2196;0.9961 0.7725 0.2157;0.9961 0.7804 0.2078;0.9961 0.7843 0.2039;0.9961 0.7922 0.2;0.9922 0.7961 0.1961;0.9922 0.8039 0.1922;0.9922 0.8078 0.1922;0.9882 0.8157 0.1882;0.9843 0.8235 0.1843;0.9843 0.8275 0.1804;0.9804 0.8353 0.1804;0.9765 0.8392 0.1765;0.9765 0.8471 0.1725;0.9725 0.851 0.1686;0.9686 0.8588 0.1647;0.9686 0.8667 0.1647;0.9647 0.8706 0.1608;0.9647 0.8784 0.1569;0.9608 0.8824 0.1569;0.9608 0.8902 0.1529;0.9608 0.898 0.149;0.9608 0.902 0.149;0.9608 0.9098 0.1451;0.9608 0.9137 0.1412;0.9608 0.9216 0.1373;0.9608 0.9255 0.1333;0.9608 0.9333 0.1294;0.9647 0.9373 0.1255;0.9647 0.9451 0.1216;0.9647 0.949 0.1176;0.9686 0.9569 0.1098;0.9686 0.9608 0.1059;0.9725 0.9686 0.102;0.9725 0.9725 0.0941;0.9765 0.9765 0.0863;0.9765 0.9843 0.0824];
            app.UIFigure.Position = [100 100 640 480];
            app.UIFigure.Name = 'MATLAB App';

            % Create TabGroup
            app.TabGroup = uitabgroup(app.UIFigure);
            app.TabGroup.Position = [1 1 640 480];

            % Create ChooseprocessingtypeTab
            app.ChooseprocessingtypeTab = uitab(app.TabGroup);
            app.ChooseprocessingtypeTab.Title = 'Choose processing type: ';

            % Create IQprocessingLabel
            app.IQprocessingLabel = uilabel(app.ChooseprocessingtypeTab);
            app.IQprocessingLabel.Position = [12 426 90 22];
            app.IQprocessingLabel.Text = 'IQ processing : ';

            % Create superlocButton
            app.superlocButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.superlocButton.ButtonPushedFcn = createCallbackFcn(app, @superlocButtonPushed, true);
            app.superlocButton.Tooltip = {'compute superloc images, starting from *.scan  *.hraw  *.raw acquisition data'};
            app.superlocButton.Position = [20 391 100 36];
            app.superlocButton.Text = 'superloc';

            % Create BandwisedopplerButton
            app.BandwisedopplerButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.BandwisedopplerButton.Tooltip = {'extract the doppler bandwise  depending on blood velocity'};
            app.BandwisedopplerButton.Position = [130 391 133 36];
            app.BandwisedopplerButton.Text = 'Bandwise doppler';

            % Create AcquisitioneditorLabel
            app.AcquisitioneditorLabel = uilabel(app.ChooseprocessingtypeTab);
            app.AcquisitioneditorLabel.Position = [14 365 107 22];
            app.AcquisitioneditorLabel.Text = 'Acquisition editor : ';

            % Create scaneditingButton
            app.scaneditingButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.scaneditingButton.Position = [23 330 100 36];
            app.scaneditingButton.Text = 'scan editing';

            % Create SuppressionArtefactsButton
            app.SuppressionArtefactsButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.SuppressionArtefactsButton.Position = [130 330 133 36];
            app.SuppressionArtefactsButton.Text = 'Suppression Artefacts';

            % Create MultianalysisprocessingLabel
            app.MultianalysisprocessingLabel = uilabel(app.ChooseprocessingtypeTab);
            app.MultianalysisprocessingLabel.Position = [12 295 149 22];
            app.MultianalysisprocessingLabel.Text = 'Multi analysis processing : ';

            % Create ConnectivityButton
            app.ConnectivityButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.ConnectivityButton.Position = [23 260 100 36];
            app.ConnectivityButton.Text = 'Connectivity';

            % Create HemoDynamicsresponseButton
            app.HemoDynamicsresponseButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.HemoDynamicsresponseButton.Position = [130 260 133 36];
            app.HemoDynamicsresponseButton.Text = {'HemoDynamics '; 'response'};

            % Create RecalageButton
            app.RecalageButton = uibutton(app.ChooseprocessingtypeTab, 'push');
            app.RecalageButton.Position = [274 391 120 36];
            app.RecalageButton.Text = 'Recalage';

            % Create SuperLocTab
            app.SuperLocTab = uitab(app.TabGroup);
            app.SuperLocTab.SizeChangedFcn = createCallbackFcn(app, @SuperLocTabSizeChanged, true);
            app.SuperLocTab.Title = 'SuperLoc';

            % Create SelectsourcefolderButton
            app.SelectsourcefolderButton = uibutton(app.SuperLocTab, 'push');
            app.SelectsourcefolderButton.ButtonPushedFcn = createCallbackFcn(app, @SelectsourcefolderButtonPushed, true);
            app.SelectsourcefolderButton.Position = [14 414 122 22];
            app.SelectsourcefolderButton.Text = 'Select source folder';

            % Create UITable
            app.UITable = uitable(app.SuperLocTab);
            app.UITable.ColumnName = {'Data name'; 'Processed'; 'ToBeProcessed'};
            app.UITable.RowName = {0:1:10};
            app.UITable.CellEditCallback = createCallbackFcn(app, @UITableCellEdit, true);
            app.UITable.Tag = 'sourceFolderListTab';
            app.UITable.Position = [23 183 417 220];

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = batchProcessing_edit

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